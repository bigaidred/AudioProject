#include "SoundManager.h"
#include <iostream>

SoundManager::SoundManager()
{
	intensity = 0;

	result = FMOD::System_Create(&system);

	system->init(32, FMOD_INIT_NORMAL, nullptr);

	system->createSound(R"(Assets/Audio/Layer1_Ambience.wav)", FMOD_LOOP_NORMAL, nullptr, &layer1);

	system->createSound(R"(Assets/Audio/Layer2_Rhythm.wav)", FMOD_LOOP_NORMAL, nullptr, &layer2);

	system->createSound(R"(Assets/Audio/Layer3_Melody.wav)", FMOD_LOOP_NORMAL, nullptr, &layer3);

	system->createSound(R"(Assets/Audio/Layer4_Percussion.wav)", FMOD_LOOP_NORMAL, nullptr, &layer4);

	result = system->playSound(layer1, nullptr, false, &channel1);
	channel1->setVolume(0.7);

	system->playSound(layer2, nullptr, false, &channel2);
	channel2->setVolume(0);

	system->playSound(layer3, nullptr, false, &channel3);
	channel3->setVolume(0);

	system->playSound(layer4, nullptr, false, &channel4);
	channel4->setVolume(0);
}

SoundManager::~SoundManager()
{

}

void SoundManager::update(float dt)
{
	system->update();
}

void SoundManager::UpdateMusic()
{

	switch (intensity)
	{

	case(0):
	{
		channel2->setVolume(0);
		channel3->setVolume(0);
		channel4->setVolume(0);
	};	break;

	case(1):
	{
		channel2->setVolume(0.7);

		channel3->setVolume(0);
		channel4->setVolume(0);
	};	break;

	case(2):
	{
		channel2->setVolume(0.7);
		channel3->setVolume(0.7);
		channel4->setVolume(0);
	};	break;

	case(3):
	{
		channel2->setVolume(0.7);
		channel3->setVolume(0.7);
		channel4->setVolume(0.7);
	};	break;

	}
}