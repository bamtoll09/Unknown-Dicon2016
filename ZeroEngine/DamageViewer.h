#pragma once
#include "Zero.h"

class DamageViewer : public ZeroFont
{
private:
	ZeroSprite *object;

	int foTime; // FadeOut Time
	float time;
	bool activated;
public:
	DamageViewer(ZeroSprite *object);
	virtual ~DamageViewer();

	void Update(float eTime);
	void Render();

	bool Activate();
};

