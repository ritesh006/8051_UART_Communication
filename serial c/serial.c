#include <reg52.h>


sbit RS = P2^0;			/* here port 2.0 is renamed as RS (register_select)   */

sbit RW = P2^1;			/* Port 2.1 is renamed as a RW (read / write) */

sbit E = P2^2;		       /* Port 2.2 is renamed as a E (Enable) */



void send_command(unsigned int command_value);			/* Prototyping of sending command value function */

void send_data(unsigned int command_data);			/* Prototyping of sending data function */
	
void ms_delay(unsigned int time);				/* Prototyping of delay */

void main()
{
	

TMOD = 0x20;         // timer1 mode2

SCON=0x50 ;          // mode1 ren

TH1=0x0FD  ;     	  //9600 baud rate

TR1=1; //on timer1 

//tx 
while(1)
{
	
	
	send_command(0x38);					/* Initialize lcd of 2 lines and 5x7 dots use command (0x38) */
	
	send_command(0x0E);					/* When display is on cursor will blink  */	
	
	send_command(0x01);         /* This will clear the data which was previously wrote to the disply registers */
	send_command(0x80);						/* shift curser on 1st line */
	send_data ('A');
SBUF ='L';

while(!TI);
TI=0;
	
SBUF ='A';
while(!TI);
TI=0;
	
SBUF ='B';
while(!TI);
TI=0;
	

//rx
while(!RI);
P1=SBUF;
RI=0;
	
while(!RI);
P1=SBUF;
RI=0;

}
	
}
		void send_command(unsigned int command_value) /* this function send command value p1 to command register_ */
{
	P1 = command_value;			/* command value send to port P1 */
	RW = 0;									/* for accpet data, logic low enble the write data_ pin */
	RS = 0;								/* for selecting instruction command code register in LCD use RS = low */
	E = 1;								/* To latch data present in port 1 to LCD enable pin set to high */
	ms_delay(10);					/* add some delay of 10ms */
	E = 0;								/* then enable pin set to low for completion of latching data */
}


void send_data(unsigned int data_value)
{
	P1 = data_value;			/* Send data for display on lcd to Port 1 */
	RW = 0;								/* read / write pin enable using logic low for writing a data_ */
	RS = 1;								/* selecting data register using logic high */
	E = 1;								/* To latch data present in port 1 to LCD enable pin set to high */
	ms_delay(10);					/* add some delay of 10ms */
	E = 0;								/* then enable pin set to low for completion of latching data */

}


void ms_delay (unsigned int time)
{
	unsigned int i, j;
	
	/* if we pass time argument equal to 1000 then (time * 1 ms) equal to 1 sec of 
		 dealy will generate */
	

	for (i = 0; i < time; i++)
	{
		for (j = 0; j < 113; j++)					/* This will generate delay of 1 m.s. */
		{
		}
	}
	
}																																																																																																																		
																																																																																																																				