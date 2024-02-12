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

/********* 8-bit Timer/Counter0 with PWM *********/

/* TCCR0A – Timer/Counter0 Control Register A */
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

/* TCCR0B - Timer/Counter0 Control Register B */
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

/* TCNT0 - Timer/Counter0 Register */
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

/* TIMSK0 - Timer/Counter0 Interrupt Mask Register */
#define TIMSK0 (*(volatile Uch8 *)(0x6E))
#define TOIE0  0
#define OCIE0A 1
#define OCIE0B 2

/* TIFR0 - Timer/Counter0 Interrupt Flag Register */
#define TIFR0 (* (volatile Uch8 *)(0x35))
#define TOV0  0
#define OCF0A 1
#define OCF0B 2


/********* 16-bit Timer/Counter1 with PWM *********/

/* TCCR1A – Timer/Counter1 Control Register A */
#define TCCR1A (*(volatile Uch8 *)(0x80))

/* Waveform Generation Mode bits 1:0 */
#define WGM10 0
#define WGM11 1
/* Compare Match Output B Mode bits 1:0 */
#define COM1B0 4
#define COM1B1 5
/* Compare Match Output A Mode bits 1:0 */
#define COM1A0 6
#define COM1A1 7


/* TCCR1B – Timer/Counter1 Control Register B */
#define TCCR1B (*(volatile Uch8 *)(0x81))

/* Bit 2:0 – CS12:0: Clock Select */
#define CS10  0
#define CS11  1
#define CS12  2
/* Bit 4:3 – WGM13:2: Waveform Generation Mode */
#define WGM12 3
#define WGM13 4
/* Bit 6 – ICES1: Input Capture Edge Select */
#define ICES1 6
/* Bit 7 – ICNC1: Input Capture Noise Canceler */
#define ICNC1 7

/* TCCR1C – Timer/Counter1 Control Register C */
#define TCCR1C (*(volatile Uch8 *)(0x82))

/* Bit 7 – FOC1A: Force Output Compare for Channel A */
#define FOC1B 6
/* Bit 6 – FOC1B: Force Output Compare for Channel B */
#define FOC1A 7


/* TCNT1H and TCNT1L – Timer/Counter1 */
#define TCNT1L  (*(volatile Uch8*)(0x84))
#define TCNT1L0 0
#define TCNT1L1 1
#define TCNT1L2 2
#define TCNT1L3 3
#define TCNT1L4 4
#define TCNT1L5 5
#define TCNT1L6 6
#define TCNT1L7 7

#define TCNT1H  (*(volatile Uch8*)(0x85))
#define TCNT1H0 0
#define TCNT1H1 1
#define TCNT1H2 2
#define TCNT1H3 3
#define TCNT1H4 4
#define TCNT1H5 5
#define TCNT1H6 6
#define TCNT1H7 7

/* OCR1AH and OCR1AL – Output Compare Register 1 A */
#define OCR1AL  (*(volatile Uch8*)(0x88))
#define OCR1AL0 0
#define OCR1AL1 1
#define OCR1AL2 2
#define OCR1AL3 3
#define OCR1AL4 4
#define OCR1AL5 5
#define OCR1AL6 6
#define OCR1AL7 7

#define OCR1AH  (*(volatile Uch8*)(0x89))
#define OCR1AH0 0
#define OCR1AH1 1
#define OCR1AH2 2
#define OCR1AH3 3
#define OCR1AH4 4
#define OCR1AH5 5
#define OCR1AH6 6
#define OCR1AH7 7

/* OCR1BH and OCR1BL – Output Compare Register 1 B */
#define OCR1BL  (*(volatile Uch8*)(0x8A))
#define OCR1BL0 0
#define OCR1BL1 1
#define OCR1BL2 2
#define OCR1BL3 3
#define OCR1BL4 4
#define OCR1BL5 5
#define OCR1BL6 6
#define OCR1BL7 7

