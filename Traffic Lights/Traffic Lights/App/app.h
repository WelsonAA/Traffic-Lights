//
// Created by George Welson on 07-Oct-22.
//


#ifndef APP_H_
#define APP_H_
#include "../MCAL/Interrupts Driver/interrupts.h"
#include "../ECUAL/LED Driver/led.h"
#include "../ECUAL/BTN Driver/btn.h"
#include "../ECUAL/Mode Driver/mode.h"
typedef enum EN_appError_t{
    APP_OK, APP_LED_ERROR, APP_BTN_ERROR, APP_TIMER_LARGE_DELAY,APP_TIMER_ERROR,APP_INT_ERROR,APP_ERROR_EXIT
}EN_appError_t;
EN_appError_t APP_init();//initialising the system
EN_appError_t APP_start();//starting the system

#endif /* APP_H_ */