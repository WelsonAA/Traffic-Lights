//
// Created by George Welson on 07-Oct-22.
//

#ifndef LED_H_
#define LED_H_
#include "../../MCAL/DIO Driver/dio.h"
#include "../../MCAL/Timer Driver/tmr.h"
typedef enum EN_ledError_t{
    LED_OK,LED_INVALID_PORT, LED_INVALID_PIN, LED_INVALID_DIRECTION,LED_INVALID_VALUE
}EN_ledError_t;
EN_ledError_t LED_init(uint8_t ledPort,uint8_t ledPin);//initialising a LED
EN_ledError_t LED_on(uint8_t ledPort,uint8_t ledPin);//turning a led on
EN_ledError_t LED_off(uint8_t ledPort,uint8_t ledPin);//turning off a led
EN_ledError_t LED_toggle(uint8_t ledPort,uint8_t ledPin);//switching an on led to off or vice versa
EN_ledError_t LED_blink(uint8_t ledPortCar,uint8_t ledPinCar,uint8_t ledPortPed,uint8_t ledPinPed);//blinking 2 leds for a second


#endif /* LED_H_ */