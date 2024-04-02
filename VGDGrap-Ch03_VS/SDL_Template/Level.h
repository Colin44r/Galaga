#pragma once
#include "PlaySideBar.h"
#include "Player.h"

class Level : public GameEntity {
private:
	Timer* mTimer;
	PlaySideBar* mSideBar;

	int mStage;
	bool mStageStarted;

	float mLabelTimer;

	Texture* mStageLabel;
	Scoreboard* mStageNumber;
	float mStageLabelOnScreen;
	float mStageLabelOffScreen;

	Texture* mReadyLabel;
	float mReadyLabelOnScreen;
	float mReadyLabelOffScreen;

	Player* mPlayer;

	void StartStage();

public:
	enum LevelStates { Running, Finished, GameOver };
	Level(int stage, PlaySideBar* side, Player* player);
	~Level();

	void Update() override;
	void Render() override;
};