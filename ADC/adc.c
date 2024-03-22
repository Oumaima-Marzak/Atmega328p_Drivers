/*
*   Author : Oumaima MARZAK
*
*/

#include "adc.h"

/* Configure the ADC reference 

    reference options : 

        ADC_REF_AREF     
        ADC_REF_AVCC     
        ADC_REF_INTERNAL 
    
*/
void adc_ref_config(Uch8 reference)
{

    switch (reference)
    {
        // case 0 : Set ADC voltage reference to AREF (Internal Vref turned off)
        case ADC_REF_AREF :
            // No action needed, AREF selected by default
            break; 
        
        // Case 1 : Set ADC voltage reference to AVCC
        case ADC_REF_AVCC :
            
            SET_VAL_BIT(ADMUX, REFS0);

            break;

        // Case 2 : Set ADC voltage reference to Internal 1.1V Voltage Reference
        case ADC_REF_INTERNAL :
            
            ADMUX |= (1 << REFS1) | (1 << REFS0);

            break;
    }
}

/* Configure the ADC prescaler 

    prescaler options :
        
        ADC_PRESCALER_2    
        ADC_PRESCALER_4   
        ADC_PRESCALER_8   
        ADC_PRESCALER_16   
        ADC_PRESCALER_32   
        ADC_PRESCALER_64   
        ADC_PRESCALER_128 

*/
void adc_prescaler_config(Uch8 prescaler)
{
    switch(prescaler)
    {
        // Set ADC prescaler to 2
        case ADC_PRESCALER_2 :

            SET_VAL_BIT(ADCSRA, ADPS0);
            
            break;         

        // Set ADC prescaler to 4 (ADC clock frequency = 16 MHz / 4 = 4 MHz)
        case ADC_PRESCALER_4 :

            SET_VAL_BIT(ADCSRA, ADPS1);
            
            break;   

        // Set ADC prescaler to 8 (ADC clock frequency = 16 MHz / 8 = 2 MHz)
        case ADC_PRESCALER_8 :

            ADCSRA |= (1 << ADPS1) | (1 << ADPS0);
            
            break;   

        // Set ADC prescaler to 16 (ADC clock frequency = 16 MHz / 16 = 1 MHz)
        case ADC_PRESCALER_16 :

            SET_VAL_BIT(ADCSRA, ADPS2);
            
            break;   

        // Set ADC prescaler to 32 (ADC clock frequency = 16 MHz / 32 = 500 kHz)
        case ADC_PRESCALER_32 :

            ADCSRA |= (1 << ADPS2) | (1 << ADPS0);
            
            break;  

        // Set ADC prescaler to 64 (ADC clock frequency = 16 MHz / 64 = 250 kHz)
        case ADC_PRESCALER_64 :

            ADCSRA |= (1 << ADPS2) | (1 << ADPS1);
            
            break;  

        // Set ADC prescaler to 128 (ADC clock frequency = 16 MHz / 128 = 128 kHz)
        case ADC_PRESCALER_128 :

            ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);

            break;  

    }
}

void adc_auto_trigger(Uch8 source)
{
    //Enable the ADC auto Trigger
    SET_VAL_BIT(ADCSRA, ADATE);

    switch(source)
    {

        case Free_Running_mode :
            // No action needed, Free Running selected by default
            break;         

        case  Analog_Comparator:

            SET_VAL_BIT(ADCSRB, ADTS0);
            
            break;   

        case  Ext_Int_Request:

            SET_VAL_BIT(ADCSRB, ADTS1);
            
            break;   

        case Timer0_Compare_Match_A :

            ADCSRB |= (1 << ADTS1) | (1 << ADTS0);

            break;   

        case Timer0_Overflow :

            SET_VAL_BIT(ADCSRB, ADTS2);

            break;  

        case Timer1_Compare_Match_B :

            ADCSRB |= (1 << ADTS2) | (1 << ADTS0);
            
            break;  

        case Timer1_Overflow :

            ADCSRB |= (1 << ADTS2) | (1 << ADTS1);

            break;

        case Timer1_Capture_Event :

            ADCSRB |= (1 << ADTS2) | (1 << ADTS1) | (1 << ADTS0);

            break;    

    }
}

void adc_init()
{
    // Enable ADC
    ADCSRA |= (1 << ADEN); 
}

Unt16 adc_read(Unt16 channel)
{
    // Select ADC channel (0-7)
    ADMUX = (ADMUX & 0xF0) | (channel & 0x0F);

    // Start conversion
    ADCSRA |= (1 << ADSC);

    // Wait for conversion to complete
    while (ADCSRA & (1 << ADSC));
    
    // Combine ADCL and ADCH to form the 10-bit ADC result
    Unt16 adc_result = ADCL | (ADCH << 8);
    
    // Return ADC result
    return adc_result;
}


