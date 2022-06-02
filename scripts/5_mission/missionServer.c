modded class MissionServer
{
	static const string FISH_CFG_PATH = "/gebsfish/Fish_Cfg.json";

	ref array<int> MACKEREL_CHANCE;

	
	override void OnInit()
	{		
		super.OnInit();
		readFishCfg();
	}	

	void readFishCfg()
	{
		FileHandle file_index = OpenFile(FISH_CFG_PATH, FileMode.READ);
		
		if ( file_index == 0 )
		{
			return;
		}
		string line_content = "";
		while (!line_content && !line_content.Contains("<FileEnd>"))
		{
			bool validEntry = false;
			if (line_content.Contains("MACKEREL_CHANCE"))
			{
				line_content.Replace("MACKEREL_CHANCE = ", "");
				MACKEREL_CHANCE = line_content.ToFloat();
				validEntry = true;
			}
			if (validEntry)
		}
		CloseFile(file_index);
	}
}