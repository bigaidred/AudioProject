#include "SoundManager.h"
#include "fmod_errors.h"
#include <iostream>

SoundManager::SoundManager()
{
	FMOD::Studio::System::create(&system);

	system->initialize(32, FMOD_INIT_NORMAL, FMOD_INIT_NORMAL, nullptr);

	system->loadBankFile(R"(Assets/Audio/Desktop/Master.strings.bank)", FMOD_STUDIO_LOAD_BANK_NORMAL, &mStringsBank);
	system->loadBankFile(R"(Assets/Audio/Desktop/Master.bank)", FMOD_STUDIO_LOAD_BANK_NORMAL, &masterBank);

	masterBank->getEventList(desc, 1, num);

	result = desc[0]->createInstance(&inst);

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

