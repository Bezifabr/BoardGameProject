#include "GameStatesMachine.h"
#include "StateGame.h"
#include "StateIntro.h"
#include "StateMainMenu.h"
#include "StateOutro.h"
#include "StateCinematic.h"
#include "StateOptions.h"
#include "StateLobby.h"


GameStatesMachine::GameStatesMachine(ViewWindow * viewWindow)
{
	ConnectWithViewWindow(viewWindow);
}

GameStatesMachine::~GameStatesMachine()
{
	assert(gameDataContainer);
	gameDataContainer = nullptr;

	assert(viewWindow);
	viewWindow = nullptr;

	assert(currentState);
	delete currentState;
	currentState = NULL;
}

void GameStatesMachine::ConnectWithViewWindow(ViewWindow * viewWindow)
{
	assert(viewWindow);
	this->viewWindow = viewWindow;
}

void GameStatesMachine::InitializeAndLoadData(GameDataContainer * container)
{
	SetGameContainer(container);
	LoadStateByString("MainMenu");
	currentState->InitializeGameCamera();

	TestCharactersAndTexturesLoading();
	TestGraphicObjectsAndTexturesLoading();
	TestInterfaceObjectsAndTexturesLoading();
	TestCustomTextObjectsAndFontsAndTexturesLoading();
}

void GameStatesMachine::CheckStatesUpdates()
{
	if (currentState)
	{
		viewWindow->SetView(currentState->GetCurrentView());
		currentState->UpdateState();

		if (currentState->IsFinished())
			ExitGame();
		else if (currentState->IsChangingState())
			ChangeState(currentState->NewState());
	}
}

bool GameStatesMachine::IsFinished()
{
	return isFinished;
}

void GameStatesMachine::LoadStateByString(const std::string & stateName)
{
	if (stateName == "Game")
		return CreateNewState(new StateGame);
	if (stateName == "MainMenu")
		return CreateNewState(new StateMainMenu);
	if (stateName == "Options")
		return CreateNewState(new StateOptions);
	if (stateName == "Lobby")
		return CreateNewState(new StateLobby);
	if (stateName == "Intro")
		return CreateNewState(new StateIntro);
	if (stateName == "Outro")
		return CreateNewState(new StateOutro);
	if (stateName == "Cinematic")
		return CreateNewState(new StateCinematic);
}

void GameStatesMachine::CreateNewState(State * newState)
{
	currentState = newState;
	assert(currentState);
	currentState->LoadData(gameDataContainer);

}

void GameStatesMachine::ChangeState(const std::string & newStateName)
{
	if (currentState) {
		currentState->UnloadData();
		delete currentState;
	}
	assert(!newStateName.empty());
	LoadStateByString(newStateName);
	assert(currentState);
}

void GameStatesMachine::ExitGame()
{
	assert(currentState);
	currentState->UnloadData();
	isFinished = true;
}

void GameStatesMachine::SetGameContainer(GameDataContainer * container)
{
	assert(container);
	gameDataContainer = container;
	assert(gameDataContainer);
}

void GameStatesMachine::TestCharactersAndTexturesLoading()
{
	if (GAME_TESTS && CHARACTER_AND_TEXTURES_LOADING_TEST)
	{
		assert(sfmlTestingTexture.loadFromFile(TESTING_GRAPHIC_SOURCE));
		Character* sfmlTestingCharacter = new Character;

		sfmlTestingCharacter->SetLocation(0);
		sfmlTestingCharacter->setTexture(sfmlTestingTexture);

		gameDataContainer->AddCharacter(sfmlTestingCharacter);
	}
}

void GameStatesMachine::TestGraphicObjectsAndTexturesLoading()
{
	if (GAME_TESTS && GRAPHIC_OBJECT_AND_TEXTURES_LOADING_TEST)
	{
		assert(sfmlTestingTexture.loadFromFile(TESTING_GRAPHIC_SOURCE));
		GraphicObject* sfmlTestingGraphicObject = new GraphicObject;

		sfmlTestingGraphicObject->SetLocation(0);
		sfmlTestingGraphicObject->SetTexture(sfmlTestingTexture);

		gameDataContainer->AddGraphicObject(sfmlTestingGraphicObject);
	}
}

void GameStatesMachine::TestInterfaceObjectsAndTexturesLoading()
{
	if (GAME_TESTS && INTERFACE_OBJECT_AND_TEXTURES_LOADING_TEST)
	{
		assert(sfmlTestingTexture.loadFromFile(TESTING_GRAPHIC_SOURCE));
		InterfaceObject* sfmlTestingInterfaceObject = new InterfaceObject;

		sfmlTestingInterfaceObject->SetLocation(0);
		sfmlTestingInterfaceObject->SetTexture(sfmlTestingTexture);

		if (INTERFACE_EVENT_TEST)
			sfmlTestingInterfaceObject->GetEventType().SetEventType(sf::Event::MouseButtonPressed);

		if (INTERFACE_MOUSE_POSITION_TEST)
			sfmlTestingInterfaceObject->GetMouseEvent().NeedMousePosition(true);

		if (INTERFACE_MOUSE_TEST)
			sfmlTestingInterfaceObject->GetMouseEvent().SetMouseButton(sf::Mouse::Right);

		if (INTERFACE_KEYBOARD_TEST)
			sfmlTestingInterfaceObject->GetKeyboardEvent().SetKeyboardKey(sf::Keyboard::K);

		if (INTERFACE_KEYBOARD_EVENT_TYPE)
			sfmlTestingInterfaceObject->GetEventType().SetEventType(sf::Event::KeyPressed);

		gameDataContainer->AddInterfaceObject("Test", sfmlTestingInterfaceObject);

		//Mouse Test fails when EventType is turned off
		//Test fails when Mouse_Test and Event_Test are turned on
		//Do not see holding keys
	}
}

void GameStatesMachine::TestCustomTextObjectsAndFontsAndTexturesLoading()
{
	if (GAME_TESTS && CUSTOM_TEXTS_AND_TEXTURES_LOADING_TEST)
	{
		assert(sfmlTestingFont.loadFromFile(DEFAULT_FONT_SOURCE));
		CustomText* testingCustomText = new CustomText;
		testingCustomText->SetColor(sf::Color::White);
		testingCustomText->SetFont(sfmlTestingFont);
		testingCustomText->SetString("This is test");
		testingCustomText->SetPosition(sf::Vector2f(150, 150));
		testingCustomText->SetSize(45);
		testingCustomText->SetLayer(1);
		testingCustomText->SetLocation(0);

		assert(testingCustomText);
		gameDataContainer->AddCustomText("Testing", testingCustomText);
	}
}