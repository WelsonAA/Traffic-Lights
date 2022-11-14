//
// Created by George Welson on 07-Oct-22.
//

#include "btn.h"
EN_btnError_t BTN_init(uint8_t btnPort,uint8_t btnPin) {
    return(DIO_init(btnPort,btnPin,IN));
}
EN_btnError_t BTN_read(uint8_t btnPort,uint8_t btnPin,uint8_t* value){
    return(DIO_read(btnPort,btnPin,value));
}