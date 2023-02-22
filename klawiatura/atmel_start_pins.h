/*
 * Code generated from START.
 *
 * This file will be overwritten when reconfiguring your START project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */
#ifndef ATMEL_START_PINS_H_INCLUDED
#define ATMEL_START_PINS_H_INCLUDED

#include <avr/io.h>
#include <stdlib.h>
//#include "port.h"



enum port_pull_mode {
	PORT_PULL_OFF,
	PORT_PULL_UP,
};

enum port_dir {
	PORT_DIR_IN,
	PORT_DIR_OUT,
	//PORT_DIR_OFF,
};


/**
 * \brief Set ROW2 pull mode
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] pull_mode Pin pull mode
 */
static inline void ROW2_set_pull_mode(const enum port_pull_mode pull_mode)
{
	//PORTC_set_pin_pull_mode(4, pull_mode);
	if (pull_mode == PORT_PULL_UP) {
		PORTC |= (1 << PORTC4);
	} else if (pull_mode == PORT_PULL_OFF) {
		PORTC &= ~(1 << PORTC4);
	}
	
}

/**
 * \brief Set ROW2 data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void ROW2_set_dir(const enum port_dir dir)
{
	//PORTC_set_pin_dir(4, dir);
	if (dir == PORT_DIR_OUT) {
		DDRC |= (1 << PORTC4);
	} else if (dir == PORT_DIR_IN) {
		DDRC &= ~(1 << PORTC4);
	}
}

/**
 * \brief Set ROW2 input/sense configuration
 *
 * Enable/disable ROW2 digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_INTDISABLE_gc    = Iterrupt disabled but input buffer enabled
 *                PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
/*
static inline void ROW2_set_isc(const PORT_ISC_t isc)
{
	PORTC_pin_set_isc(4, isc);
}
*/
/**
 * \brief Set ROW2 inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on ROW2 is inverted
 *                     false = I/O on ROW2 is not inverted
 */
/*
static inline void ROW2_set_inverted(const bool inverted)
{
	PORTC_pin_set_inverted(4, inverted);
}
*/
/**
 * \brief Set ROW2 level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void ROW2_set_level(const uint8_t level)
{
	//PORTC_set_pin_level(4, level);
	if (level) {
		PORTC |= (1 << PORTC4);
	} else {
		PORTC &= ~(1 << PORTC4);
	}
	
}

/**
 * \brief Toggle output level on ROW2
 *
 * Toggle the pin level
 */
static inline void ROW2_toggle_level()
{
	PORTC ^= (1 << PORTC4);
}

/**
 * \brief Get level on ROW2
 *
 * Reads the level on a pin
 */
static inline uint8_t ROW2_get_level()
{
	//return PORTC_get_pin_level(4);
	if (PINC & (1 << PINC4)) {
		return 1;
	} else {
		return 0;
	}
}

/**
 * \brief Set ROW0 pull mode
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] pull_mode Pin pull mode
 */
static inline void ROW0_set_pull_mode(const enum port_pull_mode pull_mode)
{
	//PORTC_set_pin_pull_mode(1, pull_mode);
	if (pull_mode == PORT_PULL_UP) {
		PORTC |= (1 << PORTC1);
	} else if (pull_mode == PORT_PULL_OFF) {
		PORTC &= ~(1 << PORTC1);
	}
}

/**
 * \brief Set ROW0 data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void ROW0_set_dir(const enum port_dir dir)
{
	//PORTC_set_pin_dir(1, dir);
	if (dir == PORT_DIR_OUT) {
		DDRC |= (1 << PORTC1);
	} else if (dir == PORT_DIR_IN) {
		DDRC &= ~(1 << PORTC1);
	}
}

/**
 * \brief Set ROW0 input/sense configuration
 *
 * Enable/disable ROW0 digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_INTDISABLE_gc    = Iterrupt disabled but input buffer enabled
 *                PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
/*
static inline void ROW0_set_isc(const PORT_ISC_t isc)
{
	PORTC_pin_set_isc(1, isc);
}
*/
/**
 * \brief Set ROW0 inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on ROW0 is inverted
 *                     false = I/O on ROW0 is not inverted
 */
