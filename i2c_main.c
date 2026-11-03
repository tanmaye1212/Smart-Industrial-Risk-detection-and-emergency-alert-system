#include<lpc21xx.h>
//#include"header.h"
unsigned int h,s,m;
        void i2c_print(void){

		h=i2c_read(0xD1,0x2);//read hrs

		m=i2c_read(0xD1,0x1);//read mins

		s=i2c_read(0xD1,0x0);//read secs

		

        uart0_tx((h/0x10)+48);

		uart0_tx((h%0x10)+48);

		uart0_tx(':');

		

		uart0_tx((m/0x10)+48);

		uart0_tx((m%0x10)+48);

		uart0_tx(':');

		

		uart0_tx((s/0x10)+48);

		uart0_tx((s%0x10)+48);

	//z	uart0_tx_string("\r\n");

	  }
//
//		void i2c_store(void)
//		{ 	
//		h=i2c_read(0xD1,0x2);//read hrs
//
//		m=i2c_read(0xD1,0x1);//read mins
//
//		s=i2c_read(0xD1,0x0);//read secs
//		           }

	




