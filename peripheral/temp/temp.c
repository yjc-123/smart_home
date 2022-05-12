#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
 
typedef unsigned char uint8;
typedef unsigned int  uint16;
typedef unsigned long uint32;
 
#define HIGH_TIME 32
 
int pinNumber = 16;
uint32 databuf;
  
uint32 getTempData(void)
{
    uint8 i;
    databuf = 0;
    wiringPiSetup(); 
    pinMode(pinNumber, OUTPUT); // set mode to output
    digitalWrite(pinNumber, 0); // output a high level 
    delay(25);
    digitalWrite(pinNumber, 1); // output a low level 
    pinMode(pinNumber, INPUT); // set mode to input
 
    delayMicroseconds(27);
    if (digitalRead(pinNumber) == 0) //SENSOR ANS
    {
        while (!digitalRead(pinNumber)); //wait to high
 
        for (i = 0; i < 32; i++)
        {
            while (digitalRead(pinNumber)); //data clock start
            while (!digitalRead(pinNumber)); //data start
            delayMicroseconds(HIGH_TIME);
            databuf *= 2;
            if (digitalRead(pinNumber) == 1) //1
            {
                databuf++;
            }
        }
 
        return databuf;
    }
    else
    {
        return databuf;
    }
}
  
