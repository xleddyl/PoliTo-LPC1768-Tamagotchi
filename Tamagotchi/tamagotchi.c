#include "tamagotchi.h"
#include "../GLCD_advanced/GLCD.h"
#include "../Timer/timer.h"
#include "../RIT/RIT.h"
#include "../MIDI/MIDI.h"
#include "../ADC/adc.h"
#include <string.h>

const struct tamagotchi_bmp frame0 = {
	32, 31,
  {
    White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,
    White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,
    White,White,White,White,White,White,Black,Black,Black,Black,Black,Black,White,White,White,White,White,White,White,White,Black,Black,Black,Black,Black,Black,White,White,White,White,White,White,
    White,White,White,White,White,Black,Black,Black,Black,Black,Black,Black,Black,White,White,White,White,White,White,Black,Black,Black,Black,Black,Black,Black,Black,White,White,White,White,White,
    White,White,White,White,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,White,White,White,White,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,White,White,White,White,
    White,White,White,White,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,White,White,White,White,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,White,White,White,White,
    White,White,White,White,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,White,White,White,White,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,White,White,White,White,
    White,White,White,White,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,White,White,White,White,
    White,White,White,White,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,White,White,White,White,
    White,White,White,White,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,White,White,White,White,
    White,White,White,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,White,White,White,
    White,White,White,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,White,White,White,
    White,White,Black,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,Black,White,White,
    White,White,Black,White,White,White,Black,Black,Black,Black,Black,White,White,White,White,White,White,White,White,White,White,Black,Black,Black,Black,Black,White,White,White,Black,White,White,
    White,Black,White,White,White,Black,Black,Black,Black,White,White,Black,White,White,White,White,White,White,White,White,Black,Black,Black,Black,White,White,Black,White,White,White,Black,White,
    White,Black,White,White,Black,Black,White,Black,Black,White,White,White,Black,White,White,White,White,White,White,Black,Black,White,Black,Black,White,White,White,Black,White,White,Black,White,
    White,Black,White,White,Black,Black,White,Black,Black,White,White,White,Black,White,White,White,White,White,White,Black,Black,White,Black,Black,White,White,White,Black,White,White,Black,White,
    White,Black,White,White,Black,Black,Black,Black,Black,White,White,White,Black,White,White,White,White,White,White,Black,Black,Black,Black,Black,White,White,White,Black,White,White,Black,White,
    White,Black,White,White,White,Black,Black,Black,Black,White,White,Black,White,White,White,White,White,White,White,White,Black,Black,Black,Black,White,White,Black,White,White,White,Black,White,
    White,Black,White,White,White,White,Black,Black,Black,Black,Black,White,White,White,White,White,White,White,White,White,White,Black,Black,Black,Black,Black,White,White,White,White,Black,White,
    White,Black,White,White,Black,Black,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,Black,Black,White,White,Black,White,
    White,Black,White,Black,White,White,Black,White,White,White,White,White,Black,White,White,White,White,White,White,Black,White,White,White,White,White,Black,White,White,Black,White,Black,White,
    White,White,Black,Black,White,White,Black,White,White,White,White,White,White,Black,Black,Black,Black,Black,Black,White,White,White,White,White,White,Black,White,White,Black,Black,White,White,
    White,White,Black,White,Black,Black,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,Black,Black,White,Black,White,White,
    White,White,White,Black,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,Black,White,White,White,
    White,White,White,White,Black,Black,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,Black,Black,White,White,White,White,
    White,White,White,White,White,White,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,White,White,White,White,White,White,
    White,White,White,White,White,White,White,White,Black,White,White,White,White,White,White,White,White,White,White,White,White,White,White,Black,White,White,White,White,White,White,White,White,
    White,White,White,White,White,White,White,Black,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,Black,White,White,White,White,White,White,White,
    White,White,White,White,White,White,White,Black,White,White,Black,White,White,White,White,White,White,White,White,White,White,Black,White,White,Black,White,White,White,White,White,White,White,
		White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White
  }
};

