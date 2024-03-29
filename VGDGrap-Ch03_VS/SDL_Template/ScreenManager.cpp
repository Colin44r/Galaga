#include "ScreenManager.h"

ScreenManager* ScreenManager::sInstance = nullptr;

ScreenManager* ScreenManager::Instance() {
	if (sInstance == nullptr) {
		sInstance = new ScreenManager();
	}

	return sInstance;
}

void ScreenManager::Release() {
	delete sInstance;
	sInstance = nullptr;
}

ScreenManager::ScreenManager() {
	mInput = InputManager::Instance();

	mStartScreen = new StartScreen();

	mCurrentScreen = Start;
}

ScreenManager::~ScreenManager() {
	mInput = nullptr;

	delete mStartScreen;
	mStartScreen = nullptr;
}

void ScreenManager::Update() {
	//Call update on any background image/effect that you want to persist between screens here!


	switch (mCurrentScreen)
	{
	case ScreenManager::Start:
		mStartScreen->Update();

		if (mInput->KeyPressed(SDL_SCANCODE_RETURN)) {
			mCurrentScreen = Play;
			std::cout << "Changing to PlayScreen";
		}

		break;
	case ScreenManager::Play:
		//This is where we would update our PlayScreen
		if (mInput->KeyPressed(SDL_SCANCODE_ESCAPE)) {
			mCurrentScreen = Start;
			std::cout << "Changing to StartScreen";
		}
		break;
	default:
		break;
	}
}

void ScreenManager::Render() {
	//Call Render on any background image/effect that you want to persist between screens here!


	switch (mCurrentScreen)
	{
	case ScreenManager::Start:
		mStartScreen->Render();

		break;
	case ScreenManager::Play:
		//This is where we would Render our PlayScreen

		break;
	default:
		break;
	}
}