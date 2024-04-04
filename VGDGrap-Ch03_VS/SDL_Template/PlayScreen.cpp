#include "PlayScreen.h"

PlayScreen::PlayScreen() {
	mTimer = Timer::Instance();
	mAudio = AudioManager::Instance();

	mSideBar = new PlaySideBar();
	mSideBar->Parent(this);
	mSideBar->Position(Graphics::SCREEN_WIDTH * 0.87, Graphics::SCREEN_HEIGHT * 0.05);


	mControlConfigSheet = new Texture("QBert General Sprites.png", 0, 0, 225, 143);

	mControlConfigSheet->Position(550.0f, 250.0);


	mTopPart->Parent(this);
	mControlConfigSheet->Parent(mTopPart);




}

PlayScreen::~PlayScreen() {
	mTimer = nullptr;
	mAudio = nullptr;

	delete mControlConfigSheet;
	mControlConfigSheet = nullptr;
	delete mSideBar;
	mSideBar = nullptr;
}

void PlayScreen::Update() {
	mSideBar->Update();

}

void PlayScreen::Render() {
	mSideBar->Render();
	mControlConfigSheet->Render();

}

