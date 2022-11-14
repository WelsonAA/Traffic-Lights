//
// Created by George Welson on 01-Nov-22.
//
#include "interrupts.h"
EN_interruptError_t INT0_init(){
    CLEAR_BIT(MCUCR,BIT_0);
    SET_BIT(MCUCR,BIT_1);
    SET_BIT(GICR,BIT_6);
    SET_BIT(SREG,BIT_7);
    return INT_OK;
}