//
// Created by George Welson on 07-Oct-22.
//

#include "dio.h"

EN_dioError_t DIO_init(uint8_t portNumber,uint8_t pinNumber,uint8_t direction){
    if(pinNumber>7||pinNumber<0)
        return DIO_INVALID_PIN;
    switch(portNumber){
        case PORT_A:{
            if(direction==IN){
                CLEAR_BIT(DDRA,pinNumber);
                return DIO_OK;
            }
            else if(direction==OUT){
                SET_BIT(DDRA,pinNumber);
                return DIO_OK;
            }
            else{
                return DIO_INVALID_DIRECTION;
            }
            break;
        }

        case PORT_B:{
            if(direction==IN){
                CLEAR_BIT(DDRB,pinNumber);
                return DIO_OK;
            }
            else if(direction==OUT){
                SET_BIT(DDRB,pinNumber);
                return DIO_OK;
            }
            else{
                return DIO_INVALID_DIRECTION;
            }
            break;
        }

        case PORT_C:{
            if(direction==IN){
                CLEAR_BIT(DDRC,pinNumber);
                return DIO_OK;
            }
            else if(direction==OUT){
                SET_BIT(DDRC,pinNumber);
                return DIO_OK;
            }
            else{
                return DIO_INVALID_DIRECTION;
            }
            break;
        }

        case PORT_D:{
            if(direction==IN){
                CLEAR_BIT(DDRD,pinNumber);
                return DIO_OK;
            }
            else if(direction==OUT){
                SET_BIT(DDRD,pinNumber);
                return DIO_OK;
            }
            else{
                return DIO_INVALID_DIRECTION;
            }
            break;
        }

        default:{
            return DIO_INVALID_PORT;
        }

    }
}
EN_dioError_t DIO_write(uint8_t portNumber,uint8_t pinNumber,uint8_t value){
    if(pinNumber>7||pinNumber<0)
        return DIO_INVALID_PIN;
    switch(portNumber){
        case PORT_A:{
            if(value==LOW){
                CLEAR_BIT(PORTA,pinNumber);
                return DIO_OK;
            }
            else if(value==HIGH){
                SET_BIT(PORTA,pinNumber);
                return DIO_OK;
            }
            else{
                return DIO_INVALID_VALUE;
            }
            break;
        }

        case PORT_B:{
            if(value==LOW){
                CLEAR_BIT(PORTB,pinNumber);
                return DIO_OK;
            }
            else if(value==HIGH){
                SET_BIT(PORTB,pinNumber);
                return DIO_OK;
            }
            else{
                return DIO_INVALID_VALUE;
            }
            break;
        }

        case PORT_C:{
            if(value==LOW){
                CLEAR_BIT(PORTC,pinNumber);
                return DIO_OK;
            }
            else if(value==HIGH){
                SET_BIT(PORTC,pinNumber);
                return DIO_OK;
            }
            else{
                return DIO_INVALID_VALUE;
            }
            break;
        }

        case PORT_D:{
            if(value==LOW){
                CLEAR_BIT(PORTD,pinNumber);
                return DIO_OK;
            }
            else if(value==HIGH){
                SET_BIT(PORTD,pinNumber);
                return DIO_OK;
            }
            else{
                return DIO_INVALID_VALUE;
            }
            break;
        }

        default:{
            return DIO_INVALID_PORT;
        }

    }
}
EN_dioError_t DIO_toggle(uint8_t portNumber,uint8_t pinNumber){
    if(pinNumber>7||pinNumber<0)
        return DIO_INVALID_PIN;
    switch(portNumber){
        case PORT_A: {
            TOGGLE_BIT(PORTA, pinNumber);
            return DIO_OK;
        }
        case PORT_B: {
            TOGGLE_BIT(PORTB, pinNumber);
            return DIO_OK;
        }
        case PORT_C: {
            TOGGLE_BIT(PORTC, pinNumber);
            return DIO_OK;
        }
        case PORT_D: {
            TOGGLE_BIT(PORTD, pinNumber);
            return DIO_OK;
        }
        default:{
            return DIO_INVALID_PORT;
        }
    }
}
EN_dioError_t DIO_read(uint8_t portNumber,uint8_t pinNumber,uint8_t* value){
    if(pinNumber>7||pinNumber<0)
        return DIO_INVALID_PIN;
    switch(portNumber){
        case PORT_A:{
            *value= CHECK_BIT(PINA,pinNumber);
            return DIO_OK;
        }
        case PORT_B:{
            *value= CHECK_BIT(PINB,pinNumber);
            return DIO_OK;
        }
        case PORT_C:{
            *value= CHECK_BIT(PINC,pinNumber);
            return DIO_OK;
        }
        case PORT_D:{
            *value= CHECK_BIT(PIND,pinNumber);
            return DIO_OK;
        }
        default:{
            return DIO_INVALID_PORT;
        }
    }
}