const struct tamagotchi_bmp frame1 = {
	32, 31,
	{
		White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,
		White,White,White,White,Black,Black,Black,Black,Black,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,Black,Black,Black,Black,White,White,White,White,
		White,White,White,Black,Black,Black,Black,Black,Black,Black,White,White,White,White,White,White,White,White,White,White,White,White,White,Black,Black,Black,Black,Black,Black,White,White,White,
		White,White,Black,Black,Black,Black,Black,Black,Black,Black,Black,White,White,White,White,White,White,White,White,White,White,White,Black,Black,Black,Black,Black,Black,Black,Black,White,White,
		White,White,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,White,White,White,White,White,White,White,White,White,Black,Black,Black,Black,Black,Black,Black,Black,Black,White,White,
		White,White,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,White,White,White,White,White,White,White,White,White,Black,Black,Black,Black,Black,Black,Black,Black,Black,White,White,
		White,White,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,White,White,
		White,White,White,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,White,White,White,
		White,White,White,White,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,White,White,White,White,
		White,White,White,White,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,White,White,White,White,
		White,White,White,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,White,White,White,
		White,White,White,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,White,White,White,
		White,White,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,White,White,
		White,White,Black,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,Black,White,White,
		White,Black,White,White,White,White,Black,Black,Black,Black,Black,Black,White,White,White,White,White,White,White,White,Black,Black,Black,Black,Black,Black,White,White,White,White,Black,White,
		White,Black,White,White,White,Black,White,White,Black,Black,White,Black,Black,White,White,White,White,White,White,Black,Black,White,Black,Black,White,White,Black,White,White,White,Black,White,
		White,Black,White,White,Black,White,White,Black,Black,Black,White,Black,Black,Black,White,White,White,White,Black,Black,Black,White,Black,Black,Black,White,White,Black,White,White,Black,White,
		White,Black,White,White,Black,White,White,Black,Black,Black,Black,Black,Black,Black,White,White,White,White,Black,Black,Black,Black,Black,Black,Black,White,White,Black,White,White,Black,White,
		White,Black,White,White,Black,White,White,Black,Black,Black,Black,Black,Black,Black,White,White,White,White,Black,Black,Black,Black,Black,Black,Black,White,White,Black,White,White,Black,White,
		White,Black,White,White,Black,White,White,Black,Black,Black,Black,Black,Black,Black,White,White,White,White,Black,Black,Black,Black,Black,Black,Black,White,White,Black,White,White,Black,White,
		White,Black,White,White,White,Black,White,White,Black,Black,Black,Black,Black,White,Black,Black,Black,Black,White,Black,Black,Black,Black,Black,White,White,Black,White,White,White,Black,White,
		White,Black,White,White,White,White,Black,Black,Black,Black,Black,Black,White,White,Black,Black,Black,Black,White,White,Black,Black,Black,Black,Black,Black,White,White,White,White,Black,White,
		White,Black,White,White,White,White,White,White,White,White,White,White,White,White,Black,Black,Black,Black,White,White,White,White,White,White,White,White,White,White,White,White,Black,White,
		White,Black,White,White,White,White,White,White,White,White,White,White,White,White,Black,Black,Black,Black,White,White,White,White,White,White,White,White,White,White,White,White,Black,White,
		White,Black,White,White,Black,Black,Black,White,White,White,White,White,White,White,Black,Black,Black,Black,White,White,White,White,White,White,White,White,White,White,White,White,Black,White,
		White,White,Black,Black,White,White,White,Black,White,White,White,White,White,White,Black,Black,Black,Black,White,White,White,White,White,White,White,White,White,White,White,Black,White,White,
		White,White,White,Black,White,White,White,White,Black,White,White,White,White,White,White,Black,Black,White,White,White,White,White,White,White,White,White,White,Black,Black,White,White,White,
		White,White,White,Black,White,White,White,White,White,Black,White,White,White,White,White,White,White,White,White,White,White,White,White,Black,Black,Black,Black,White,White,White,White,White,
		White,White,White,White,Black,White,White,White,White,White,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,White,Black,White,White,White,White,White,White,White,
		White,White,White,White,White,Black,Black,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,Black,White,White,White,White,White,White,
		White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White
	}
};
const struct tamagotchi_bmp frame2 = {
	32, 31,
	{
		White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,
		White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,
		White,White,White,White,White,White,White,White,White,White,White,Black,Black,Black,Black,White,White,White,White,White,White,White,Black,Black,Black,Black,White,White,White,White,White,White,
		White,White,White,White,White,White,White,White,White,White,Black,Black,Black,Black,Black,Black,White,White,White,White,White,Black,Black,Black,Black,Black,Black,White,White,White,White,White,
		White,White,White,White,White,White,White,White,White,Black,Black,Black,Black,Black,Black,Black,White,White,White,White,White,Black,Black,Black,Black,Black,Black,Black,White,White,White,White,
		White,White,White,White,White,White,White,White,White,Black,Black,Black,Black,Black,Black,Black,White,White,White,White,White,Black,Black,Black,Black,Black,Black,Black,White,White,White,White,
		White,White,White,White,White,White,White,White,White,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,White,White,White,White,
		White,White,White,White,White,White,White,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,White,White,White,White,
		White,White,White,White,White,White,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,White,White,White,White,
		White,White,White,White,White,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,White,White,White,
		White,White,White,White,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,White,White,
		White,White,White,White,Black,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,Black,Black,Black,White,White,
		White,White,White,Black,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,Black,Black,White,
		White,White,White,Black,White,White,White,White,Black,Black,Black,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,Black,White,
		White,White,White,Black,White,White,White,White,Black,Black,Black,White,White,White,White,White,White,White,White,White,White,Black,Black,Black,White,White,White,White,White,White,Black,White,
		White,White,White,Black,White,White,White,White,Black,Black,Black,White,White,White,White,White,White,White,White,White,White,Black,Black,Black,White,White,White,White,White,White,Black,White,
		White,White,White,Black,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,Black,Black,Black,White,White,White,White,White,White,Black,White,
		White,White,White,Black,White,White,White,Black,Black,Black,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,Black,White,
		White,White,White,Black,White,White,Black,White,White,White,Black,White,White,White,White,White,White,White,White,White,White,White,Black,Black,Black,White,White,White,White,White,Black,White,
		White,White,White,Black,White,White,Black,White,White,White,Black,White,White,White,White,White,White,White,White,White,White,Black,White,White,White,Black,White,White,White,White,Black,White,
		White,White,White,White,Black,White,Black,White,White,White,Black,White,White,Black,Black,Black,Black,White,White,White,White,Black,White,White,White,Black,White,White,White,Black,White,White,
		White,White,White,White,Black,White,White,Black,Black,Black,White,White,White,Black,Black,Black,Black,White,White,White,White,Black,White,White,White,Black,White,White,White,Black,White,White,
		White,White,White,White,White,Black,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,Black,Black,Black,White,White,White,Black,White,White,White,
		White,White,White,White,White,White,Black,Black,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,Black,Black,White,White,White,White,
		White,White,White,White,White,White,White,White,Black,Black,White,White,Black,Black,White,White,White,White,White,White,White,White,White,White,Black,Black,White,White,White,White,White,White,
		White,White,White,White,White,White,White,White,White,Black,Black,Black,White,White,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,White,White,White,White,White,White,White,White,
		White,White,White,White,White,White,White,White,White,White,White,Black,White,White,Black,White,White,White,White,White,White,Black,White,White,White,White,White,White,White,White,White,White,
		White,White,White,White,White,White,White,White,White,White,White,Black,White,White,White,White,White,White,White,White,White,White,Black,White,White,White,White,White,White,White,White,White,
		White,White,White,White,White,White,White,White,White,White,White,White,Black,White,White,White,White,White,White,White,White,White,White,Black,White,White,White,White,White,White,White,White,
		White,White,White,White,White,White,White,White,White,White,White,White,White,Black,White,White,White,White,White,White,White,White,White,White,Black,White,White,White,White,White,White,White,
		White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White
	}
};
const struct tamagotchi_bmp frame3 = {
	32, 31,
	{
		White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,
		White,White,White,White,White,Black,Black,Black,Black,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,Black,Black,Black,Black,White,White,White,White,
		White,White,White,White,Black,Black,Black,Black,Black,Black,White,White,White,White,White,White,White,White,White,White,White,White,White,Black,Black,Black,Black,Black,Black,White,White,White,
		White,White,White,Black,Black,Black,Black,Black,Black,Black,Black,White,White,White,White,White,White,White,White,White,White,White,Black,Black,Black,Black,Black,Black,Black,Black,White,White,
		White,White,White,Black,Black,Black,Black,Black,Black,Black,Black,White,White,White,White,White,White,White,White,White,White,White,Black,Black,Black,Black,Black,Black,Black,Black,White,White,
		White,White,White,Black,Black,Black,Black,Black,Black,Black,Black,White,White,White,White,White,White,White,White,White,White,White,Black,Black,Black,Black,Black,Black,Black,Black,White,White,
		White,White,White,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,White,White,
		White,White,White,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,White,White,
		White,White,White,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,White,White,
		White,White,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,White,White,
		White,White,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,White,White,
		White,Black,Black,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,Black,Black,White,
		White,Black,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,Black,White,
		White,Black,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,Black,White,
		White,Black,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,Black,White,
		White,Black,White,White,White,White,Black,Black,Black,White,White,White,White,White,White,White,White,White,White,White,White,White,White,Black,Black,Black,White,White,White,White,Black,White,
		White,Black,White,White,White,Black,Black,Black,Black,Black,White,White,White,White,White,White,White,White,White,White,White,White,Black,Black,Black,Black,Black,White,White,White,Black,White,
		White,Black,White,White,Black,Black,White,White,White,White,Black,White,White,White,White,White,White,White,White,White,White,Black,White,White,White,White,Black,Black,White,White,Black,White,
		White,Black,White,White,Black,Black,White,White,White,White,Black,White,White,White,White,White,White,White,White,White,White,Black,White,White,White,White,Black,Black,White,White,Black,White,
		White,Black,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,Black,White,
		White,Black,White,White,White,Black,Black,Black,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,Black,Black,Black,White,White,White,Black,White,
		White,Black,White,White,Black,White,White,White,Black,White,White,White,Black,White,White,White,White,White,White,Black,White,White,White,Black,White,White,White,Black,White,White,Black,White,
		White,Black,White,White,Black,White,White,White,Black,White,White,White,White,Black,Black,Black,Black,Black,Black,White,White,White,White,Black,White,White,White,Black,White,White,Black,White,
		White,Black,White,White,Black,White,White,White,Black,White,White,White,White,Black,Black,Black,Black,Black,Black,White,White,White,White,Black,White,White,White,Black,White,White,Black,White,
		White,White,Black,White,White,Black,Black,Black,White,White,White,White,White,Black,Black,Black,Black,Black,Black,White,White,White,White,White,Black,Black,Black,White,White,Black,White,White,
		White,White,White,Black,Black,White,White,White,White,White,White,White,White,White,Black,Black,Black,Black,White,White,White,White,White,White,White,White,White,Black,Black,White,White,White,
		White,White,White,White,White,Black,Black,White,White,White,White,Black,Black,White,White,White,White,White,White,Black,Black,White,White,White,White,Black,Black,White,White,White,White,White,
		White,White,White,White,White,White,White,Black,Black,Black,Black,White,White,Black,Black,Black,Black,Black,Black,White,White,Black,Black,Black,Black,White,White,White,White,White,White,White,
		White,White,White,White,White,White,White,White,White,Black,Black,White,White,Black,White,White,White,White,Black,White,White,Black,Black,White,White,White,White,White,White,White,White,White,
		White,White,White,White,White,White,White,White,White,Black,White,White,White,Black,White,White,White,White,Black,White,White,White,Black,White,White,White,White,White,White,White,White,White,
		White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White
	}
};

