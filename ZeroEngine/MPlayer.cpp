#include "stdafx.h"
#include "MPlayer.h"

MPlayer::MPlayer() : ZeroSprite("Texture/Object/Character/%s.png", "Player")
{
	mSword = new ZeroSprite("Texture/Object/Item/Weapon/%s.png", "Sword");
	mSword->SetRotCenter(mSword->Width() / 2 - 20.f, mSword->Height() / 2 + 30.f);

	m_vRectCollider = new ZeroRect();

	w = a = s = d = vcX = vcY = 0.f;
	speed = 150.f;

	isAttacking = false;
	attack = false;
	attacked = false;
	attackTime = 0.f;
}

MPlayer::~MPlayer()
{
}

void MPlayer::Update(float eTime)
{
	ZeroSprite::Update(eTime);
	
	speedXeTime = speed * eTime;

	if (ZeroInputMgr->GetKey('W') == INPUTMGR_KEYON || ZeroInputMgr->GetKey(VK_UP) == INPUTMGR_KEYON) // w 입력
	{
		//if (w >= 1.f)
		w = 1.f;
		//else
		//	w += eTime;
	} else {
		//if (w <= 0.f)
		w = 0.f;
		//else
		//	w -= eTime;
	}

	if (ZeroInputMgr->GetKey('A') == INPUTMGR_KEYON || ZeroInputMgr->GetKey(VK_LEFT) == INPUTMGR_KEYON) // a 입력
	{
		//if (a >= 1.f)
		a = 1.f;
		//else
		//	a += eTime;
	} else {
		//if (a <= 0.f)
		a = 0.f;
		//else
		//	a -= eTime;
	}

	if (ZeroInputMgr->GetKey('S') == INPUTMGR_KEYON || ZeroInputMgr->GetKey(VK_DOWN) == INPUTMGR_KEYON) // s 입력
	{
		//if (s >= 1.f)
		s = 1.f;
		//else
		//	s += eTime;
	} else {
		//if (s <= 0.f)
		s = 0.f;
		//else
		//	s -= eTime;
	}

	if (ZeroInputMgr->GetKey('D') == INPUTMGR_KEYON || ZeroInputMgr->GetKey(VK_RIGHT) == INPUTMGR_KEYON) // d 입력
	{
		//if (d >= 1.f)
		d = 1.f;
		//else
		//	d += eTime;
	} else {
		//if (d <= 0.f)
		d = 0.f;
		//else
		//	d -= eTime;
	}

	if (ZeroInputMgr->GetKey('0') == INPUTMGR_KEYON)
		this->SetPos(0.f, 0.f);

	if (w == 1 && a == 1 && s == 0 && d == 0) // ↖
		w = a = 0.707f;
	else if (w == 1 && a == 0 && s == 0 && d == 1) // ↗
		w = d = 0.707f;
	else if (w == 0 && a == 1 && s == 1 && d == 0) // ↙
		s = a = 0.707f;
	else if (w == 0 && a == 0 && s == 1 && d == 1) // ↘
		s = d = 0.707f;

	vcX = (-1 * a * speedXeTime) + (d * speedXeTime);
	vcY = (-1 * w * speedXeTime) + (s * speedXeTime);

	/*
	float tempX = powf(vcX, 2.f);
	float tempY = powf(vcY, 2.f);
	float temp = tempX + tempY;

	if (temp > powf(speedXeTime, 2.f)) // 만약 원 밖으로 나갈 때 <이동>
	{
	temp -= powf(speedXeTime, 2.f);

	tempX = temp * (tempX / (tempX + tempY));
	tempY = temp * (tempY / (tempX + tempY));

	if (vcX != 0.f)
	vcX = sqrtf(powf(vcX, 2.f) - tempX);
	if (vcY != 0.f)
	vcY = sqrtf(powf(vcY, 2.f) - tempY);
	}

	if (vcX != 0.f || vcY != 0.f)
	printf("vcX: %f, vcY: %f, temp: %f, speedXeTime: %f\n", vcX, vcY, temp, speedXeTime);
	*/

	this->AddPosX(vcX); // a, d
	this->AddPosY(vcY); // w, s

	mSword->SetPos(this->Pos().x + this->Width() - mSword->Width(), this->Pos().y - mSword->Height() + 220.f);

	if (!isAttacking)
	{
		if (ZeroInputMgr->GetKey('Z') == INPUTMGR_KEYDOWN)
		{
			printf("ATTACK!\n");
			isAttacking = true;
		}
	}

	if (isAttacking) // 120도
	{
		if (attackTime <= 0.1f) {
			mSword->AddRot(1200.f * eTime);
			if (!attack)
				attack = true;
		} else if (attack) {
			if (mSword->Rot() < 120.f || mSword->Rot() > 120.f)
				mSword->SetRot(120.f);
			attack = false;
		} else if (attackTime <= 0.2f) {
			mSword->AddRot(-1200.f * eTime);
			if (!attacked)
				attacked = true;
		} else if (attacked) {
			if (mSword->Rot() < 0.f || mSword->Rot() > 0.f)
				mSword->SetRot(0.f);
			attacked = false;
		} else {
			isAttacking = false;
			attackTime = 0.f;
		}

		attackTime += eTime;
	}

	/*
	m_vRectCollider->top = this->Pos().y;
	m_vRectCollider->left = this->Pos().x;
	m_vRectCollider->bottom = this->Pos().y + this->Height();
	m_vRectCollider->right = this->Pos().x + this->Width();
	*/
}

void MPlayer::Render()
{
	ZeroSprite::Render();

	mSword->Render();
}