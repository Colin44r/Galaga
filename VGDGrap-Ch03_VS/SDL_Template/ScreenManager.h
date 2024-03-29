#pragma once
#include "StartScreen.h"

class ScreenManager {
private:
	static ScreenManager* sInstance;

	ScreenManager();
	~ScreenManager();

	InputManager* mInput;

	enum Screens { Start, Play };
	Screens mCurrentScreen;

	StartScreen* mStartScreen;

public:
	static ScreenManager* Instance();
	static void Release();

	void Update();
	void Render();
};