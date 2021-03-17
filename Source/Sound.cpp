#include "Sound.h"

void sound::soundPlay(string a)
{
	soundBuffer.loadFromFile(a);
	SOUND.setBuffer(soundBuffer);
	SOUND.play();
}