const struct tamagotchi_bmp frame4 = {
	32, 31,
	{
		White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,
		White,White,Black,Black,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,
		White,White,Black,Black,White,White,White,White,White,White,White,Black,Black,Black,Black,White,White,White,White,White,White,White,Black,Black,Black,Black,White,White,White,White,White,White,
		White,White,Black,Black,White,White,White,White,White,White,Black,Black,Black,Black,Black,Black,White,White,White,White,White,Black,Black,Black,Black,Black,Black,White,White,White,White,White,
		White,White,Black,Black,White,White,White,White,White,Black,Black,Black,Black,Black,Black,Black,White,White,White,White,White,Black,Black,Black,Black,Black,Black,Black,White,White,White,White,
		White,White,Black,Black,White,White,White,White,White,Black,Black,Black,Black,Black,Black,Black,White,White,White,White,White,Black,Black,Black,Black,Black,Black,Black,White,White,White,White,
		White,White,White,White,White,White,White,White,White,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,White,White,White,White,
		White,White,Black,Black,White,White,White,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,White,White,White,White,
		White,White,Black,Black,White,White,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,White,White,White,White,
		White,White,White,White,White,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,White,White,White,
		White,White,White,White,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,White,White,
		White,White,White,White,Black,White,White,White,Black,Black,White,White,White,White,White,White,White,White,White,White,White,White,Black,Black,White,White,White,Black,Black,Black,White,White,
		White,White,White,Black,White,White,White,White,White,Black,Black,Black,White,White,White,White,White,White,White,White,Black,Black,Black,White,White,White,White,White,White,Black,Black,White,
		White,White,White,Black,White,White,White,White,White,White,White,Black,Black,Black,White,White,White,White,White,Black,Black,Black,White,White,White,White,White,White,White,White,Black,White,
		White,White,White,Black,White,White,White,White,Black,Black,Black,White,White,Black,Black,White,White,White,Black,Black,White,Black,Black,Black,White,White,White,White,White,White,Black,White,
		White,White,White,Black,White,White,White,White,Black,Black,Black,White,White,White,White,White,White,White,White,White,White,Black,Black,Black,White,White,White,White,White,White,Black,White,
		White,White,White,Black,White,White,White,White,Black,Black,Black,White,White,White,White,White,White,White,White,White,White,Black,Black,Black,White,White,White,White,White,White,Black,White,
		White,White,White,Black,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,Black,White,
		White,White,White,Black,White,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,White,Black,White,
		White,White,White,Black,White,Black,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,Black,White,Black,White,
		White,White,White,White,Black,Black,White,Black,Black,Black,White,White,White,Black,Black,Black,Black,White,Black,White,Black,White,Black,White,Black,Black,Black,White,Black,Black,White,White,
		White,White,White,White,Black,Black,White,White,Black,White,White,White,White,Black,White,White,Black,White,Black,White,Black,White,Black,White,White,Black,White,White,Black,Black,White,White,
		White,White,White,White,White,Black,White,White,Black,White,White,White,White,Black,White,White,Black,White,Black,White,Black,White,Black,White,White,Black,White,White,Black,White,White,White,
		White,White,White,White,White,Black,White,White,Black,White,White,White,White,Black,White,Black,White,White,Black,White,Black,White,Black,White,White,Black,White,White,Black,White,White,White,
		White,White,White,White,White,Black,White,Black,Black,Black,White,White,White,Black,Black,White,Black,White,Black,Black,Black,White,Black,White,White,Black,White,White,Black,White,White,White,
		White,White,White,White,White,Black,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,Black,White,White,White,
		White,White,White,White,White,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,White,White,White,
		White,White,White,White,White,White,White,White,Black,Black,White,Black,White,White,White,White,White,White,White,White,White,White,Black,White,Black,White,White,White,White,White,White,White,
		White,White,White,White,White,White,White,White,White,Black,Black,Black,Black,White,White,White,White,White,White,White,White,White,Black,Black,Black,White,White,White,White,White,White,White,
		White,White,White,White,White,White,White,White,White,White,White,Black,White,Black,White,White,White,White,White,White,White,White,Black,White,White,White,White,White,White,White,White,White,
		White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White
	}
};


