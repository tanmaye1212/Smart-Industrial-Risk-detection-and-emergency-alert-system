#include<lpc21xx.h>
//undigned int h,s,m;
//#include <LPC21xx.H>

#include "header.h"
 //extern int flag0,flag1;
  extern int flag0,flag1,h,s,m;
 //extern int flag,h,s,m;
 typedef unsigned int u32;

u32 count2;


void EINT0_Handler(void) __irq{

	//count2++;//def task of isr
    flag0=1;
	EXTINT=1;//Clear EINT0 Intr Flag
//	uart0_tx_string("VIB DET\r\n");

VICVectAddr=0;

}


void config_eint0(void){

	PINSEL1|=0x1;//P0.16->EINT0

	EXTMODE |= 1<<0;//EINT0->Edge trigger

	EXTPOLAR &= ~(1<<0);//EINT0->Active low

	VICIntSelect=0;//all intrs are IRQs

	VICVectCntl0=14|(1<<5);//init slot1

	VICVectAddr0=(u32)EINT0_Handler;//init slot1

	VICIntEnable=(1<<14);//En EINT0 

}
void EINT1_Handler(void) __irq{

	//count2++;//def task of isr

	flag1=1;
	EXTINT=2;//Clear EINT0 Intr Flag
//	uart0_tx_string("flame DET\r\n");
	//i2c_print();
     //VICIntEnClr=1<<15;


	VICVectAddr=0;

}


void config_eint1(void){

	PINSEL0|=0x20000000;//P0.16->EINT0

	EXTMODE|=(1<<1);//EINT0->Edge trigger

	EXTPOLAR &= ~(1<<1);//EINT0->Active low

	VICIntSelect=0;//all intrs are IRQs

	VICVectCntl1=15|(1<<5);//init slot1

	VICVectAddr1=(u32)EINT1_Handler;//init slot1

	VICIntEnable=(1<<15);//En EINT0 

}

