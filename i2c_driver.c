/*i2c_driver.c*/

#include <LPC21xx.H>

#include "header.h"


void i2c_init(void){

	PINSEL0|=0x50;//P0.2->SCL,P0.3->SDA

	I2SCLH=I2SCLL=75;//100Kbps freq

	

	/*select master mode*/

	I2CONCLR=(1<<2);//AA=0

	I2CONSET=(1<<6);//I2EN=1

}


/*i2c byte write frame*/

#define SI ((I2CONSET>>3)&1)

void i2c_send(u8 sa,u8 mr,u8 data){	

	/*step1:generate start condi*/

	I2CONSET=(1<<5);//STA=1

	I2CONCLR=(1<<3);//Clear SI*

	while(SI==0);//waiting for start condi

							 //to get generated

	I2CONCLR=(1<<5);//STA=0*

	

	/*step2:send sa+w & check ack*/

	I2DAT=sa;//send sa+w

	I2CONCLR=(1<<3);//SI=0

	while(SI==0);

	if(I2STAT==0x20){

		uart0_tx_string("err:sa+w\r\n");

		goto exit;

	}


	

	/*step3:send mr_addr & check ack*/

	I2DAT=mr;//send mr_addr

	I2CONCLR=(1<<3);//SI=0

	while(SI==0);

	if(I2STAT==0x30){

		uart0_tx_string("err:mr_addr\r\n");

		goto exit;

	}

	

	

	/*step4:send data & check ack*/

	I2DAT=data;//send data

	I2CONCLR=(1<<3);//SI=0

	while(SI==0);

	if(I2STAT==0x30){

		uart0_tx_string("err:data\r\n");

		goto exit;

	}

	

	/*step5:generate stop condi*/

	exit:

	I2CONSET=(1<<4);//STO=1

	I2CONCLR=(1<<3);//Clear SI*

}




/*i2c byte read frame*/

u8 i2c_read(u8 sa, u8 mr){

	u8 res=0;

	/*step1:generate start condi*/

	I2CONSET=(1<<5);

	I2CONCLR=(1<<3);

	while(SI==0);

	I2CONCLR=(1<<5);

	

	/*step2:send sa+w & check ack*/

	I2DAT=sa^1;//send sa+w

	I2CONCLR=(1<<3);//SI=0

	while(SI==0);

	if(I2STAT==0x20){

		uart0_tx_string("err:sa+w\r\n");

		goto exit;

	}

	

	/*step3:send mr_addr & check ack*/

	I2DAT=mr;//send mr_addr

	I2CONCLR=(1<<3);//SI=0

	while(SI==0);

	if(I2STAT==0x30){

		uart0_tx_string("err:mr_addr\r\n");

		goto exit;

	}

	

	/*step4:generate restart condi*/

	I2CONSET=(1<<5);

	I2CONCLR=(1<<3);

	while(SI==0);

	I2CONCLR=(1<<5);

	

	/*step5:send sa+r & check ack*/

	I2DAT=sa;//send SA+R

	I2CONCLR=(1<<3);//SI=0

	while(SI==0);

	if(I2STAT==0x48){

		uart0_tx_string("err:sa+r\r\n");

		goto exit;

	}

	

	/*step6:read data from slave & send noack*/

	I2CONCLR=(1<<3);//SI=0

	while(SI==0);//waiting for data receive

	res=I2DAT;

	

	/*step7:generate stop condi*/

	exit:

	I2CONSET=(1<<4);//STO=1

	I2CONCLR=(1<<3);//SI=0

		

	/*step8:return data*/

	return res;

}

