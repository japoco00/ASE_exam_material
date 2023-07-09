#include "lpc17xx.h"
#include "led.h"
#include "../timer/timer.h"

#define LED_NUM     8
const unsigned long led_mask[] = { 1UL<<0, 1UL<<1, 1UL<<2, 1UL<< 3, 1UL<< 4, 1UL<< 5, 1UL<< 6, 1UL<< 7 };

extern unsigned char led_value;

void LED_On(unsigned int num) {
 
  LPC_GPIO2->FIOPIN |= led_mask[num];
	led_value = LPC_GPIO2->FIOPIN;
}

void LED_Off(unsigned int num) {

  LPC_GPIO2->FIOPIN &= ~led_mask[num];
	led_value = LPC_GPIO2->FIOPIN;
}

void LED_Out(unsigned int value) {
  int i;

  for (i = 0; i < LED_NUM; i++) {
    if (value & (1<<i)) {
      LED_On (i);
    } else {
      LED_Off(i);
    }
  }
	led_value = value;
}

void LED_All_On (void){
	int i;
	for (i=0; i<8; i++){
		LED_On(i);
	}
}

void LED_All_Off (void){
	int i;
	for (i=0; i<8; i++){
		LED_Off(i);
	}
}

void LED_blink (float sec, int n_timer){
	init_timer(n_timer, ((int)(sec*25000000)));
	enable_timer(n_timer);
}

