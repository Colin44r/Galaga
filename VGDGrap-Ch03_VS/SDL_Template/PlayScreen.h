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

	PlaySideBar* mSideBar;

public:
	PlayScreen();
	~PlayScreen();

	void StartNewGame();
	void StartNextLevel();

	void Update() override;
	void Render() override;
};