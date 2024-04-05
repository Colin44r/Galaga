#include "PlayScreen.h"

PlayScreen::PlayScreen() {
	mTimer = Timer::Instance();
	//mAudio = AudioManager::Instance();

	//mSideBar = new PlaySideBar();
	//mSideBar->Parent(this);
	//mSideBar->Position(Graphics::SCREEN_WIDTH * 0.87, Graphics::SCREEN_HEIGHT * 0.05);


	mControlSheet = new Texture("ControlConfigSheet.png", 0, 0, 256, 240);
	mControlSheetFace1 = new Texture("ControlConfigSheet.png", 6, 150, 98, 240);
	mControlSheetFace2 = new Texture("ControlConfigSheet.png", 259, 151, 345, 240);
	mControlSheetFace3 = new Texture("ControlConfigSheet.png", 347, 151, 433, 240);
	mNumber1 = new Texture("ControlConfigSheet.png", 265.56, 24.14, 271, 32);
	mNumber2 = new Texture("ControlConfigSheet.png", 273, 24, 281, 32);
	
	mTopPart->Parent(this);
	mControlSheet->Parent(mTopPart);


	mControlSheet->Position(0.0f, 0.0);
	mControlSheetFace1->Position(0.0f, 0.0);
	mControlSheetFace2->Position(0.0f, 0.0);
	mControlSheetFace3->Position(0.0f, 0.0);
	mNumber1->Position(0.0f, 0.0);
	mNumber2->Position(0.0f, 0.0);



}

PlayScreen::~PlayScreen() {
	
	//mAudio = nullptr;

	delete mControlSheet;
	mControlSheet = nullptr;

	/*delete mSideBar;
	mSideBar = nullptr;*/
	
	delete mControlSheetFace1;
	mControlSheetFace1 = nullptr;
	
	delete mControlSheetFace2;
	mControlSheetFace2 = nullptr;
	
	delete mControlSheetFace3;
	mControlSheetFace3 = nullptr;
	
	delete mNumber1;
	mNumber1 = nullptr;
	
	delete mNumber2;
	mNumber2 = nullptr;

	mTimer = nullptr;



}

void PlayScreen::Update() {
	//mSideBar->Update();
	mControlSheet->Update();
	mControlSheetFace1->Update();
	mControlSheetFace2->Update();
	mControlSheetFace3->Update();
	mNumber1->Update();
	mNumber2->Update();



}

void PlayScreen::Render() {
	//mSideBar->Render();
	mControlSheet->Render();
	mControlSheetFace1->Render();
	mControlSheetFace2->Render();
	mControlSheetFace3->Render();
	mNumber1->Render();
	mNumber2->Render();







}

