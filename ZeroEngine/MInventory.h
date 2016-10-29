#pragma once
#include "Zero.h"

#define MInven MInventory::GetInstance()

class MInventory : public ZeroSprite
{
public:
	ZeroSprite *tempSprite, *item_empty, *item_sword, *item_apple;

	float pos[3];

public:
	ZeroSprite *inventory[3];

public:
	MInventory();
	~MInventory();

	static MInventory *GetInstance();

	void Update(float eTime);
	void Render();

	// temp1.image <- temp2.image
	void ChangeImage(ZeroSprite *temp1, ZeroSprite *temp2);
};

