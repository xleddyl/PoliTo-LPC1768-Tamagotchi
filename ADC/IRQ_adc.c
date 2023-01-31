/*********************************************************************************************************
**--------------File Info---------------------------------------------------------------------------------
** File name:           IRQ_adc.c
** Last modified Date:  20184-12-30
** Last Version:        V1.00
** Descriptions:        functions to manage A/D interrupts
** Correlated files:    adc.h
**--------------------------------------------------------------------------------------------------------       
*********************************************************************************************************/

#include "lpc17xx.h"
#include "adc.h"
#include "../Tamagotchi/tamagotchi.h"

/*----------------------------------------------------------------------------
  A/D IRQ: Executed when A/D Conversion is ready (signal from ADC peripheral)
 *----------------------------------------------------------------------------*/

unsigned short AD_current = 0xFFF;   
unsigned short AD_last = 0xFFF;
uint8_t ADC_first_read = 0;
	
void ADC_IRQHandler(void) {
	uint8_t lvl = 0;
	
  AD_current = ((LPC_ADC->ADGDR>>4) & 0xFFF);
	AD_current &= 0xF00;
  if((ADC_first_read == 0) || (AD_current != AD_last)){
		ADC_first_read = 1;
		if(AD_current <= 0xF00 && AD_current > 0xA00){
			lvl = 3;
		} else if(AD_current <= 0xA00 && AD_current > 0x400) {
			lvl = 2;
		} else if(AD_current <= 0x400 && AD_current > 0x0) {
			lvl = 1;
		} else if(AD_current == 0x0) {
			lvl = 0;
		}
		set_volume(lvl, 7 - (AD_current * 7 / 0xFFF), 0);		
		AD_last = AD_current;
  }
}
