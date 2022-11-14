//
// Created by George Welson on 07-Oct-22.
//

#ifndef DIO_H_
#define DIO_H_
#include "../../Utilities/registers.h"
#include "../../Utilities/bits.h"
#include "../../Utilities/abbreviations.h"
#include "../../MCAL/Interrupts Driver/interrupts.h"
typedef unsigned char uint8_t;
typedef enum EN_dioError_t{
    DIO_OK, DIO_INVALID_PORT, DIO_INVALID_PIN, DIO_INVALID_DIRECTION,DIO_INVALID_VALUE
}EN_dioError_t;
EN_dioError_t DIO_init(uint8_t portNumber,uint8_t pinNumber,uint8_t direction);//initializing an input or output
EN_dioError_t DIO_write(uint8_t portNumber,uint8_t pinNumber,uint8_t value);//writing to an output
EN_dioError_t DIO_toggle(uint8_t portNumber,uint8_t pinNumber);//switching the value of an output from 0 to 1 or vice versa
EN_dioError_t DIO_read(uint8_t portNumber,uint8_t pinNumber,uint8_t* value);//reading the value of an input



#endif /* DIO_H_ */