const struct tamagotchi_bmp battery0 = {
	31, 16,
	{
		White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,
		White,White,White,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,White,White,White,White,White,White,
		White,White,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,White,White,White,White,
		White,Black,Black,Black,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,Black,Black,Black,Black,White,White,White,
		White,Black,Black,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,Black,Black,White,White,White,
		White,Black,Black,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,Black,Black,Black,Black,White,
		White,Black,Black,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,Black,Black,Black,Black,White,
		White,Black,Black,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,Black,Black,Black,Black,White,
		White,Black,Black,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,Black,Black,Black,Black,White,
		White,Black,Black,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,Black,Black,Black,Black,White,
		White,Black,Black,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,Black,Black,Black,Black,White,
		White,Black,Black,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,Black,Black,White,White,White,
		White,Black,Black,Black,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,Black,Black,Black,Black,White,White,White,
		White,White,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,White,White,White,White,
		White,White,White,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,White,White,White,White,White,White,
		White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White
	}
};
const struct tamagotchi_bmp battery1 = {
	31, 16,
	{
		White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,
		White,White,White,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,White,White,White,White,White,White,
		White,White,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,White,White,White,White,
		White,Black,Black,Black,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,Black,Black,Black,Black,White,White,White,
		White,Black,Black,White,White,Black,Black,Black,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,Black,Black,White,White,White,
		White,Black,Black,White,White,Black,Black,Black,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,Black,Black,Black,Black,White,
		White,Black,Black,White,White,Black,Black,Black,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,Black,Black,Black,Black,White,
		White,Black,Black,White,White,Black,Black,Black,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,Black,Black,Black,Black,White,
		White,Black,Black,White,White,Black,Black,Black,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,Black,Black,Black,Black,White,
		White,Black,Black,White,White,Black,Black,Black,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,Black,Black,Black,Black,White,
		White,Black,Black,White,White,Black,Black,Black,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,Black,Black,Black,Black,White,
		White,Black,Black,White,White,Black,Black,Black,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,Black,Black,White,White,White,
		White,Black,Black,Black,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,Black,Black,Black,Black,White,White,White,
		White,White,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,White,White,White,White,
		White,White,White,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,White,White,White,White,White,White,
		White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White
	}
};
const struct tamagotchi_bmp battery2 = {
	31, 16,
	{
		White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,
		White,White,White,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,White,White,White,White,White,White,
		White,White,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,White,White,White,White,
		White,Black,Black,Black,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,Black,Black,Black,Black,White,White,White,
		White,Black,Black,White,White,Black,Black,Black,White,White,Black,Black,Black,White,White,White,White,White,White,White,White,White,White,White,White,White,Black,Black,White,White,White,
		White,Black,Black,White,White,Black,Black,Black,White,White,Black,Black,Black,White,White,White,White,White,White,White,White,White,White,White,White,White,Black,Black,Black,Black,White,
		White,Black,Black,White,White,Black,Black,Black,White,White,Black,Black,Black,White,White,White,White,White,White,White,White,White,White,White,White,White,Black,Black,Black,Black,White,
		White,Black,Black,White,White,Black,Black,Black,White,White,Black,Black,Black,White,White,White,White,White,White,White,White,White,White,White,White,White,Black,Black,Black,Black,White,
		White,Black,Black,White,White,Black,Black,Black,White,White,Black,Black,Black,White,White,White,White,White,White,White,White,White,White,White,White,White,Black,Black,Black,Black,White,
		White,Black,Black,White,White,Black,Black,Black,White,White,Black,Black,Black,White,White,White,White,White,White,White,White,White,White,White,White,White,Black,Black,Black,Black,White,
		White,Black,Black,White,White,Black,Black,Black,White,White,Black,Black,Black,White,White,White,White,White,White,White,White,White,White,White,White,White,Black,Black,Black,Black,White,
		White,Black,Black,White,White,Black,Black,Black,White,White,Black,Black,Black,White,White,White,White,White,White,White,White,White,White,White,White,White,Black,Black,White,White,White,
		White,Black,Black,Black,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,Black,Black,Black,Black,White,White,White,
		White,White,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,White,White,White,White,
		White,White,White,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,White,White,White,White,White,White,
		White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White
	}
};
const struct tamagotchi_bmp battery3 = {
	31, 16,
	{
		White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,
		White,White,White,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,White,White,White,White,White,White,
		White,White,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,White,White,White,White,
		White,Black,Black,Black,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,Black,Black,Black,Black,White,White,White,
		White,Black,Black,White,White,Black,Black,Black,White,White,Black,Black,Black,White,White,Black,Black,Black,White,White,White,White,White,White,White,White,Black,Black,White,White,White,
		White,Black,Black,White,White,Black,Black,Black,White,White,Black,Black,Black,White,White,Black,Black,Black,White,White,White,White,White,White,White,White,Black,Black,Black,Black,White,
		White,Black,Black,White,White,Black,Black,Black,White,White,Black,Black,Black,White,White,Black,Black,Black,White,White,White,White,White,White,White,White,Black,Black,Black,Black,White,
		White,Black,Black,White,White,Black,Black,Black,White,White,Black,Black,Black,White,White,Black,Black,Black,White,White,White,White,White,White,White,White,Black,Black,Black,Black,White,
		White,Black,Black,White,White,Black,Black,Black,White,White,Black,Black,Black,White,White,Black,Black,Black,White,White,White,White,White,White,White,White,Black,Black,Black,Black,White,
		White,Black,Black,White,White,Black,Black,Black,White,White,Black,Black,Black,White,White,Black,Black,Black,White,White,White,White,White,White,White,White,Black,Black,Black,Black,White,
		White,Black,Black,White,White,Black,Black,Black,White,White,Black,Black,Black,White,White,Black,Black,Black,White,White,White,White,White,White,White,White,Black,Black,Black,Black,White,
		White,Black,Black,White,White,Black,Black,Black,White,White,Black,Black,Black,White,White,Black,Black,Black,White,White,White,White,White,White,White,White,Black,Black,White,White,White,
		White,Black,Black,Black,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,Black,Black,Black,Black,White,White,White,
		White,White,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,White,White,White,White,
		White,White,White,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,White,White,White,White,White,White,
		White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White
	}
};
const struct tamagotchi_bmp battery4 = {
	31, 16,
	{
		White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,
		White,White,White,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,White,White,White,White,White,White,
		White,White,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,White,White,White,White,
		White,Black,Black,Black,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,Black,Black,Black,Black,White,White,White,
		White,Black,Black,White,White,Black,Black,Black,White,White,Black,Black,Black,White,White,Black,Black,Black,White,White,Black,Black,Black,White,White,White,Black,Black,White,White,White,
		White,Black,Black,White,White,Black,Black,Black,White,White,Black,Black,Black,White,White,Black,Black,Black,White,White,Black,Black,Black,White,White,White,Black,Black,Black,Black,White,
		White,Black,Black,White,White,Black,Black,Black,White,White,Black,Black,Black,White,White,Black,Black,Black,White,White,Black,Black,Black,White,White,White,Black,Black,Black,Black,White,
		White,Black,Black,White,White,Black,Black,Black,White,White,Black,Black,Black,White,White,Black,Black,Black,White,White,Black,Black,Black,White,White,White,Black,Black,Black,Black,White,
		White,Black,Black,White,White,Black,Black,Black,White,White,Black,Black,Black,White,White,Black,Black,Black,White,White,Black,Black,Black,White,White,White,Black,Black,Black,Black,White,
		White,Black,Black,White,White,Black,Black,Black,White,White,Black,Black,Black,White,White,Black,Black,Black,White,White,Black,Black,Black,White,White,White,Black,Black,Black,Black,White,
		White,Black,Black,White,White,Black,Black,Black,White,White,Black,Black,Black,White,White,Black,Black,Black,White,White,Black,Black,Black,White,White,White,Black,Black,Black,Black,White,
		White,Black,Black,White,White,Black,Black,Black,White,White,Black,Black,Black,White,White,Black,Black,Black,White,White,Black,Black,Black,White,White,White,Black,Black,White,White,White,
		White,Black,Black,Black,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,Black,Black,Black,Black,White,White,White,
		White,White,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,White,White,White,White,
		White,White,White,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,Black,White,White,White,White,White,White,
		White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White
	}
};
	