/*
static inline void ROW0_set_inverted(const bool inverted)
{
	PORTC_pin_set_inverted(1, inverted);
}
*/
/**
 * \brief Set ROW0 level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void ROW0_set_level(const uint8_t level)
{
	//PORTC_set_pin_level(1, level);
	if (level) {
		PORTC |= (1 << PORTC1);
	} else {
		PORTC &= ~(1 << PORTC1);
	}
}

/**
 * \brief Toggle output level on ROW0
 *
 * Toggle the pin level
 */
static inline void ROW0_toggle_level()
{
	PORTC ^= (1 << PORTC1);
}

/**
 * \brief Get level on ROW0
 *
 * Reads the level on a pin
 */
static inline uint8_t ROW0_get_level()
{
	//return PORTC_get_pin_level(1);
	if (PINC & (1 << PINC1)) {
		return 1;
	} else {
		return 0;
	}
}

/**
 * \brief Set ROW1 pull mode
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] pull_mode Pin pull mode
 */
static inline void ROW1_set_pull_mode(const enum port_pull_mode pull_mode)
{
	//PORTC_set_pin_pull_mode(5, pull_mode);
	if (pull_mode == PORT_PULL_UP) {
		PORTC |= (1 << PORTC5);
	} else if (pull_mode == PORT_PULL_OFF) {
		PORTC &= ~(1 << PORTC5);
	}
}

/**
 * \brief Set ROW1 data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void ROW1_set_dir(const enum port_dir dir)
{
	//PORTC_set_pin_dir(5, dir);
	if (dir == PORT_DIR_OUT) {
		DDRC |= (1 << PORTC5);
	} else if (dir == PORT_DIR_IN) {
		DDRC &= ~(1 << PORTC5);
	}
}

/**
 * \brief Set ROW1 input/sense configuration
 *
 * Enable/disable ROW1 digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_INTDISABLE_gc    = Iterrupt disabled but input buffer enabled
 *                PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
/*
static inline void ROW1_set_isc(const PORT_ISC_t isc)
{
	PORTC_pin_set_isc(5, isc);
}
*/
/**
 * \brief Set ROW1 inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on ROW1 is inverted
 *                     false = I/O on ROW1 is not inverted
 */
/*
static inline void ROW1_set_inverted(const bool inverted)
{
	PORTC_pin_set_inverted(5, inverted);
}
*/
/**
 * \brief Set ROW1 level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void ROW1_set_level(const uint8_t level)
{
	//PORTC_set_pin_level(5, level);
	if (level) {
		PORTC |= (1 << PORTC5);
	} else {
		PORTC &= ~(1 << PORTC5);
	}
}

/**
 * \brief Toggle output level on ROW1
 *
 * Toggle the pin level
 */
static inline void ROW1_toggle_level()
{
	PORTC ^= (1 << PORTC5);
}

/**
 * \brief Get level on ROW1
 *
 * Reads the level on a pin
 */
static inline uint8_t ROW1_get_level()
{
	//return PORTC_get_pin_level(5);
	if (PINC & (1 << PINC5)) {
		return 1;
	} else {
		return 0;
	}
}

// 
/**
 * \brief Set ROW3 pull mode
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] pull_mode Pin pull mode
 */
//static inline void ROW3_set_pull_mode(const enum port_pull_mode pull_mode)
//{
	//PORTC_set_pin_pull_mode(4, pull_mode);
//}

/**
 * \brief Set ROW3 data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
//static inline void ROW3_set_dir(const enum port_dir dir)
//{
	//PORTC_set_pin_dir(4, dir);
//}

/**
 * \brief Set ROW3 input/sense configuration
 *
 * Enable/disable ROW3 digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_INTDISABLE_gc    = Iterrupt disabled but input buffer enabled
 *                PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
//static inline void ROW3_set_isc(const PORT_ISC_t isc)
//{
	//PORTC_pin_set_isc(4, isc);
//}

/**
 * \brief Set ROW3 inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on ROW3 is inverted
 *                     false = I/O on ROW3 is not inverted
 */
