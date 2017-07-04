#include "mbed.h"
#include "MMA8451Q.h"

#if   defined (TARGET_KL25Z) || defined (TARGET_KL46Z)
  PinName const SDA = PTE25;
  PinName const SCL = PTE24;
#elif defined (TARGET_KL05Z)
  PinName const SDA = PTB4;
  PinName const SCL = PTB3;
#elif defined (TARGET_K20D50M)
  PinName const SDA = PTB1;
  PinName const SCL = PTB0;
#else
  #error TARGET NOT DEFINED
#endif

#define MMA8451_I2C_ADDRESS (0x1d<<1)

int main(void)
{
    MMA8451Q acc(SDA, SCL, MMA8451_I2C_ADDRESS);
    PwmOut led1(LED1);
    PwmOut led2(LED2);
    PwmOut led3(LED3);

    while (true) {
        float x, y, z;
        x = abs(acc.getAccX());
        y = abs(acc.getAccY());
        z = abs(acc.getAccZ());
        led1 = 1.0f - x;
        led2 = 1.0f - y;
        led3 = 1.0f - z;
        wait(0.1f);        
    }
}
