#pragma once
#include "Unit.h"
class Particle : public Unit
{
	int alpha;
	float size;
public:
	Particle();
	Particle(float tx, float ty, float trad);
	~Particle();
	void Update();
	void Draw();
};

