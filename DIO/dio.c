#include "dio.h"
#include "DataTypes.h"
#include "BitConfig.h"


void configure_pin_direction(PinConfig pin, Uch8 dir)
{ 
    volatile Uch8 *ddr;

    switch (pin.port)
    {
        case Reg_B:
         ddr = &DDRB;
         break;

        case Reg_C:
         ddr = &DDRC;
         break;

        case Reg_D:
         ddr = &DDRD;
         break;
    
    }  

    if (dir == OUT)
    {
        SET_VAL_BIT(*ddr, pin.pin);
    }
    else
    {
        CLEAR_VAL_BIT(*ddr, pin.pin);
    }  
}

void configure_pin_state(PinConfig pin, Uch8 STATE)
{
    volatile Uch8 *port;

    switch (pin.port)
    {
        case Reg_B:
         port = &PORTB;
         break;

        case Reg_C:
         port = &PORTC;
         break;

        case Reg_D:
         port = &PORTD;
         break;
    
    }  

    if (STATE == HIGH)
    {
        SET_VAL_BIT(*port, pin.pin);
    }
    else
    {
        CLEAR_VAL_BIT(*port, pin.pin);
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
