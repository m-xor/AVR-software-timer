/*
 * soft_timer/software_timer.h
 *
 *  Created on: 31 sty 2021
 *      Author: slawek
 */

#ifndef SOFTWARE_TIMER_H_
#define SOFTWARE_TIMER_H_

#include "software_timer_port.h"

typedef struct Timer {
	_Bool active;
	volatile Counter cnt;
} Timer;

#define TICKS(period,timer_period) ((period)/(timer_period)+(((period)%(timer_period))?1:0))

static inline void Timer_ctor(Timer * const me)
{
	me->active = 0;
	CRITICAL_SECTION_BEGIN
	me->cnt = 0;
	CRITICAL_SECTION_END
}

static inline void Timer_setPeriod(Timer * const me, Counter ticks)
{
	CRITICAL_SECTION_BEGIN
	me->cnt = ticks;
	CRITICAL_SECTION_END
	me->active = 1;
}
static inline void Timer_activate(Timer * const me, _Bool activeness)
{
	me->active = activeness;
}
static inline _Bool Timer_isTime(Timer * const me)
{
	Counter cnt;
	_Bool result;
	CRITICAL_SECTION_BEGIN
	cnt = me->cnt;
	CRITICAL_SECTION_END
	result = !cnt && me->active && !(me->active=0);
	return result;
}

static inline void Timer_count(Timer * const me)
{
	Counter tmp = me->cnt;
	if(tmp) {
		me->cnt=--tmp;
	}
}

#endif /* SOFTWARE_TIMER_H_ */
