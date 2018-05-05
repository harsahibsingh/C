
/*
 * exam_day24.c
 *
 * Created: 04-05-2018 00:15:18
 * Author : DESD-34
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include <avr/interrupt.h>
#include <string.h>
#include <util/delay.h>
#include <stdio.h>
void enable();
void lcdCmd(unsigned char );
void lcdData(unsigned char );
void uartInit();
void lcdInit();
void dataTxc(char * );
void lcdString(char *);
void buzzer(int n);

char gch[50];
unsigned volatile  int i=0;
int volatile flag=0;

char user[]="sameer";
char pass[]="Ajinkya";


int main(void)
{

    DDRA=0xFF;
	DDRC=0xff;
	PORTC=0x0F;
	lcdInit();
	uartInit();
	
	dataTxc("Enter Username  : ");
	lcdString("Enter Username  : ");
    while (1)
	{
		
		
		if(flag==1)
		{
			PORTC=0X01;
			flag=0;
			if(!(strcmp(gch,user)))
			{
				dataTxc("Enter password : ");
				lcdString("Enter password : ");
				while(flag==0);
				if(flag==1)
				{
					flag=0;
					if(!(strcmp(gch,pass)))
					{
						dataTxc("Root Access Granted  ");
						lcdString("Root Access Granted  ");
					}
					else
					{
						dataTxc("Invalid Password !");
						lcdString("Invalid Password !");
						buzzer(20);
					}
					
				}
			}
			else
			{
				dataTxc("Invalid username");
				lcdString("Invalid username");
				buzzer(2);
			
				
			}
			
			
		}
		
		
	}
	
}

void buzzer(int n)
{
	int l;
	for(l=0;l<n;l++)
	{
		PORTA|=0X08;
		_delay_ms(200);
		PORTA&=~(1<<3);
		_delay_ms(200);
		PORTA|=0X08;
		_delay_ms(200);
		PORTA&=~(1<<3);
		_delay_ms(200);
	}
	
}
void enable()
{
	PORTA|=(1<<2);
	_delay_ms(20);
	PORTA&=~(1<<2);
	_delay_ms(20);
	
}

void lcdCmd(unsigned char ch)
{
	PORTA=ch&(0xF0);
	PORTA&=~(1<<0);
	enable();
	ch=ch<<4;
	PORTA=ch&(0xF0);
	PORTA&=~(1<<0);
	enable();
}

void lcdData(unsigned char ch)
{
	PORTA=ch&(0xF0);
	PORTA|=(1<<0);
	enable();
	ch=ch<<4;
	PORTA=ch&(0xF0);
	PORTA|=(1<<0);
	enable();	
}

void lcdString(char *ch)
{
	lcdCmd(0x01);
	unsigned int m;
	for(m=0;ch[m]!='\0';++m)
	{
		lcdData(ch[m]);
		_delay_ms(20);
	}

	
	
}
void lcdInit()
{
	lcdCmd(0x28);
	lcdCmd(0x0F);
	lcdCmd(0x01);
	//lcdCmd(0x06);
	lcdCmd(0x14);
	
}

void uartInit()
{
	UBRR1L=0x67;
	UCSR1B=(1<<RXEN1)|(1<<TXEN1);
	UCSR1C=(1<<UCSZ0)|(1<<UCSZ1);
	sei();
}

void dataTxc(char *ch)
{
	
	unsigned int j=0;
	while(!(UCSR1A&(1<<UDRE1)));
	UDR1='\n';
	while(!(UCSR1A&(1<<UDRE1)));
	UDR1='\r';
	
	while(ch[j]!='\0') 
	{
		while(!(UCSR1A&(1<<UDRE1)));
		UDR1=ch[j++];
	}
	
	UCSR1B=(1<<RXEN1)|(1<<TXEN1)|(1<<RXCIE);
	
}

ISR(USART1_RX_vect)
{
	cli();
	gch[i++]=UDR1;
	
	
	if(gch[i-1]=='\r')
	{
		gch[i-1]='\0';
		flag=1;
		PORTC=~PORTC;
		i = 0;
		
	}
	
	sei();
}

