#include "header.h"

static void fsm_blink(const uint16_t blink_speed_ms);
static void delay_ms(const uint16_t delay_time_ms);

static enum led_state state = LED_STATE_OFF;

/********************************************************************************
* fsm_reset: Återställer tillståndsmaskinen till startläget, vilket medför
*            att lysdioderna släcks.
********************************************************************************/
void fsm_reset(void)
{
	state = LED_STATE_OFF;
	LEDS_OFF;
	return;
}

/********************************************************************************
* fsm_uppdate: Uppdaterar utefter vilket tillstånd vi befinner oss i, samt
*              vilken tryckknapp som trycks ned. 
********************************************************************************/
void fsm_update(void)
{
	switch(state)
	{
		case LED_STATE_OFF:
		{
			if (BUTTON_NEXT_PRESSED)
			{
				state = LED_STATE_SLOW;
			}
			else if (BUTTON_BACK_PRESSED)
			{
				state = LED_STATE_ON;
			}
			else if (BUTTON_BACK_2_PRESSED)
			{
				state = LED_STATE_FAST;
			}
			else if (BUTTON_NEXT_2_PRESSED)
			{
				state = LED_STATE_MEDIUM;
			}
			
			break;
		}
		
		case LED_STATE_SLOW:
		{
			if (BUTTON_NEXT_PRESSED)
			{
				state  = LED_STATE_MEDIUM;
			}
			else if (BUTTON_BACK_PRESSED)
			{
				state = LED_STATE_OFF;
			}
			else if (BUTTON_BACK_2_PRESSED)
			{
				state = LED_STATE_ON;
			}
			else if (BUTTON_NEXT_2_PRESSED)
			{
				state = LED_STATE_FAST;
			}
			break;
		}
		
		case LED_STATE_MEDIUM:
		{
			if (BUTTON_NEXT_PRESSED)
			{
				state = LED_STATE_FAST;
			}
			else if (BUTTON_BACK_PRESSED)
			{
				state = LED_STATE_SLOW;
			}
			else if (BUTTON_BACK_2_PRESSED)
			{
				state = LED_STATE_OFF;
			}
			else if (BUTTON_NEXT_2_PRESSED)
			{
				state = LED_STATE_ON;
			}
			break;
		}
		case LED_STATE_FAST:
		{
			if (BUTTON_NEXT_PRESSED)
			{
				state = LED_STATE_ON;
			}
			else if (BUTTON_BACK_PRESSED)
			{
				state = LED_STATE_MEDIUM;
			}
			else if (BUTTON_BACK_2_PRESSED)
			{
				state = LED_STATE_SLOW;
			}
			else if (BUTTON_NEXT_2_PRESSED)
			{
				state = LED_STATE_OFF;
			}
			break;
		}
		case LED_STATE_ON:
		{
			if (BUTTON_NEXT_PRESSED)
			{
				state = LED_STATE_OFF;
			}
			else if (BUTTON_BACK_PRESSED)
			{
				state = LED_STATE_FAST;
			}
			else if (BUTTON_BACK_2_PRESSED)
			{
				state = LED_STATE_MEDIUM;
			}
			else if (BUTTON_NEXT_2_PRESSED)
			{
				state = LED_STATE_SLOW;
			}
			break;
		}
		
		default:
		{
			fsm_reset();
			break;
		}
	}

	return;
}

/********************************************************************************
* fsm_set_output: Uppdaterar utsignaler utefter de tillstånd vi befinner oss i.
********************************************************************************/
void fsm_set_output(void)
{
	if (state == LED_STATE_OFF)
	{
		LEDS_OFF;
	}
	else if (state == LED_STATE_SLOW)
	{
		fsm_blink(500);
	}
	else if (state == LED_STATE_MEDIUM)
	{
		fsm_blink(250);
	}
	else if (state == LED_STATE_FAST)
	{
		fsm_blink(50);
	}
	else if (state == LED_STATE_ON)
	{
		LEDS_ON;
	}
	else
	  {
		  fsm_reset();
	  }
	  return;
}

/********************************************************************************
* leds_blink: Blinkar/tänder lysdioderna i en slinga.
********************************************************************************/
static void fsm_blink(const uint16_t blink_speed_ms)
{
   LEDS_OFF;
   LED1_STATE_ON;
   delay_ms(blink_speed_ms);
   
   LED1_STATE_OFF;
   LED2_STATE_ON;
   delay_ms(blink_speed_ms);
   
   
   LED2_STATE_OFF;
   LED3_STATE_ON;
   delay_ms(blink_speed_ms);
   
   LED3_STATE_OFF;
   return;
}

/********************************************************************************
* delay_ms: Fördröjning mätt i millisekunder.
*            delay_time_ms: Fördröjningstiden mätt i ms.
********************************************************************************/
static void delay_ms(const uint16_t delay_time_ms)
{
	for (uint16_t i = 0; i < delay_time_ms; ++i)
	{
		_delay_ms(1); // 1 ms varje varv.
	}
	
	return;
}
