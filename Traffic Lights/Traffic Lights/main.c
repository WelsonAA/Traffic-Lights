//
// Created by George Welson on 07-Oct-22.
//
#include "App/app.h"
int main(void){
    if(APP_init()!=APP_OK)
        return 1;
    if(APP_start()!=APP_OK)
        return 1;
    return 0;
}
