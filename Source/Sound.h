#pragma once
#include <SFML/Audio.hpp>
#include <iostream>
using namespace std;
using namespace sf;



class sound
{
private:
	SoundBuffer soundBuffer;
	Sound SOUND;
public:
	string amvachamthanhdo = "Sound\\vachamthanhdo.ogg";
	string amvachamcanhban = "Sound\\vachamcanhban.ogg";
	string win1 = "Sound\\win1.ogg";
	string win = "Sound\\win.ogg";
	string lose1 = "Sound\\lose1.ogg";
	string lose = "Sound\\lose.ogg";
	string backgroundsound = "Sound\\background.ogg";
	string choose = "Sound\\choose.ogg";

	void soundPlay(string);
};


