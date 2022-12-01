/*
 * bluetooth.c
 *
 * Created: 2022-11-28 오전 11:41:23
 * Author : 서동현
 */ 

/************************************************************************/
/*                             책                                       */
/************************************************************************/
//#define F_CPU 14745600UL
//#include <avr/io.h>
//#include <stdio.h>
//#include "UART1.h"
//
//FILE OUTPUT = FDEV_SETUP_STREAM(UART1_transmit, NULL, _FDEV_SETUP_WRITE);
//FILE INPUT = FDEV_SETUP_STREAM(NULL, UART1_receive, _FDEV_SETUP_READ);
//
//int main(void)
//{
	//uint8_t data;
	//
	//stdout = &OUTPUT;
	//stdin = &INPUT;
	//
	//UART_1_init();
	//while (1)
	//{
		//scanf("%c", &data);
		//printf("%c", data);
	//}
	//return 0;
//}




/*강의자료*/
//#define F_CPU 14745600UL // 외부 크리스탈 14.7456MHz
//#include <avr/io.h>
//#include <util/delay.h>
//#include <stdio.h>
//#include "lcd.h"
//#include "UART1.h"
//
//FILE OUTPUT = FDEV_SETUP_STREAM(UART1_transmit, NULL, _FDEV_SETUP_WRITE);
//FILE INPUT = FDEV_SETUP_STREAM(NULL, UART1_receive, _FDEV_SETUP_READ);
//
//char rx_char(void)
//{
	//while(!(UCSR0A & (1<<RXC0)));		//데이터 수신 대기
	//return UDR0;
//}
//
//void tx_char(uint8_t bData)
//{
	//while(!(UCSR0A & (1 << UDRE0)));		// 송신 가능 대기
	//UDR0 = bData;		//데이터 전송
//}
//
//int main(void)
//{
	//char bData = 'A';
	//stdout = &OUTPUT;
	//stdin = &INPUT;
	//
	//UCSR0A = 0x00; //flag 레지스터를 사용하지 않음
	//UCSR0B=0x18; //수신 enable, 송신 enable, 전송비트 8bit
	//UCSR0C=0x06; //비동기식 통신
	//UBRR0H=0;
	//UBRR0L=95; //9600bps
	//
	///* Replace with your application code */
	//while (1)
	//{
		////scanf("%c",&bData);
		//
		//tx_char(bData);
		//rx_char();
		//printf("%c",bData);
	//}
	//
	//return 0;
//}

/************************************************************************/
/*                          구글링                                       */
/************************************************************************/
#define F_CPU 14745600UL // 외부 크리스탈 16MHz
#include <avr/io.h>
#include <util/delay.h>

char rx_char(void)
{
	while(!(UCSR0A & 0x80));
	return UDR0;
}

void tx_char(uint8_t bData)
{
	while((UCSR0A&0x20) == 0)
	UDR0 = bData;
}

int main(void)
{
	uint8_t bData = 'A';
	
	UCSR0A=0x00; //flag 레지스터를 사용하지 않음
	UCSR0B=0x18; //수신 enable, 송신 enable, 전송비트 8bit
	UCSR0C=0x06; //비동기식 통신
	UBRR0H=0;
	UBRR0L=95; //9600bps
	
	/* Replace with your application code */
	while (1)
	{
		tx_char(bData);
		_delay_ms(2000);
	}
	
	return 0;
}



/************************************************************************/
/*                 전공책                                               */
/************************************************************************/
//#define F_CPU 14745600UL
//#include <avr/io.h>
//#include <util/delay.h>
//#include <avr/interrupt.h>
//
//unsigned char Udata, Bdata;
//void Init_USART_IntCon(void){
	//UCSR1A &= ~(1<<UDRE1);
	//UCSR1B = (1<<RXCIE1) | (1<<TXCIE1) | (1<<RXEN1) | (1<<TXEN1);
	//UBRR1H = 0x00;
	//UBRR1L = 95;
	//
	//UCSR0A &= ~(1<<UDRE0);
	//UCSR0B = (1<<RXCIE0) | (1<<TXCIE0) | (1<<RXEN0) | (1<<TXEN0);
	//UBRR0H = 0x00;
	//UBRR0L = 95;
	//
	//SREG |= 0x80;
//}
//
//ISR(USART1_RX_vect){
	//Udata = UDR1;
//}
//
//ISR(USART0_RX_vect){
	//Bdata = UDR0;
//}
//
//ISR(USART0_TX_vect){
	//
//}
//
//ISR(USART1_TX_vect){
	//
//}
//
//void SendData0(char data){
	//UCSR0A |= (1<<TXC0);
	//UDR0=data;
//}
//
//void SendData1(char data){
	//UCSR1A |= (1<<TXC1);
	//UDR1 = data;
//}
//
//void main(void){
	//Udata = 0;
	//Bdata = 0;
	//Init_USART_IntCon();
	//while(1){
		//if(Udata != 0){
			//SendData0(Udata);		// 터미널로
			//Udata = 0;
		//}
		//if(Bdata != 0){
			//SendData1(Bdata);
			//Bdata = 0;
		//}
	//}
	//
//}


//#define F_CPU 14745600UL
//#include <avr/io.h>
//#include <util/delay.h>
//#include <avr/interrupt.h>
//#include <stdio.h>
//#include "UART1.h"
//#include "lcd.h"
//
//FILE OUTPUT = FDEV_SETUP_STREAM(UART1_transmit, NULL, _FDEV_SETUP_WRITE);
//FILE INPUT = FDEV_SETUP_STREAM(NULL, UART1_receive, _FDEV_SETUP_READ);
//
//unsigned char ch;
//
//void putch_USART0(char data){
	//while(!(UCSR0A & (1<<UDRE0)));
	//UDR0 = data;
//}
//
//ISR(USART0_RX_vect){
	//ch = UDR0;
//}
//
//ISR(USART0_TX_vect){
	//UDR0 = ch;
//}
//
//unsigned char getch_USART0(void){
	//while(!(UCSR0A & (1<<RXC0)));
	//return UDR0;
//}
//
//void Init_USART0(void){
	//UCSR0A = 0x00;
	//UCSR0B = (1<<RXCIE0)|(1<<RXEN0) | (1<<TXEN0);
	//UCSR1C = (1<<UCSZ01) | (1<<UCSZ00);
	//UCSR0C &= ~(1<<UMSEL0);
	//
	//UBRR0H = 0;
	//UBRR0L = 95;
//}
//
//void main(void){
	//DDRB = 0xff;
	//PORTB = 0xff;
	//Init_USART0();
	//LCD_Clear();
	//stdout = &OUTPUT;
	//stdin = &INPUT;
	//LCD_Init();
	//LCD_Clear();
	//sei();
	//char tmp;
	//while(1){;}
//}