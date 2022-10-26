/********************************************************************************
* main.c: Implementering av en tillståndsmaskin för tre lysdioder, som kan
          befinna sig i fem tillstånd: 
                                      - STATE_OFF
									  - STATE_SLOW
									  - STATE_MEDIUM
									  - STATE_FAST
									  - STATE_ON
									  
*          Fem tryckknappar som uppdaterar lysdiodernas tillstånd:
           ett hopp framåt, ett hopp bakåt, två hopp framåt, två hopp bakåt
		   eller reset.
********************************************************************************/
#include "header.h"


/********************************************************************************
* main: startpunkten i koden. Programmet körs så länge det finns matningsspänning.
********************************************************************************/
int main(void)
{
    setup();
	
    while (1) 
    {
	   fsm_set_output();
    }
	return 0;
}