const struct tamagotchi_bmp meal = {
	20, 20,
	{
		White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,
		White,White,White,White,White,White,White,White,White,Black,Black,Black,Black,Black,Black,Black,Black,White,White,White,
		White,White,White,White,White,White,White,White,Black,White,White,White,White,White,White,White,White,Black,White,White,
		White,White,White,White,White,White,White,Black,White,White,Black,Black,Black,Black,White,Black,White,White,Black,White,
		White,White,White,White,White,White,Black,White,White,Black,White,White,White,White,White,White,White,White,Black,White,
		White,White,White,White,White,White,Black,White,Black,White,White,White,White,White,White,White,White,White,Black,White,
		White,White,White,White,White,Black,White,White,Black,White,White,White,White,White,White,White,White,White,Black,White,
		White,White,White,White,White,Black,White,White,Black,White,White,White,White,White,White,White,White,White,Black,White,
		White,White,White,White,White,Black,White,White,White,White,White,White,White,White,White,White,White,White,Black,White,
		White,White,White,White,White,Black,White,White,White,White,White,White,White,White,White,White,White,White,Black,White,
		White,White,White,White,White,Black,White,White,White,White,White,White,White,White,White,White,White,White,Black,White,
		White,White,White,White,White,Black,White,White,White,White,White,White,White,White,White,White,White,Black,White,White,
		White,White,White,White,White,Black,White,White,White,White,White,White,White,White,White,White,Black,White,White,White,
		White,White,White,White,Black,White,Black,White,White,White,White,White,White,White,Black,Black,White,White,White,White,
		White,Black,Black,Black,White,White,White,Black,Black,Black,Black,Black,Black,Black,White,White,White,White,White,White,
		White,Black,White,White,White,White,Black,White,White,White,White,White,White,White,White,White,White,White,White,White,
		White,Black,White,White,White,Black,White,White,White,White,White,White,White,White,White,White,White,White,White,White,
		White,White,Black,White,White,Black,White,White,White,White,White,White,White,White,White,White,White,White,White,White,
		White,White,White,Black,Black,Black,White,White,White,White,White,White,White,White,White,White,White,White,White,White,
		White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White
	}
};
const struct tamagotchi_bmp snack = {
	16, 16,
	{
		White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,
		White,White,White,White,White,White,White,Black,Black,Black,Black,Black,White,White,White,White,
		White,White,White,White,White,Black,Black,White,White,White,White,White,Black,White,White,White,
		White,White,White,White,Black,White,White,White,Black,Black,White,White,White,Black,White,White,
		White,White,White,Black,White,White,White,White,Black,Black,White,White,White,White,Black,White,
		White,White,Black,White,White,White,White,White,White,White,White,White,White,White,Black,White,
		White,White,Black,White,White,White,White,White,White,White,White,Black,White,White,Black,White,
		White,Black,White,White,Black,Black,White,White,White,White,White,White,White,White,Black,White,
		White,Black,White,White,Black,Black,White,White,White,Black,Black,White,White,White,Black,White,
		White,Black,White,White,White,White,White,White,White,Black,Black,White,White,Black,Black,White,
		White,Black,White,White,White,White,White,White,White,White,White,White,Black,Black,Black,White,
		White,White,Black,White,White,Black,Black,White,White,White,White,Black,Black,Black,White,White,
		White,White,Black,White,White,White,White,White,White,White,Black,Black,Black,White,White,White,
		White,White,White,Black,White,White,White,White,Black,Black,Black,Black,White,White,White,White,
		White,White,White,White,Black,Black,Black,Black,Black,Black,White,White,White,White,White,White,
		White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White
	}
};
const struct tamagotchi_bmp hearth = {
	17, 16,
	{
		White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,
		White,White,Black,Black,Black,Black,White,White,White,White,White,Black,Black,Black,Black,White,White,
		White,Black,White,White,White,White,Black,White,White,White,Black,White,White,White,White,Black,White,
		Black,White,White,Black,Black,White,White,Black,White,Black,White,White,White,White,White,White,Black,
		Black,White,Black,Black,White,White,White,White,Black,White,White,White,White,White,White,White,Black,
		Black,White,Black,White,White,White,White,White,White,White,White,White,White,White,White,White,Black,
		Black,White,Black,White,White,White,White,White,White,White,White,White,White,White,White,White,Black,
		Black,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,Black,
		White,Black,White,White,White,White,White,White,White,White,White,White,White,White,White,Black,White,
		White,White,Black,White,White,White,White,White,White,White,White,White,White,White,Black,White,White,
		White,White,White,Black,White,White,White,White,White,White,White,White,White,Black,White,White,White,
		White,White,White,White,Black,White,White,White,White,White,White,White,Black,White,White,White,White,
		White,White,White,White,White,Black,White,White,White,White,White,Black,White,White,White,White,White,
		White,White,White,White,White,White,Black,White,White,White,Black,White,White,White,White,White,White,
		White,White,White,White,White,White,White,Black,White,Black,White,White,White,White,White,White,White,
		White,White,White,White,White,White,White,White,Black,White,White,White,White,White,White,White,White
	}
};

