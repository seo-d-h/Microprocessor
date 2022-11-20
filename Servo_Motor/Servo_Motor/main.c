/*
 * Servo_Motor.c
 *
 * Created: 2022-11-19 오후 3:19:22
 * Author : donghyun
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#define ROTATION_DELAY	1000	//1초 대기
#define  PULSE_MIN	1300		//최소 펄스 길이
#define	 PULSE_MID	3000
#define  PULSE_MAX	4700

void InitializeTimer1(void){
	TCCR1A |= (1<<WGM11);
	TCCR1B |= (1<<WGM12) | (1<<WGM13);
	
	TCCR1A |= (1<<COM1A1);
	TCCR1B |= (1<<CS11);
	ICR1 = 39999;
} 


int main(void)
{
    DDRB |= (1<<PB5);
	InitializeTimer1();
	
    while (1) 
    {
		OCR1A = PULSE_MIN;
		_delay_ms(ROTATION_DELAY);
		
		OCR1A = PULSE_MID;
		_delay_ms(ROTATION_DELAY);
		
		OCR1A = PULSE_MAX;
		_delay_ms(ROTATION_DELAY);
    }
	return 0;
}

