//
// Created by George Welson on 10-Oct-22.
//
#include "tmr.h"
EN_timerError_T TIMER_init(){
    //normal mode
    CLEAR_BIT(TCCR0,BIT_0);
    CLEAR_BIT(TCCR0,BIT_1);
    CLEAR_BIT(TCCR0,BIT_2);
    return TIMER_OK;
}

EN_timerError_T TIMER_delay(uint16_t millisec) {
    if(millisec>10000)
        return LARGE_DELAY;
    uint16_t N,tmrInitial;
    int64_t tMax,tTick;
    uint32_t overFlowcnt=0;
    //max delay 256 micro second
    //at 1MHz no prescaler
    // 256 prescaler
    tTick = 256.0/1000.0; //ms    tTick = Presc/FCPU
    tMax= 65.536; //ms		tMax = tTick * 2^8
    if(millisec<tMax){
        tmrInitial = (tMax-millisec)/tTick;
        N = 1;

    }else if(millisec == (uint32_t)tMax){
        tmrInitial=0;
        N=1;
    }else{
        N = ceil((int64_t)millisec/tMax);
        tmrInitial = (1<<8) - ((int64_t )millisec/tTick)/N;

    }
    TCNT0 = tmrInitial;
    SET_BIT(TCCR0,BIT_2);//set 256 prescaler
    while(overFlowcnt<N){
        //busy wait
        while(CHECK_BIT(TIFR,BIT_0)==LOW);
        //clear overflow flag
        SET_BIT(TIFR,BIT_0);
        //increment counter
        overFlowcnt++;
    }
    //Timer stop
    TIMER_init();
    return TIMER_OK;
}
