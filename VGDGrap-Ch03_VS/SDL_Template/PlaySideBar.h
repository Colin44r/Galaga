#pragma once
#include "Timer.h"
#include "Scoreboard.h"
#include "AudioManager.h"

using namespace SDLFramework;

class PlaySideBar : public GameEntity {
private:
	static const int MAX_SHIP_TEXTURES = 5;

	Timer* mTimer;
	AudioManager* mAudio;

	Texture* mBackground;

	Texture* mPlayerOneLabel;
	float mBlinkTimer;
	float mBlinkInterval;
	bool mPlayerOneLabelVisible;

	Texture* mHighLabel;
	Texture* mScoreLabel;
	Scoreboard* mHighScoreBoard;

	Scoreboard* mPlayerOneScore;

	GameEntity* mShips;
	Texture* mShipTextures[MAX_SHIP_TEXTURES];
	Scoreboard* mTotalShipsLabel;
	int mTotalShips;

public:
	PlaySideBar();
	~PlaySideBar();

	void SetHighScore(int score);
	void SetPlayerScore(int score);
	void SetShip(int ships);

	void Update() override;
	void Render() override;
};