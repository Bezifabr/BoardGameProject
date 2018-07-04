#include "Language.h"

Language & Language::Get()
{
	static Language instance;
	return instance;
}

void Language::SetLanguages(const std::string& language)
{
		if (language == "English")
		{
			Get()["Menu_Title"] = "The board game project";
			Get()["Menu_Play"] = "Play";
			Get()["Menu_Options"] = "Settings";
			Get()["Menu_Quit"] = "Quit";
			Get()["Options_Title"] = "Settings";
			Get()["Options_Graphics"] = "Graphics";
			Get()["Options_Controls"] = "Controls";
			Get()["Options_Back"] = "Back";
			Get()["Lobby_Title"] = "Select a slot to save game:";
			Get()["Lobby_Back"] = "Back";
		}
		else if (language == "Polish")
		{
			Get()["Menu_Title"] = "Stworki";
			Get()["Menu_Play"] = "Graj";
			Get()["Menu_Options"] = "Opcje";
			Get()["Menu_Quit"] = "WyjdŸ";
			Get()["Options_Title"] = "Ustawienia";
			Get()["Options_Graphics"] = "Grafika";
			Get()["Options_Controls"] = "Sterowanie";
			Get()["Options_Back"] = "Wróæ";
			Get()["Lobby_Title"] = "Wybierz miejsce na twoje zapisy:";
			Get()["Lobby_Back"] = "Wróæ";
		}
}
