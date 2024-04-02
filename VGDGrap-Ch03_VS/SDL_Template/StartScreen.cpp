#include "StartScreen.h"

StartScreen::StartScreen() {
	mTimer = Timer::Instance();
	mInputManager = InputManager::Instance();

	mTopBar = new GameEntity(Graphics::SCREEN_WIDTH * 0.5f, 80.0f);
	mPlayerOne = new Texture("1UP", "emulogic.ttf", 32, { 200, 0, 0 });
	mPlayerTwo = new Texture("2UP", "emulogic.ttf", 32, { 200, 0, 0 });
	
	
	mBottomBar = new GameEntity(Graphics::SCREEN_WIDTH * 0.5f,Graphics::SCREEN_HEIGHT * 0.7f);
	//mNamco = new Texture("namcot", "namco__.ttf", 36, { 200, 0, 0 });
	mTM = new Texture("TM AND  ©  1989", "emulogic.ttf", 32, { 230, 230, 230 });
	mLTD = new Texture("KONAMI INDUSTRY CO. ,LTD.", "emulogic.ttf", 32, { 230, 230, 230 });
	mRights = new Texture("LICENSED BY", "emulogic.ttf", 32, { 230, 230, 230 });
	mNintendo = new Texture("NINTENDO OF AMERICA INC.", "emulogic.ttf", 32, { 230, 230, 230 });
	mUltra = new Texture("ULTRA GAMES IS A REGISTERED", "emulogic.ttf", 32, { 230, 230, 230 });
	mTradeMark1 = new Texture("TRADEMARK OF ULTRA SOFTWARE", "emulogic.ttf", 32, { 230, 230, 230 });
	mTradeMark2 = new Texture("CORPORATION.", "emulogic.ttf", 32, { 230, 230, 230 });

	mLogo = new Texture("QBert General Sprites.png", 128, 31, 95, 16);
	

	mBottomBar->Parent(this);
	//mNamco->Parent(mBottomBar);
	mLTD->Parent(mBottomBar);
	mRights->Parent(mBottomBar);
	mTM -> Parent(mBottomBar);
	mNintendo->Parent(mBottomBar);
	mUltra->Parent(mBottomBar);
	mTradeMark1->Parent(mBottomBar);
	mTradeMark2->Parent(mBottomBar);

	mTopBar->Parent(this);
	mPlayerOne->Parent(mTopBar);
	mPlayerTwo->Parent(mTopBar);
	

	mPlayerOne->Position(-Graphics::SCREEN_WIDTH * 0.35f, 0.0f);
	mPlayerTwo->Position(Graphics::SCREEN_WIDTH * 0.2f, 0.0f);
	

	mPlayerModes = new GameEntity(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.55f);
	mOnePlayerMode = new Texture("1 Player ", "emulogic.ttf", 32, { 230, 230, 230 });
	mTwoPlayerMode = new Texture("2 Player ", "emulogic.ttf", 32, { 230, 230, 230 });
	mQBertCursor = new Texture(QBertSpriteSheet, 0,0,16,16);

	mPlayerModes->Parent(this);
	mOnePlayerMode->Parent(mPlayerModes);
	mTwoPlayerMode->Parent(mPlayerModes);
	mQBertCursor->Parent(mPlayerModes);

	mOnePlayerMode->Position(0.0f, -35.0f);
	mTwoPlayerMode->Position(0.0f, 35.0f);
	mQBertCursor->Position(-195.0, -35.0f);
	//mQBertCursor->Position(-195.0, -35.0f);

	//mNamco->Position(Vec2_Zero);
	mTM->Position(0.0f, -30.0f);
	mLTD->Position(0.0f, 10.0f);
	mRights->Position(0.0f, 45.0f);
	mNintendo->Position(0.0f, 85.0f);
	mUltra->Position(0.0f, 150.0f);
	mTradeMark1->Position(0.0f, 190.0f);
	mTradeMark2->Position(-230.0f, 230.0f);
	mLogo->Position(550.0f, 150.0);

	mLogo->Scale(Vector2 (6.5f, 6.5f));
	mQBertCursor->Scale(Vector2(3.5f, 3.5f));
}

StartScreen::~StartScreen() {
	delete mTopBar;
	mTopBar = nullptr;
	delete mPlayerOne;
	mPlayerOne = nullptr;
	delete mPlayerTwo;
	mPlayerTwo = nullptr;
	delete mPlayerModes;
	mPlayerModes = nullptr;
	delete mOnePlayerMode;
	mOnePlayerMode = nullptr;
	delete mTwoPlayerMode;
	mTwoPlayerMode = nullptr;
	delete mQBertCursor;
	mQBertCursor = nullptr;
	//delete mNamco;
	//mNamco = nullptr;
	delete mLTD;
	mLTD = nullptr;
	delete mRights;
	mRights = nullptr;

	delete mTM;
	mTM = nullptr;
	delete mNintendo;
	mNintendo = nullptr;
	delete mUltra;
	mUltra = nullptr;
	delete mTradeMark1;
	mTradeMark1 = nullptr;
	delete mTradeMark2;
	mTradeMark2 = nullptr;

	delete mLogo;
	mLogo = nullptr;

	mTimer = nullptr;
	mInputManager = nullptr;
}

void StartScreen::Update() {

}

void StartScreen::Render() {
	mPlayerOne->Render();
	mPlayerTwo->Render();
	mOnePlayerMode->Render();
	mTwoPlayerMode->Render();
	mQBertCursor->Render();
	mRights->Render();
	mLTD->Render();
	mLogo->Render();
	//mNamco->Render();

	mTM->Render();
	mNintendo->Render();
	mUltra->Render();
	mTradeMark1->Render();
	mTradeMark2->Render();
}