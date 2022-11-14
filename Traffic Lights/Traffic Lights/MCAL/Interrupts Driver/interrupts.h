//
// Created by George Welson on 01-Nov-22.
//

#ifndef UNTITLED10_INTERRUPTS_H
#define UNTITLED10_INTERRUPTS_H
#include "../../Utilities/registers.h"
#include "../../Utilities/bits.h"
#include "../../Utilities/abbreviations.h"
typedef enum EN_interruptError_t{
    INT_OK
}EN_interruptError_t;

#define EXT_INT_0 __vector_1

    //ISR macro
#define ISR(INT_VECT) \
void INT_VECT(void) __attribute__ ((signal,used)); \
void INT_VECT(void)

EN_interruptError_t INT0_init();//initializing INT0
#endif //UNTITLED10_INTERRUPTS_H
