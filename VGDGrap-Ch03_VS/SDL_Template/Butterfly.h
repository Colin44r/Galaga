#pragma once
#include "Enemy.h"

class Butterfly : public Enemy {
private:
	//Inheritted via Enemy
	Vector2 LocalFormationPosition() override;

	void HandleDiveState() override;
	void HandleDeadState() override;

	void RenderDiveState() override;
	void RenderDeadState() override;

public:
	Butterfly(int path, int index, bool challenge);
	~Butterfly();
};