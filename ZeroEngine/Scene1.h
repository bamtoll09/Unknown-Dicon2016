#pragma once
#include "Zero.h"
#include "MPlayer.h"
#include "MInventory.h"
#include "MEnemyManager.h"
#include "MRubbishManager.h"

class Scene1 : public ZeroIScene
{
private:
	MPlayer *mPlayer;
	MEnemy *mEnemy;

	bool initialized;
	bool hit;
	EnemyDeadInfo enemyDeadInfo;
	GottenRubbishInfo gottenRubbishInfo;

public:
	Scene1();
	~Scene1();

	void Update(float eTime);
	void Render();

	float Distance(float x1, float y1, float x2, float y2);
};

