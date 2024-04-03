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
	

	GameEntity* mPlayerModes;
	Texture* mOnePlayerMode;
	Texture* mTwoPlayerMode;
	Texture* mQBertCursor;
	Vector2 mQBertCursorStartPos;
	Vector2 mQBertCursorOffset;
	int mSelectedMode;
	Texture* mRights;
	Texture* mLTD;
	Texture* mPlayerSelect;
	Texture* mTM;
	Texture* mNintendo;
	Texture* mUltra;
	Texture* mTradeMark1;
	Texture* mTradeMark2;
	Texture* mLogo;
	Texture* mLetterOne;
	Texture* mLetterTwo;
	Texture* mUltraGames;
	std::string QBertSpriteSheet = "QBert General Sprites.png";

public:
	StartScreen();
	~StartScreen();
	void ChangeSelectedMode(int change);
	void Update() override;
	void Render() override;
};