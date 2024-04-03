#pragma once
#include "PlaySideBar.h"
#include "Player.h"
#include "Enemy.h"

class Level : public GameEntity {
public:
	enum LevelStates { Running, Finished, GameOver };

private:
	Timer* mTimer;
	PlaySideBar* mSideBar;

	int mStage;
	bool mStageStarted;

	float mLabelTimer;

	bool mPlayerHit;
	float mRespawnDelay;
	float mRespawnTimer;
	float mRespawnLabelOnScreen;

	Texture* mGameOverLabel;
	float mGameOverDelay;
	float mGameOverTimer;
	float mGameOverLabelOnScreen;


	Texture* mStageLabel;
	Scoreboard* mStageNumber;
	float mStageLabelOnScreen;
	float mStageLabelOffScreen;

	Texture* mReadyLabel;
	float mReadyLabelOnScreen;
	float mReadyLabelOffScreen;

	Player* mPlayer;
	Enemy* mEnemy;

	void StartStage();

	LevelStates mCurrentState;

	void HandleStartLabels();
	void HandleCollisions();
	void HandlePlayerDeath();

public:
	Level(int stage, PlaySideBar* side, Player* player);
	~Level();

	LevelStates State();

	void Update() override;
	void Render() override;
};