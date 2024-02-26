# Digital_Input_Output_Atmega328p

## Fuctions Documentation
### Configure pin direction 

 - Description: Configures the direction (input or output) of a specified pin.
 
 - Variables:
    
    - pin: A structure representing the pin configuration, containing:
        
        pin : The specific pin number within the port (0-7).
        ddr : The direction register to which the pin belongs (Reg_B, Reg_C, or Reg_D).
        port: The port register to which the pin belongs (Reg_B, Reg_C, or Reg_D).

    - dir: The desired direction for the pin (OUT for output or IN for input).

 ```c_cpp

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

```

### Configure pin state 
 - Description: Configures the state (HIGH or LOW) of a specified pin.
 
 - Variables:
    
    - pin: A structure representing the pin configuration, containing:
            
        pin : The specific pin number within the port (0-7).
        ddr : The direction register to which the pin belongs (Reg_B, Reg_C, or Reg_D).
        port: The port register to which the pin belongs (Reg_B, Reg_C, or Reg_D).

    - STATE: The desired state for the pin (HIGH for logic HIGH or LOW for logic LOW).

 ```c_cpp

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

```

### Set pin state 
 - Description: Sets the state of a specified pin to logic HIGH.
 
 - Variables:

    pin: A structure representing the pin configuration, containing:
        
        pin : The specific pin number within the port (0-7).
        ddr : The direction register to which the pin belongs (Reg_B, Reg_C, or Reg_D).
        port: The port register to which the pin belongs (Reg_B, Reg_C, or Reg_D).

 ```c_cpp

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

```

### Clear pin state 
 - Description: sets the state of a specified pin to logic LOW.
 
 - Variables:

    pin: A structure representing the pin configuration, containing:

        pin : The specific pin number within the port (0-7).
        ddr : The direction register to which the pin belongs (Reg_B, Reg_C, or Reg_D).
        port: The port register to which the pin belongs (Reg_B, Reg_C, or Reg_D).

```c_cpp

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

```

### Toggle pin state
 
 - Description: Toggles the state of a specified pin. If the pin was previously logic HIGH, it will be set to logic LOW, and vice versa.
 
 - Variables:

    pin: A structure representing the pin configuration, containing:
        
        pin : The specific pin number within the port (0-7).
        ddr : The direction register to which the pin belongs (Reg_B, Reg_C, or Reg_D).
        port: The port register to which the pin belongs (Reg_B, Reg_C, or Reg_D).

```c_cpp

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


```
