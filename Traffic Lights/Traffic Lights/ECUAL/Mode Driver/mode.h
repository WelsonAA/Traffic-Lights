//
// Created by George Welson on 25-Oct-22.
//

#ifndef UNTITLED10_MODE_H
#define UNTITLED10_MODE_H
#include "../../MCAL/Timer Driver/tmr.h"
#include "../LED Driver/led.h"
#include "../BTN Driver/btn.h"
typedef enum EN_modeError_t{
    MODE_OK,MODE_LED_ERROR,MODE_BTN_ERROR,MODE_TIMER_ERROR,MODE_TIMER_LARGE_DELAY,MODE_BTN_PRESSED
}EN_modeError_t;
typedef unsigned char uint8_t;
EN_modeError_t MODE_normal();//normal mode sequence for the traffic light system
EN_modeError_t MODE_abnormal();//abnormal mode sequence for the traffic light system
#endif //UNTITLED10_MODE_H