const struct tamagotchi_bmp volume0 = {
	16, 16,
	{
		White,White,White,White,White,White,White,White,Black,White,White,White,White,White,White,White,
		White,White,White,White,White,White,White,Black,Black,White,White,White,White,White,White,White,
		White,White,White,White,White,White,Black,Black,Black,White,White,White,White,White,White,White,
		White,White,White,White,White,Black,Black,Black,Black,White,White,White,White,White,White,White,
		White,White,White,White,Black,Black,Black,Black,Black,White,White,White,White,White,White,White,
		Black,Black,Black,Black,Black,Black,Black,Black,Black,White,Black,White,White,White,White,Black,
		Black,Black,Black,Black,Black,Black,Black,Black,Black,White,White,Black,White,White,Black,White,
		Black,Black,Black,Black,Black,Black,Black,Black,Black,White,White,White,White,Black,White,White,
		Black,Black,Black,Black,Black,Black,Black,Black,Black,White,White,White,Black,White,White,White,
		Black,Black,Black,Black,Black,Black,Black,Black,Black,White,White,Black,White,White,Black,White,
		Black,Black,Black,Black,Black,Black,Black,Black,Black,White,Black,White,White,White,White,Black,
		White,White,White,White,Black,Black,Black,Black,Black,White,White,White,White,White,White,White,
		White,White,White,White,White,Black,Black,Black,Black,White,White,White,White,White,White,White,
		White,White,White,White,White,White,Black,Black,Black,White,White,White,White,White,White,White,
		White,White,White,White,White,White,White,Black,Black,White,White,White,White,White,White,White,
		White,White,White,White,White,White,White,White,Black,White,White,White,White,White,White,White
	}
};
const struct tamagotchi_bmp volume1 = {
	16, 16,
	{
		White,White,White,White,White,White,White,White,Black,White,White,White,White,White,White,White,
		White,White,White,White,White,White,White,Black,Black,White,White,White,White,White,White,White,
		White,White,White,White,White,White,Black,Black,Black,White,White,White,White,White,White,White,
		White,White,White,White,White,Black,Black,Black,Black,White,White,White,White,White,White,White,
		White,White,White,White,Black,Black,Black,Black,Black,White,White,White,White,White,White,White,
		Black,Black,Black,Black,Black,Black,Black,Black,Black,White,Black,White,White,White,White,White,
		Black,Black,Black,Black,Black,Black,Black,Black,Black,White,White,Black,White,White,White,White,
		Black,Black,Black,Black,Black,Black,Black,Black,Black,White,White,Black,White,White,White,White,
		Black,Black,Black,Black,Black,Black,Black,Black,Black,White,White,Black,White,White,White,White,
		Black,Black,Black,Black,Black,Black,Black,Black,Black,White,White,Black,White,White,White,White,
		Black,Black,Black,Black,Black,Black,Black,Black,Black,White,Black,White,White,White,White,White,
		White,White,White,White,Black,Black,Black,Black,Black,White,White,White,White,White,White,White,
		White,White,White,White,White,Black,Black,Black,Black,White,White,White,White,White,White,White,
		White,White,White,White,White,White,Black,Black,Black,White,White,White,White,White,White,White,
		White,White,White,White,White,White,White,Black,Black,White,White,White,White,White,White,White,
		White,White,White,White,White,White,White,White,Black,White,White,White,White,White,White,White
	}
};
const struct tamagotchi_bmp volume2 = {
	16, 16,
	{
		White,White,White,White,White,White,White,White,Black,White,White,White,White,White,White,White,
		White,White,White,White,White,White,White,Black,Black,White,White,White,White,White,White,White,
		White,White,White,White,White,White,Black,Black,Black,White,White,White,White,White,White,White,
		White,White,White,White,White,Black,Black,Black,Black,White,White,Black,White,White,White,White,
		White,White,White,White,Black,Black,Black,Black,Black,White,White,White,Black,White,White,White,
		Black,Black,Black,Black,Black,Black,Black,Black,Black,White,Black,White,White,Black,White,White,
		Black,Black,Black,Black,Black,Black,Black,Black,Black,White,White,Black,White,Black,White,White,
		Black,Black,Black,Black,Black,Black,Black,Black,Black,White,White,Black,White,Black,White,White,
		Black,Black,Black,Black,Black,Black,Black,Black,Black,White,White,Black,White,Black,White,White,
		Black,Black,Black,Black,Black,Black,Black,Black,Black,White,White,Black,White,Black,White,White,
		Black,Black,Black,Black,Black,Black,Black,Black,Black,White,Black,White,White,Black,White,White,
		White,White,White,White,Black,Black,Black,Black,Black,White,White,White,Black,White,White,White,
		White,White,White,White,White,Black,Black,Black,Black,White,White,Black,White,White,White,White,
		White,White,White,White,White,White,Black,Black,Black,White,White,White,White,White,White,White,
		White,White,White,White,White,White,White,Black,Black,White,White,White,White,White,White,White,
		White,White,White,White,White,White,White,White,Black,White,White,White,White,White,White,White
	}
};
const struct tamagotchi_bmp volume3 = {
	16, 16,
	{
		White,White,White,White,White,White,White,White,Black,White,White,White,White,White,White,White,
		White,White,White,White,White,White,White,Black,Black,White,White,White,Black,White,White,White,
		White,White,White,White,White,White,Black,Black,Black,White,White,White,White,Black,White,White,
		White,White,White,White,White,Black,Black,Black,Black,White,White,Black,White,White,Black,White,
		White,White,White,White,Black,Black,Black,Black,Black,White,White,White,Black,White,White,Black,
		Black,Black,Black,Black,Black,Black,Black,Black,Black,White,Black,White,White,Black,White,Black,
		Black,Black,Black,Black,Black,Black,Black,Black,Black,White,White,Black,White,Black,White,Black,
		Black,Black,Black,Black,Black,Black,Black,Black,Black,White,White,Black,White,Black,White,Black,
		Black,Black,Black,Black,Black,Black,Black,Black,Black,White,White,Black,White,Black,White,Black,
		Black,Black,Black,Black,Black,Black,Black,Black,Black,White,White,Black,White,Black,White,Black,
		Black,Black,Black,Black,Black,Black,Black,Black,Black,White,Black,White,White,Black,White,Black,
		White,White,White,White,Black,Black,Black,Black,Black,White,White,White,Black,White,White,Black,
		White,White,White,White,White,Black,Black,Black,Black,White,White,Black,White,White,Black,White,
		White,White,White,White,White,White,Black,Black,Black,White,White,White,White,Black,White,White,
		White,White,White,White,White,White,White,Black,Black,White,White,White,Black,White,White,White,
		White,White,White,White,White,White,White,White,Black,White,White,White,White,White,White,White
	}
};
const struct tamagotchi_sound init_sound = {
	6,
	{
		{g4b, time_semicroma},
		{a4, time_semicroma},
		{b4, time_semicroma},
		{c5, time_semicroma},
		{c5, time_semicroma},
		{c5, time_semicroma},
	}
};
const struct tamagotchi_sound click_sound = {
	1,
	{
		{a4, time_semicroma}
	}
};
const struct tamagotchi_sound eat_sound = {
	3,
	{
		{b3, time_semicroma},
		{d4, time_semicroma},
		{e4, time_semicroma}
	}
};
const struct tamagotchi_sound runaway_sound = {
	8,
	{
		{d4, time_semicroma},
		{c4, time_semicroma},
		{b3, time_semicroma},
		{c4, time_semicroma},
		{b3, time_semicroma},
		{a3b, time_semicroma},
		{a3, time_semicroma},
		{g3, time_semicroma}
	}
};
const struct tamagotchi_sound cuddle_sound = {
	8,
	{
		{g4b, time_semicroma},
		{a4, time_semicroma},
		{b4, time_semicroma},
		{a4, time_semicroma},
		{g4b, time_semicroma},
		{b4, time_semicroma},
		{a4, time_semicroma},
		{a4, time_semicroma}
	}
};


volatile int gone = 0;
volatile int selected = 0;
int running_away = 0;
int volume = 0;
const struct tamagotchi_sound *playing;

void timer_age(uint8_t enable, uint8_t reset) {
	if(enable == 1) {
		if(reset == 1) {
			reset_timer(0);
		}
		init_timer(0, 0x017D7840);	// (1s * 25Mhz)
		enable_timer(0);
	} else if(enable == 0) {
		disable_timer(0);
	}
}

