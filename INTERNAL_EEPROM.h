/* 
 * File:   INTERNAL_EEPROM.h
 * Author: Bharath
 *
 * Created on 21 February, 2025, 9:05 AM
 */

#ifndef INTERNAL_EEPROM_H
#define	INTERNAL_EEPROM_H

unsigned char read_internal_eeprom(unsigned char address);
void write_internal_eeprom(unsigned char address,unsigned char data);
#endif	/* INTERNAL_EEPROM_H */

