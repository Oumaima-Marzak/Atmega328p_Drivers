# Digital to Analog Converter (ADC) ATmega328p

## 1. Overview (Overview about ADCs generaly)

## 2. ADC ATmega328p

### 2.1 Features

### 2.2 Registers 

#### 2.1 ADMUX – ADC Multiplexer Selection Register
 - Bits 3:0 – MUX3:0: Analog Channel Selection Bits
 - Bit 4 – Res: Reserved Bit
 - Bit 5 – ADLAR: ADC Left Adjust Result
 - Bits 7:6 – REFS1:0: Reference Selection Bits

    | REFS1 | REFS0 |                    Voltage Reference Selection                      |
    |-------|-------|---------------------------------------------------------------------|
    |   0   |   0   | AREF, Internal Vref turned off                                      |
    |   0   |   1   | AVCC with external capacitor at AREF pin                            |
    |   1   |   0   | Reserved                                                            |
    |   1   |   1   | Internal 1.1V Voltage Reference with external capacitor at AREF pin |
 
#### 2.2 ADCSRA – ADC Control and Status Register A
 - Bits 2:0 – ADPS2:0: ADC Prescaler Select Bits
 - Bit 3 – ADIE: ADC Interrupt Enable
 - Bit 4 – ADIF: ADC Interrupt Flag
 - Bit 5 – ADATE: ADC Auto Trigger Enable
 - Bit 6 – ADSC: ADC Start Conversion
 - Bit 7 – ADEN: ADC Enable 

#### 2.3 ADCL and ADCH – The ADC Data Register
 - ADC9:0: ADC Conversion Result

#### 2.4 ADCSRB – ADC Control and Status Register B
 - Bit 2:0 – ADTS2:0: ADC Auto Trigger Source
 - Bit 6 – ACME: Analog Comparator Multiplexer Enable
 - Bit 7, 5:3 – Res: Reserved Bits

#### 2.5 DIDR0 – Digital Input Disable Register 0
 - Bit 5:0 – ADC5D..ADC0D: ADC5..0 Digital Input Disable
 - Bits 7:6 – Res: Reserved Bits
## 3. ADC Driver Documentation 


