#pragma once
#include "Particle.h"
#include <list>
#include <vector>

class Emitter
{
	int particle_image;
	Unit* pos;
	Particle* pParticle;
	std::list<Particle> particleList;

public:
	Emitter(Unit*);
	~Emitter();
	void Update();
	void Draw();
	void ParticleGenerate(int);

	void SetParticleImage(int i) { particle_image = i; }
};

