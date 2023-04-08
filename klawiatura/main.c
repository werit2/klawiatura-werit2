/*
 * klawiatura.c
 *
 * Created: 28.01.2023 14:16:49
 * Author : Andrzej
 */ 
#define F_CPU 16000000

#include <avr/io.h>
#include "atmel_start.h"
#include <stdlib.h>
#include <util/delay.h>

#define PRESS_VALID 0x01

uint8_t key_pressed; //volatile

/* Function prototypes */
void row_output_column_input(void);
void row_input_column_output(void);
void scan_keys(void);
void btn_debounce(void);
void twinkle(uint8_t number);




int main(void)
{
	
	
	/* Initializes MCU, drivers and middleware */
	//atmel_start_init();
	DDRB |= 0b00111100; //(1 << PORTB5);
	
	
	ROW0_set_dir(PORT_DIR_OUT);
	ROW0_set_level(0);
	
	ROW1_set_dir(PORT_DIR_OUT);
	ROW1_set_level(0);
	
	ROW2_set_dir(PORT_DIR_OUT);
	ROW2_set_level(0);
	
	COLUMN1_set_dir(PORT_DIR_IN);
	COLUMN1_set_level(1);
	
	COLUMN0_set_dir(PORT_DIR_IN);
	COLUMN0_set_level(1);
	//COLUMN1_set_pull_mode(PORT_PULL_UP);
	
	
	while (1) {
		ROW0_set_level(0);
		ROW1_set_level(1);
		ROW2_set_level(1);
		_delay_ms(1);
		if(COLUMN0_get_level() == 0 )  PORTB |= 0b00010000; //on //port 12
		else if(COLUMN1_get_level() == 0) PORTB &= 0b11101111; //off
		else if(COLUMN2_get_level() == 0)  PORTB |= 0b00010000; //on
		else PORTB &= 0b11101111; //off
		//_delay_ms(200);
		ROW0_set_level(1);
		ROW1_set_level(0);
		ROW2_set_level(1);
		_delay_ms(1);
		if(COLUMN0_get_level() == 0 )  PORTB |= 0b00100000; //on //port 13
		else if(COLUMN1_get_level() == 0) PORTB &= 0b11011111; //off
		else if(COLUMN2_get_level() == 0)  PORTB |= 0b00100000; //on
		else PORTB &= 0b11011111; //off
		_delay_ms(200);
		ROW0_set_level(1);
		ROW1_set_level(1);
		ROW2_set_level(0);
		_delay_ms(1);
		if(COLUMN0_get_level() == 0 )  PORTB |= 0b00001000; //on //port 11
		else if(COLUMN1_get_level() == 0) PORTB &= 0b11110111; //off
		else if(COLUMN2_get_level() == 0)  PORTB |= 0b00001000; //on
		else PORTB &= 0b11110111; //off
		
		/*
		if(COLUMN1_get_level() == 0 && COLUMN0_get_level() == 0 ) { PORTB |= 0b00100000; }
		else PORTB &= 0b11011111;
		
		if(COLUMN1_get_level() == 0 && COLUMN0_get_level() == 0 ) { PORTB |= 0b00001000; }
		else PORTB &= 0b11110111;
		
		*/
	}
	
}

void row_output_column_input()
{
	ROW0_set_dir(PORT_DIR_OUT);
	ROW0_set_level(0);
	ROW1_set_dir(PORT_DIR_OUT);
	ROW1_set_level(0);
	ROW2_set_dir(PORT_DIR_OUT);
	ROW2_set_level(0);

	COLUMN0_set_dir(PORT_DIR_IN);
	COLUMN0_set_level(1);
	COLUMN1_set_dir(PORT_DIR_IN);
	COLUMN1_set_level(1);
	COLUMN2_set_dir(PORT_DIR_IN);
	COLUMN2_set_level(1);
}

void row_input_column_output()
{
	ROW0_set_dir(PORT_DIR_IN);
	ROW0_set_level(1);
	ROW1_set_dir(PORT_DIR_IN);
	ROW1_set_level(1);
	ROW2_set_dir(PORT_DIR_IN);
	ROW2_set_level(1);

	COLUMN0_set_dir(PORT_DIR_OUT);
	COLUMN0_set_level(0);
	COLUMN1_set_dir(PORT_DIR_OUT);
	COLUMN0_set_level(0);
	COLUMN2_set_dir(PORT_DIR_OUT);
	COLUMN0_set_level(0);
}

void scan_keys()
{
	key_pressed = 0;

	if (!COLUMN0_get_level()) {
		key_pressed = 1;
		} else if (!COLUMN1_get_level()) {
		key_pressed = 2;
		} else if (!COLUMN2_get_level()) {
		key_pressed = 3;
	}

	row_input_column_output();

	if (!ROW0_get_level()) {
		key_pressed += 0;
		} else if (!ROW1_get_level()) {
		key_pressed += 3;
		} else if (!ROW2_get_level()) {
		key_pressed += 6;
		} else {
		key_pressed = 0;	
	}

	row_output_column_input();
}

void btn_debounce()
{
	/* GPIOR0 bit 0 (PRESS_VALID) is press validation flag */
	GPIOR0 |= PRESS_VALID;
	PORTB &= ~(1 << PORTC4);
	
	for (uint8_t i = 0; i < 10; i++) {
		/* If no button is pressed */
		if (COLUMN0_get_level() >= 1 && COLUMN1_get_level() >= 1 && COLUMN2_get_level() >= 1 ) {
			//three high levels mean no button is being pressed
			GPIOR0 &= ~PRESS_VALID;
			PORTB |= (1 << PORTC4);
			break;
		}
		_delay_ms(2);
	}
}

 void twinkle(uint8_t number) {
	 for (uint8_t i = 0; i< number; i++)
	 {
		 PORTB ^= 0b00100000; //(1 << PORTB5);
		 _delay_ms(500);
		 PORTB ^= 0b00100000; //(1 << PORTB5);
		 _delay_ms(500);
	 }
 }
