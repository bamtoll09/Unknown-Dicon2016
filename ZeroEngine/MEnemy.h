#pragma once
#include "Zero.h"
#include "DamageViewer.h"

class MEnemy : public ZeroSprite
{
private:
	bool initialized;
	int hp;

public:
	bool dead;
	DamageViewer *damageViewer[3];

public:
	MEnemy();
	virtual ~MEnemy();

	void Update(float eTime);
	void Render();

	void Damaged(int damage);
};

