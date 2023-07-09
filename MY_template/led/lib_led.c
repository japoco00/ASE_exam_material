#include "lpc17xx.h"
#include "led.h"

unsigned char led_value;

void LED_init(void) {

  LPC_PINCON->PINSEL4 &= 0xFFFF0000;				//GPIO mode per tutti i led : 00 per ogni led da porta 2.0 a 2.7
	LPC_GPIO2->FIODIR   |= 0x000000FF;  			//set direzione OUTPUT per tutti i pin dei led
  // LPC_GPIO2->FIOSET    = 0x000000FF;			//all LEDs on 
	LPC_GPIO2->FIOCLR    = 0x000000FF;  			//all LEDs off
	
	led_value = 0;
}

void LED_deinit(void) {

  LPC_GPIO2->FIODIR &= 0xFFFFFF00;  				//P2.0...P2.7 Output LEDs on PORT2 defined as Input
}
