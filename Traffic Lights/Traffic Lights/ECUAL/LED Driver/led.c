//
// Created by George Welson on 07-Oct-22.
//

#include "led.h"
EN_ledError_t LED_init(uint8_t ledPort,uint8_t ledPin){
    return(DIO_init(ledPort,ledPin,OUT));
}
EN_ledError_t LED_on(uint8_t ledPort,uint8_t ledPin){
    return(DIO_write(ledPort,ledPin,HIGH));
}
EN_ledError_t LED_off(uint8_t ledPort,uint8_t ledPin){
    return(DIO_write(ledPort,ledPin,LOW));
}
EN_ledError_t LED_toggle(uint8_t ledPort,uint8_t ledPin){
    return(DIO_toggle(ledPort,ledPin));
}
EN_ledError_t LED_blink(uint8_t ledPortCar,uint8_t ledPinCar,uint8_t ledPortPed,uint8_t ledPinPed){
    for(int i=0;i<2;i++) {
        if (DIO_toggle(ledPortCar, ledPinCar) != DIO_OK) {
            return (DIO_toggle(ledPortCar, ledPinCar));
        }
        if (DIO_toggle(ledPortPed, ledPinPed) != DIO_OK) {
            return (DIO_toggle(ledPortCar, ledPinCar));
        }
        TIMER_delay(500);
    }
    return LED_OK;
}