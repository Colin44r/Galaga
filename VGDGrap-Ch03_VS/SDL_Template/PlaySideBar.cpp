#include "PlaySideBar.h"

PlaySideBar::PlaySideBar() {
	mTimer = Timer::Instance();
	mAudio = AudioManager::Instance();

	mBackground = new Texture("Black.png");
	mBackground->Parent(this);
	mBackground->Scale(Vector2(3.0f, 10.0f));
	mBackground->Position(45.0f, 380.0f);

	mHighLabel = new Texture("HIGH", "emulogic.ttf", 32, { 150, 0, 0 });
	mHighLabel->Parent(this);
	mHighLabel->Position(-25.0f, 0.0f);

	mScoreLabel = new Texture("SCORE", "emulogic.ttf", 32, { 150, 0, 0 });
	mScoreLabel->Parent(this);
	mScoreLabel->Position(25.0f, 32.0f);

	mHighScoreBoard = new Scoreboard({ 0, 0, 0 });
	mHighScoreBoard->Parent(this);
	mHighScoreBoard->Position(90.0f, 64.0f);

	mPlayerOneLabel = new Texture("1UP", "emulogic.ttf", 32, { 150, 0, 0 });
	mPlayerOneLabel->Parent(this);
	mPlayerOneLabel->Position(-45.0f, 160.0f);

	mBlinkTimer = 0;
	mBlinkInterval = 0.5;
	mPlayerOneLabelVisible = true;

	mPlayerOneScore = new Scoreboard();
	mPlayerOneScore->Parent(this);
	mPlayerOneScore->Position(90.0f, 192.0f);

	mShips = new GameEntity();
	mShips->Parent(this);
	mShips->Position(-40.0f, 420.0f);

	for (int i = 0; i < MAX_SHIP_TEXTURES; ++i) {
		mShipTextures[i] = new Texture("PlayerShips.png", 0, 0, 60, 64);
		mShipTextures[i]->Parent(mShips);
		mShipTextures[i]->Position(62.0f * (i % 3), 70.0f * (i / 3));
	}

	mTotalShipsLabel = new Scoreboard();
	mTotalShipsLabel->Parent(mShips);
	mTotalShipsLabel->Position(140.0f, 80.0f);
	mTotalShipsLabel->Score(3);
}

PlaySideBar::~PlaySideBar() {
	mTimer = nullptr;
	mAudio = nullptr;

	delete mBackground;
	mBackground = nullptr;

	delete mHighLabel;
	mHighLabel = nullptr;
	delete mScoreLabel;
	mScoreLabel = nullptr;
	delete mHighScoreBoard;
	mHighScoreBoard = nullptr;
	delete mPlayerOneLabel;
	mPlayerOneLabel = nullptr;
	delete mPlayerOneScore;
	mPlayerOneScore = nullptr;

	delete mShips;
	mShips = nullptr;

	for (int i = 0; i < MAX_SHIP_TEXTURES; ++i) {
		delete mShipTextures[i];
		mShipTextures[i] = nullptr;
	}

	delete mTotalShipsLabel;
	mTotalShipsLabel = nullptr;
}

void PlaySideBar::SetHighScore(int score) {
	mHighScoreBoard->Score(score);
}

void PlaySideBar::SetPlayerScore(int score) {
	mPlayerOneScore->Score(score);
}

void PlaySideBar::SetShip(int ships) {
	mTotalShips = ships;

	if (ships > MAX_SHIP_TEXTURES) {
		mTotalShipsLabel->Score(ships);
	}
}

void PlaySideBar::Update() {
	mBlinkTimer += mTimer->DeltaTime();
	if (mBlinkTimer >= mBlinkInterval) {
		mPlayerOneLabelVisible = !mPlayerOneLabelVisible;
		mBlinkTimer = 0.0f;
	}
}

void PlaySideBar::Render() {
	mBackground->Render();
	mHighLabel->Render();
	mScoreLabel->Render();
	mHighScoreBoard->Render();

	mPlayerOneScore->Render();

	if (mPlayerOneLabelVisible) {
		mPlayerOneLabel->Render();
	}

	for (int i = 0; i < MAX_SHIP_TEXTURES; ++i) {
		mShipTextures[i]->Render();
	}

	if (mTotalShips > MAX_SHIP_TEXTURES) {
		mTotalShipsLabel->Render();
	}
}void PlaySideBar::Update() {
	mBlinkTimer += mTimer->DeltaTime();
	if (mBlinkTimer >= mBlinkInterval) {
		mOnePlayerModeVisible = !mOnePlayerModeVisible;
		mBlinkTimer = 0.0f;
		mBlinkTimer += mTimer->DeltaTime();

		if (mBlinkTimer >= mBlinkInterval) {
			mTwoPlayerModeVisible = !mTwoPlayerModeVisible;
			mBlinkTimer = 0.0f;
			mBlinkTimer += mTimer->DeltaTime();

		}


	}

	void PlaySideBar::Render() {
		mTwoPlayerMode->Render();

		if (mTwoPlayerModeVisible) {
			mTwoPlayerMode->Render();
		}
	}