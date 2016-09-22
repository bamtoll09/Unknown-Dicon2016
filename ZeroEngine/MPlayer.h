#pragma once
#include "Zero.h"

class MPlayer : public ZeroSprite
{
private:
	ZeroRect *m_vRectCollider;

	float w, a, s, d; // �̵� ����
	float speed;
	float vcX, vcY;
	float speedXeTime;

	float attackTime; // ���� ����
	bool isAttacking;
public:
	ZeroSprite *m_vSword;

	bool attack;
	bool attacked;
public:
	MPlayer();
	virtual ~MPlayer();

	void Update(float eTime);
	void Render();
};

