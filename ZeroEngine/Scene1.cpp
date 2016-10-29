#include "stdafx.h"
#include "Scene1.h"
#include <math.h>

Scene1::Scene1()
	:mEnemy(NULL), initialized(false)
{
	//player = new ZeroSprite("Texture/Character/%s.png", "Character");
	mPlayer = new MPlayer();
	mPlayer->SetPos(0.f, 0.f);
	RM->SetPlayer(mPlayer);

	mEnemy = EM->addMEnemy();
	mEnemy->SetPos(ZeroApp->GetWindowWidth() / 2, /*ZeroApp->GetWindowHeight() / 2*/ 0);
	
	PushScene(mPlayer);
	PushScene(mPlayer->mSword);

	PushScene(mEnemy);

	for (int i=0; i<3; i++)
		PushScene(mEnemy->damageViewer[i]);

	ZeroCameraMgr->SetCameraOn();
	ZeroCameraMgr->SetTarget(mPlayer);
	ZeroCameraMgr->SetScreen(1280, 1024);

	hit = false;
	enemyDeadInfo = {};
}


Scene1::~Scene1()
{
}

void Scene1::Update(float eTime)
{
	ZeroIScene::Update(eTime);

	//ÃÊ±âÈ­
	/*if (!initialized)
	{
		

		initialized = true;
	}*/

	

	if (mEnemy != NULL)
	{
		if (IsExistScene(mEnemy))
		{
			if (mEnemy->IsOverlapped(mPlayer->mSword) && !hit && mPlayer->attack)
			{
				printf("HIT!\n");
				
				//printf("%f %f\n", mPlayer->Pos().x, mPlayer->Pos().y);
				mEnemy->Damaged(30);
				hit = true;
			}
			else if (mPlayer->attacked) hit = false;
		}
	}

	if ((enemyDeadInfo = EM->findDeadMEnemy()).index > -1)
	{
		//auto it = EM->mEnemyManager.begin();
		//advance(it, num);
		MRubbish *rb = RM->addRubbish("apple");
		PushScene(rb);
		rb->SetPos(enemyDeadInfo.iter->Pos().x + enemyDeadInfo.iter->Width() / 2 - rb->Width()/2, enemyDeadInfo.iter->Pos().y + enemyDeadInfo.iter->Height() - rb->Height() );
		EM->popMEnemy(enemyDeadInfo.iter);
		PopScene(enemyDeadInfo.iter);
	}

	if ((gottenRubbishInfo = RM->findGottenRubbish()).index > -1)
	{
		if (gottenRubbishInfo.iter->tag.compare("apple") == 0)
		{
			MInven->ChangeImage(MInven->inventory[1], MInven->item_apple);
		}

		RM->popRubbish(gottenRubbishInfo.iter);
		PopScene(gottenRubbishInfo.iter);
	}

}

void Scene1::Render()
{
	ZeroIScene::Render();

	for (auto iter = EM->mEnemyManager.begin(); iter != EM->mEnemyManager.end(); ++iter)
	{
		(*iter)->Render();
	}

	for (auto iter = RM->mRubbishManager.begin(); iter != RM->mRubbishManager.end(); ++iter)
	{
		(*iter)->Render();
	}

	mPlayer->Render();

	for (auto iter = EM->mEnemyManager.begin(); iter != EM->mEnemyManager.end(); ++iter)	
	{
		for (int i=0; i<3; ++i)
			(*iter)->damageViewer[i]->Render();
	}

	MInven->Render();
}

float Scene1::Distance(float x1, float y1, float x2, float y2)
{
	return sqrtf(powf((x1 - x2), 2.f) + ((y1 - y2), 2.f));
}