#pragma once
#include "fmod.hpp"
#include "fmod_studio.hpp"

class SoundManager
{
public:

	SoundManager();
	~SoundManager();

	void updateMusic(int intensity, bool powerup);

private:

	FMOD_RESULT result;

	FMOD::Studio::System* system;
	FMOD::Studio::Bank* soundBank;
	FMOD::Studio::Bank* masterSBank;

	FMOD::Studio::EventDescription* desc[1];
	FMOD::Studio::EventInstance* inst;

	int* num;
};

