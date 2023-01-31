#include <string.h>
#include "lpc17xx.h"
#include "timer.h"
#include "../GLCD/GLCD.h" 
#include "../TouchPanel/TouchPanel.h"
#include "../Tamagotchi/tamagotchi.h"

uint16_t SinTable[45] =
{
    410, 467, 523, 576, 627, 673, 714, 749, 778,
    799, 813, 819, 817, 807, 789, 764, 732, 694, 
    650, 602, 550, 495, 438, 381, 324, 270, 217,
    169, 125, 87 , 55 , 30 , 12 , 2  , 0  , 6  ,   
    20 , 41 , 70 , 105, 146, 193, 243, 297, 353
};


void TIMER0_IRQHandler (void) {
	static int flag = 0;
	
	age_controller(0);
	if(running_away) {
		runaway();
	} else {
		if(flag == 0) {
			display_tamagotchi(1, (uint16_t) TAMAGOTCHI_OFFSET_X, (uint16_t) TAMAGOTCHI_OFFSET_Y, 0);
			flag = 1;
		} else {
			display_tamagotchi(0, (uint16_t) TAMAGOTCHI_OFFSET_X, (uint16_t) TAMAGOTCHI_OFFSET_Y, 0);
			flag = 0;
		}
	}
	
  LPC_TIM0->IR = 1;			/* clear interrupt flag */
  return;
}


void TIMER1_IRQHandler (void) {
	scale_happiness_satiety();
	
  LPC_TIM1->IR = 1;			/* clear interrupt flag */
  return;
}

void TIMER2_IRQHandler (void) {
	static int sineticks=0;
	static int currentValue; 
	
	currentValue = SinTable[sineticks];
	
	if(volume == 7) {
		currentValue = 0;
	} else {
		currentValue -= 410;
		currentValue /= volume;
		currentValue += 410;
	}
	
	LPC_DAC->DACR = currentValue << 6;
	sineticks++;
	if(sineticks==45) sineticks=0;
	
  LPC_TIM2->IR = 1;			/* clear interrupt flag */
  return;
}

void TIMER3_IRQHandler (void) {
	disable_timer(2);
	play_sound((void*) 0, 1);
	
  LPC_TIM3->IR = 1;			/* clear interrupt flag */
  return;
}
