#include "MIDI.h"

#include "../timer/timer.h"

uint8_t first_sound = 0;

void playNote(NOTE note) {
	if(first_sound == 0){
		first_sound = 1;
		init_timer(2, 0x0);
		init_timer(3, 0x0);
	}
	if(note.freq != pause) {
		reset_timer(2);
		init_timer(2, note.freq);
		enable_timer(2);
	}
	reset_timer(3);
	init_timer(3, note.duration);
	enable_timer(3);
}

BOOL isNotePlaying(void) {
	return ((LPC_TIM0->TCR != 0) || (LPC_TIM1->TCR != 0));
}
