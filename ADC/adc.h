/*
*   Author : Oumaima MARZAK
*
*/

#ifndef ADC_H
#define ADC_H

#include "DataTypes.h"
#include "BitConfig.h"

/* ADC Registers Address */

#define ADMUX  (*(volatile Uch8 *)(0x7C)) 
#define ADCSRA (*(volatile Uch8 *)(0x7A))
#define ADCL   (*(volatile Uch8 *)(0x78))
#define ADCH   (*(volatile Uch8 *)(0x79))
#define ADCSRB (*(volatile Uch8 *)(0x7B))
#define DIDR0  (*(volatile Uch8 *)(0x7E))

/* ADC Registers Bits */

// ADMUX – ADC Multiplexer Selection Register
#define MUX0  0
#define MUX1  1
#define MUX2  2
#define MUX3  3
#define ADLAR 5
#define REFS0 6
#define REFS1 7

// ADCSRA – ADC Control and Status Register A 
#define ADPS0 0
#define ADPS1 1
#define ADPS2 2
#define ADIE  3
#define ADIF  4
#define ADATE 5
#define ADSC  6
#define ADEN  7

// ADCL and ADCH – The ADC Data Register 
#define ADCL0 0
#define ADCL1 1
#define ADCL2 2
#define ADCL3 3
#define ADCL4 4
#define ADCL5 5
#define ADCL6 6
#define ADCL7 7

#define ADCH0 0
#define ADCH1 1
#define ADCH2 2
#define ADCH3 3
#define ADCH4 4
#define ADCH5 5
#define ADCH6 6
#define ADCH7 7

// ADCSRB – ADC Control and Status Register B 
#define ADTS0 0
#define ADTS1 1
#define ADTS2 2
#define ACME  6

// DIDR0 – Digital Input Disable Register 0 
#define ADC0D 0
#define ADC1D 1
#define ADC2D 2
#define ADC3D 3
#define ADC4D 4
#define ADC5D 5

// Define configuration options for ADC reference
#define ADC_REF_AREF     0
#define ADC_REF_AVCC     1
#define ADC_REF_INTERNAL 2

// Define configuration options for ADC prescaler
#define ADC_PRESCALER_2     1
#define ADC_PRESCALER_4     2
#define ADC_PRESCALER_8     3
#define ADC_PRESCALER_16    4
#define ADC_PRESCALER_32    5
#define ADC_PRESCALER_64    6
#define ADC_PRESCALER_128   7

// Define Trigger source options 
#define Free_Running_mode       0
#define Analog_Comparator       1
#define Ext_Int_Request         2
#define Timer0_Compare_Match_A  3
#define Timer0_Overflow         4
#define Timer1_Compare_Match_B  5
#define Timer1_Overflow         6
#define Timer1_Capture_Event    7


/* Functions Prototypes */
void adc_ref_config(Uch8 reference);

void adc_prescaler_config(Uch8 prescaler); 

void adc_auto_trigger(Uch8 source);

void adc_init();

Unt16 adc_read(Unt16 channel);

void adc_init_temperature_sensor();

Unt16 read_internal_temperature(); 




#endif