void timer_happiness_satiety(uint8_t enable, uint8_t reset) {
	if(enable == 1) {
		if(reset == 1) {
			reset_timer(1);
		}
		init_timer(1, 0x07735940);	// (5s * 25Mhz)
		enable_timer(1);
	} else if(enable == 0) {
		disable_timer(1);
	}
}

void timer_joystick_touchpanel(uint8_t enable, uint8_t reset) {
	if(enable == 1) {
		if(reset == 1) {
			reset_RIT();
		}
		init_RIT(0x004C4B40);			  // (50ms * 100MHz)
		enable_RIT();	
	} else if(enable == 0) {
		disable_RIT();
	}
}

void joystick_selection(void) {
	timer_joystick_touchpanel(0, 0);
	if(gone == 1) {
		start_tamagotchi();
	} else if(gone == 0) {
		play_sound(&click_sound, 0);
		if(selected == -1) {
			give_snack();
			timer_joystick_touchpanel(1, 1);
		} else if(selected == 1) {
			give_meal();
			timer_joystick_touchpanel(1, 1);
		}
	}
}
	
void buttons_selection(int8_t direction) {
	selected = direction;
	
	if(gone == 1) {
		LCD_DrawLine(0, 280, 120, 280, White);	 		 // up sx
		LCD_DrawLine(0, 279, 120, 279, White);	 		 // up sx
		
		LCD_DrawLine(120, 280, 240, 280, White); 		 // up dx
		LCD_DrawLine(120, 279, 240, 279, White); 		 // up dx
		
		
		LCD_DrawLine(118, 280, 118, 320, White); 	 	 // sep sx
		LCD_DrawLine(119, 280, 119, 320, White); 	 	 // sep sx
		
		LCD_DrawLine(120, 280, 120, 320, White); 		 // sep dx
		LCD_DrawLine(121, 280, 121, 320, White); 		 // sep dx
		
		
		LCD_DrawLine(0, 280, 240, 280, Red);
		LCD_DrawLine(0, 279, 240, 279, Red);
		
		GUI_Text(35, 295, (uint8_t *) "Snack", White, White);
		GUI_Text(165, 295, (uint8_t *) "Meal", White, White);
		GUI_Text(100, 295, (uint8_t *) "Reset", Red, White);
	} else if(gone == 0) {
		if(selected == -1) {
			GUI_Text(35, 295, (uint8_t *) "Snack", Red, White);
			GUI_Text(165, 295, (uint8_t *) "Meal", Black, White);
			LCD_DrawLine(0, 280, 120, 280, Red);	 		 // up sx
			LCD_DrawLine(0, 279, 120, 279, Red);	 		 // up sx
			
			LCD_DrawLine(120, 280, 240, 280, Black); 		 // up dx
			LCD_DrawLine(120, 279, 240, 279, Black); 		 // up dx
			
			
			LCD_DrawLine(118, 280, 118, 320, Red); 	 	 // sep sx
			LCD_DrawLine(119, 280, 119, 320, Red); 	 	 // sep sx
			
			LCD_DrawLine(120, 280, 120, 320, Black); 		 // sep dx
			LCD_DrawLine(121, 280, 121, 320, Black); 		 // sep dx
		} else if(selected == 1){
			GUI_Text(35, 295, (uint8_t *) "Snack", Black, White);
			GUI_Text(165, 295, (uint8_t *) "Meal", Red, White);
			LCD_DrawLine(0, 280, 120, 280, Black);	 		 // up sx
			LCD_DrawLine(0, 279, 120, 279, Black);	 		 // up sx
			
			LCD_DrawLine(120, 280, 240, 280, Red); 		 // up dx
			LCD_DrawLine(120, 279, 240, 279, Red); 		 // up dx
			
			
			LCD_DrawLine(118, 280, 118, 320, Black); 	 	 // sep sx
			LCD_DrawLine(119, 280, 119, 320, Black); 	 	 // sep sx
			
			LCD_DrawLine(120, 280, 120, 320, Red); 		 // sep dx
			LCD_DrawLine(121, 280, 121, 320, Red); 		 // sep dx
		}
	}
}

void start_tamagotchi(void) {
	gone = 0;
	running_away = 0;
	ADC_first_read = 0;
	LCD_Clear(White);
	init_ui();
	set_happiness(+4);
	set_satiety(+4);
	display_tamagotchi(0, TAMAGOTCHI_OFFSET_X, TAMAGOTCHI_OFFSET_Y, 0);
	timer_age(1, 0);
	timer_happiness_satiety(1, 0);
	timer_joystick_touchpanel(1, 0);
	play_sound(&init_sound, 0);
}

void give_meal(void) {
	int move = TAMAGOTCHI_OFFSET_X;
	int step = 5;
	
	draw_to_screen(&meal, TREAT_OFFSET_X, TREAT_OFFSET_Y, 2, 0);
	while(move > TREAT_OFFSET_X) {
		display_tamagotchi(2, move, TAMAGOTCHI_OFFSET_Y, 0);
		move -= step;
	}
	set_satiety(+1);
	play_sound(&eat_sound, 0);
	draw_to_screen(&meal, TREAT_OFFSET_X, TREAT_OFFSET_Y, 2, 1);
	while(move <= TAMAGOTCHI_OFFSET_X) {
		display_tamagotchi(3, move, TAMAGOTCHI_OFFSET_Y, 0);
		move += step;
	}
	timer_happiness_satiety(1, 1);
}

void give_snack(void) {
	int move = TAMAGOTCHI_OFFSET_X;
	int step = 5;
	
	draw_to_screen(&snack, TREAT_OFFSET_X, TREAT_OFFSET_Y, 2, 0);
	while(move > TREAT_OFFSET_X) {
		display_tamagotchi(2, move, TAMAGOTCHI_OFFSET_Y, 0);
		move -= step;
	}
	set_happiness(+1);
	play_sound(&eat_sound, 0);
	draw_to_screen(&snack, TREAT_OFFSET_X, TREAT_OFFSET_Y, 2, 1);
	while(move <= TAMAGOTCHI_OFFSET_X) {
		display_tamagotchi(3, move, TAMAGOTCHI_OFFSET_Y, 0);
		move += step;
	}
	timer_happiness_satiety(1, 1);
}

