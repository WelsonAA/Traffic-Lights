//
// Created by George Welson on 07-Oct-22.
//
#include "app.h"
volatile uint8_t CURRENT_MODE;
extern volatile uint8_t BTN_PRESSED;
extern volatile uint8_t MODE;
EN_appError_t APP_init(){
    if(LED_init(PORT_CAR,PIN_GREEN)!=LED_OK)
        return APP_LED_ERROR;
    if(LED_init(PORT_CAR,PIN_YELLOW)!=LED_OK)
        return APP_LED_ERROR;
    if(LED_init(PORT_CAR,PIN_RED)!=LED_OK)
        return APP_LED_ERROR;
    if(LED_init(PORT_PED,PIN_GREEN)!=LED_OK)
        return APP_LED_ERROR;
    if(LED_init(PORT_PED,PIN_YELLOW)!=LED_OK)
        return APP_LED_ERROR;
    if(LED_init(PORT_PED,PIN_RED)!=LED_OK)
        return APP_LED_ERROR;
    if(BTN_init(PORT_INT,PIN_INT)!=BTN_OK)
        return APP_LED_ERROR;
    if(TIMER_init()!=TIMER_OK)
        return APP_LED_ERROR;
    if(INT0_init()!=INT_OK)
        return APP_LED_ERROR;
    CURRENT_MODE=NORMAL;
    BTN_PRESSED=NOT_PRESSED;
    return APP_OK;
}
EN_appError_t APP_start() {
    while (1){
        if(BTN_PRESSED == PRESSED){//executing code regarding button pressing
            switch (MODE_abnormal()) {
                case MODE_LED_ERROR:{
                    return APP_LED_ERROR;
                }
                case MODE_TIMER_ERROR:{
                    return APP_TIMER_ERROR;
                }
                case MODE_BTN_ERROR:{
                    return APP_BTN_ERROR;
                }
                case MODE_TIMER_LARGE_DELAY:{
                    return APP_TIMER_LARGE_DELAY;
                }
                default:{
                    continue;
                }
            }
        }
        else{//executing code normally without having the button pressed
            switch (MODE_normal()) {
                case MODE_LED_ERROR: {
                    return APP_LED_ERROR;
                }
                case MODE_TIMER_ERROR: {
                    return APP_TIMER_ERROR;
                }
                case MODE_BTN_ERROR: {
                    return APP_BTN_ERROR;
                }
                case MODE_TIMER_LARGE_DELAY: {
                    return APP_TIMER_LARGE_DELAY;
                }
                case MODE_BTN_PRESSED: {
                    continue;
                }
                default: {
                    continue;
                }
            }
        }
    }
}
ISR(EXT_INT_0){//handling the interrupt
    if(CURRENT_MODE==NORMAL && MODE!=ABNORMAL_CODE)
        BTN_PRESSED=PRESSED;
}
