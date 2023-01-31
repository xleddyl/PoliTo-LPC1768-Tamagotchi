#include "lpc17xx.h"
#include "RIT.h"
#include "../Tamagotchi/tamagotchi.h"
#include "../TouchPanel/TouchPanel.h"
#include "../ADC/adc.h"

void RIT_IRQHandler (void) {
	
	// touch
	if(getDisplayPoint(&display, Read_Ads7846(), &matrix)) {
		if(
			(display.y > (TAMAGOTCHI_OFFSET_Y) && display.y < (TAMAGOTCHI_OFFSET_Y + 160)) &&
			(display.x > (TAMAGOTCHI_OFFSET_X) && display.x < (TAMAGOTCHI_OFFSET_X + 160))
		) {
			cuddle();
		}
	}
	
	// joystick
	if((LPC_GPIO1->FIOPIN & (1<<28)) == 0){
		buttons_selection(1);
	} else if((LPC_GPIO1->FIOPIN & (1<<27)) == 0){
		buttons_selection(-1);
	} else if((LPC_GPIO1->FIOPIN & (1<<25)) == 0){
		joystick_selection();
	}
	
	// potentiometer
	ADC_start_conversion();
	
	LPC_RIT->RICTRL |= 0x1;	/* clear interrupt flag */
  return;
}
