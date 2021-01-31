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

typedef uint16_t Counter;

#define CRITICAL_SECTION_BEGIN 	uint8_t sreg = SREG;cli();
#define CRITICAL_SECTION_END 		SREG = sreg;


#endif /* SOFTWARE_TIMER_PORT_H_ */
