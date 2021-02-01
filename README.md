To use:
1. define include path to appriopriate port file "software_timer_port.h"
2. define global variable of Timer type. There's no need to define it volatile.
3. export variable to every file timer is in use.
4. include software_timer.h file in every file timer is in use. 

Usage example

/* main.c */
#include <avr/io.h>
#include <avr/interrupt.h>
#include "button.h"
#include "software_timer.h"

Timer buttonPeriod;
Timer busyWait;

int main()
{
	Timer_ctor(&buttonPeriod); /* actually not needed when variable in bss section */
	Timer_setPeriod(&buttonPeriod, TICKS(1000,10));

	Timer_ctor(&busyWait); /* actually not needed when variable in bss section */


	sei();
	while(1)
	{
		/* repeated action */
		if(Timer_isTime(&buttonPeriod)) {
			button_poll();
			/* reactivation */
			Timer_setPeriod(&buttonPeriod, TICKS(1000,10));
		}

		/* conditional deactivation */
		if(codition0) {
			Timer_activate(&buttonPeriod, 0);
		}

		/* one shot action */
		some_action_init();

		Timer_setPeriod(&busyWait,TICKS(10,10)); /* timer activation */
		while(Timer_isTime(&busyWait));	/* we're waiting for expiry */
		/* busyWait timer is inactive now */
		
		some_action_after_delay();

	}

}

/* timer.c */
#include <avr/interrupt.h>
#include "software_timer.h"

Timer buttonPeriod;
Timer busyWait;

ISR(TIMER0_OVF_vect)
{
	Timer_count(&buttonPeriod);
	Timer_count(&busyWait);
}