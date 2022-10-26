/********************************************************************************
* interrupts.c: Innehåller avbrottsrutiner.
********************************************************************************/

#include "header.h"

/********************************************************************************
* ISR (PCINT0_vect): Avbrottsrutin för PCI-avbrott på I/O-port B.
********************************************************************************/
ISR (PCINT0_vect)
{
	if (BUTTON_BACK_PRESSED || BUTTON_NEXT_PRESSED || BUTTON_NEXT_2_PRESSED)
	{
		fsm_update();
	}

	return;
}

/********************************************************************************
* ISR (INT0_vect): Avbrottsrutin som anropas vid nedtryckning av reset-knappen
*                  ansluten till pin 2. 
********************************************************************************/
ISR (INT0_vect)
{
   fsm_reset();
   return;
}

/********************************************************************************
* ISR (INT1_vect): Avbrottsrutin som anropas vid nedtryckning av knappen
*                  ansluten till pin 3.
********************************************************************************/
ISR (INT1_vect)
{
   fsm_update();
   return;
}