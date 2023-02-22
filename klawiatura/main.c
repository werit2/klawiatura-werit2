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
	atmel_start_init();
	DDRB |= 0b00111100; //(1 << PORTB5);

	while (1) {
		/* Sleep until key press wakes up the CPU */
		//sleep_mode();
		/* PRESS_VALID flag in GPIOR0 is high if a valid press is detected */
		
		btn_debounce();
		_delay_ms(20);

		/* If the key press was valid */
		if ((GPIOR0 & PRESS_VALID) == PRESS_VALID) {
			scan_keys();
			twinkle(key_pressed);
			/* Wait for all buttons to be released */
			while ((GPIOR0 & PRESS_VALID) == PRESS_VALID) { 
				 
				btn_debounce();
				_delay_ms(20);
			}
		}
		//_delay_ms(20);
		twinkle(1);
		PORTB &= ~(1 << PORTC4);
		_delay_ms(3000);
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
		if (COLUMN0_get_level() == 1 && COLUMN1_get_level() == 1 && COLUMN2_get_level() == 1 ) {
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
