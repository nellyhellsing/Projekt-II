/********************************************************************************
* header.h: Innehåller diverse makrodefinitioner och deklarationer.
********************************************************************************/
#ifndef HEADER_H_
#define HEADER_H_

#define F_CPU 16000000UL /* 16 MHz. */
 
 /* Inkluderingsdirektiv */
#include <avr/io.h>        /* Innehåller information om I/O-portar såsom DDRB och PORTB. */
#include <avr/interrupt.h> /* Innehåller information om avbrottsrutiner såsom INT0_vect. */
#include <util/delay.h>    /* fördröjning */

/* makrodefinitoner */ 
#define LED1 0 /* lydsiod på pin 8 / PORTB0 */
#define LED2 1 /* lydsiod på pin 9 / PORTB1 */
#define LED3 2 /* lydsiod på pin 10 / PORTB2 */

#define BUTTON_BACK 3   /* tryckknapp på pin 11 / PORTB3 */
#define BUTTON_NEXT 4   /* tryckknapp på pin 12 / PORTB4 */
#define BUTTON_NEXT_2 5 /* tryckknapp på pin 13 / PORTB5 */
#define BUTTON_RESET 2  /* tryckknapp på pin 2/ PORTD2 */
#define BUTTON_BACK_2 3 /* tyrckknap på pin 3 / PORTD3 */


#define LED1_STATE_ON PORTB |= (1 << LED1) /* Tänder lysdiod 1 */
#define LED2_STATE_ON PORTB |= (1 << LED2) /* Tänder lysdiod 2 */
#define LED3_STATE_ON PORTB |= (1 << LED3) /* Tänder lysdiod 3 */

#define LED1_STATE_OFF PORTB &= ~(1 << LED1) /* Släcker lysdiod 1 */
#define LED2_STATE_OFF PORTB &= ~(1 << LED2) /* Släcker lysdiod 2 */
#define LED3_STATE_OFF PORTB &= ~(1 << LED3) /* Släcker lysdiod 3 */

#define LEDS_ON PORTB |= (1 << LED1) | (1 << LED2) | (1 << LED3)     /* Tänder lysdioderna. */
#define LEDS_OFF PORTB &= ~((1 << LED1) | (1 << LED2) | (1 << LED3)) /* Släcker lysdioderna. */

#define BUTTON_BACK_PRESSED (PINB & (1 << BUTTON_BACK))     /* Indikerar byte till föregående tillstånd. */
#define BUTTON_NEXT_PRESSED (PINB & (1 << BUTTON_NEXT))     /* Indikerar byte till nästa tillstånd */
#define BUTTON_NEXT_2_PRESSED (PINB & (1 << BUTTON_NEXT_2)) /* indikerar byte två hopp frammåt */
#define BUTTON_RESET_PRESSED (PIND & (1 << BUTTON_RESET))   /* Indikerar reset knapp */
#define BUTTON_BACK_2_PRESSED (PIND & (1 << BUTTON_BACK_2)) /* Indikerar byte två hopp bakåt */

/*******************************************************************************
*bool: Data typ som indikerar sant eller falskt
 *******************************************************************************/
typedef enum { false, true } bool;
	
/*******************************************************************************
*led_state: lysdiodernas tillstånd
********************************************************************************/
enum led_state {LED_STATE_OFF, LED_STATE_SLOW, LED_STATE_MEDIUM, LED_STATE_FAST, LED_STATE_ON};

/********************************************************************************
* setup: Initierar mikrodatorn vid start.
********************************************************************************/
void setup(void);

/********************************************************************************
* fsm_reset: Återställer till startläget, vilket innebär
*            att lysdioderna släcks.
********************************************************************************/
void fsm_reset(void);

/********************************************************************************
* fsm_uppdate: Uppdaterar vid nuvarande tillstånd samt
*              vilken tryckknapp som trycks ned.
********************************************************************************/
void fsm_update(void);

/********************************************************************************
* fsm_set_output: Uppdaterar utsignaler utefter aktuellt tillstånd
*                 blink_speed_ms: Lysdiodernas blinkhastighet vid blinkning.
********************************************************************************/
void fsm_set_output(void);

#endif /* HEADER_H_ */