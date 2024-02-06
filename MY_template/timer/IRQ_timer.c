#include "lpc17xx.h"
#include "timer.h"
#include "../led/led.h"

extern unsigned char led_value;

//int blink_status =0;									// PER BLINK


void TIMER0_IRQHandler (void) {
  LPC_TIM0->IR = 1;			/* clear interrupt flag */
  return;
}

void TIMER1_IRQHandler (void) {
  LPC_TIM1->IR = 1;			/* clear interrupt flag */
  return;
}

void TIMER2_IRQHandler (void) {
  LPC_TIM2->IR = 1;			/* clear interrupt flag */
  return;
}

void TIMER3_IRQHandler (void) {
  LPC_TIM3->IR = 1;			/* clear interrupt flag */
  return;
}


// DA AGGIUNGERE PER BLINK ALL'HANDLER DEL TIMER SCELTO
// TIMER INIT VAL = 3

	/*
if(blink_status ==0 ){
		LED_All_On();
		blink_status++;
	} else {
		LED_All_Off();
		blink_status=0;
	}
*/

