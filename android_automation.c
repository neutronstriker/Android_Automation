#include<reg52.h>
#include<stdio.h>

/*Program for Controlling Electrical Appliances via bluetooth module like HC-05 or HC-06 
connected to a microcontroller (in this case AT89s52) using Android Phone or Laptop 

Program Author : NeutroN StrikeR a.k.a N.Srinivas

*/

#define on 1
#define off 0

#define relay_port P2

sbit led = P1^0;   //Indicator Led

/* Port	1 used as input to uln2803 to drive relays*/

sbit relay1=P2^0;	 
sbit relay2=P2^1;
sbit relay3=P2^2;
sbit relay4=P2^3;
sbit relay5=P2^4;
sbit relay6=P2^5;
sbit relay7=P2^6;
sbit relay8=P2^7;

void main()
{
	unsigned char x;

	/* Serial port initialized at 9600 baud using crystal 11.0592Mhz*/

	SCON=0x52;
	TMOD=0x20;
	TH1=-3;
	TL1=-3;
	TR1=1;
	
	relay_port = 0;		 //Initialize PORT -1 
	
	led = 0; // Led Indicator Turned On
	
	while(RI == 0);
	printf("Bluetooth Android Automation via PC and Android \n \
			Designed by NeutroN Striker a.k.a N.Srinivas \n\n \	
			To Turn On Relay-1 send 'A' \n \
			to turn it off send 'a' \n \
			For Relay-2 'B' On 'b' Off \n \
			For Relay-3 'C' On 'c' Off \n \
			For Relay-4 'D' On 'd' Off \n \
			For Relay-5 'E' On 'e' Off \n \
			For Relay-6 'F' On 'f' Off \n \
			For Relay-7 'G' On 'g' Off \n \
			For Relay-8 'H' On 'h' Off \n \
			Send 'I' to turn On all \n \
			Send 'i' to turn Off all \n ");
			

	while(1)
	{
		while (RI==0);

		x=SBUF;
		switch(x)
		{
		case 'A':relay1 = on;
		printf("Relay-1 is ON\n");
		break;
		case 'a':relay1 = off;
		printf("Relay-1 is OFF\n");
		break;

		case 'B':relay2 = on;
		printf("Relay-2 is ON\n");
		break;
		case 'b':relay2 = off;
		printf("Relay-2 is OFF\n");
		break;
				
		case 'C':relay3 = on;
		printf("Relay-3 is ON\n");
		break;
		case 'c':relay3 = off;
		printf("Relay-3 is OFF\n");
		break;
		
		case 'D':relay4 = on;
		printf("Relay-4 is ON\n");
		break;
		case 'd':relay4 = off;
		printf("Relay-4 is OFF\n");
		break;
		
		case 'E':relay5 = on;
		printf("Relay-5 is ON\n");
		break;
		case 'e':relay5 = off;
		printf("Relay-5 is OFF\n");
		break;

		case 'F':relay6 = on;
		printf("Relay-6 is ON\n");
		break;
		case 'f':relay6 = off;
		printf("Relay-6 is OFF\n");
		break;

		case 'G':relay7 = on;
		printf("Relay-7 is ON\n");
		break;
		case 'g':relay7 = off;
		printf("Relay-7 is OFF\n");
		break;

		case 'H':relay8 = on;
		printf("Relay-8 is ON\n");
		break;
		case 'h':relay8 = off;
		printf("Relay-8 is OFF\n");
		break;

		case 'I':
		printf("ALL Relays are ON\n");
		
		relay_port = 0xff;
		break;

		case 'i':
		printf("ALL Relays are OFF\n");
		
		relay_port = 0;		

		}
			RI=0;
			x=0;	
		
	}
} 
