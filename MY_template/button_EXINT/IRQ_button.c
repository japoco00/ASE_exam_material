#include "button.h"
#include "lpc17xx.h"

//	#include "../led/led.h"
#include "../RIT/RIT.h"	

extern int down_0;												//versione gestione de-bouncing con più pulsanti o con joystick
extern int down_1;
extern int down_2;


void EINT0_IRQHandler (void)	  						/* INT0 */
{			

	down_0 = 1;																// versione gestione de-bouncing con più pulsanti o con joystick
	NVIC_DisableIRQ(EINT0_IRQn);							// disable Button interrupts
	LPC_PINCON->PINSEL4    &= ~(1 << 20);   	// imposta la funzione del pin del button a general IO
	
	LPC_SC->EXTINT &= (1 << 0);     					// reset flag interrupt
}


void EINT1_IRQHandler (void)	  						/* KEY1 */
{
	
	down_1 = 1;																// versione gestione de-bouncing con più pulsanti o con joystick
	NVIC_DisableIRQ(EINT1_IRQn);							// disable Button interrupts
	LPC_PINCON->PINSEL4    &= ~(1 << 22);     // imposta la funzione del pin del button a general IO

	//enable_RIT();															// attiva RIT a 50ms				 
	//NVIC_DisableIRQ(EINT1_IRQn);							// disable Button interrupts
	//LPC_PINCON->PINSEL4    &= ~(1 << 22);     // imposta la funzione del pin del button a general IO
	
	LPC_SC->EXTINT &= (1 << 1);     					// reset flag interrupt
}

void EINT2_IRQHandler (void)	  						/* KEY2	*/
{	
	
	down_2 = 1;																// versione gestione de-bouncing con più pulsanti o con joystick
	NVIC_DisableIRQ(EINT2_IRQn);							// disable Button interrupts
	LPC_PINCON->PINSEL4    &= ~(1 << 24);     // imposta la funzione del pin del button a general IO
	
  LPC_SC->EXTINT &= (1 << 2);     					// reset flag interrupt    
}


