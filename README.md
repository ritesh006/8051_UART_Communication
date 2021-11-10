

Here we are going to program a serial communication using UART protocol and display data on serial window  P89V51RD2 controller used at 9600 baud rate pin 10 and 11 rx and tx pin used P3.0 n P3.1

/*----------------------------------------------------------------------------------- 
	timer 1 mode 2 initialize in TMOD register M1 = 1 , M0 = 0, 8bit auto reload mode
		 
	Bit position :		    bit7  bit6  bit5  bit4 | bit3  bit2  bit1  bit0
	bit name			    Gate   C/T   M1	   M0  | GATE   C/T	 M1	   M0
	bit value set:			  0    0      1     0  |   0     0    0     0			
										  2 in hex |          0 in hex
  TMOD = 0X20 				
	------------------------------------------------------------------------------------*/


    
	/*------------------------------------------------------------------------------------
	 UART mode1 initialize in SCON register, SM0 = 0, SM1= 1, 8-bit UART mode
	
	Bit position :		bit7  bit6  bit5  bit4 | bit3  bit2  bit1  bit0
	bit name     :		SM0    SM1   SM2   REN | TB8   RB8    TI    RI
	bit value set:		 0      1     X     1  |  0     0     0     0
                                     5 in hex  | 0 in hex                             
	SCON = 0x50; 
	REN = 1 ; for receiver enable 
	------------------------------------------------------------------------------------*/


    