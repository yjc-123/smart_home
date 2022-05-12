#include <stdio.h>
#include <wiringPi.h>

#define LED 15
int initStatus = 1;


void initLed()
{
    if(initStatus)
    {
	printf("enter initLed function\n");
        wiringPiSetup(); //打开gpio设备

        pinMode(LED, OUTPUT); //设置引脚为输出模式

        initStatus = 0;
    }
}

void controlLed(int status)
{

	initLed();

        digitalWrite(LED, status);
}

