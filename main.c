/*#define F_CPU 8000000UL
#include <avr/io.h>

// UART Initialization
void UART_Init(unsigned long baud)
{
	unsigned int ubrr = F_CPU/16/baud - 1;

	UBRRH = (unsigned char)(ubrr>>8);
	UBRRL = (unsigned char)ubrr;

	UCSRB = (1<<RXEN) | (1<<TXEN);        // Enable RX, TX
	UCSRC = (1<<URSEL) | (1<<UCSZ0) | (1<<UCSZ1); // 8-bit data
}

// Receive character
char UART_RxChar()
{
	while(!(UCSRA & (1<<RXC)));
	return UDR;
}

int main(void)
{
	char data;

	DDRB = 0x0F;      // PB0–PB3 output
	PORTB = 0x00;     // All relays OFF (Active HIGH)

	UART_Init(9600);

	while(1)
	{
		data = UART_RxChar();

		switch(data)
		{
			case '1': PORTB |= (1<<PB0); break;   // Bulb ON
			case 'A': PORTB &= ~(1<<PB0); break;  // Bulb OFF

			case '2': PORTB |= (1<<PB1); break;   // Motor ON
			case 'B': PORTB &= ~(1<<PB1); break;  // Motor OFF

			case '3': PORTB |= (1<<PB2); break;   // LED ON
			case 'C': PORTB &= ~(1<<PB2); break;  // LED OFF

			case '4': PORTB |= (1<<PB3); break;   // Buzzer ON
			case 'D': PORTB &= ~(1<<PB3); break;  // Buzzer OFF
		}
	}
}*/
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

#define RS PD2
#define EN PD3

void LCD_Command(unsigned char cmnd)
{
	PORTD = (PORTD & 0x0F) | (cmnd & 0xF0);
	PORTD &= ~(1<<RS);
	PORTD |= (1<<EN);
	_delay_ms(1);
	PORTD &= ~(1<<EN);

	PORTD = (PORTD & 0x0F) | (cmnd<<4);
	PORTD |= (1<<EN);
	_delay_ms(1);
	PORTD &= ~(1<<EN);
}

void LCD_SetCursor(unsigned char row, unsigned char col)
{
	unsigned char pos;

	if(row==0)
	pos = 0x80 + col;
	else
	pos = 0xC0 + col;

	LCD_Command(pos);
}


void LCD_Char(unsigned char data)
{
	PORTD = (PORTD & 0x0F) | (data & 0xF0);
	PORTD |= (1<<RS);
	PORTD |= (1<<EN);
	_delay_ms(1);
	PORTD &= ~(1<<EN);

	PORTD = (PORTD & 0x0F) | (data<<4);
	PORTD |= (1<<EN);
	_delay_ms(1);
	PORTD &= ~(1<<EN);
}

void LCD_String(const char *str)
{
	while(*str)
	{
		LCD_Char(*str++);
	}
}

void LCD_Init()
{
	DDRD = 0xFC;
	_delay_ms(20);

	LCD_Command(0x02);
	LCD_Command(0x28);
	LCD_Command(0x0C);
	LCD_Command(0x06);
	LCD_Command(0x01);
}

void UART_Init(unsigned long baud)
{
	unsigned int ubrr = F_CPU/16/baud - 1;

	UBRRH = (unsigned char)(ubrr>>8);
	UBRRL = (unsigned char)ubrr;

	UCSRB = (1<<RXEN) | (1<<TXEN);
	UCSRC = (1<<URSEL) | (1<<UCSZ0) | (1<<UCSZ1);
}

char UART_RxChar()
{
	while(!(UCSRA & (1<<RXC)));
	return UDR;
}

