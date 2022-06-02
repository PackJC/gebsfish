class FileReadHelper
{
	static string SearchForNextTermInFile(FileHandle file_index, string searchTerm, string abortTerm)
	{
		int char_count = 0;
		while ( char_count != -1 )
		{			
			string line_content = "";
			char_count = FGets( file_index,  line_content );
			
			line_content = TrimComment(line_content);

			if (line_content.Contains(searchTerm) || (line_content.Contains(abortTerm) && abortTerm != ""))
				return line_content;
		}
		
		return string.Empty;
	}

	static string SearchForNextTermsInFile(FileHandle file_index, array<string> searchTerms, string abortTerm)
	{
		int char_count = 0;
		while ( char_count != -1 )
		{			
			string line_content = "";
			char_count = FGets( file_index,  line_content );
			
			line_content = TrimComment(line_content);

			if (line_content.Contains(abortTerm) && abortTerm != "")
					return line_content;

			for (int i = 0; i < searchTerms.Count(); i++)
			{
				if (line_content.Contains(searchTerms.Get(i)))
					return line_content;
			}
		}
		
		return string.Empty;
	}
	
	static string TrimComment(string line)
	{
		int to_substring_end = line.Length();
		
		for (int i = 0; i < to_substring_end; i++)
		{
			string sign = line.Get(i);
			if ( sign == "/" && i + 1 < to_substring_end)
			{
				if (line.Get(i + 1) == "/")
				{
					to_substring_end = i;
					break;
				}
			}
		}
		
		string lineOut = "";

		if (to_substring_end != 0)
			lineOut = line.Substring(0, to_substring_end);
		
		return TrimSpaces(lineOut);
	}
	
	static string TrimSpaces(string line)
	{
		line.Replace("	", ""); // Replace Tabs("\t" or "	") with nothing.
		
		bool hasSpaces = true;		
		while(hasSpaces)
		{
			line = line.Trim();
			
			if (line.Length() > 0)
				hasSpaces = line.Get(0) == " " || line.Get(line.Length() - 1) == " ";
			else
				hasSpaces = false;
		}
		
		return line;
	}
}