#include "mbed.h"
#include "TSISensor.h"

// ATIVIDADE 2 - ITEM B

int main(void) {

    PwmOut led1(LED_GREEN);
    PwmOut led2(LED_BLUE);
    PwmOut led3(LED_RED);

    TSISensor tsi;
    
    while (true) {
        led1 = 1.0 - tsi.readPercentage();
        led2 = 1.0 - led1;
        led3 = 1.0 - led2;
        
        wait(0.1);
    }
}