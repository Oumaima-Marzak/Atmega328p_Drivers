#include "dio.h"
#include "DataTypes.h"
#include "BitConfig.h"


void configure_pin_direction(PinConfig pin, Uch8 dir)
{ 
    
    switch (pin.port)
    {
        case Reg_B:
        
        if (dir == OUT)
        {
            SET_VAL_BIT(DDRB, pin.pin);
        }
        else
        {
            CLEAR_VAL_BIT(DDRB, pin.pin);
        } 

        break;

        case Reg_C:
        
        if (dir == OUT)
        {
            SET_VAL_BIT(DDRC, pin.pin);
        }
        else
        {
            CLEAR_VAL_BIT(DDRC, pin.pin);
        } 

        break;

        case Reg_D:
        
        if (dir == OUT)
        {
            SET_VAL_BIT(DDRD, pin.pin);
        }
        else
        {
            CLEAR_VAL_BIT(DDRD, pin.pin);
        } 

        break;
    
    }   
}

void configure_pin_state(PinConfig pin, Uch8 STATE)
{
    switch (pin.port)
    {
        case Reg_B:
        
        if (STATE == HIGH)
        {
            SET_VAL_BIT(PORTB, pin.pin);
        }
        else
        {
            CLEAR_VAL_BIT(PORTB, pin.pin);
        } 

        break;

        case Reg_C:
        
        if (STATE == HIGH)
        {
            SET_VAL_BIT(PORTC, pin.pin);
        }
        else
        {
            CLEAR_VAL_BIT(PORTC, pin.pin);
        } 

        break;

        case Reg_D:
        
        if (STATE == HIGH)
        {
            SET_VAL_BIT(PORTD, pin.pin);
        }
        else
        {
            CLEAR_VAL_BIT(PORTD, pin.pin);
        } 

        break;
    
    }
}

void set_pin_state(PinConfig pin)
{
    switch (pin.port)
    {
        case Reg_B :
        SET_VAL_BIT(PORTB, pin.pin);
        break;

        case Reg_C :
        SET_VAL_BIT(PORTC, pin.pin);
        break;

        case Reg_D :
        SET_VAL_BIT(PORTD, pin.pin);
        break;
    }
}

void clear_pin_state(PinConfig pin)
{
    switch (pin.port)
    {
        case Reg_B:

        CLEAR_VAL_BIT(PORTB, pin.pin);

        break;

        case Reg_C:

        CLEAR_VAL_BIT(PORTC, pin.pin); 

        break;

        case Reg_D:
        
        CLEAR_VAL_BIT(PORTD, pin.pin); 

        break;
    
    }
}

void toggle_pin_state(PinConfig pin)
{
    switch (pin.port)
    {
        case Reg_B:

        TOGGLE_VAL_BIT(PORTB, pin.pin);

        break;

        case Reg_C:

        TOGGLE_VAL_BIT(PORTC, pin.pin); 

        break;

        case Reg_D:
        
        TOGGLE_VAL_BIT(PORTD, pin.pin); 

        break;
    
    }
}