void cuddle(void) {
	int move = TAMAGOTCHI_OFFSET_Y;
	int step = 5;
	int dx = 200, sx = 5;
	int top = 150, center = 200, bottom = 230;
	
	timer_joystick_touchpanel(0, 0);
	set_happiness(+1);
	play_sound(&cuddle_sound, 0);
	
	draw_to_screen(&hearth, sx, bottom, 2, 0);
	draw_to_screen(&hearth, sx, top, 2, 0);
	draw_to_screen(&hearth, dx, center, 2, 0);
	
	while(move > TAMAGOTCHI_OFFSET_Y - 10) {
		display_tamagotchi(3, TAMAGOTCHI_OFFSET_X, move, 0);
		move -= step;
	}
	
	draw_to_screen(&hearth, sx, bottom, 2,1);
	draw_to_screen(&hearth, sx, top, 2, 1);
	draw_to_screen(&hearth, dx, center, 2, 1);
	draw_to_screen(&hearth, dx, bottom, 2, 0);
	draw_to_screen(&hearth, dx, top, 2, 0);
	draw_to_screen(&hearth, sx, center, 2, 0);
	
	while(move <= TAMAGOTCHI_OFFSET_Y) {
		display_tamagotchi(3, TAMAGOTCHI_OFFSET_X, move, 0);
		move += step;
	}
	
	draw_to_screen(&hearth, dx, bottom, 2, 1);
	draw_to_screen(&hearth, dx, top, 2, 1);
	draw_to_screen(&hearth, sx, center, 2, 1);
	
	timer_joystick_touchpanel(1, 1);
	timer_happiness_satiety(1, 1);
}
	
void runaway(void) {
	int move = TAMAGOTCHI_OFFSET_X;
	int step = 5;
	
	timer_joystick_touchpanel(0, 0);
	timer_age(0, 0);
	timer_happiness_satiety(0, 0);
		
	play_sound(&runaway_sound, 0);
	
	while(move < 200) {
		display_tamagotchi(4, move, TAMAGOTCHI_OFFSET_Y, 0);
		move += step;
	}
	display_tamagotchi(4, move, TAMAGOTCHI_OFFSET_Y, 1);
	
	gone = 1;
	GUI_Text(TAMAGOTCHI_OFFSET_X + 10, TAMAGOTCHI_OFFSET_Y + 20, (uint8_t *) "YOUR TAMAGOTHI HAS", Black, White);
	GUI_Text(TAMAGOTCHI_OFFSET_X + 35, TAMAGOTCHI_OFFSET_Y + 40, (uint8_t *) "LEFT YOU :(", Black, White);
	buttons_selection(-1);
	timer_joystick_touchpanel(1, 1);
}

uint8_t set_happiness(int8_t difference) {
	static int lvl = 0;
	uint16_t off_x = 30, off_y = 45, scaling = 2;
	const struct tamagotchi_bmp *img = &battery0;
	
	if((lvl + difference) < 0) {
		lvl = 0;
	} else if((lvl + difference) > 4) {
		lvl = 4;
	} else {
		lvl += difference;
	}
		
	switch(lvl) {
		case(0): {
			img = &battery0;
			break;
		}
		case(1): {
			img = &battery1;
			break;
		}
		case(2): {
			img = &battery2;
			break;
		}
		case(3): {
			img = &battery3;
			break;
		}
		case(4): {
			img = &battery4;
			break;
		}
	}
	draw_to_screen(img, off_x, off_y, scaling, 0);
	
	return (lvl == 0);
}
	
uint8_t set_satiety(int8_t difference) {
	static int lvl = 0;
	uint16_t off_x = 145, off_y = 45, scaling = 2;
	const struct tamagotchi_bmp *img = &battery0;
	
	if((lvl + difference) < 0) {
		lvl = 0;
	} else if((lvl + difference) > 4) {
		lvl = 4;
	} else {
		lvl += difference;
	}

		
	switch(lvl) {
		case(0): {
			img = &battery0;
			break;
		}
		case(1): {
			img = &battery1;
			break;
		}
		case(2): {
			img = &battery2;
			break;
		}
		case(3): {
			img = &battery3;
			break;
		}
		case(4): {
			img = &battery4;
			break;
		}
	}
		
	draw_to_screen(img, off_x, off_y, scaling, 0);
	
	return (lvl == 0);
}

void set_volume(uint8_t lvl, unsigned short val, uint8_t clear) {
	uint16_t off_x = 2, off_y = 2, scaling = 1;
	const struct tamagotchi_bmp *img = &volume0;
	
	volume = val;
	switch(lvl) {
		case(0): {
			img = &volume0;
			break;
		}
		case(1): {
			img = &volume1;
			break;
		}
		case(2): {
			img = &volume2;
			break;
		}
		case(3): {
			img = &volume3;
			break;
		}
	}
		
	draw_to_screen(img, off_x, off_y, scaling, clear);
}

void scale_happiness_satiety(void) {
	uint8_t ret_sat = 0, ret_hap = 0;
	ret_sat = set_satiety(-1);
	ret_hap = set_happiness(-1);
	running_away = ret_sat || ret_hap;
}

void age_controller(uint8_t reset) {
	static int s = 0;
	static int m = 0;
	static int h = 0;
	char age[20];
		
	if(reset == 1) {
		s = 0;
		m = 0;
		h = 0;
	} else {
		s++;
		if(s > 59) {
			s = 0;
			m++;
			if(m > 59) {
				m = 0;
				h++;
				if(h > 99) {
					h = 0;
				}
			}
		}
	}
	
	sprintf(age, "Age: %02d:%02d:%02d", h, m, s);
	GUI_Text(70, 0, (uint8_t *) age, Black, White);
}

void display_tamagotchi(uint8_t frame, uint16_t off_x, uint16_t off_y, uint8_t clear) {
	uint16_t scaling = 5;
	const struct tamagotchi_bmp *img = &frame0;
	
		switch(frame) {
		case(0): {
			img = &frame0;
			break;
		}
		case(1): {
			img = &frame1;
			break;
		}
		case(2): {
			img = &frame2;
			break;
		}
		case(3): {
			img = &frame3;
			break;
		}
		case(4): {
			img = &frame4;
			break;
		}
	}
		
	draw_to_screen(img, off_x, off_y, scaling, clear);
}

void draw_to_screen(const struct tamagotchi_bmp *img, uint16_t off_x, uint16_t off_y, uint16_t scaling, uint8_t clear) {
	int i = 0, j = 0;
	uint16_t x = 0, y = 0, color;
	
	for(i = 0; i < img->height && gone == 0; i += 1) {
		for(j = 0; j < img->width && gone == 0; j += 1) {
			if(clear == 1) {
				color = White;
			} else {
				color = img->data[(i * img->width)  + j];
			}
			LCD_DrawRectangle(x + off_x, y + off_y, scaling, scaling, color);
			x += scaling;
		}
		x = 0;
		y += scaling;
	}
}

void play_sound(const struct tamagotchi_sound *sound, uint8_t next_note) {
	static int note = 0;
	
	if(next_note == 0) {
		note = 0;
		playing = sound;
		playNote(playing->notes[note]);
	} else {
		note++;
		if(note < playing->len) {
			playNote(playing->notes[note]);
		} else {
			reset_timer(2);
			reset_timer(3);
		}
	}
}

void init_ui(void) {
	// age controller
	age_controller(1);
	
	// status
	GUI_Text(25, 25, (uint8_t *) "Happiness", Black, White);
	GUI_Text(150, 25, (uint8_t *) "Satiety", Black, White);
	
	// food
	buttons_selection(-1);
}
