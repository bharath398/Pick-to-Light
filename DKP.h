/* 
 * File:   Digital_keypad.h
 * Author: Bharath
 *
 * Created on 19 February, 2025, 3:35 PM
 */

#ifndef DIGITAL_KEYPAD_H
#define	DIGITAL_KEYPAD_H

#define STATE_CHANGE 1
#define LEVEL        0

#define sw1 0x0E
#define sw2 0x0D
#define sw3 0x0B
#define sw4 0x07

#define All_released 0x0F
#define KEY_PORT     PORTC
#define INPUT_PINS   0x0F

void init_DKP();
unsigned int read_DKP(char detection_type);

#endif	/* DIGITAL_KEYPAD_H */

