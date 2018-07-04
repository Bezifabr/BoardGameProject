#include "StateIntro.h"

void StateIntro::Update()
{
	TestingButton();
}

void StateIntro::Load()
{
	ButtonsTestAndTexturesLoading();

	//	IsChanging(true);
	//	SetNewState(new StateMainMenu);
}

void StateIntro::Unload()
{
}

void StateIntro::ButtonsTestAndTexturesLoading()
{
	if (GAME_TESTS && MAP_LOADING_TEST)
	{
		assert(testingTexture.loadFromFile(TESTING_GRAPHIC_SOURCE));
		InterfaceObject* object = new InterfaceObject;

		assert(object);
		object->GetEventType().SetEventType(sf::Event::MouseButtonPressed);
		object->GetMouseEvent().NeedMousePosition(true);
		object->GetMouseEvent().SetMouseButton(sf::Mouse::Left);
		object->SetTexture(testingTexture);

		assert(object);
		(*GetInterfaceObjects())["Button"] = object;
		assert((*GetInterfaceObjects())["Button"]);
	}
}

void StateIntro::TestingButton()
{
	if (GAME_TESTS && MAP_LOADING_TEST)
		if ((*GetInterfaceObjects())["Button"]->IsActivated())
		{
			IsChanging(true);
			SetNewState("Game");
		}
}
