#include "stdafx.h"
#include "MEnemyManager.h"

MEnemyManager::MEnemyManager() { }

MEnemyManager::~MEnemyManager() { }

MEnemyManager *MEnemyManager::GetInstance()
{
	static MEnemyManager instance;
	return &instance;
}

MEnemy *MEnemyManager::addMEnemy()
{
	MEnemy *mEnemy = new MEnemy();
	mEnemyManager.push_back(mEnemy);
	return mEnemy;
}

void MEnemyManager::popMEnemy(MEnemy *mEnemy)
{
	mEnemyManager.remove(mEnemy);
}

edi MEnemyManager::findDeadMEnemy()
{
	int i = 0;
	for (auto node = mEnemyManager.begin(); node != mEnemyManager.end(); ++node)
	{
		if ((*node)->dead)
		{
			return edi{ i, *node };
		}

		++i;
	}
	return edi{ -1, nullptr };
}