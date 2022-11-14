//
// Created by George Welson on 25-Oct-22.
//
#include "mode.h"
extern volatile uint8_t CURRENT_MODE;
volatile uint8_t BTN_PRESSED;
volatile uint8_t MODE;
EN_modeError_t MODE_normal(){
    //starting at green for cars, red for pedestrians
    MODE=NORMAL_CODE;
    if(LED_toggle(PORT_CAR,PIN_GREEN)!=LED_OK)
        return MODE_LED_ERROR;
    CURRENT_MODE = NORMAL;
    if(LED_toggle(PORT_PED,PIN_RED)!=LED_OK)
        return MODE_LED_ERROR;
    if(BTN_PRESSED == PRESSED)//checking if the button is pressed
        return MODE_BTN_PRESSED;
    for(int i=0;i<10;i++) {
        if(TIMER_delay(500)!=TIMER_OK)
            return MODE_TIMER_ERROR;
        if(BTN_PRESSED == PRESSED)//checking if the button is pressed
            return MODE_BTN_PRESSED;
    }
    if(BTN_PRESSED == PRESSED)//checking if the button is pressed
        return MODE_BTN_PRESSED;
    //blinking yellow light for both car and pedestrian for 5 seconds
    for(int i = 0;i<5;i++){
        if(LED_blink(PORT_CAR, PIN_YELLOW, PORT_PED, PIN_YELLOW)!=LED_OK)
            return MODE_LED_ERROR;
        if(BTN_PRESSED == PRESSED)//checking if the button is pressed
            return MODE_BTN_PRESSED;
    }
    if(BTN_PRESSED == PRESSED)//checking if the button is pressed
        return MODE_BTN_PRESSED;
    //switching cars to red and pedestrian to green
    if(LED_toggle(PORT_CAR,PIN_GREEN)!=LED_OK)
        return MODE_LED_ERROR;
    CURRENT_MODE = PEDESTRIAN;
    if(LED_toggle(PORT_PED,PIN_RED)!=LED_OK)
        return MODE_LED_ERROR;
    if(LED_toggle(PORT_CAR,PIN_RED)!=LED_OK)
        return MODE_LED_ERROR;
    if(LED_toggle(PORT_PED,PIN_GREEN)!=LED_OK)
        return MODE_LED_ERROR;
    if(BTN_PRESSED == PRESSED)//checking if the button is pressed
        return MODE_BTN_PRESSED;
    for(int i=0;i<10;i++) {
        if(TIMER_delay(500)!=TIMER_OK)
            return MODE_TIMER_ERROR;
        if(BTN_PRESSED == PRESSED)//checking if the button is pressed
            return MODE_BTN_PRESSED;
    }
    if(BTN_PRESSED == PRESSED)//checking if the button is pressed
        return MODE_BTN_PRESSED;
    //blinking yellow light for both car and pedestrian for 5 seconds
    for(int i = 0;i<5;i++){
        if(LED_blink(PORT_CAR, PIN_YELLOW, PORT_PED, PIN_YELLOW)!=LED_OK)
            return MODE_LED_ERROR;
        if(BTN_PRESSED == PRESSED)//checking if the button is pressed
            return MODE_BTN_PRESSED;
    }
    if(BTN_PRESSED == PRESSED)//checking if the button is pressed
        return MODE_BTN_PRESSED;
    //turning all on leds to off
    if(LED_toggle(PORT_CAR,PIN_RED)!=LED_OK)
        return MODE_LED_ERROR;
    if(LED_toggle(PORT_PED,PIN_GREEN)!=LED_OK)
        return MODE_LED_ERROR;
    return MODE_OK;
}
EN_modeError_t MODE_abnormal(){
    //avoid checking for button press in abnormal mode to avoid responding to double presses
        //turn off all leds
    if(LED_off(PORT_CAR,PIN_GREEN)!=LED_OK)
        return MODE_LED_ERROR;
    if(LED_off(PORT_CAR,PIN_YELLOW)!=LED_OK)
        return MODE_LED_ERROR;
    if(LED_off(PORT_CAR,PIN_RED)!=LED_OK)
        return MODE_LED_ERROR;
    if(LED_off(PORT_PED,PIN_GREEN)!=LED_OK)
        return MODE_LED_ERROR;
    if(LED_off(PORT_PED,PIN_YELLOW)!=LED_OK)
        return MODE_LED_ERROR;
    if(LED_off(PORT_PED,PIN_RED)!=LED_OK)
        return MODE_LED_ERROR;
    BTN_PRESSED=NOT_PRESSED;
        //checking if the green car light was on
    if(CURRENT_MODE==NORMAL){
            //keeping only the car green light and pedestrian red light on and turning off yellow leds
        MODE=ABNORMAL_CODE;
        if(LED_toggle(PORT_CAR,PIN_GREEN)!=LED_OK)
            return MODE_LED_ERROR;
        if(LED_toggle(PORT_PED,PIN_RED)!=LED_OK)
            return MODE_LED_ERROR;
        //blinking yellow light for both car and pedestrian for 5 seconds
        for(int i = 0;i<5;i++){
            if(LED_blink(PORT_CAR, PIN_YELLOW, PORT_PED, PIN_YELLOW)!=LED_OK)
                return MODE_LED_ERROR;
        }
        //switching from green for cars and red for pedestrian to red for cars and green for pedestrian
        //allowing pedestrians to cross for 5 seconds
        if(LED_toggle(PORT_CAR,PIN_GREEN)!=LED_OK)
            return MODE_LED_ERROR;
        CURRENT_MODE=PEDESTRIAN;
        if(LED_toggle(PORT_CAR,PIN_RED)!=LED_OK)
            return MODE_LED_ERROR;
        if(LED_toggle(PORT_PED,PIN_GREEN)!=LED_OK)
            return MODE_LED_ERROR;
        if(LED_toggle(PORT_PED,PIN_RED)!=LED_OK)
            return MODE_LED_ERROR;
        for(int i=0;i<10;i++) {
            if(TIMER_delay(500)!=TIMER_OK)
                return MODE_TIMER_ERROR;
        }
        //blinking yellow light for both car and pedestrian for 5 seconds
        for(int i = 0;i<5;i++){
            if(LED_blink(PORT_CAR, PIN_YELLOW, PORT_PED, PIN_YELLOW)!=LED_OK)
                return MODE_LED_ERROR;
        }
        //switching from green for pedestrians and red for car to red for cars and green for pedestrian
        if(LED_toggle(PORT_CAR,PIN_RED)!=LED_OK)
            return MODE_LED_ERROR;
        if(LED_toggle(PORT_PED,PIN_GREEN)!=LED_OK)
            return MODE_LED_ERROR;
        CURRENT_MODE=NORMAL;
        return MODE_OK;
    }
    return MODE_OK;
}
