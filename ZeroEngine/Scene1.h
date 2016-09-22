#pragma once
#include "Zero.h"
#include "MPlayer.h"
#include "DamageViewer.h"

class Scene1 : public ZeroIScene
{
private:
	MPlayer *mPlayer;
	ZeroSprite *player2;
	DamageViewer *damageViewer[3];

	bool hit;
public:
	Scene1();
	~Scene1();

	void Update(float eTime);
	void Render();

	float Distance(float x1, float y1, float x2, float y2);
};

