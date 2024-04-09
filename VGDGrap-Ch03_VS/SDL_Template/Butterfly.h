#pragma once
#include "Enemy.h"

class Butterfly : public Enemy {
private:
	static std::vector<std::vector<Vector2>> sDivePaths;

	// Inherited via Enemy
	Vector2 LocalFormationPosition() override;

	void HandleDiveState() override;
	void HandleDeadState() override;

	void RenderDiveState() override;
	void RenderDeadState() override;

public:

	Butterfly(int path, int index, bool challenge);
	~Butterfly();
};