#include "LPC17xx.h"
#include "../GLCD_advanced/GLCD.h"
#include "../MIDI/MIDI.h"

#ifndef __TAMAGOTCHI_H

#define __TAMAGOTCHI_H

#define DATA_MAX_WIDTH 32
#define DATA_MAX_HEIGHT 31
#define TAMAGOTCHI_OFFSET_X 40
#define TAMAGOTCHI_OFFSET_Y 110
#define TREAT_OFFSET_X 0
#define TREAT_OFFSET_Y 230

struct tamagotchi_bmp {
	uint8_t width;
	uint8_t height;
	uint16_t data[DATA_MAX_WIDTH * DATA_MAX_HEIGHT];
};

struct tamagotchi_sound {
	uint8_t len;
	NOTE notes[8];
};

extern int volume;
extern int running_away;

void timer_age(uint8_t enable, uint8_t reset);
void timer_happiness_satiety(uint8_t enable, uint8_t reset);
void timer_joystick_touchpanel(uint8_t enable, uint8_t reset);
void joystick_selection(void);
void buttons_selection(int8_t direction);
void start_tamagotchi(void);
void give_meal(void);
void give_snack(void);
void cuddle(void);
void runaway(void);
void display_tamagotchi(uint8_t frame, uint16_t off_x, uint16_t off_y, uint8_t clear);
uint8_t set_happiness(int8_t difference);
uint8_t set_satiety(int8_t difference);
void set_volume(uint8_t lvl, unsigned short val, uint8_t clear);
void scale_happiness_satiety(void);
void age_controller(uint8_t reset);
void draw_to_screen(const struct tamagotchi_bmp *img, uint16_t off_x, uint16_t off_y, uint16_t scaling, uint8_t clear);
void play_sound(const struct tamagotchi_sound *sound, uint8_t next_note);
void init_ui(void);
	
#endif