int main(void)
{
	char data;

	DDRB = 0x0F;
	PORTB = 0x00;

	LCD_Init();
	UART_Init(9600);

	//LCD_String("Smart Home");
	LCD_Command(0x01);
	LCD_SetCursor(0,0);
	LCD_String("SMART HOME");

	LCD_SetCursor(1,0);
	LCD_String("AUTOMATION");


	while(1)
	{
		data = UART_RxChar();

		switch(data)
		{
			case '1':
			PORTB |= (1<<PB0);
			LCD_Command(0x01);
			LCD_String("Bulb ON");
			break;

			case 'A':
			PORTB &= ~(1<<PB0);
			LCD_Command(0x01);
			LCD_String("Bulb OFF");
			break;

			case '2':
			PORTB |= (1<<PB1);
			LCD_Command(0x01);
			LCD_String("Motor ON");
			break;

			case 'B':
			PORTB &= ~(1<<PB1);
			LCD_Command(0x01);
			LCD_String("Motor OFF");
			break;

			case '3':
			PORTB |= (1<<PB2);
			LCD_Command(0x01);
			LCD_String("LED ON");
			break;

			case 'C':
			PORTB &= ~(1<<PB2);
			LCD_Command(0x01);
			LCD_String("LED OFF");
			break;

			case '4':
			PORTB |= (1<<PB3);
			LCD_Command(0x01);
			LCD_String("Buzzer ON");
			break;

			case 'D':
			PORTB &= ~(1<<PB3);
			LCD_Command(0x01);
			LCD_String("Buzzer OFF");
			break;
		}
	}
}
//starting ma relay ON ane pachi 1 = ON
/*#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

#define RS PD2
#define EN PD3

void LCD_Command(unsigned char cmnd)
{
	PORTD = (PORTD & 0x0C) | (cmnd & 0xF0);
	PORTD &= ~(1<<RS);
	PORTD |= (1<<EN);
	_delay_ms(1);
	PORTD &= ~(1<<EN);

	PORTD = (PORTD & 0x0C) | (cmnd<<4);
	PORTD |= (1<<EN);
	_delay_ms(1);
	PORTD &= ~(1<<EN);
}

void LCD_SetCursor(unsigned char row, unsigned char col)
{
	unsigned char pos;

	if(row==0)
	pos = 0x80 + col;
	else
	pos = 0xC0 + col;

	LCD_Command(pos);
}

void LCD_Char(unsigned char data)
{
	PORTD = (PORTD & 0x0C) | (data & 0xF0);
	PORTD |= (1<<RS);
	PORTD |= (1<<EN);
	_delay_ms(1);
	PORTD &= ~(1<<EN);

	PORTD = (PORTD & 0x0C) | (data<<4);
	PORTD |= (1<<EN);
	_delay_ms(1);
	PORTD &= ~(1<<EN);
}

void LCD_String(const char *str)
{
	while(*str)
	{
		LCD_Char(*str++);
	}
}

void LCD_Init()
{
	DDRD = 0xFC;
	_delay_ms(20);

	LCD_Command(0x02);
	LCD_Command(0x28);
	LCD_Command(0x0C);
	LCD_Command(0x06);
	LCD_Command(0x01);
}

void UART_Init(unsigned long baud)
{
	unsigned int ubrr = F_CPU/16/baud - 1;

	UBRRH = (unsigned char)(ubrr>>8);
	UBRRL = (unsigned char)ubrr;

	UCSRB = (1<<RXEN) | (1<<TXEN);
	UCSRC = (1<<URSEL) | (1<<UCSZ0) | (1<<UCSZ1);
}

char UART_RxChar()
{
	while(!(UCSRA & (1<<RXC)));
	return UDR;
}

int main(void)
{
	
	MCUCSR |= (1<<JTD);
	MCUCSR |= (1<<JTD);
	
	
	char data;

	DDRB = 0x0F;
	PORTB = 0x0F;   // ? All relays OFF (Active LOW)

	LCD_Init();
	UART_Init(9600);

	LCD_Command(0x01);
	LCD_SetCursor(0,0);
	LCD_String("SMART HOME");

	LCD_SetCursor(1,0);
	LCD_String("AUTOMATION");

	while(1)
	{
		data = UART_RxChar();

		switch(data)
		{
			case 'A':
			PORTB &= ~(1<<PB0);
			LCD_Command(0x01);
			LCD_String("Bulb ON");
			break;

			case '1':
			PORTB |= (1<<PB0);
			LCD_Command(0x01);
			LCD_String("Bulb OFF");
			break;

			case 'B':
			PORTB &= ~(1<<PB1);
			LCD_Command(0x01);
			LCD_String("Motor ON");
			break;

			case '2':
			PORTB |= (1<<PB1);
			LCD_Command(0x01);
			LCD_String("Motor OFF");
			break;

			case 'C':
			PORTB &= ~(1<<PB2);
			LCD_Command(0x01);
			LCD_String("LED ON");
			break;

			case '3':
			PORTB |= (1<<PB2);
			LCD_Command(0x01);
			LCD_String("LED OFF");
			break;

			case 'D':
			PORTB &= ~(1<<PB3);
			LCD_Command(0x01);
			LCD_String("Buzzer ON");
			break;

			case '4':
			PORTB |= (1<<PB3);
			LCD_Command(0x01);
			LCD_String("Buzzer OFF");
			break;
		}
	}
}*/
/*#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

#define RS PD2
#define EN PD3

// -------- LCD Functions Same --------
void LCD_Command(unsigned char cmnd)
{
	PORTD = (PORTD & 0x0C) | (cmnd & 0xF0);
	PORTD &= ~(1<<RS);      // RS = 0
	PORTD |= (1<<EN);
	_delay_ms(5);
	PORTD &= ~(1<<EN);

	PORTD = (PORTD & 0x0C) | (cmnd<<4);
	PORTD &= ~(1<<RS);      // ?? MUST AGAIN
	PORTD |= (1<<EN);
	_delay_ms(5);
	PORTD &= ~(1<<EN);
}

void LCD_Char(unsigned char data)
{
	PORTD = (PORTD & 0x0C) | (data & 0xF0);
	PORTD |= (1<<RS);       // RS = 1
	PORTD |= (1<<EN);
	_delay_ms(5);
	PORTD &= ~(1<<EN);

	PORTD = (PORTD & 0x0C) | (data<<4);
	PORTD |= (1<<RS);       // ?? AGAIN IMPORTANT
	PORTD |= (1<<EN);
	_delay_ms(5);
	PORTD &= ~(1<<EN);
}

void LCD_SetCursor(unsigned char row, unsigned char col)
{
	unsigned char pos;

	if(row==0)
	pos = 0x80 + col;
	else
	pos = 0xC0 + col;

	LCD_Command(pos);
}


void LCD_String(const char *str)
{
	while(*str)
	{
		LCD_Char(*str++);
	}
}

void LCD_Init()
{
	DDRD = 0xFC;
	_delay_ms(50);

	LCD_Command(0x02); // 4-bit mode
	LCD_Command(0x28); // 2 line, 5x7
	LCD_Command(0x0C); // display ON
	LCD_Command(0x06); // entry mode
	LCD_Command(0x01); // clear

	_delay_ms(10);
}

// -------- UART --------
void UART_Init(unsigned long baud)
{
	unsigned int ubrr = F_CPU/16/baud - 1;

	UBRRH = (unsigned char)(ubrr>>8);
	UBRRL = (unsigned char)ubrr;

	UCSRB = (1<<RXEN) | (1<<TXEN);
	UCSRC = (1<<URSEL) | (1<<UCSZ0) | (1<<UCSZ1);
}

char UART_RxChar()
{
	while(!(UCSRA & (1<<RXC)));
	return UDR;
}

// -------- MAIN --------
int main(void)
{
	MCUCSR |= (1<<JTD);
	MCUCSR |= (1<<JTD);   // write twice within 4 cycles
	char data;

	DDRC = 0x0F;       // PC0-PC3 output
	PORTC = 0x0F;      // All relays OFF (Active LOW)

	_delay_ms(500);    // ?? Important: Startup stability

	LCD_Init();
	UART_Init(9600);

	LCD_Command(0x01);
	LCD_SetCursor(0,0);
	LCD_String("SMART HOME");

	LCD_SetCursor(1,0);
	LCD_String("AUTOMATION");

	while(1)
	{
		data = UART_RxChar();

		switch(data)
		{
			case 'A':
			PORTC &= ~(1<<PC0);
			LCD_SetCursor(0,0);
			LCD_String("Bulb ON");
			LCD_SetCursor(0,1);
			LCD_String("					");
			break;

			case '1':
			PORTC |= (1<<PC0);
			LCD_SetCursor(0,0);
			LCD_String("Bulb OFF");
			LCD_SetCursor(0,1);
			LCD_String("					");
			break;

			case 'B':
			PORTC &= ~(1<<PC1);
			LCD_SetCursor(0,0);
			LCD_String("Motor ON");
			LCD_SetCursor(0,1);
			LCD_String("					");
			break;

			case '2':
			PORTC |= (1<<PC1);
			LCD_SetCursor(0,0);
			LCD_String("Motor OFF");
			LCD_SetCursor(0,1);
			LCD_String("					");
			break;

			case 'C':
			PORTC &= ~(1<<PC2);
			LCD_SetCursor(0,0);
			LCD_String("LED ON");
			LCD_SetCursor(0,1);
			LCD_String("					");
			break;

			case '3':
			PORTC |= (1<<PC2);
			LCD_SetCursor(0,0);
			LCD_String("LED OFF");
			LCD_SetCursor(0,1);
			LCD_String("					");
			break;

			case 'D':
			PORTC &= ~(1<<PC3);
			LCD_SetCursor(0,0);
			LCD_String("Buzzer ON");
			LCD_SetCursor(0,1);
			LCD_String("					");
			break;

			case '4':
			PORTC |= (1<<PC3);
			LCD_SetCursor(0,0);
			LCD_String("Buzzer OFF");
			LCD_SetCursor(0,1);
			LCD_String("					");
			break;
		}
	}
}*/
