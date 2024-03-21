# ATMEGA328P_DRIVERS

## Overview 
 This repository contains drivers for various peripherals of the Atmega328p microcontroller. The Atmega328p is commonly used on the Arduino Uno board.

 While the Atmega328p is considered an older microcontroller architecture, it remains popular in various embedded and IoT projects due to its low cost and accessibility, especially through the Arduino Uno board. Additionally, it serves as a good starting point for beginners interested in embedded bare-metal programming, offering an opportunity to enhance their skills beyond the Arduino IDE.

 These drivers have been developed with both embedded programming beginners and bare-metal programming enthusiasts in mind. They aim to support users in different embedded projects involving the Atmega328p microcontroller.

 (Note that this repository is not yet complete, and some peripheral drivers for the target microcontroller are still under development. They will be uploaded in the coming days.)

## Atmega328p Microcontroller 

 The Atmega328p is a low-power 8-bit microcontroller based on the AVR enhanced RISC architecture. It features two main memory spaces: data memory space (2K Bytes SRAM) and program memory space (32K Bytes of In-System Reprogrammable Flash). Additionally, the Atmega328p includes EEPROM memory of 1K Byte for data storage.

 The Atmega328p also includes various peripherals:

  - I/O peripherals with 28 pins.
  - ADC peripheral with 6 channels, each with 10-bit resolution.
  - 6 PWM channels.
  - Two 8-bit Timer/Counters.
  - One 16-bit Timer/Counter.
  - Programmable Serial USART.
  - SPI Serial Interface.
  - TWI (Two-Wire Interface) Serial Interface.
  - Programmable Watchdog Timer.

For more details check the Atmega328p Datasheet.

### Digital Input/Output Ports (DIO)
 [DIO Documentation](https://github.com/Oumaima-Marzak/Atmega328p_Drivers/tree/master/DIO)

### Analog to Digital Converter (ADC)
 [ADC Documentation](https://github.com/Oumaima-Marzak/Atmega328p_Drivers/tree/master/ADC)
 





