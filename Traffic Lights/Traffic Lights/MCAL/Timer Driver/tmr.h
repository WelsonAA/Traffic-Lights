//
// Created by George Welson on 10-Oct-22.
//

#ifndef UNTITLED10_TMR_H
#define UNTITLED10_TMR_H
#include "../../Utilities/registers.h"
#include "../../Utilities/bits.h"
#include "../../Utilities/abbreviations.h"
#include <math.h>
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef double int64_t;
typedef enum EN_timerError_T{
    TIMER_OK, LARGE_DELAY
}EN_timerError_T;
EN_timerError_T TIMER_init();//initialize Timer0
EN_timerError_T TIMER_delay(uint16_t millisec); //delay of specific amount default uses 256 prescalar

#endif //UNTITLED10_TMR_H
