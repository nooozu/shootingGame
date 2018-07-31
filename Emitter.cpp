#include "Emitter.h"

Emitter::Emitter(Unit* u)
{
	SRand(GetNowCount());
	pos = u;
}

Emitter::~Emitter()
{
	if (pParticle) {
		pParticle = NULL;
	}
}

void Emitter::Update()
{
	for (auto itr = particleList.begin(); itr != particleList.end();) {
		itr->Update();

		if (!itr->GetFlag()) {
			itr = particleList.erase(itr);
		}
		else {
			itr++;
		}
	}
}

void Emitter::Draw()
{
	for (auto itr = particleList.begin(); itr != particleList.end(); itr++) {
		itr->Draw();
	}
}

void Emitter::ParticleGenerate(int par_num)
{
	pParticle = new Particle(pos->GetX(), pos->GetY(), 0);
	pParticle->SetImage(particle_image);

	for (int i = 0; i < par_num; i++) {
		pParticle->SetRad(DEG_TO_RAD(GetRand(360)));
		pParticle->SetSpeed((float)(GetRand(100.0) / 100.0) + 1.0);
		particleList.push_back(*pParticle);
	}

	delete pParticle;
}