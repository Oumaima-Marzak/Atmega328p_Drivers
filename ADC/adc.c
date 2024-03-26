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

/* Select ADC trigger source

    source options :
        
        Free_Running_mode       
        Analog_Comparator       
        Ext_Int_Request         
        Timer0_Compare_Match_A  
        Timer0_Overflow         
        Timer1_Compare_Match_B  
        Timer1_Overflow         
        Timer1_Capture_Event    

*/
void adc_auto_trigger(Uch8 source)
{
    //Enable the ADC auto Trigger
    SET_VAL_BIT(ADCSRA, ADATE);

    // Switch-case statement to select the ADC trigger source 
    switch (source) 
    { 
        case Free_Running_mode: 
        // No action needed, Free Running selected by default 
        break; 
        
        case Analog_Comparator: // Set ADC trigger source to Analog Comparator 
            SET_VAL_BIT(ADCSRB, ADTS0); 
            break; 
        
        case Ext_Int_Request: // Set ADC trigger source to External Interrupt Request 
            SET_VAL_BIT(ADCSRB, ADTS1); 
            break; 
        
        case Timer0_Compare_Match_A: // Set ADC trigger source to Timer0 Compare Match A 
            SET_VAL_BIT(ADCSRB, ADTS1); 
            SET_VAL_BIT(ADCSRB, ADTS0); 
            break; 
        
        case Timer0_Overflow: // Set ADC trigger source to Timer0 Overflow 
            SET_VAL_BIT(ADCSRB, ADTS2); 
            break; 
        
        case Timer1_Compare_Match_B: // Set ADC trigger source to Timer1 Compare Match B 
            SET_VAL_BIT(ADCSRB, ADTS2); 
            SET_VAL_BIT(ADCSRB, ADTS0); 
            break; 
        
        case Timer1_Overflow: // Set ADC trigger source to Timer1 Overflow 
            SET_VAL_BIT(ADCSRB, ADTS2); 
            SET_VAL_BIT(ADCSRB, ADTS1); 
            break; 
        
        case Timer1_Capture_Event: // Set ADC trigger source to Timer1 Capture Event 
            SET_VAL_BIT(ADCSRB, ADTS0); 
            SET_VAL_BIT(ADCSRB, ADTS2); 
            SET_VAL_BIT(ADCSRB, ADTS1);  
            break;
    }
}

/* 
    Function to enable the ADC     
*/
void adc_init()
{
    // Enable ADC
    ADCSRA |= (1 << ADEN); 
}


/* 
    Reads the digital value from a specific ADC channel
*/
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

/*
    Initializes ADC for temperature measurement
    
    Note: Calling adc_init_temperature_sensor() eliminates the need for separate calls to configure ADC settings using 
    adc_ref_config(), adc_prescaler_config(), and adc_init().

*/
void adc_init_temperature_sensor() {

    // Select ADC channel 8 (internal temperature sensor)
    ADMUX = (ADMUX & 0xF0) | 0x08;
    
    // Set ADC reference to Internal 1.1V Voltage Reference
    ADMUX |= (1 << REFS1) | (1 << REFS0);
    
    // Set ADC prescaler to 128 (ADC clock frequency = 16 MHz / 128 = 125 kHz)
    ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
    
    // Enable ADC
    ADCSRA |= (1 << ADEN);
}

/* 
    Function to read temperature from internal sensor     
*/
Unt16 read_internal_temperature() {
    
    // Start conversion
    ADCSRA |= (1 << ADSC);
    
    // Wait for conversion to complete
    while (ADCSRA & (1 << ADSC));
    
    // Read ADC result (combine ADCH and ADCL)
    Unt16 adc_value = (ADCH << 8) | ADCL;
    
    // Coefficients for temperature calculation
    const Unt16 TOS = 314; // Offset voltage at 25°C (mV)
    const Unt16 k = 1; // Coefficient (mV/°C)
    
    // Calculate temperature using formula: T = { (ADC_value - TOS) / k }
    Unt16 temperature = ((Unt16)adc_value - TOS) / k;
    
    return temperature;
}



