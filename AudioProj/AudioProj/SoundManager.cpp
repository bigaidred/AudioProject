#include "SoundManager.h"
#include "fmod_errors.h"
#include <iostream>

SoundManager::SoundManager()
{

	/*result = FMOD::System_Create(&system);

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
	channel4->setVolume(0);*/

	FMOD::Studio::System::create(&system);

	system->initialize(32, FMOD_INIT_NORMAL, FMOD_INIT_NORMAL, nullptr);

	result = system->loadBankFile(R"(Assets/Audio/Desktop/Master.bank)", FMOD_STUDIO_LOAD_BANK_NORMAL, &masterSBank);
	system->loadBankFile(R"(Assets/Audio/Desktop/Master.strings.bank)", FMOD_STUDIO_LOAD_BANK_NORMAL, &soundBank);

	soundBank->getEventList(desc, 1, num);

	desc[0]->createInstance(&inst);

	inst->setParameterByName("Intensity", 0);

	inst->setParameterByName("Powerup", 0);

	inst->start();

	if (result != FMOD_OK)
	{
		printf("FMOD error! (%d) %s\n", result, FMOD_ErrorString(result));
	}

}

SoundManager::~SoundManager()
{

}

void SoundManager::updateMusic(int intensity, bool powerup)
{
	inst->setParameterByName("Intensity", intensity);
	inst->setParameterByName("Powerup", powerup);

	system->update();

}

