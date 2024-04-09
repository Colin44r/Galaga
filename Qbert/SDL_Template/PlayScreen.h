#pragma once
//#include "AudioManager.h"
#include "GameEntity.h"
#include "Timer.h"
//#include "PlaySideBar.h"
#include "Texture.h"

using namespace SDLFramework;

class PlayScreen : public GameEntity {
private:
	Timer* mTimer;
	//AudioManager* mAudio;
	GameEntity* mTopPart;
	//PlaySideBar* mSideBar;
	Texture* mControlSheet;
	Texture* mControlSheetFace1;
	Texture* mControlSheetFace2;
	Texture* mControlSheetFace3;
	Texture* mNumber1;
	Texture* mNumber2;


public:
	PlayScreen();
	~PlayScreen();

	void Update() override;
	void Render() override;
};