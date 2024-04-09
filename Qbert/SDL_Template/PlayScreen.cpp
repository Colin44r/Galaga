#include "PlayScreen.h"

PlayScreen::PlayScreen() {
	mTimer = Timer::Instance();
	

	
	mControlSheet = new Texture("TuturSheet.png", 0, 0, 256, 240);
	mControlSheetFace1 = new Texture("TuturSheet.png", 6, 150, 98, 240);
	mControlSheetFace2 = new Texture("TuturSheet.png", 259, 151, 345, 240);
	mControlSheetFace3 = new Texture("TuturSheet.png", 347, 151, 433, 240);
	mNumber1 = new Texture("TuturSheet.png", 265.56, 24.14, 271, 32);
	mNumber2 = new Texture("TuturSheet.png", 273, 24, 281, 32);

	mTopPart = new GameEntity();
	mTopPart->Parent(this);
	mControlSheet->Parent(mTopPart);


	mControlSheet->Position(600.0f, 400.0);
	//For animation to face textures vvv
	// 
	//	mControlSheetFace1->Position(100.0f, 500.0);
	//mControlSheetFace2->Position(400.0f, 500.0);
	//mControlSheetFace3->Position(300.0f, 500.0);
	//mNumber1->Position(100.0f, 100.0);
	//mNumber2->Position(100.0f, 100.0);

	mControlSheet->Scale(Vector2(4.75f, 4.15f));

}

PlayScreen::~PlayScreen() {
	


	delete mControlSheet;
	mControlSheet = nullptr;

	
	//delete mControlSheetFace1;
	//mControlSheetFace1 = nullptr;
	
	//delete mControlSheetFace2;
	//mControlSheetFace2 = nullptr;
	//
	//delete mControlSheetFace3;
	//mControlSheetFace3 = nullptr;
	
	//delete mNumber1;
	//mNumber1 = nullptr;
	
	//delete mNumber2;
	//mNumber2 = nullptr;

	mTimer = nullptr;



}

void PlayScreen::Update() {
	
	mControlSheet->Update();
	//mControlSheetFace1->Update();
	//mControlSheetFace2->Update();
	//mControlSheetFace3->Update();
//	mNumber1->Update();
	//mNumber2->Update();



}

void PlayScreen::Render() {
	
	mControlSheet->Render();
	/*mControlSheetFace1->Render();*/
	//mControlSheetFace2->Render();
	//mControlSheetFace3->Render();
	//mNumber1->Render();
	//mNumber2->Render();







}

