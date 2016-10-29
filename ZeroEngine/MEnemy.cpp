#include "stdafx.h"
#include "MEnemy.h"
#include "MRubbishManager.h"
#include "MEnemyManager.h"

MEnemy::MEnemy() : ZeroSprite("Texture/Object/Character/%s.png", "Enemy"), initialized(false), hp(100),
																	dead(false)
{
	for (int i = 0; i < 3; i++)
	{
		damageViewer[i] = new DamageViewer(this);
	}
}

MEnemy::~MEnemy() { }

void MEnemy::Update(float eTime)
{
	ZeroSprite::Update(eTime);

	// ÃÊ±âÈ­
	/*if (!initialized)
	{
		

		initialized = true;
	}*/

	if (!dead && hp <= 0)
	{
		dead = true;
		printf("dead\n");
		//RM->addRubbish()->SetPos(Pos().x, Pos().y);
		//EM->popMEnemy(this);
	}
}

void MEnemy::Render()
{
	ZeroSprite::Render();

	
	/*for (int i = 0; i < 3; i++)
	{
		damageViewer[i]->Render();
	}*/
}

void MEnemy::Damaged(int damage)
{
	hp -= damage;
	
	for (int i = 0; i < 3; i++)
	{
		if (damageViewer[i]->Activate())
			break;
	}
}