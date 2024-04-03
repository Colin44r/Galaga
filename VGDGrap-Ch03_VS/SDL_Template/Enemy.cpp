#include "Enemy.h"

std::vector<std::vector<Vector2>> Enemy::sPaths;

void Enemy::CreatePaths() {

}

void Enemy::HandleFlyInState() { }
void Enemy::HandleFormationState() { }
void Enemy::HandleDiveState() { }
void Enemy::HandleDeadState() { }

void Enemy::HandleStates() {
	switch (mCurrentState) {
	case FlyIn:
		HandleFlyInState();
		break;
	case Formation:
		HandleFormationState();
		break;
	case Diving:
		HandleDiveState();
		break;
	case Dead:
		HandleDeadState();
		break;
	}
}

void Enemy::RenderFlyInState() { }
void Enemy::RenderFormationState() { }
void Enemy::RenderDiveState() { }
void Enemy::RenderDeadState() { }

void Enemy::RenderStates() {
	switch (mCurrentState) {
	case FlyIn:
		HandleFlyInState();
		break;
	case Formation:
		HandleFormationState();
		break;
	case Diving:
		HandleDiveState();
		break;
	case Dead:
		HandleDeadState();
		break;
	}
}

Enemy::Enemy(int path)
	: mCurrentPath(path)
{
	mTimer = Timer::Instance();

	mCurrentState = FlyIn;

	mCurrentWaypoint = 1;
	Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.2);

	mTexture = new Texture("AnimatedEnemies.png", 0, 0, 52, 40);
	mTexture->Parent(this);
	mTexture->Position(Vec2_Zero);

	mSpeed = 100.0f;
}

Enemy::~Enemy() {
	mTimer = nullptr;

	delete mTexture;
	mTexture = nullptr;
}

Enemy::States Enemy::CurrentState() {
	return mCurrentState;
}

void Enemy::Update() {
	if (Active()) {
		HandleStates();
	}
}

void Enemy::Render() {
	if (Active()) {
		mTexture->Render();
	}
}