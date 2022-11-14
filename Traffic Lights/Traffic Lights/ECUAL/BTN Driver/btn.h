//
// Created by George Welson on 07-Oct-22.
//
#ifndef BTN_H
#define BTN_H


#include "../../MCAL/DIO Driver/dio.h"
typedef enum EN_btnError_t{
    BTN_OK,BTN_INVALID_PORT, BTN_INVALID_PIN, BTN_INVALID_DIRECTION,BTN_INVALID_VALUE
}EN_btnError_t;
EN_btnError_t BTN_init(uint8_t btnPort,uint8_t btnPin);//initialising a button
EN_btnError_t BTN_read(uint8_t btnPort,uint8_t btnPin,uint8_t* value);//reading the value of a button

#endif //UNTITLED10_BTN_H
