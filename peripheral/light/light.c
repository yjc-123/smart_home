#include <stdio.h>
#include <wiringPi.h>
#include "../include/led.h"

#define LED 1
int lightInitStatus = 1;
extern  void controlLed(int status);

void initLight()
{
    if(lightInitStatus)
    {
	printf("lightInitStatus is coming\n");

        wiringPiSetup(); //打开gpio设备

        pinMode(LED, INPUT); //设置引脚为输出模式

        lightInitStatus = 0;
    }
}

void controlLight()
{
        initLight();

	while(1)
	{
		delay(1000);
        	int status = digitalRead(LED);
		if(status)
		{
		    controlLed(1);
		}
		else
		{
		    controlLed(0);
		}
	}
}
