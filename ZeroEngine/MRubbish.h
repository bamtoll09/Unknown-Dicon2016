#pragma once
#include "Zero.h"

class MRubbish : public ZeroSprite
{
private:
	ZeroSprite *player;

public:
	bool gotten;
	string tag;

public:
	MRubbish(ZeroSprite *_player, string _tag);
	~MRubbish();

	void Update(float eTime);
	void Render();
};

