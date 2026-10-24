// Gebsfish wiki script. The fish database renders from FISH (inline in index.html, which
// tools/stingray/check.py reads), the pictures and descriptions from fish-details.js and
// item-details.js (tools/build_wiki_assets.py, tools/build_wiki_items.py). Nav, reveal, copy
// and the detail sheet work like the Animals, Plants and Mushrooms sites' app.js.
(() => {
  "use strict";
  const $ = (s, r = document) => r.querySelector(s);
  const $$ = (s, r = document) => [...r.querySelectorAll(s)];
  const FISHES = typeof FISH !== "undefined" ? FISH : [];
  const FD = typeof FISHDETAIL !== "undefined" ? FISHDETAIL : {};
  const ID = typeof ITEMDETAIL !== "undefined" ? ITEMDETAIL : {};
  document.documentElement.classList.add("js");

  function h(tag, attrs = {}, ...kids) {
    const el = document.createElement(tag);
    for (const [k, v] of Object.entries(attrs)) {
      if (v == null || v === false) continue;
      if (k === "class") el.className = v;
      else if (k === "text") el.textContent = v;
      else if (k.startsWith("on")) el.addEventListener(k.slice(2), v);
      else el.setAttribute(k, v === true ? "" : v);
    }
    for (const kid of kids.flat()) if (kid != null && kid !== false) el.append(kid);
    return el;
  }

  // The generated descriptions arrive HTML-escaped (&#x27; and so on); decode them to plain text.
  const decoder = document.createElement("textarea");
  const plain = s => { decoder.innerHTML = s || ""; return decoder.value; };

  const WORDS = ["zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve",
    "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"];
  const TENS = ["", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"];
  const words = n => n < 20 ? WORDS[n] : n < 100 ? TENS[Math.floor(n / 10)] + (n % 10 ? "-" + WORDS[n % 10] : "") : String(n);
  const cap = s => s.charAt(0).toUpperCase() + s.slice(1);

  // ---- stats and counts in the copy
  const STATS = {
    species: FISHES.length || null,
    items: Object.keys(ID).filter(k => !/_Opened$/.test(k)).length || null
  };
  $$("[data-stat]").forEach(el => { const v = STATS[el.dataset.stat]; if (v != null) el.textContent = v; });
  $$("[data-stat-words]").forEach(el => { const v = STATS[el.dataset.statWords]; if (v != null) el.textContent = cap(words(v)); });

  // ---- copy + toast
  const toast = $("#toast");
  let toastTimer;
  async function copy(text, label = "Copied") {
    try { await navigator.clipboard.writeText(text); }
    catch {
      const t = h("textarea", { style: "position:fixed;opacity:0" }); t.value = text;
      document.body.append(t); t.select(); document.execCommand("copy"); t.remove();
    }
    toast.textContent = label;
    toast.classList.add("show");
    clearTimeout(toastTimer);
    toastTimer = setTimeout(() => toast.classList.remove("show"), 1500);
  }

  // ---- navigation
  const menu = $("#menu"), links = $("#nav-links");
  menu.addEventListener("click", () => {
    const open = links.classList.toggle("open");
    menu.setAttribute("aria-expanded", String(open));
  });
  $$("a", links).forEach(a => a.addEventListener("click", () => {
    links.classList.remove("open"); menu.setAttribute("aria-expanded", "false");
  }));
  function scrollSpy(map, margin) {
    const spy = new IntersectionObserver(entries => {
      for (const en of entries) {
        if (!en.isIntersecting) continue;
        map.forEach(a => a.classList.remove("active"));
        const a = map.get(en.target.id);
        if (a) a.classList.add("active");
      }
    }, { rootMargin: margin });
    map.forEach((_, id) => { const s = document.getElementById(id); if (s) spy.observe(s); });
  }
  scrollSpy(new Map($$("a[href^='#']", links).map(a => [a.getAttribute("href").slice(1), a])), "-45% 0px -50% 0px");

  // The wiki used to be tabs; old links to #tab-guide and so on land on the section. On load,
  // any link is followed again once the grids below are built, as they move what's under them.
  function hashTarget(tabsOnly) {
    let id = "";
    try { id = decodeURIComponent(location.hash.slice(1)); } catch { return null; }  // a malformed % escape
    const m = /^tab-([\w-]+)$/.exec(id);
    return m ? document.getElementById(m[1]) : tabsOnly ? null : id && document.getElementById(id);
  }
  addEventListener("hashchange", () => { const el = hashTarget(true); if (el) el.scrollIntoView({ behavior: "instant" }); });

  // ---- reveal on scroll
  const reveal = new IntersectionObserver(entries => {
    for (const en of entries) if (en.isIntersecting) { en.target.classList.add("in"); reveal.unobserve(en.target); }
  }, { rootMargin: "0px 0px -8% 0px" });
  const watch = root => $$(".reveal:not(.in)", root).forEach(el => reveal.observe(el));
  watch(document);

  // ---- detail sheet
  const sheet = $("#sheet"), body = $("#sheet-body");
  function openSheet(content) {
    body.replaceChildren(...content);
    if (typeof sheet.showModal === "function") sheet.showModal(); else sheet.setAttribute("open", "");
    sheet.scrollTop = 0;
  }
  $("#sheet-close").addEventListener("click", () => sheet.close());
  sheet.addEventListener("click", e => { if (e.target === sheet) sheet.close(); });
  const clsButton = cls => h("button", { class: "cls", type: "button", title: "Copy classname", onclick: () => copy(cls, cls + " copied") }, cls);
  const noArt = label => h("div", { class: "noart", text: label || "" });
  // A missing picture swaps itself for the placeholder rather than leaving a broken-image box.
  const art = (src, alt, label, eager) => src ? h("img", {
    src, alt, loading: eager ? "eager" : "lazy", decoding: "async",
    onerror: e => e.target.replaceWith(noArt(label))
  }) : noArt(label);

  function segmented(root, options, onPick) {
    let current = options[0].key;
    const buttons = options.map(o => h("button", {
      type: "button", "aria-pressed": String(o.key === current),
      onclick: () => {
        current = o.key;
        buttons.forEach((b, i) => b.setAttribute("aria-pressed", String(options[i].key === current)));
        onPick(current);
      }
    }, o.label, o.count != null ? h("small", { text: o.count }) : null));
    root.replaceChildren(...buttons);
  }

  function stagger(grid, cards) {
    grid.replaceChildren(...cards);
    cards.forEach((c, i) => { c.classList.add("reveal"); c.style.transitionDelay = Math.min(i % 8, 7) * 40 + "ms"; });
    watch(grid);
  }

  // ---- fish database
  const ENV = { 1: ["Freshwater", "pond"], 2: ["Saltwater", "sea"], 3: ["Both", "both"] };
  const BITE = { Nocturnal: "Nocturnal", Crepuscular: "Dawn & dusk", Pelagic: "Open-water", Diurnal: "Daytime",
    TwilightNight: "Twilight & night", Steady: "Steady", FilterFeeder: "Filter feeder", Constant: "Always active" };
  const methodNames = m => [m & 1 && "Rod", m & 2 && "Large trap", m & 4 && "Small trap"].filter(Boolean);
  const rarity = p => p >= 20 ? ["Abundant", "abundant"] : p >= 12 ? ["Common", "common"] : p >= 7 ? ["Uncommon", "uncommon"] : ["Rare", "rare"];
  const meat = f => f.rm ? (f.mn === f.mx ? String(f.mn) : f.mn + "–" + f.mx) : "—";
  function recipeDesc(f) {
    if (!f.rm) return "Catch only — no fillet recipe";
    const m = meat(f);
    if (f.shape === 1) return f.rb + " + " + m + " × " + f.rm + " (caviar keep-chance applies)";
    if (f.shape === 2) return f.rb + " (tail) + " + m + " × " + f.rm + " (claws)";
    return m + " × " + f.rm;
  }
  // The seven vanilla fish (Carp, Mackerel, Sardines, Bitterlings, Shrimp, Steelhead Trout and
  // Walleye Pollock) have no render or description, so they show the placeholder.
  const fishArt = (f, eager) => art(FD[f.c] && FD[f.c].img, eager ? f.n : "", "Vanilla DayZ fish", eager);

  function fishSheet(f) {
    const det = FD[f.c];
    const [envName] = ENV[f.env] || ["?"];
    const [rarName, rarCls] = rarity(f.p);
    openSheet([
      h("div", { class: "gallery" }, fishArt(f, true)),
      h("div", { class: "text" },
        h("p", { class: "kicker", text: f.env === 3 ? "Fresh and salt water" : envName }),
        h("h2", { id: "sheet-title", text: f.n }),
        h("span", { class: "badge r-" + rarCls, text: rarName }),
        det && det.desc ? h("p", { class: "desc", text: plain(det.desc) }) : null,
        h("dl", {},
          h("dt", { text: "Classname" }), h("dd", {}, clsButton(f.c)),
          h("dt", { text: "Caught by" }), h("dd", { text: methodNames(f.m).join(", ") }),
          h("dt", { text: "Catch weight" }), h("dd", { text: f.p + " / 25" }),
          h("dt", { text: "Temperature" }), h("dd", { text: f.tmin + "° to " + f.tmax + "° (best " + f.to + "°)" }),
          h("dt", { text: "Weather bias" }), h("dd", { text: "Rain ×" + f.rain + " · Storm ×" + f.storm }),
          h("dt", { text: "Time of day" }), h("dd", { text: "Dawn ×" + f.dawn + " · Day ×" + f.day + " · Dusk ×" + f.dusk + " · Night ×" + f.night }),
          h("dt", { text: "Activity" }), h("dd", { text: BITE[f.bite] || f.bite }),
          h("dt", { text: "Prep result" }), h("dd", { text: recipeDesc(f) })))
    ]);
  }

  if ($("#fish-grid") && FISHES.length) {
    const st = { env: "", method: "", rarity: "", q: "", key: "n", asc: true, view: "cards", expanded: false };
    const grid = $("#fish-grid"), table = $("#fish-table"), tbody = $("#fishbody"), sortSel = $("#f-sort"), dirBtn = $("#f-dir");
    const more = $("#fish-more"), limit = +grid.dataset.limit || 0;

    function rows() {
      const q = st.q.trim().toLowerCase();
      const list = FISHES.filter(f => {
        if (q && !(f.n.toLowerCase().includes(q) || f.c.toLowerCase().includes(q))) return false;
        if (st.env && f.env !== +st.env) return false;
        if (st.method === "rod" && !(f.m & 1)) return false;
        if (st.method === "large" && !(f.m & 2)) return false;
        if (st.method === "small" && !(f.m & 4)) return false;
        if (st.rarity && rarity(f.p)[1] !== st.rarity) return false;
        return true;
      });
      return list.sort((a, b) => {
        let x = a[st.key], y = b[st.key];
        if (typeof x === "string") { x = x.toLowerCase(); y = y.toLowerCase(); }
        return (x < y ? -1 : x > y ? 1 : 0) * (st.asc ? 1 : -1);
      });
    }

    function render() {
      const list = rows();
      $("#count").textContent = list.length + " of " + FISHES.length + " species";
      sortSel.value = st.key;
      dirBtn.textContent = st.asc ? "↑" : "↓";
      dirBtn.setAttribute("aria-label", st.asc ? "Ascending, click for descending" : "Descending, click for ascending");
      grid.hidden = st.view !== "cards";
      table.hidden = st.view !== "table";
      // The cards show the first rows until asked for all; a search or a filter shows every match.
      const cut = st.view === "cards" && limit && !st.expanded && !(st.q.trim() || st.env || st.method || st.rarity) &&
        list.length > limit + 3;
      more.hidden = !cut;
      $("button", more).textContent = "Show all " + list.length + " species";
      if (st.view === "cards") {
        const cards = (cut ? list.slice(0, limit) : list).map(f => {
          const [envName] = ENV[f.env] || ["?"];
          const [rarName, rarCls] = rarity(f.p);
          return h("button", { class: "card", type: "button", onclick: () => fishSheet(f), "aria-label": f.n + ", details" },
            h("div", { class: "pic" }, fishArt(f)),
            h("div", { class: "info" },
              h("h3", { text: f.n }),
              h("p", { class: "meta", text: envName + " · " + methodNames(f.m).join(", ") }),
              h("div", { class: "chips" }, h("span", { class: "chip", text: "Best " + f.to + " °C" }), h("span", { class: "chip", text: BITE[f.bite] || f.bite })),
              h("span", { class: "badge r-" + rarCls, text: rarName })));
        });
        if (!cards.length) cards.push(h("p", { class: "empty", text: "No fish match that search." }));
        stagger(grid, cards);
      } else {
        tbody.replaceChildren(...list.map(f => {
          const [envName, envCls] = ENV[f.env] || ["?", ""];
          const [rarName, rarCls] = rarity(f.p);
          // Tab reaches every row; Enter or Space opens it like a click
          return h("tr", { tabindex: "0", onclick: () => fishSheet(f),
            onkeydown: e => { if (e.key === "Enter" || e.key === " ") { e.preventDefault(); fishSheet(f); } } },
            h("td", {}, h("span", { class: "tn" }, fishArt(f), f.n)),
            h("td", {}, h("span", { class: "tag " + envCls, text: envName })),
            h("td", { text: methodNames(f.m).join(", ") }),
            h("td", {}, h("span", { class: "tag " + rarCls, text: rarName })),
            h("td", { text: f.to + "°" }),
            h("td", { text: meat(f) }),
            h("td", { text: BITE[f.bite] || f.bite }));
        }));
        if (!list.length) tbody.append(h("tr", {}, h("td", { colspan: "7", class: "empty", text: "No fish match that search." })));
      }
      $$("#fishtable thead th").forEach(th => {
        const on = th.dataset.k === st.key;
        th.querySelector(".arrow").textContent = on ? (st.asc ? "▲" : "▼") : "";
        th.setAttribute("aria-sort", on ? (st.asc ? "ascending" : "descending") : "none");
      });
    }

    const count = env => FISHES.filter(f => f.env === env).length;
    segmented($("#f-env"), [{ key: "", label: "All waters", count: FISHES.length },
      { key: "1", label: "Freshwater", count: count(1) }, { key: "2", label: "Saltwater", count: count(2) },
      { key: "3", label: "Both", count: count(3) }], v => { st.env = v; render(); });
    segmented($("#f-view"), [{ key: "cards", label: "Cards" }, { key: "table", label: "Table" }], v => { st.view = v; render(); });
    $("#search").addEventListener("input", e => { st.q = e.target.value; render(); });
    $("#f-method").addEventListener("change", e => { st.method = e.target.value; render(); });
    $("#f-rarity").addEventListener("change", e => { st.rarity = e.target.value; render(); });
    sortSel.addEventListener("change", e => { st.key = e.target.value; st.asc = true; render(); });
    dirBtn.addEventListener("click", () => { st.asc = !st.asc; render(); });
    $("button", more).addEventListener("click", () => { st.expanded = true; render(); });
    // Tab reaches every column heading; Enter or Space sorts by it like a click
    $$("#fishtable thead th").forEach(th => {
      th.tabIndex = 0;
      th.addEventListener("click", () => {
        if (st.key === th.dataset.k) st.asc = !st.asc; else { st.key = th.dataset.k; st.asc = true; }
        render();
      });
      th.addEventListener("keydown", e => { if (e.key === "Enter" || e.key === " ") { e.preventDefault(); th.click(); } });
    });
    render();
  }

  // ---- item tiles: image + name, the in-game description on hover and in the sheet
  const CAT = { gear: "Gear", boat: "Boat", food: "Food", bait: "Live bait", lure: "Lure" };
  const GROUPS = [["all", "All"], ["rods", "Rods"], ["knives", "Knives"], ["boxes", "Tackle boxes"], ["coolers", "Coolers"],
    ["clothing", "Clothing"], ["boats", "Boats"], ["camp", "Camp & tools"]];
  function group(it) {
    const n = it.name;
    if (it.cat === "boat") return "boats";
    if (/Tackle Box$/.test(n)) return "boxes";
    if (/Cooler$/.test(n)) return "coolers";
    if (/Fish Knife$/.test(n)) return "knives";
    if (/Rod$/.test(n)) return "rods";
    if (/(Gloves|Hat|Raincoat|Shirt|Vest|Wellies)$/.test(n)) return "clothing";
    return "camp";
  }
  const itemSheet = (cls, it) => openSheet([
    h("div", { class: "gallery" }, art(it.img, it.name, "", true)),
    h("div", { class: "text" },
      h("p", { class: "kicker", text: CAT[it.cat] || it.cat }),
      h("h2", { id: "sheet-title", text: it.name }),
      it.desc ? h("p", { class: "desc", text: plain(it.desc) }) : null,
      h("dl", {}, h("dt", { text: "Classname" }), h("dd", {}, clsButton(cls))))
  ]);

  $$(".items-grid[data-cats]").forEach(grid => {
    const cats = grid.dataset.cats.split(",");
    const all = Object.keys(ID).filter(k => cats.includes(ID[k].cat))
      .sort((a, b) => ID[a].name.localeCompare(ID[b].name));
    const id = grid.id.replace(/-grid$/, "");
    const seg = $("#" + id + "-filter"), search = $("#" + id + "-search"), countEl = $("#" + id + "-count");
    const more = $("#" + id + "-more"), limit = +grid.dataset.limit || 0;
    let pick = "all", expanded = false;
    const draw = () => {
      const q = search ? search.value.trim().toLowerCase() : "";
      const list = all.filter(k => (pick === "all" || group(ID[k]) === pick) &&
        (!q || (ID[k].name + " " + k).toLowerCase().includes(q)));
      const cut = limit && !expanded && !q && list.length > limit + 3;
      const shown = cut ? list.slice(0, limit) : list;
      const tiles = shown.map(k => h("button", { class: "item", type: "button", title: plain(ID[k].desc || ID[k].name),
        onclick: () => itemSheet(k, ID[k]) }, art(ID[k].img, ""), h("b", { text: ID[k].name })));
      if (!tiles.length) tiles.push(h("p", { class: "empty", text: "Nothing matches that search." }));
      grid.replaceChildren(...tiles);
      if (countEl) countEl.textContent = list.length + (list.length === 1 ? " item" : " items");
      if (more) {
        more.hidden = !cut;
        $("button", more).textContent = "Show all " + list.length;
      }
    };
    if (seg) segmented(seg, GROUPS.map(([key, label]) => ({ key, label,
      count: key === "all" ? all.length : all.filter(k => group(ID[k]) === key).length })).filter(o => o.count),
      v => { pick = v; expanded = false; draw(); });
    if (search) search.addEventListener("input", draw);
    if (more) $("button", more).addEventListener("click", () => { expanded = true; draw(); });
    draw();
  });

  // ---- the guide's contents, built from its numbered chapters
  const toc = $("#guide-toc");
  if (toc) {
    const heads = $$("#guide .prose > h3[id]");
    toc.replaceChildren(h("p", { text: "Contents" }), ...heads.map(hd => h("a", { href: "#" + hd.id, text: hd.textContent })));
    scrollSpy(new Map($$("a", toc).map(a => [a.getAttribute("href").slice(1), a])), "-10% 0px -80% 0px");
  }

  const target = hashTarget(false);
  if (target) target.scrollIntoView({ behavior: "instant" });
})();
