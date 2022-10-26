/********************************************************************************
* header.h: Inneh�ller diverse makrodefinitioner och deklarationer.
********************************************************************************/
#ifndef HEADER_H_
#define HEADER_H_

#define F_CPU 16000000UL /* 16 MHz. */
 
 /* Inkluderingsdirektiv */
#include <avr/io.h>        /* Inneh�ller information om I/O-portar s�som DDRB och PORTB. */
#include <avr/interrupt.h> /* Inneh�ller information om avbrottsrutiner s�som INT0_vect. */
#include <util/delay.h>    /* f�rdr�jning */

/* makrodefinitoner */ 
#define LED1 0 /* lydsiod p� pin 8 / PORTB0 */
#define LED2 1 /* lydsiod p� pin 9 / PORTB1 */
#define LED3 2 /* lydsiod p� pin 10 / PORTB2 */

#define BUTTON_BACK 3   /* tryckknapp p� pin 11 / PORTB3 */
#define BUTTON_NEXT 4   /* tryckknapp p� pin 12 / PORTB4 */
#define BUTTON_NEXT_2 5 /* tryckknapp p� pin 13 / PORTB5 */
#define BUTTON_RESET 2  /* tryckknapp p� pin 2/ PORTD2 */
#define BUTTON_BACK_2 3 /* tyrckknap p� pin 3 / PORTD3 */


#define LED1_STATE_ON PORTB |= (1 << LED1) /* T�nder lysdiod 1 */
#define LED2_STATE_ON PORTB |= (1 << LED2) /* T�nder lysdiod 2 */
#define LED3_STATE_ON PORTB |= (1 << LED3) /* T�nder lysdiod 3 */

#define LED1_STATE_OFF PORTB &= ~(1 << LED1) /* Sl�cker lysdiod 1 */
#define LED2_STATE_OFF PORTB &= ~(1 << LED2) /* Sl�cker lysdiod 2 */
#define LED3_STATE_OFF PORTB &= ~(1 << LED3) /* Sl�cker lysdiod 3 */

#define LEDS_ON PORTB |= (1 << LED1) | (1 << LED2) | (1 << LED3)     /* T�nder lysdioderna. */
#define LEDS_OFF PORTB &= ~((1 << LED1) | (1 << LED2) | (1 << LED3)) /* Sl�cker lysdioderna. */

#define BUTTON_BACK_PRESSED (PINB & (1 << BUTTON_BACK))     /* Indikerar byte till f�reg�ende tillst�nd. */
#define BUTTON_NEXT_PRESSED (PINB & (1 << BUTTON_NEXT))     /* Indikerar byte till n�sta tillst�nd */
#define BUTTON_NEXT_2_PRESSED (PINB & (1 << BUTTON_NEXT_2)) /* indikerar byte tv� hopp framm�t */
#define BUTTON_RESET_PRESSED (PIND & (1 << BUTTON_RESET))   /* Indikerar reset knapp */
#define BUTTON_BACK_2_PRESSED (PIND & (1 << BUTTON_BACK_2)) /* Indikerar byte tv� hopp bak�t */

/*******************************************************************************
*bool: Data typ som indikerar sant eller falskt
 *******************************************************************************/
typedef enum { false, true } bool;
	
/*******************************************************************************
*led_state: lysdiodernas tillst�nd
********************************************************************************/
enum led_state {LED_STATE_OFF, LED_STATE_SLOW, LED_STATE_MEDIUM, LED_STATE_FAST, LED_STATE_ON};

/********************************************************************************
* setup: Initierar mikrodatorn vid start.
********************************************************************************/
void setup(void);

/********************************************************************************
* fsm_reset: �terst�ller till startl�get, vilket inneb�r
*            att lysdioderna sl�cks.
********************************************************************************/
void fsm_reset(void);

/********************************************************************************
* fsm_uppdate: Uppdaterar vid nuvarande tillst�nd samt
*              vilken tryckknapp som trycks ned.
********************************************************************************/
void fsm_update(void);

/********************************************************************************
* fsm_set_output: Uppdaterar utsignaler utefter aktuellt tillst�nd
*                 blink_speed_ms: Lysdiodernas blinkhastighet vid blinkning.
********************************************************************************/
void fsm_set_output(void);

#endif /* HEADER_H_ */