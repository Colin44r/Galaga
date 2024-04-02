#include "PlayScreen.h"

PlayScreen::PlayScreen() {
	mTimer = Timer::Instance();
	mAudio = AudioManager::Instance();

	mSideBar = new PlaySideBar();
	mSideBar->Parent(this);
	mSideBar->Position(Graphics::SCREEN_WIDTH * 0.87, Graphics::SCREEN_HEIGHT * 0.05);
}

PlayScreen::~PlayScreen() {
	mTimer = nullptr;
	mAudio = nullptr;

	delete mSideBar;
	mSideBar = nullptr;
}

void PlayScreen::Update() {
	mSideBar->Update();
}

void PlayScreen::Render() {
	mSideBar->Render();
}

void PlayScreen::StartNewGame() {
	mSideBar->SetHighScore(30000);
	mSideBar->SetShip(2);
	StartNextLevel();
}

void PlayScreen::StartNextLevel() {
	mSideBar->SetLevel(30);
}