#include "LPC17xx.h"
#include "TouchPanel/TouchPanel.h"
#include "timer/timer.h"
#include "GLCD_advanced/GLCD.h"
#include "Tamagotchi/tamagotchi.h"
#include "ADC/adc.h"

#include "RIT/RIT.h"

#define SIMULATOR 1
#ifdef SIMULATOR
extern uint8_t ScaleFlag;
#endif

int main (void) {
	// system init
	SystemInit();

	// LCD and TP
	LCD_Initialization();
	ADC_init();
	TP_Init();
	TouchPanel_Calibrate();
	
  // tamagotchi
	start_tamagotchi();
	
	// power down
	LPC_SC->PCON |= 0x1;
	LPC_SC->PCON &= ~(0x2);		
	
	while (1) {
		__ASM("wfi");
  }
}
