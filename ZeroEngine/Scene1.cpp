#include "stdafx.h"
#include "Scene1.h"
#include <math.h>

Scene1::Scene1()
{
	//player = new ZeroSprite("Texture/Character/%s.png", "Character");
	mPlayer = new MPlayer();
	mPlayer->SetPos(0.f, 0.f);

	player2 = new ZeroSprite("Texture/Character/%s.png", "Character");
	player2->SetPos(ZeroApp->GetWindowWidth() / 2, /*ZeroApp->GetWindowHeight() / 2*/ 0);
	
	for (int i = 0; i < 3; i++)
	{
		damageViewer[i] = new DamageViewer(player2);
		PushScene(damageViewer[i]);
	}
	
	PushScene(player2);
	PushScene(mPlayer);

	hit = false;
}


Scene1::~Scene1()
{
}

void Scene1::Update(float eTime)
{
	ZeroIScene::Update(eTime);

	if (player2->IsOverlapped(mPlayer->m_vSword) && !hit && mPlayer->attack)
	{
		printf("HIT!\n");
		
		for (int i = 0; i < 3; i++)
		{
			if (damageViewer[i]->Activate())
				break;
		}

		//printf("%f %f\n", mPlayer->Pos().x, mPlayer->Pos().y);
		hit = true;
	} else if (mPlayer->attacked) hit = false;
}

void Scene1::Render()
{
	ZeroIScene::Render();

	player2->Render();
	mPlayer->Render();
	for (int i = 0; i < 3; i++)
	{
		damageViewer[i]->Render();
	}
}

float Scene1::Distance(float x1, float y1, float x2, float y2)
{
	return sqrtf(powf((x1 - x2), 2.f) + ((y1 - y2), 2.f));
}