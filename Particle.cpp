#include "Particle.h"

Particle::Particle()
{
	Initialize(0, 0, 0, 0, "");
	alpha = 0;
	size = 0;
}

Particle::Particle(float tx, float ty, float trad)
{
	Initialize(tx, ty, 1, 3.0, "");
	SetRad(trad);
	speed = speed_max;
	size = 1.0;
	alpha = GetRand(90) + 255;
}

Particle::~Particle()
{
}

void Particle::Update()
{
	if (alpha < 0) {
		flag = false;
	}

	alpha -= 3;

	//Rotate();

	x += dx;
	y += dy;
}

void Particle::Draw()
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
	
	DrawRotaGraph(x, y, size, 0.0, image, TRUE);
	
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}