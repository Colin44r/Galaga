#pragma once
#include "AnimatedTexture.h"
#include "InputManager.h"

using namespace SDLFramework;

class StartScreen : public GameEntity {
private:
	Timer* mTimer;
	InputManager* mInputManager;

	GameEntity* mTopBar;
	GameEntity* mBottomBar;
	Texture* mPlayerOne;
	Texture* mPlayerTwo;
	

	GameEntity* mPlayerModes;
	Texture* mOnePlayerMode;
	Texture* mTwoPlayerMode;
	Texture* mCursor;
	Texture* mRights;
	Texture* mLTD;
	//Texture* mNamco;
	Texture* mTM;
	Texture* mNintendo;
	Texture* mUltra;
	Texture* mTradeMark1;
	Texture* mTradeMark2;

	Texture* mLogo;

public:
	StartScreen();
	~StartScreen();

	void Update() override;
	void Render() override;
};