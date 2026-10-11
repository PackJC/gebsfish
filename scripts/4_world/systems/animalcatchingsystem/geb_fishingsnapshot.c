/*

  CREATED BY PACKJC
  https://github.com/PackJC/gebsfish
  https://steamcommunity.com/sharedfiles/filedetails/?id=2757509117
  https://discord.com/invite/G8uSGZ8yyf
  Contributions welcome via github

*/

// The world inputs one fishing cast is computed from: the in-game date/time,
// the rain and the snowfall. Vanilla runs the catch math on the client AND the server with
// one synced random number, so both sides must feed it identical inputs --
// reading the live world on each side doesn't (the client's interpolated
// clock and rain lag the server's). The client captures this once when the
// cast starts and sends it with the action, the same way vanilla sends "is
// this the sea"; the server adopts it after checking it against its own
// reading (ActionFishingNew.HandleReciveData). Every weather, time-of-day,
// moon and water-temperature effect in CatchingContextFishingRodAction reads
// from it for the whole cast.
class GebFishingSnapshot {
	// How far the client's reading may sit from the server's before the
	// server uses its own instead. Loose enough for network lag at high time
	// acceleration, and the rain tolerance covers snowfall too. What it
	// guarantees: a modified client can't claim a storm on a dry day or dawn
	// at noon. What it allows: within these margins a client can land on the
	// better side of a boundary (dawn from 05:01 while the server reads 04:30,
	// the storm bonus at rain 0.71 against the server's 0.65). Snapping to the
	// server's reading whenever the two straddle a boundary would close that,
	// but honest clients lag the server and straddle every dawn and dusk, so
	// their casts there would desync; the margin is the cheaper side.
	protected const int MAX_CLOCK_DRIFT_MINUTES = 60;
	protected const float MAX_RAIN_DRIFT = 0.1;

	int Year;
	int Month;
	int Day;
	int Hour;
	int Minute;
	float Rain;
	float Snow;

	static GebFishingSnapshot CaptureLocal() {
		GebFishingSnapshot snapshot = new GebFishingSnapshot();
		// Midsummer noon, dry, if the world isn't up yet (mission startup).
		snapshot.Year = 2000;
		snapshot.Month = 6;
		snapshot.Day = 15;
		snapshot.Hour = 12;
		if (!g_Game)
			return snapshot;

		if (g_Game.GetWorld())
			g_Game.GetWorld().GetDate(snapshot.Year, snapshot.Month, snapshot.Day, snapshot.Hour, snapshot.Minute);

		Weather weather = g_Game.GetWeather();
		if (weather && weather.GetRain())
			snapshot.Rain = weather.GetRain().GetActual();
		if (weather && weather.GetSnowfall())
			snapshot.Snow = weather.GetSnowfall().GetActual();
		return snapshot;
	}

	void Write(ParamsWriteContext ctx) {
		ctx.Write(Year);
		ctx.Write(Month);
		ctx.Write(Day);
		ctx.Write(Hour);
		ctx.Write(Minute);
		ctx.Write(Rain);
		ctx.Write(Snow);
	}

	bool Read(ParamsReadContext ctx) {
		if (!ctx.Read(Year))
			return false;
		if (!ctx.Read(Month))
			return false;
		if (!ctx.Read(Day))
			return false;
		if (!ctx.Read(Hour))
			return false;
		if (!ctx.Read(Minute))
			return false;
		if (!ctx.Read(Rain))
			return false;
		if (!ctx.Read(Snow))
			return false;
		return true;
	}

	// True when `other` (the server's own reading) agrees within tolerance.
	bool IsCloseTo(GebFishingSnapshot other) {
		if (!other)
			return false;
		// Every field in range first: the comparisons below only look at
		// totals, so e.g. Hour 0 + Minute 720 would otherwise pass as noon.
		if (Month < 1 || Month > 12 || Day < 1 || Day > 31)
			return false;
		if (Hour < 0 || Hour > 23 || Minute < 0 || Minute > 59)
			return false;
		if (!(Rain >= 0.0 && Rain <= 1.0)) // also rejects NaN
			return false;
		if (Math.AbsFloat(Rain - other.Rain) > MAX_RAIN_DRIFT)
			return false;
		if (!(Snow >= 0.0 && Snow <= 1.0))
			return false;
		if (Math.AbsFloat(Snow - other.Snow) > MAX_RAIN_DRIFT)
			return false;

		int dayDiff = DayStamp() - other.DayStamp();
		if (dayDiff < -1 || dayDiff > 1)
			return false;
		int minuteDiff = dayDiff * 1440 + (Hour * 60 + Minute) - (other.Hour * 60 + other.Minute);
		if (Math.AbsInt(minuteDiff) > MAX_CLOCK_DRIFT_MINUTES)
			return false;
		return true;
	}

	// A day number that steps by 1 between consecutive days, except across
	// the end of a month shorter than 31 days (a gap of 2-4). A cast that
	// straddles such a midnight just fails IsCloseTo, and the server then
	// uses its own reading.
	int DayStamp() {
		return (Year * 12 + Month) * 31 + Day;
	}

	string Describe() {
		return Year.ToString() + "-" + Month.ToString() + "-" + Day.ToString() + " " + Hour.ToString() + ":" + Minute.ToString() + " rain=" + Rain.ToString() + " snow=" + Snow.ToString();
	}
}
