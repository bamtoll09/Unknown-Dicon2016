#pragma once
#include "Zero.h"

class MPlayer : public ZeroSprite
{
public:
	ZeroRect *m_vRectCollider;
	ZeroSprite *mSword;

	// �̵� ����
	bool left, up;
	float w, a, s, d;
	float speed;
	float vcX, vcY;
	float speedXeTime;

	// ���� ����
	bool attack;
	bool attacked;
	bool isAttacking;
	float attackTime;
	
public:
	MPlayer();
	~MPlayer();

	void Update(float eTime);
	void Render();
};

