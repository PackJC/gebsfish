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

        if (moved > 0)
            GebsfishLogger.Info("Archived " + moved + " old-layout file(s) into gebs_oldfiles. The emptied old folders (Fish/, extras/) are safe to delete manually -- scripts cannot remove directories.", "Migrate");
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
