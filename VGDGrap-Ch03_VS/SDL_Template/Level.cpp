#include "Level.h"

void Level::StartStage() {
	mStageStarted = true;
}

Level::Level(int stage, PlaySideBar* sideBar, Player* player) {
	mTimer = Timer::Instance();
	mSideBar = sideBar;
	mSideBar->SetLevel(stage);
	mPlayer = player;

	mStage = stage;
	mStageStarted = false;

	mLabelTimer = 0.0;

	mStageLabel = new Texture("STAGE", "emulogic.ttf", 32, { 75, 75, 200 });
	mStageLabel->Parent(this);
	mStageLabel->Position(Graphics::SCREEN_WIDTH * 0.35f, Graphics::SCREEN_HEIGHT * 0.5f);

	mStageNumber = new Scoreboard({ 75, 75, 200 });
	mStageNumber->Score(mStage);
	mStageNumber->Parent(this);
	mStageNumber->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.5f);

	mStageLabelOnScreen = 0.0f;
	mStageLabelOffScreen = 1.5f;

	mReadyLabel = new Texture("READY", "emulogic.tff", 32, { 150, 0, 0 });
	mReadyLabel->Parent(this);
	mReadyLabel->Position(Graphics::SCREEN_WIDTH * 0.4f, Graphics::SCREEN_HEIGHT * 0.5f);

	mReadyLabelOnScreen = mStageLabelOffScreen;
	mReadyLabelOffScreen = mReadyLabelOnScreen + 3.0f;

	mPlayerHit = false;
	mRespawnDelay = 3.0f;
	mRespawnTimer = 0.0f;
	mRespawnLabelOnScreen = 2.0f;

	mGameOverLabel = new Texture("GAME OVER", "emulogix.ttf", 32, { 150, 0, 0 });
	mGameOverLabel->Parent(this);
	mGameOverLabel->Position(Graphics::SCREEN_WIDTH * 0.4f, Graphics::SCREEN_HEIGHT * 0.5f);

	mGameOverDelay = 6.0f;
	mGameOverTimer = 0.0;
	mGameOverLabelOnScreen = 1.0f;

	mCurrentState = Running;
}

Level::~Level() {
	mTimer = nullptr;
	mSideBar = nullptr;
	mPlayer = nullptr;

	delete mStageLabel;
	mStageLabel = nullptr;
	delete mStageNumber;
	mStageNumber = nullptr;
	delete mReadyLabel;
	mReadyLabel = nullptr;
	delete mGameOverLabel;
	mGameOverLabel = nullptr;
}

void Level::Update() {
	if (!mStageStarted) {
		HandleStartLabels();
	}
	else {
		HandleCollisions();

		if (mPlayerHit) {
			HandlePlayerDeath();
		}
		else {
			if (InputManager::Instance()->KeyPressed(SDL_SCANCODE_N)) {
				mCurrentState = Finished;
			}
		}
	}
}

void Level::Render() {
	if (!mStageStarted) {
		if (mLabelTimer > mStageLabelOnScreen && mLabelTimer < mStageLabelOffScreen) {
			mStageLabel->Render();
			mStageNumber->Render();
		}
		else if (mLabelTimer > mReadyLabelOnScreen && mLabelTimer < mReadyLabelOffScreen) {
			mReadyLabel->Render();
		}
	}
}

Level::LevelStates Level::State() {
	return mCurrentState;
}

void Level::HandleStartLabels() {
	mLabelTimer += mTimer->DeltaTime();
	if (mLabelTimer >= mStageLabelOffScreen) {
		if (mStage > 1) {
			StartStage();
		}
		else {
			if (mLabelTimer >= mReadyLabelOffScreen) {
				StartStage();
			}
		}
		mPlayer->Active(true);
		mPlayer->Visible(true);
	}
}

void Level::HandleCollisions() {
	if (!mPlayerHit) {
		if (InputManager::Instance()->KeyPressed(SDL_SCANCODE_X)) {
			mPlayer->WasHit();
			mSideBar->SetShip(mPlayer->Lives());

			mPlayerHit = true;
			mRespawnTimer = 0.0f;
			mPlayer->Active(false);
		}
	}
}

void Level::HandlePlayerDeath() {
	if (!mPlayer->IsAnimating()) {
		if (mPlayer->Lives() > 0) {
			if (mRespawnTimer == 0.0f) {
				mPlayer->Visible(false);
			}

			mRespawnTimer += mTimer->DeltaTime();
			if (mRespawnTimer >= mRespawnDelay) {
				mPlayer->Active(true);
				mPlayer->Visible(true);
				mPlayerHit = false;
			}
		}
		else {
			if (mGameOverTimer == 0.0f) {
				mPlayer->Visible(false);
			}

			mGameOverTimer += mTimer->DeltaTime();
			if (mGameOverTimer >= mGameOverDelay) {
				mCurrentState = GameOver;
			}
		}
	}
}