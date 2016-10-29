#include "stdafx.h"
#include "MRubbish.h"
#include "MRubbishManager.h"

MRubbish::MRubbish(ZeroSprite *_player, string _tag) : ZeroSprite("Texture/Object/Rubbish/%s.png", "junk"), gotten(false)
{
	player = _player;
	tag = _tag;
}

MRubbish::~MRubbish()
{
}

void MRubbish::Update(float eTime)
{
	ZeroSprite::Update(eTime);

	if (this->IsOverlapped(player))
	{
		gotten = true;
	}
}

void MRubbish::Render()
{
	ZeroSprite::Render();
}