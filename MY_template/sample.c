#include <stdio.h>
#include "LPC17xx.H"                    /* LPC17xx definitions                */
#include "led/led.h"
#include "button_EXINT/button.h"
#include "timer/timer.h"
#include "RIT/RIT.h"
#include "GLCD/GLCD.h" 
#include "TouchPanel/TouchPanel.h"
#include "joystick/joystick.h"


extern unsigned char led_value;					/* defined in funct_led								*/
#ifdef SIMULATOR
extern uint8_t ScaleFlag; 
#endif



int main (void) {
  	
	SystemInit();  												/* System Initialization (i.e., PLL)  */
  LED_init();                           /* LED Initialization                 */
  BUTTON_init();												/* BUTTON Initialization              */
	init_RIT(0x004C4B40);									/* RIT Initialization 50 msec       	*/
	joystick_init();
	
	/*
	Se bottoni multipli: attivo rit in main e levo dagli IRQ dei pulsanti.
	Se bottone singolo: attivo RIT direttamente nell'IRQ del bottone
	*/
	
	//enable_RIT();												// RIT con più pulsanti o con joystick
	
	//LCD_Initialization(); 							//Inizializza LCD
	//TP_Init();													//Inizializza touch
	//TouchPanel_Calibrate();							//Inizializza calibrazione touch
	
	//init_timer(numero, value);					// TIMERn Initialization. 	value = sec * F (=25 GHz)																				
	//enable_timer(numero);								// abilita timer

	//LPC_SC->PCONP |= (1<<22);						// Abilita timer 2 in power down
	//LPC_SC->PCONP |= (1<<23);						// Abilita timer 3 in power down
	LPC_SC->PCON |= 0x1;									// power-down	mode
	LPC_SC->PCON &= ~(0x2);								// se volessi la sleep mode PCON[1,0] = 00 e SYS CONTROL REGISTER [2] = 1
		
  while (1) {
		__ASM("wfi");
  }

}
