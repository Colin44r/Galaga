#pragma once
#include "AnimatedTexture.h"
#include <vector>

using namespace SDLFramework;

class Enemy : public GameEntity {
public:
	enum States { FlyIn, Formation, Diving, Dead };

protected:
	const float EPSILON = 5.0f;
	static std::vector<std::vector<Vector2>> sPaths;

	Timer* mTimer;

	Texture* mTexture;

	States mCurrentState;

	unsigned mCurrentPath;
	unsigned mCurrentWaypoint;

	float mSpeed;

	virtual void HandleFlyInState();
	virtual void HandleFormationState();
	virtual void HandleDiveState();
	virtual void HandleDeadState();

	void HandleStates();

	virtual void RenderFlyInState();
	virtual void RenderFormationState();
	virtual void RenderDiveState();
	virtual void RenderDeadState();

	void RenderStates();

public:
	static void CreatePaths();

	Enemy(int path);
	virtual ~Enemy();

	States CurrentState();

	void Update();
	void Render();
};
