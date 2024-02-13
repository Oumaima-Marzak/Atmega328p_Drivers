#include "dio.h"
#include "DataTypes.h"
#include "BitConfig.h"


void configure_pin_direction(PinConfig pin)
{
    switch (pin.ddr) 
    {
        case Reg_B:
            SET_VAL_BIT(DDRB, pin.pin);
            break;

        case Reg_C:
            SET_VAL_BIT(DDRC, pin.pin);
            break;

        case Reg_D:
            SET_VAL_BIT(DDRD, pin.pin);
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
