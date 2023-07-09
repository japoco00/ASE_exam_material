#include "button.h"
#include "lpc17xx.h"

#include "../led/led.h"

int val = 0;

void EINT0_IRQHandler (void)	    /* INT0														 */
{
	LED_On(0);
	//val ++;
	//LED_Out(val);
  LPC_SC->EXTINT &= (1 << 0);     /* clear pending interrupt         */
}


void EINT1_IRQHandler (void)	    /* KEY1														 */
{
  LED_On(1);
	//val --;
	//LED_Out(val);
	LPC_SC->EXTINT &= (1 << 1);     /* clear pending interrupt         */
}

void EINT2_IRQHandler (void)	    /* KEY2														 */
{
	LED_Off(0);
	LED_Off(1);
//	LED_Out(0);
  LPC_SC->EXTINT &= (1 << 2);     /* clear pending interrupt         */    
}


