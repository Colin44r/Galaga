#include "StartScreen.h"

StartScreen::StartScreen() {
	mTimer = Timer::Instance();
	mInputManager = InputManager::Instance();

	mTopBar = new GameEntity(Graphics::SCREEN_WIDTH * 0.5f, 80.0f);

	
	
	mBottomBar = new GameEntity(Graphics::SCREEN_WIDTH * 0.5f,Graphics::SCREEN_HEIGHT * 0.7f);
	mTM = new Texture("TM AND  ©  1989", "emulogic.ttf", 32, { 230, 230, 230 });
	mLTD = new Texture("KONAMI INDUSTRY CO. ,LTD.", "emulogic.ttf", 32, { 230, 230, 230 });
	mRights = new Texture("LICENSED BY", "emulogic.ttf", 32, { 230, 230, 230 });
	mNintendo = new Texture("NINTENDO OF AMERICA INC.", "emulogic.ttf", 32, { 230, 230, 230 });
	mUltra = new Texture("ULTRA GAMES IS A REGISTERED", "emulogic.ttf", 32, { 230, 230, 230 });
	mTradeMark1 = new Texture("TRADEMARK OF ULTRA SOFTWARE", "emulogic.ttf", 32, { 230, 230, 230 });
	mTradeMark2 = new Texture("CORPORATION.", "emulogic.ttf", 32, { 230, 230, 230 });
	mLogo = new Texture("QBert General Sprites.png", 128, 31, 95, 16);
	mUltraGames = new Texture("UltraGames.png", 5,1,467,112);
	mLogoR = new Texture("LogoR.png", 0, 0, 70, 62);
	


	mBottomBar->Parent(this);
	mLTD->Parent(mBottomBar);
	mRights->Parent(mBottomBar);
	mTM -> Parent(mBottomBar);
	mNintendo->Parent(mBottomBar);
	mUltra->Parent(mBottomBar);
	mTradeMark1->Parent(mBottomBar);
	mTradeMark2->Parent(mBottomBar);
	mUltraGames->Parent(mBottomBar);



	mTopBar->Parent(this);
	
	


	

	mPlayerModes = new GameEntity(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.55f);
	mOnePlayerMode = new Texture("Player ", "emulogic.ttf", 32, { 230, 230, 230 });
	mTwoPlayerMode = new Texture("Player ", "emulogic.ttf", 32, { 230, 230, 230 });
	mLetterOne = new Texture("1 ", "emulogic.ttf", 32, { 255, 0, 0 });
	mLetterTwo = new Texture("2 ", "emulogic.ttf", 32, { 255, 0, 0 });
	mPlayerSelect = new Texture("Player Select ", "emulogic.ttf", 32, { 230, 230, 230 });
	mQBertCursor = new Texture(QBertSpriteSheet, 0,0,16,16);

	mPlayerModes->Parent(this);
	mOnePlayerMode->Parent(mPlayerModes);
	mTwoPlayerMode->Parent(mPlayerModes);
	mLetterOne->Parent(mPlayerModes);
	mLetterTwo->Parent(mPlayerModes);
	mQBertCursor->Parent(mPlayerModes);
	mPlayerSelect->Parent(mTopBar);

	mPlayerSelect->Position(75.0f, 300.0f);
	mOnePlayerMode->Position(50.0f, -55.0f);
	mTwoPlayerMode->Position(50.0f, 35.0f);
	mLetterOne->Position(-85.0f, -55.0f);
	mLetterTwo->Position(-85.0f, 35.0f);
	mQBertCursor->Position(-190.0, -45.0f);
	mQBertCursorStartPos = mQBertCursor->Position(Local);
	mQBertCursorOffset = Vector2(0.0f, 88.0f);
	mSelectedMode = 0;

	
	mTM->Position(0.0f, -30.0f);
	mLTD->Position(0.0f, 10.0f);
	mRights->Position(0.0f, 45.0f);
	mNintendo->Position(0.0f, 85.0f);
	mUltra->Position(0.0f, 150.0f);
	mTradeMark1->Position(0.0f, 190.0f);
	mTradeMark2->Position(-230.0f, 230.0f);
	mLogo->Position(550.0f, 250.0);
	mUltraGames->Position(40.0f,-550.0);
	mLogoR->Position(875.0f, 175.0);

	mLogo->Scale(Vector2 (6.5f, 9.5f));
	mQBertCursor->Scale(Vector2(3.5f, 3.5f));
	mLogoR->Scale(Vector2(0.5f, 0.5f));
}

