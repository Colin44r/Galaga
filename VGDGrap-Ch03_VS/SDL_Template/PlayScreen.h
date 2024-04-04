#pragma once
#include "AudioManager.h"
#include "GameEntity.h"
#include "Timer.h"
#include "PlaySideBar.h"

using namespace SDLFramework;

class PlayScreen : public GameEntity {
private:
	Timer* mTimer;
	AudioManager* mAudio;
	GameEntity* mTopPart;
	PlaySideBar* mSideBar;
	Texture* mControlConfigSheet;

public:
	PlayScreen();
	~PlayScreen();

	void Update() override;
	void Render() override;
};