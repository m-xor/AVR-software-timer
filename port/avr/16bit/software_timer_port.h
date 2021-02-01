/*
 * soft_timer/software_timer_port.h
 *
 *  Created on: 31 sty 2021
 *      Author: slawek
 */

#ifndef SOFTWARE_TIMER_PORT_H_
#define SOFTWARE_TIMER_PORT_H_

#include <avr/io.h>
#include <avr/interrupt.h>

/*! \typedef
 *  \brief type of timer counter
 *
 *  Look out of capacity of the counter (65536 ticks in this case).
 *  Overflowing is not checked.
 */
typedef uint16_t Counter;

/*! \def
 *  \brief Interrupt guards
 *
 *  To assure atomic access to 16 bit variable in 8 bit processor.
 */
#define CRITICAL_SECTION_BEGIN 	uint8_t sreg = SREG;cli();
#define CRITICAL_SECTION_END 		SREG = sreg;


#endif /* SOFTWARE_TIMER_PORT_H_ */
