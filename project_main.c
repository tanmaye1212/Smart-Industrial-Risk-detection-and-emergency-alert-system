#include<lpc21xx.h>

#define sw ((IOPIN0>>6)&1)

int gas;

int flag0,flag1;

extern unsigned char Temp_Int,RH_Int;

int main()

{

uart0_init(9600);

adc_init();

DHT11_Start();

config_eint1();

config_eint0();

i2c_init();



uart0_tx_string(" SAI GANESH  E1\r\n SPANDANA   S3 \r\n PRAVIN     P2 \r\n");

 while(sw==1);









while(1)

{

gas=(adc_read(0)*330)/1023;





DHT11_ReadTemperature();



//

uart0_tx_string("  GAS:");

uart0_integer(gas);

uart0_tx_string("%\r\n");



	if( Temp_Int>65 || RH_Int>80 || gas>100){

	 uart0_tx_string(" \r\nTIME:");

	//i2c_print();

	uart0_tx_string(" : WARNING !!!!\r\n");

	uart0_tx_string("MACHINE RELAY OFF !!! \r\n        SHUT DOWN !!!\r\n\r\n");

	while(sw==1); }

   





if(flag1==1)

{

flag1=0;

uart0_tx_string("\r\n         FIRE DETECETD \r\nTIME : ");



//i2c_print();

uart0_tx_string(" : MACHINE RELAY OFF !!! \r\n         SHUT DOWN !!!\r\n\r\n");

while(sw==1);

//VICIntEnable=1<<15;

}

if(flag0==1)

{

flag0=0;



uart0_tx_string("\r\n           MACHINE SHAKING \r\nTIME : ");

//i2c_print();

uart0_tx_string(" : MACHINE RELAY OFF !!! \r\n        SHUT DOWN !!!\r\n\r\n");

while(sw==1);

//VICIntEnable=1<<15;

}



delay_ms(1000);







}}