//static inline void ROW3_set_inverted(const bool inverted)
//{
	//PORTC_pin_set_inverted(4, inverted);
//}

/**
 * \brief Set ROW3 level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
//static inline void ROW3_set_level(const bool level)
//{
//	PORTC_set_pin_level(4, level);
//}

/**
 * \brief Toggle output level on ROW3
 *
 * Toggle the pin level
 */
//static inline void ROW3_toggle_level()
//{
//	PORTC_toggle_pin_level(4);
//}

/**
 * \brief Get level on ROW3
 *
 * Reads the level on a pin
 */
//static inline bool ROW3_get_level()
//{
//	return PORTC_get_pin_level(4);
//}

/**
 * \brief Set COLUMN1 pull mode
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] pull_mode Pin pull mode
 */
static inline void COLUMN1_set_pull_mode(const enum port_pull_mode pull_mode)
{
	//PORTC_set_pin_pull_mode(0, pull_mode);
	if (pull_mode == PORT_PULL_UP) {
		PORTC |= (1 << PORTC0);
	} else if (pull_mode == PORT_PULL_OFF) {
		PORTC &= ~(1 << PORTC0);
	}
}

/**
 * \brief Set COLUMN1 data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void COLUMN1_set_dir(const enum port_dir dir)
{
	//PORTC_set_pin_dir(0, dir);
	if (dir == PORT_DIR_OUT) {
		DDRC |= (1 << PORTC0);
	} else if (dir == PORT_DIR_IN) {
		DDRC &= ~(1 << PORTC0);
	}
}

/**
 * \brief Set COLUMN1 input/sense configuration
 *
 * Enable/disable COLUMN1 digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_INTDISABLE_gc    = Iterrupt disabled but input buffer enabled
 *                PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
/*
static inline void COLUMN1_set_isc(const PORT_ISC_t isc)
{
	PORTC_pin_set_isc(0, isc);
}
*/
/**
 * \brief Set COLUMN1 inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on COLUMN1 is inverted
 *                     false = I/O on COLUMN1 is not inverted
 */
/*
static inline void COLUMN1_set_inverted(const bool inverted)
{
	PORTC_pin_set_inverted(0, inverted);
}
*/
/**
 * \brief Set COLUMN1 level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void COLUMN1_set_level(const uint8_t level)
{
	//PORTC_set_pin_level(0, level);
	if (level) {
		PORTC |= (1 << PORTC0);
	} else {
		PORTC &= ~(1 << PORTC0);
	}
}

/**
 * \brief Toggle output level on COLUMN1
 *
 * Toggle the pin level
 */
static inline void COLUMN1_toggle_level()
{
	PORTC ^= (1 << PORTC0);
}

/**
 * \brief Get level on COLUMN1
 *
 * Reads the level on a pin
 */
static inline uint8_t COLUMN1_get_level()
{
	//return PORTC_get_pin_level(0);
	if (PINC & (1 << PINC0)) {
		return 1;
	} else {
		return 0;
	}
}

/**
 * \brief Set COLUMN2 pull mode
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] pull_mode Pin pull mode
 */
static inline void COLUMN2_set_pull_mode(const enum port_pull_mode pull_mode)
{
	//PORTC_set_pin_pull_mode(3, pull_mode);
	if (pull_mode == PORT_PULL_UP) {
		PORTC |= (1 << PORTC3);
	} else if (pull_mode == PORT_PULL_OFF) {
		PORTC &= ~(1 << PORTC3);
	}
}

