#include "stdafx.h"
#include "MInventory.h"

//MInventory* MInventory::instance{ nullptr }; // ¼öÇöÂô

MInventory::MInventory() : ZeroSprite("Texture/UI/Inventory/%s.png", "Background")
{
	SetPos(0.0f, ZeroApp->GetWindowHeight() / 2 - Height() / 2);
	pos[0] = 100.0f;
	pos[1] = 250.0f;
	pos[2] = 400.0f;

	tempSprite = new ZeroSprite("Texture/UI/Inventory/%s.png", "Item_Empty");

	item_empty = new ZeroSprite("Texture/UI/Inventory/%s.png", "Item_Empty");
	item_sword = new ZeroSprite("Texture/UI/Inventory/%s.png", "Item_Sword");
	item_apple = new ZeroSprite("Texture/UI/Inventory/%s.png", "Item_Apple");

	for (int i = 0; i < 3; ++i)
	{
		inventory[i] = new ZeroSprite("Texture/UI/Inventory/%s.png", "Item_Empty");
		inventory[i]->SetPos(ZeroCameraMgr->Pos().x + 30.0f, ZeroCameraMgr->Pos().y + Pos().y + pos[i]);
	}

	ChangeImage(inventory[0], item_sword);
	//ChangeImage(inventory[1], item_apple);
}


MInventory::~MInventory()
{
}

MInventory *MInventory::GetInstance()
{
	static MInventory instance;
	return &instance;
}

void MInventory::Update(float eTime)
{
	ZeroSprite::Update(eTime);

	for (int i = 0; i < 3; ++i)
	{
		inventory[i]->SetPos(ZeroCameraMgr->Pos().x + 30.0f, ZeroCameraMgr->Pos().y + Pos().y + pos[i]);
	}

	SetPos(ZeroCameraMgr->Pos().x, ZeroCameraMgr->Pos().y + ZeroApp->GetWindowHeight() / 2 - Height() / 2);
}

void MInventory::Render()
{
	ZeroSprite::Render();

	for (int i = 0; i < 3; ++i)
	{
		inventory[i]->Render();
	}
}

void MInventory::ChangeImage(ZeroSprite *temp1, ZeroSprite *temp2)
{
	tempSprite = temp1;
	temp1->texture = temp2->texture;
	temp1->SetPos(tempSprite->Pos().x, tempSprite->Pos().y);
}