#include <stdio.h>
#include "./peripheral/include/light.h"
#include "./peripheral/include/temp.h"
#include <pthread.h>
#include "wiringPi.h"

typedef unsigned long uint32;

extern void controlLight();
extern uint32  getTempData();


void getTemp()
{
        while(1)
	{
            delay(2000);
	    uint32 tempData = getTempData();
	    printf("RH:%d.%d\n", (tempData >> 24) & 0xff, (tempData >> 16) & 0xff);
            printf("TMP:%d.%d\n", (tempData >> 8) & 0xff, tempData & 0xff);
	}
}

int main(int argc,char **agrv)
{
	//controlLight();
	pthread_t p_ctlLed,p_getTemp;
	pthread_create(&p_ctlLed, NULL, (void*)controlLight, NULL);
	pthread_create(&p_getTemp, NULL, (void*)getTemp, NULL);
	pthread_join(p_ctlLed, NULL);
	pthread_join(p_getTemp,NULL);
	return 1;
}
