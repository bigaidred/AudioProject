#pragma once
#include "fmod.hpp"

class SoundManager
{
public:

	SoundManager();
	~SoundManager();

	void update(float dt);

	void SetIntensity(int i)
	{
		intensity = i;
		UpdateMusic();
	}

	int GetIntensity()
	{
		return intensity;
	}

	void UpdateMusic();

private:

	FMOD_RESULT result;
	FMOD::System* system = nullptr;

	FMOD::Channel* channel1 = nullptr;
	FMOD::Channel* channel2 = nullptr;
	FMOD::Channel* channel3 = nullptr;
	FMOD::Channel* channel4 = nullptr;

	FMOD::Sound* layer1 = nullptr;
	FMOD::Sound* layer2 = nullptr;
	FMOD::Sound* layer3 = nullptr;
	FMOD::Sound* layer4 = nullptr;

	int intensity;
};

