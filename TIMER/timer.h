/*
*   Author : Oumaima MARZAK
*
*
*
*
*
*
*/

#ifndef TIMER_H
#define TIMER_H

#include "DataTypes.h"

/* TCCR0A - Timer/Counter Control Register A */
#define TCCR0A (*(volatile Uch8 *)(0x44)) 

/* Waveform Generation Mode bits 1:0 */
#define WGM00  0 
#define WGM01  1
/* Compare Match Output B Mode bits 1:0 */
#define COM0B0 4
#define COM0B1 5
/* Compare Match Output A Mode bits 1:0 */
#define COM0A0 6
#define COM0A1 7

/* TCCR0B - Timer/Counter Control Register B */
#define TCCR0B (*(volatile Uch8 *)(0x45))

/* Clock Select bits 2:0 */
#define CS00  0
#define CS01  1
#define CS02  2
/* Waveform Generation Mode bit */
#define WGM02 3
/* Force Output Compare B bit */
#define FOC0B 6
/* Force Output Compare B bit */
#define FOC0A 7

/* TCNT0 - Timer/Counter Register */
#define TCNT0 (*(volatile Uch8 *)(0x46))

/* OCR0A - Output Compare Register A */
#define OCR0A (*(volatile Uch8 *)(0x47))
#define OCR0A_0 0
#define OCR0A_1 1
#define OCR0A_2 2
#define OCR0A_3 3
#define OCR0A_4 4
#define OCR0A_5 5
#define OCR0A_6 6
#define OCR0A_7 7

/* OCR0B - Output Compare Register B */
#define OCR0B (*(volatile Uch8 *)(0x48))
#define OCR0B_0 0
#define OCR0B_1 1
#define OCR0B_2 2
#define OCR0B_3 3
#define OCR0B_4 4
#define OCR0B_5 5
#define OCR0B_6 6
#define OCR0B_7 7

/* TIMSK0 - Timer/Counter Interrupt Mask Register */
#define TIMSK0 (*(volatile Uch8 *)(0x6E))
#define TOIE0  0
#define OCIE0A 1
#define OCIE0B 2

/* TIFR0 - Timer/Counter Interrupt Flag Register */
#define TIFR0 (* (volatile Uch8 *)(0x35))
#define TOV0  0
#define OCF0A 1
#define OCF0B 2



#endif