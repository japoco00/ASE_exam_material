#include "lpc17xx.h"
#include "RIT.h"
#include "../led/led.h"

volatile int down_0=0;												//versione gestione de-bouncing con più pulsanti o con joystick
volatile int down_1=0;
volatile int down_2=0;
volatile int downj_down=0;
volatile int downj_up=0;
volatile int downj_left=0;
volatile int downj_right=0;
volatile int downj_select=0;


/*VERSIONE BOTTONE SINGOLO

void RIT_IRQHandler (void) {			
	static int down=0;													//down inizia a 1 la prima iterazione dell'handler (iterazione che conferma il press). 																						
	down++;																			//le 	successive viene aumentato
	if((LPC_GPIO2->FIOPIN & (1<<11)) == 0){			//se il bottone sta venendo premuto (stato pin FIOPIN[11] ==0 )
		reset_RIT();															//reset RIT per permettere un nuovo RIT handler
		switch(down){
			case 1:																	//se è la prima iterazione gestisco la pressione del pulsante
				//gestione evento pressione
				break;
			default:
				//gestione RIT successivi al primo: il pulsante è tenuto premuto per più tempo
				break;
		}
	}
	else {																			//bottone rilasciato
		down=0;																		//reset variabile
		disable_RIT();														
		reset_RIT();															//ferma e resetta RIT
		NVIC_EnableIRQ(EINT1_IRQn);							 	//riabilita interruzione pulsante
		LPC_PINCON->PINSEL4    |= (1 << 22);     	//reimposta funzione pin pulsante a external interrupt
	}
		
	
  LPC_RIT->RICTRL |= 0x1;											//clear flag interrupt
	
  return;
} */



void RIT_IRQHandler (void){	

	if(down_0 != 0){														
		down_0 ++;
		if((LPC_GPIO2->FIOPIN & (1<<10)) == 0){		
			switch(down_0){
				case 2:																	
					//prima gestione
					break;
				default:															
					//gestioni successive
					break;
			}
		}
		else {																		
			down_0 = 0;															//reset down
			NVIC_EnableIRQ(EINT0_IRQn);							//abilita di nuovo l'interrupt iniziale del pulsante
			LPC_PINCON->PINSEL4    |= (1 << 20);    //ri-set della funzione del pin 20 a external interrupt.		
		}
	}																						//fine gestione bottone 0.	
	
	if(down_1 != 0){													
		down_1 ++;
		if((LPC_GPIO2->FIOPIN & (1<<11)) == 0){			
			switch(down_1){
				case 2:																			

					break;
				default:															

					break;
			}
		}
		else {																		
			down_1 = 0;															//reset down
			NVIC_EnableIRQ(EINT1_IRQn);							//abilita di nuovo l'interrupt iniziale del pulsante
			LPC_PINCON->PINSEL4    |= (1 << 22);    //ri-set della funzione del pin 22 a external interrupt.		
		}
	}																						//fine gestione bottone 1.	

	
	if(down_2 != 0){														
		down_2 ++;
		if((LPC_GPIO2->FIOPIN & (1<<12)) == 0){		
			switch(down_2){
				case 2:																
	
					break;
				default:															
				
					break;
			}
		}
		else {																		
			down_2 = 0;															//reset down
			NVIC_EnableIRQ(EINT2_IRQn);							//abilita di nuovo l'interrupt iniziale del pulsante
			LPC_PINCON->PINSEL4    |= (1 << 24);    //ri-set della funzione del pin 24 a external interrupt.		
		}
	}																						//fine gestione bottone 2.


	if ((LPC_GPIO1->FIOPIN & (1<<26)) == 0 ){		//joystick down
		downj_down ++;
		if(downj_down == 1 ){											//se è mantenuto per n (qui n==1) RIT di fila gestisco evento
			
		}
	} else {																		//se è stato rilasciato prima del tempo minimo resetto il counting
		downj_down = 0;
	}
	
	if ((LPC_GPIO1->FIOPIN & (1<<25)) == 0 ){		//joystick select
		downj_select ++;
		if(downj_select == 1 ){										//se è mantenuto per n RIT di fila gestisco evento
			
		}
	} else {																		//se è stato rilasciato prima del tempo minimo resetto il counting
		downj_select = 0;
	}

	if ((LPC_GPIO1->FIOPIN & (1<<27)) == 0 ){		//joystick left
		downj_left ++;
		if(downj_left == 1 ){											//se è mantenuto per n RIT di fila gestisco evento
			
		}
	} else {																		//se è stato rilasciato prima del tempo minimo resetto il counting
		downj_left = 0;
	}

	if ((LPC_GPIO1->FIOPIN & (1<<28)) == 0 ){		//joystick right
		downj_right ++;
		if(downj_right == 1 ){										//se è mantenuto per n RIT di fila gestisco evento
			
		}
	} else {																		//se è stato rilasciato prima del tempo minimo resetto il counting
		downj_right = 0;
	}
	
	if ((LPC_GPIO1->FIOPIN & (1<<29)) == 0 ){		//joystick up
		downj_up ++;
		if(downj_up == 1 ){											//se è mantenuto per n RIT di fila gestisco evento
			
		}
	} else {																		//se è stato rilasciato prima del tempo minimo resetto il counting
		downj_up = 0;
	}		
	reset_RIT();																//resetto RIT per poter triggerare un nuov RIT
	LPC_RIT->RICTRL |= 0x1;											//reset flag interrupt RIT.
	
	return;
}