StartScreen::~StartScreen() {
	delete mTopBar;
	mTopBar = nullptr;
	delete mPlayerModes;
	mPlayerModes = nullptr;
	delete mOnePlayerMode;
	mOnePlayerMode = nullptr;
	delete mTwoPlayerMode;
	mTwoPlayerMode = nullptr;
	delete mQBertCursor;
	mQBertCursor = nullptr;
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
	delete mPlayerSelect;
	mPlayerSelect = nullptr;
	delete mLetterOne;
	mLetterOne = nullptr;
	delete mLetterTwo;
	mLetterTwo = nullptr;
	delete mUltraGames;
	mUltraGames = nullptr;
	delete mLogoR;
	mLogoR = nullptr;


	mTimer = nullptr;
	mInputManager = nullptr;
}

void StartScreen::Update() {
	if (mStartTimer == true) {
		mBlinkTimer += mTimer->DeltaTime();
		//std::cout << NumOfBlink;
		if (mBlinkTimer >= mBlinkInterval) {
			mOnePlayerModeVisible = !mOnePlayerModeVisible;
			NumOfBlink += 1;
			if (NumOfBlink >= 7) {
				mBlinkingDone = true;
			}
			mBlinkTimer = 0.0f;
			mBlinkTimer += mTimer->DeltaTime();

			if (mBlinkTimer >= mBlinkInterval) {
				mTwoPlayerModeVisible = !mTwoPlayerModeVisible;
				mBlinkTimer = 0.0f;
				mBlinkTimer += mTimer->DeltaTime();

			}
		}
	}
	if (mInputManager->KeyPressed(SDL_SCANCODE_RETURN) && NumOfBlink == 0) {
		//NumOfBlink = 1;
		mStartTimer = true;
		//if (NumOfBlink > 0 && NumOfBlink <= 5) {
		
		//}
	


	}
	

	if (mInputManager->KeyPressed(SDL_SCANCODE_DOWN)) {
		ChangeSelectedMode(1);
	}
	else if (mInputManager->KeyPressed(SDL_SCANCODE_UP)) {
		ChangeSelectedMode(-1);
	}
}

bool StartScreen::GetBlinkingDone() {
	return mBlinkingDone;
}

	
	
void StartScreen::Render() {
	

	if (mTwoPlayerModeVisible) {
		mTwoPlayerMode->Render();
	}


	if (mOnePlayerModeVisible) {
		mOnePlayerMode->Render();
	}
	
	mQBertCursor->Render();
	mRights->Render();
	mLTD->Render();
	mLogo->Render();
	mLetterOne->Render();
	mLetterTwo->Render();
	mUltraGames->Render();
	mLogoR->Render();

	mPlayerSelect->Render();
	mTM->Render();
	mNintendo->Render();
	mUltra->Render();
	mTradeMark1->Render();
	mTradeMark2->Render();
}
void StartScreen::ChangeSelectedMode(int change) {
	mSelectedMode += change;

	if (mSelectedMode < 0) {
		mSelectedMode = 1;
	}
	else if (mSelectedMode > 1) {
		mSelectedMode = 0;
	}

	mQBertCursor->Position(mQBertCursorStartPos + mQBertCursorOffset * (float)mSelectedMode);
}