/**
 * \brief Set COLUMN2 data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void COLUMN2_set_dir(const enum port_dir dir)
{
	//PORTC_set_pin_dir(3, dir);
	if (dir == PORT_DIR_OUT) {
		DDRC |= (1 << PORTC3);
	} else if (dir == PORT_DIR_IN) {
		DDRC &= ~(1 << PORTC3);
	}
}

/**
 * \brief Set COLUMN2 input/sense configuration
 *
 * Enable/disable COLUMN2 digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_INTDISABLE_gc    = Iterrupt disabled but input buffer enabled
 *                PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
/*
static inline void COLUMN2_set_isc(const PORT_ISC_t isc)
{
	PORTC_pin_set_isc(3, isc);
}
*/
/**
 * \brief Set COLUMN2 inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on COLUMN2 is inverted
 *                     false = I/O on COLUMN2 is not inverted
 */
/*
static inline void COLUMN2_set_inverted(const bool inverted)
{
	PORTC_pin_set_inverted(3, inverted);
}
*/
/**
 * \brief Set COLUMN2 level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void COLUMN2_set_level(const uint8_t level)
{
	//PORTC_set_pin_level(3, level);
	if (level) {
		PORTC |= (1 << PORTC3);
	} else {
		PORTC &= ~(1 << PORTC3);
	}
}

/**
 * \brief Toggle output level on COLUMN2
 *
 * Toggle the pin level
 */
static inline void COLUMN2_toggle_level()
{
	PORTC ^= (1 << PORTC3);
}

/**
 * \brief Get level on COLUMN2
 *
 * Reads the level on a pin
 */
static inline uint8_t COLUMN2_get_level()
{
	//return PORTC_get_pin_level(3);
	if (PINC & (1 << PINC3)) {
		return 1;
	} else {
		return 0;
	}
}


/**
 * \brief Set COLUMN0 pull mode
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] pull_mode Pin pull mode
 */
static inline void COLUMN0_set_pull_mode(const enum port_pull_mode pull_mode)
{
	//PORTC_set_pin_pull_mode(2, pull_mode);
	if (pull_mode == PORT_PULL_UP) {
		PORTC |= (1 << PORTC2);
	} else if (pull_mode == PORT_PULL_OFF) {
		PORTC &= ~(1 << PORTC2);
	}
}

/**
 * \brief Set COLUMN0 data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void COLUMN0_set_dir(const enum port_dir dir)
{
	//PORTC_set_pin_dir(2, dir);
	if (dir == PORT_DIR_OUT) {
		DDRC |= (1 << PORTC2);
	} else if (dir == PORT_DIR_IN) {
		DDRC &= ~(1 << PORTC2);
	}
}

/**
 * \brief Set COLUMN0 input/sense configuration
 *
 * Enable/disable COLUMN0 digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_INTDISABLE_gc    = Iterrupt disabled but input buffer enabled
 *                PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
/*
static inline void COLUMN0_set_isc(const PORT_ISC_t isc)
{
	PORTC_pin_set_isc(2, isc);
}
*/
/**
 * \brief Set COLUMN0 inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on COLUMN0 is inverted
 *                     false = I/O on COLUMN0 is not inverted
 */
/*
static inline void COLUMN0_set_inverted(const bool inverted)
{
	PORTC_pin_set_inverted(2, inverted);
}
*/
/**
 * \brief Set COLUMN0 level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void COLUMN0_set_level(const uint8_t level)
{
	//PORTC_set_pin_level(2, level);
	if (level) {
		PORTC |= (1 << PORTC2);
	} else {
		PORTC &= ~(1 << PORTC2);
	}
}

/**
 * \brief Toggle output level on COLUMN0
 *
 * Toggle the pin level
 */
static inline void COLUMN0_toggle_level()
{
	PORTC ^= (1 << PORTC2);
}

/**
 * \brief Get level on COLUMN0
 *
 * Reads the level on a pin
 */
static inline uint8_t COLUMN0_get_level()
{
	//return PORTC_get_pin_level(2);
	if (PINC & (1 << PINC2)) {
		return 1;
	} else {
		return 0;
	}
}

#endif /* ATMEL_START_PINS_H_INCLUDED */
