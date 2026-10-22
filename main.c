/*
 * Test_AVR.c
 *
 * Created: 10/21/2026 12:43:07 PM
 * Author : 91989
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <ctype.h>
#define R1 PA0
#define R2 PA1
#define R3 PA2
#define C1 PA3 
#define C2 PA4
#define C3 PA5
#include <string.h> 
uint8_t segCC[] = {0X06,0X5B,0X4F, 0X66, 0X6D, 0X7D, 0X07,0X7F,0X6F};
// segCC[key - '0']
void Led_Init(void){
	DDRC = 0xFF;
}

void Led_Print(uint8_t num){
	PORTC = segCC[num-1];
	_delay_ms(5);
}

void Button_Init(void){
	DDRA |= (1<<R1) | (1<<R2) | (1<<R3);
	DDRA &= ~((1<<C1) | (1<<C2) | (1<<C3)); 
	PORTA |= (1<<C1) | (1<<C2) | (1<<C3);
}

char Keypad(void){
	PORTA &= ~(1<<PA0);
	PORTA |= (1<<PA1) | (1<<PA2);
	if(!(PINA & (1<<C1))) return '1';
	if(!(PINA & (1<<C2))) return '2';
	if(!(PINA & (1<<C3))) return '3';
	
	PORTA &= ~(1<<PA1);
	PORTA |= (1<<PA0) | (1<<PA2);
	if(!(PINA & (1<<C1))) return '4';
	if(!(PINA & (1<<C2))) return '5';
	if(!(PINA & (1<<C3))) return '6';
	
	PORTA &= ~(1<<PA2);
	PORTA |= (1<<PA1) | (1<<PA0);
	if(!(PINA & (1<<C1))) return '7';
	if(!(PINA & (1<<C2))) return '8';
	if(!(PINA & (1<<C3))) return '9';
	
	return '0';		
}

void LCD_Pulse(void){
	PORTD |= (1<<PD7);
	_delay_ms(5);
	PORTD &= ~(1<<PD7);
	_delay_ms(10);
}
void LCD_Cmd(unsigned char data){
	PORTD &= ~(1<<PD6);
	PORTD = (PORTD & 0xF0) | ((data>>4) & (0x0F));
	LCD_Pulse();
	PORTD = (PORTD & 0xF0) | ((data) & (0x0F));
	LCD_Pulse();
}
void LCD_Data(unsigned char data){
	PORTD |= (1<<PD6);
	PORTD = (PORTD & 0xF0) | ((data>>4) & (0x0F));
	LCD_Pulse();
	PORTD = (PORTD & 0xF0) | ((data) & (0x0F));
	LCD_Pulse();
}

void LCD_Init(void){
	DDRD |= ((1<<PD0)|(1<<PD1)|(1<<PD2)|(1<<PD3)|(1<<PD6)|(1<<PD7));
	LCD_Cmd(0x02);
	LCD_Cmd(0x28);
	LCD_Cmd(0x06);
	LCD_Cmd(0x0C);
	LCD_Cmd(0x01);
	_delay_ms(50);
}

void LCD_Print(char *str){
	while(*str != '\0'){
		LCD_Data(*str);
		str++;
	}
}

void lcdSetcursor(uint8_t col, uint8_t row){
	unsigned address = row ? 0xC0 + col : 0x80 + col;
	LCD_Cmd(address);
}
int main(void)
{
	DDRB &= ~(1<<PB7);
	PORTB |= (1<<PB7);
    Led_Init();
	Button_Init();
	LCD_Init();
	LCD_Print("KEY:");
	lcdSetcursor(0,2);
	LCD_Print("BTN1:");
	//Led_Print(5); function for led print
	char key;
	char curr_key;
	char state[5];
	uint8_t prev_btn, curr_btn;
	prev_btn = 1;
    while (1) 
    {
    
	key = Keypad();
	if(key!='0'){
		curr_key = key;
	}
	Led_Print(curr_key-'0');
	lcdSetcursor(5,0);
	LCD_Data(curr_key);
	_delay_ms(20);
	
	curr_btn = !!(PINB & (1<<PB7));
	if(prev_btn==1 && curr_btn==0){
		 if (strcmp(state, "STOP") == 0) {
			 strcpy(state, "START"); 
			 lcdSetcursor(6,2);
			 LCD_Print("START");
			 } else {
				 strcpy(state, "STOP"); 
				 lcdSetcursor(6,2);
				 LCD_Print("STOP ");
			 
		 }
		
	}
	prev_btn = curr_btn;

    }
}

