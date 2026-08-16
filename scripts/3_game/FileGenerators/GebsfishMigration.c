// ============================================================================
// One-shot startup migration: sweep files from the pre-3.3 mod layout out of
// $profile:Gebs into $profile:Gebs/gebs_oldfiles so old and new configs never
// sit mixed together. Values from the old fishingsettings.json are NOT
// migrated (superseded schema, dropped on purpose) -- the file is archived so
// an admin can still reference their old tuning by hand.
//
// Old-layout artifacts handled:
//   Gebs/fishingsettings.json      old monolithic config
//   Gebs/Fish/Logs/*               old logger output   (new: Gebs/logs/)
//   Gebs/extras/mpmissions/*       old xml output      (new: Gebs/mpmissions/)
//
// Once the files are out, the emptied Fish/ and extras/ trees (including their
// child folders) are removed too, deepest-first. Enforce has no remove-directory
// call, so that last step depends on the engine's DeleteFile accepting an empty
// directory; when it refuses, the paths are logged for manual cleanup instead.
// ============================================================================
class GebsfishMigration {
    private const static string BASE    = "$profile:Gebs/";
    private const static string ARCHIVE = "$profile:Gebs/gebs_oldfiles/";

    static void ArchiveOldFiles() {
        bool hasSettings = FileExist(BASE + "fishingsettings.json");
        bool hasFishDir  = FileExist(BASE + "Fish");
        bool hasExtras   = FileExist(BASE + "extras");
        if (!hasSettings && !hasFishDir && !hasExtras)
            return;

        if (!MakeDirectory(ARCHIVE) && !FileExist(ARCHIVE)) {
            GebsfishLogger.Error("Could not create " + ARCHIVE + " -- old files left in place.", "Migrate");
            return;
        }

        int moved = 0;
        if (hasSettings && MoveFile(BASE + "fishingsettings.json", ARCHIVE + "fishingsettings.json"))
            moved++;
        if (hasFishDir)
            moved += MoveDirFiles(BASE + "Fish/Logs/", ARCHIVE + "Fish_Logs/");
        if (hasExtras)
            moved += MoveDirFiles(BASE + "extras/mpmissions/", ARCHIVE + "mpmissions/");

        // Now that the files are out, try to take the emptied folders with them.
        // Deepest-first: a parent can only go once its child is gone.
        array<string> stale = new array<string>();
        if (hasFishDir) {
            stale.Insert(BASE + "Fish/Logs");
            stale.Insert(BASE + "Fish");
        }
        if (hasExtras) {
            stale.Insert(BASE + "extras/mpmissions");
            stale.Insert(BASE + "extras");
        }

        array<string> leftover = new array<string>();
        int removed = RemoveEmptyDirs(stale, leftover);

        if (moved > 0)
            GebsfishLogger.Info("Archived " + moved + " old-layout file(s) into gebs_oldfiles.", "Migrate");
        if (removed > 0)
            GebsfishLogger.Info("Removed " + removed + " emptied old-layout folder(s).", "Migrate");
        if (leftover.Count() > 0) {
            string list = "";
            foreach (string s : leftover) {
                if (list != "") list = list + ", ";
                list = list + s;
            }
            GebsfishLogger.Info("These emptied old folders could not be removed and are safe to delete by hand: " + list, "Migrate");
        }
    }

    // Enforce exposes MakeDirectory but no matching remove-directory call, and
    // DeleteFile is documented as deleting a FILE (1_Core/DayZ/proto/EnSystem.c).
    // Whether it also drops an empty directory is up to the engine's native, so
    // just try it: on builds where it works the migration cleans up after itself,
    // and on builds where it doesn't the caller reports the paths instead.
    //
    // A directory is only ever attempted once it is confirmed empty -- we are
    // calling a delete primitive on a path, so nothing that still holds a file
    // (an admin's stray notes, a log the move could not archive) gets passed to it.
    // leftover is filled in place -- array is a reference type, so no `out` needed.
    protected static int RemoveEmptyDirs(array<string> dirs, array<string> leftover) {
        int removed = 0;
        foreach (string dir : dirs) {
            if (!FileExist(dir))
                continue;             // already gone, or never existed
            if (!IsDirEmpty(dir)) {
                leftover.Insert(dir); // still holds something -- leave it alone
                continue;
            }
            if (DeleteFile(dir) && !FileExist(dir))
                removed++;
            else
                leftover.Insert(dir);
        }
        return removed;
    }

    protected static bool IsDirEmpty(string dir) {
        string fileName;
        FileAttr attr;
        FindFileHandle handle = FindFile(dir + "/*", fileName, attr, FindFileFlags.ALL);
        if (!handle)
            return true;              // nothing matched at all

        bool empty = true;
        bool more = true;
        while (more) {
            // "." / ".." show up on some platforms and are not real contents
            if (fileName != "" && fileName != "." && fileName != "..") {
                empty = false;
                break;
            }
            more = FindNextFile(handle, fileName, attr);
        }
        CloseFindFile(handle);
        return empty;
    }

    // Copy-then-delete; never deletes the source unless the copy succeeded.
    protected static bool MoveFile(string from, string to) {
        if (!FileExist(from))
            return false;
        if (!CopyFile(from, to)) {
            GebsfishLogger.Error("Could not copy " + from + " to " + to + " -- left in place.", "Migrate");
            return false;
        }
        if (!DeleteFile(from))
            GebsfishLogger.Error("Copied but could not delete " + from + " -- delete it manually.", "Migrate");
        GebsfishLogger.Info("Moved " + from + " -> " + to, "Migrate");
        return true;
    }

    // Move every regular file in fromDir into toDir. Returns the count moved.
    protected static int MoveDirFiles(string fromDir, string toDir) {
        string fileName;
        FileAttr attr;
        FindFileHandle handle = FindFile(fromDir + "*", fileName, attr, FindFileFlags.ALL);
        if (!handle)
            return 0;

        // Collect names first -- moving files while iterating a live
        // directory listing risks skipping entries.
        array<string> names = new array<string>();
        bool more = true;
        while (more) {
            if (fileName != "" && (attr & FileAttr.DIRECTORY) == 0)
                names.Insert(fileName);
            more = FindNextFile(handle, fileName, attr);
        }
        CloseFindFile(handle);

        if (names.Count() == 0)
            return 0;
        if (!MakeDirectory(toDir) && !FileExist(toDir)) {
            int left = names.Count();
            GebsfishLogger.Error("Could not create " + toDir + " -- " + left + " file(s) left in " + fromDir, "Migrate");
            return 0;
        }

        int moved = 0;
        foreach (string name : names) {
            if (MoveFile(fromDir + name, toDir + name))
                moved++;
        }
        return moved;
    }
}
