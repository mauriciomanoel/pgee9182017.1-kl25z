#include "mbed.h"

// ATIVIDADE 2 - ITEM A
DigitalOut myled1(LED_GREEN);
DigitalOut myled2(LED_BLUE);
DigitalOut myled3(LED_RED);

DigitalIn btnA1(PTA1); // PORT 2
DigitalOut btnA2(PTA2); // PORT 4

void funcao_led(int valor) {
    switch ( valor ) {
     case 1 :
        myled1 = 0;
        myled2 = 1;
        myled3 = 1;
        wait(1);
        break;
     case 2 :
        myled1 = 1;
        myled2 = 0;
        myled3 = 1;
        wait(1);
        break;
     case 3 :
        myled1 = 1;
        myled2 = 1;
        myled3 = 0;
        wait(1);
        break; 
     case 4 :
        myled1 = 1;
        myled2 = 1;
        myled3 = 1;
        wait(1);
        break;
    }
}

int main() {
    int contador = 1;
    btnA2 = 0;
    
    myled1 = 1;
    myled2 = 1;
    myled3 = 1;
        
    while(1) {
        
        funcao_led(contador);
        contador++;
        
        if (btnA1 == 0) {
            contador = 1;    
        }
    }
}

