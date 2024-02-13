/*
*   Author : Oumaima MARZAK
*   
*
*
*
*/
#ifndef DIO_REG_H
#define DIO_REG_H

#include "DataTypes.h"
#include "BitConfig.h"

/* Digital I/O registers in Atmega328p (PORT, PIN, DDR) */
#define Reg_B 0
#define Reg_C 1
#define Reg_D 2

#define HIGH 1
#define LOW  0

#define PINB (*(volatile Uch8 *)(0x03 + 0x20))
#define PINB0 0
#define PINB1 1
#define PINB2 2
#define PINB3 3
#define PINB4 4
#define PINB5 5
#define PINB6 6
#define PINB7 7

#define DDRB (*(volatile Uch8 *)(0x04 + 0x20))
#define DDB0 0
#define DDB1 1
#define DDB2 2
#define DDB3 3
#define DDB4 4
#define DDB5 5
#define DDB6 6
#define DDB7 7

#define PORTB (*(volatile Uch8 *)(0x05 + 0x20))
#define PORTB0 0
#define PORTB1 1
#define PORTB2 2
#define PORTB3 3
#define PORTB4 4
#define PORTB5 5
#define PORTB6 6
#define PORTB7 7

#define PINC (*(volatile Uch8 *)(0x06 + 0x20))
#define PINC0 0
#define PINC1 1
#define PINC2 2
#define PINC3 3
#define PINC4 4
#define PINC5 5
#define PINC6 6

#define DDRC (*(volatile Uch8 *)(0x07 + 0x20))
#define DDC0 0
#define DDC1 1
#define DDC2 2
#define DDC3 3
#define DDC4 4
#define DDC5 5
#define DDC6 6

#define PORTC (*(volatile Uch8 *)(0x08 + 0x20))
#define PORTC0 0
#define PORTC1 1
#define PORTC2 2
#define PORTC3 3
#define PORTC4 4
#define PORTC5 5
#define PORTC6 6

#define PIND (*(volatile Uch8 *)(0x09 + 0x20))
#define PIND0 0
#define PIND1 1
#define PIND2 2
#define PIND3 3
#define PIND4 4
#define PIND5 5
#define PIND6 6
#define PIND7 7

#define DDRD (*(volatile Uch8 *)(0x0A + 0x20))
#define DDD0 0
#define DDD1 1
#define DDD2 2
#define DDD3 3
#define DDD4 4
#define DDD5 5
#define DDD6 6
#define DDD7 7

#define PORTD (*(volatile Uch8 *)(0x0B + 0x20))
#define PORTD0 0
#define PORTD1 1
#define PORTD2 2
#define PORTD3 3
#define PORTD4 4
#define PORTD5 5
#define PORTD6 6
#define PORTD7 7


void configure_pin_direction(PinConfig pin);
void configure_pin_state(PinConfig pin, Uch8 STATE);




#endif
