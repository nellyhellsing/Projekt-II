/********************************************************************************
* main.c: Implementering av en tillst�ndsmaskin f�r tre lysdioder, som kan
          befinna sig i fem tillst�nd: 
                                      - STATE_OFF
									  - STATE_SLOW
									  - STATE_MEDIUM
									  - STATE_FAST
									  - STATE_ON
									  
*          Fem tryckknappar som uppdaterar lysdiodernas tillst�nd:
           ett hopp fram�t, ett hopp bak�t, tv� hopp fram�t, tv� hopp bak�t
		   eller reset.
********************************************************************************/
#include "header.h"


/********************************************************************************
* main: startpunkten i koden. Programmet k�rs s� l�nge det finns matningssp�nning.
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

