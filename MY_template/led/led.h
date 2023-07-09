/* lib_led */
void LED_init(void);
void LED_deinit(void);

/* funct_led */
void LED_On (unsigned int num);
void LED_Off (unsigned int num);
void LED_Out(unsigned int value);
void LED_All_On (void);
void LED_All_Off (void);
void LED_blink (float sec, int n_timer);

