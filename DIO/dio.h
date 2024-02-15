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

#define PINB  (*(volatile Uch8 *)(0x03 + 0x20))
#define DDRB  (*(volatile Uch8 *)(0x04 + 0x20))
#define PORTB (*(volatile Uch8 *)(0x05 + 0x20))

#define PINC  (*(volatile Uch8 *)(0x06 + 0x20))
#define DDRC  (*(volatile Uch8 *)(0x07 + 0x20))
#define PORTC (*(volatile Uch8 *)(0x08 + 0x20))

#define PIND  (*(volatile Uch8 *)(0x09 + 0x20))
#define DDRD  (*(volatile Uch8 *)(0x0A + 0x20))
#define PORTD (*(volatile Uch8 *)(0x0B + 0x20))

/* Pin assigned with registers B, C or D */
#define PB0 0
#define PB1 1
#define PB2 2
#define PB3 3
#define PB4 4
#define PB5 5
#define PB6 6
#define PB7 7

#define PC0 0
#define PC1 1
#define PC2 2
#define PC3 3
#define PC4 4
#define PC5 5
#define PC6 6

#define PD0 0
#define PD1 1
#define PD2 2
#define PD3 3
#define PD4 4
#define PD5 5
#define PD6 6
#define PD7 7

typedef struct 
{
    
    Uch8 pin;
    Uch8 ddr;
    Uch8 port;

} PinConfig;


void configure_pin_direction(PinConfig pin);
void configure_pin_state(PinConfig pin, Uch8 STATE);
void set_pin_state(PinConfig pin);
void clear_pin_state(PinConfig pin);





#endif