#define OCR1BH  (*(volatile Uch8*)(0x8B))
#define OCR1BH0 0
#define OCR1BH1 1
#define OCR1BH2 2
#define OCR1BH3 3
#define OCR1BH4 4
#define OCR1BH5 5
#define OCR1BH6 6
#define OCR1BH7 7

/* ICR1H and ICR1L – Input Capture Register 1 */
#define ICR1L  (*(volatile Uch8*)(0x86))
#define ICR1L0 0
#define ICR1L1 1
#define ICR1L2 2
#define ICR1L3 3
#define ICR1L4 4
#define ICR1L5 5
#define ICR1L6 6
#define ICR1L7 7

#define ICR1H  (*(volatile Uch8*)(0x87))
#define ICR1H0 0
#define ICR1H1 1
#define ICR1H2 2
#define ICR1H3 3
#define ICR1H4 4
#define ICR1H5 5
#define ICR1H6 6
#define ICR1H7 7

/* TIMSK1 – Timer/Counter1 Interrupt Mask Register */
#define TIMSK1 (*(volatile Uch8*)(0x6F))
#define TOIE1  0
#define OCIE1A 1
#define OCIE1B 2
#define ICIE1  5

/* TIFR1 – Timer/Counter1 Interrupt Flag Register */
#define TIFR1 (*(volatile Uch8*)(0x16))
#define TOV1  0
#define OCF1A 1
#define OCF1B 2
#define ICF1  5

/********* 8-bit Timer/Counter2 with PWM and Asynchronous Operation *********/

/* TCCR2A – Timer/Counter2 Control Register A */
#define TCCR2A (*(volatile Uch8*)(0xB0))
#define WGM20  0
#define WGM21  1
#define COM2B0 4
#define COM2B1 5
#define COM2A0 6
#define COM2A1 7

/* TCCR2B – Timer/Counter2 Control Register B */
#define TCCR2B (*(volatile Uch8*)(0xB1))
#define CS20  0
#define CS21  1
#define CS22  2
#define WGM22 3
#define FOC2B 6
#define FOC2A 7

/* TCNT2 – Timer/Counter Register */
#define TCNT2   (*(volatile Uch8*)(0xB2))
#define TCNT2_0 0
#define TCNT2_1 1
#define TCNT2_2 2
#define TCNT2_3 3
#define TCNT2_4 4
#define TCNT2_5 5
#define TCNT2_6 6
#define TCNT2_7 7

/* OCR2A – Output Compare Register A */
#define OCR2A  (*(volatile Uch8*)(0xB3))
#define OCR2_0 0
#define OCR2_1 1
#define OCR2_2 2
#define OCR2_3 3
#define OCR2_4 4
#define OCR2_5 5
#define OCR2_6 6
#define OCR2_7 7

/* OCR2B – Output Compare Register B */
#define OCR2B  (*(volatile Uch8*)(0xB4))
#define OCR2_0 0
#define OCR2_1 1
#define OCR2_2 2
#define OCR2_3 3
#define OCR2_4 4
#define OCR2_5 5
#define OCR2_6 6
#define OCR2_7 7

/* TIMSK2 – Timer/Counter2 Interrupt Mask Register */
#define TIMSK2 (*(volatile Uch8*)(0x70))
#define TOIE2  0
#define OCIE2A 1
#define OCIE2B 2

/* TIFR2 – Timer/Counter2 Interrupt Flag Register */
#define TIFR2 (*(volatile Uch8*)(0x17))
#define TOV2  0
#define OCF2A 1
#define OCF2B 2

/* ASSR – Asynchronous Status Register */
#define ASSR    (*(volatile Uch8*)(0xB6))
#define TCR2BUB 0
#define TCR2AUB 1
#define OCR2BUB 2
#define OCR2AUB 3
#define TCN2UB  4
#define AS2     5
#define EXCLK   6


/* GTCCR – General Timer/Counter Control Register */
#define GTCCR   (*(volatile Uch8*)(0x23))
#define PSRSYNC 0
#define PSRASY  1
#define TSM     7

#endif