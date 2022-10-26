/********************************************************************************
* setup.c: Innehåller initieringsrutiner.
********************************************************************************/

#include "header.h"

/* Statiska funktioner: */
static inline void init_ports(void);
static inline void init_interrupts(void);

/********************************************************************************
* setup: Initierar mikrodatorn vid start.
********************************************************************************/
void setup(void)
{
	init_ports();
	init_interrupts();
	fsm_reset();
	return;
}

/********************************************************************************
* init_ports: Sätter lysdiodernas pinnar till utportar och tryckknappernas pin
*             till inportar.
********************************************************************************/
static inline void init_ports(void)
{
	DDRB = (1 << LED1) | (1 << LED2) | (1 << LED3);
	PORTB = (1 << BUTTON_BACK) | (1 << BUTTON_NEXT) | (1 << BUTTON_NEXT_2);
	PORTD = (1 << BUTTON_RESET)| (1 << BUTTON_BACK_2);
	return;
}

/********************************************************************************
* init_interrupts: Aktiverar PCI-avbrott på pin 11 - 13 / PORTB3 - PORTB5 samt 
*                  externa avbrott på pin 2 i fallande flank och pin 3 i 
*                  stigande flank.
********************************************************************************/
static inline void init_interrupts(void)
{
	asm("SEI");
	PCICR = (1 << PCIE0);
	PCMSK0 = (1 << BUTTON_BACK) | (1 << BUTTON_NEXT) | (1 << BUTTON_NEXT_2);
	
	EICRA = (1 << ISC01) | (1 << ISC10) | (1 << ISC11);
	EIMSK = (1 << INT0) | (1 << INT1);
	return;
}