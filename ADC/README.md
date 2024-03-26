# Digital to Analog Converter (ADC) ATmega328p

## 1. Overview : 
 ADCs Operation Process :

    1. Sampling: The ADC samples the analog input signal at discrete time intervals. This involves capturing the voltage of the analog signal at specific points in time.

    2. Quantization: The sampled analog voltage is then quantized into a digital representation. This process involves assigning digital values to the analog signal based on its amplitude.

    3. Encoding: The quantized values are encoded into binary digits (bits), producing a digital representation of the analog signal. The digital representation is then available for further processing by a digital system, such as a microcontroller.

 Types of ADCs:

    1. Successive Approximation ADC: This type of ADC employs a successive approximation algorithm to determine the digital output. It compares the input voltage with a series of reference voltages and adjusts them successively until a close match is achieved. This is one of the most common types of ADC due to its balance between speed and resolution.

    2. Flash ADC (Parallel ADC): Flash ADCs are the fastest type of ADCs. They use a series of comparators to directly convert the analog input into digital output, without the need for a successive approximation process. However, they are limited in resolution and are generally used in applications where speed is critical.

    3. Delta-Sigma ADC: Delta-Sigma ADCs use oversampling and noise shaping techniques to achieve high-resolution conversions. They sample the input signal at a much higher rate than the Nyquist frequency and then use digital filtering to improve resolution. Delta-Sigma ADCs are commonly used in applications requiring very high resolution and low noise.

    4. Integrating ADC (Dual-Slope ADC): Integrating ADCs measure the input voltage by integrating it over a fixed period of time and then comparing it to a reference voltage. They are relatively slow but offer high resolution and accuracy, making them suitable for applications where precision is crucial.

    5. Pipeline ADC: Pipeline ADCs split the conversion process into multiple stages, with each stage contributing a portion of the overall conversion. This allows for high-speed conversions with moderate to high resolutions. Pipeline ADCs are commonly used in applications requiring both speed and resolution, such as data acquisition systems.

    6. Time-Interleaved ADC: Time-interleaved ADCs use multiple ADC channels operating in parallel but with slightly staggered sampling times. This allows for higher overall sampling rates without sacrificing resolution. Time-interleaved ADCs are often used in high-speed data acquisition systems and communication applications.

## 2. ADC ATmega328p

### 2.1 Features
    1. 10-bit Resolution: The ADC (Analog-to-Digital Converter) in the ATmega328p has a resolution of 10 bits. This means it can represent analog input voltages across a range by converting them into digital values between 0 and 1023 (2^10 - 1).

    2. 0.5 LSB Integral Non-linearity: This refers to the maximum deviation from an ideal straight line, expressed in terms of Least Significant Bits (LSBs). In this case, the integral non-linearity is kept within 0.5 LSB, ensuring accuracy in the conversion process.

    3. ± 2 LSB Absolute Accuracy: This indicates the maximum deviation of the ADC's output from the ideal digital output. The ADC in the ATmega328p has an absolute accuracy of ± 2 LSB, which ensures reliable and consistent conversion results.

    4. 13 - 260 µs Conversion Time: The time taken by the ADC to convert an analog input voltage into a digital value ranges from 13 to 260 microseconds, depending on the ADC clock frequency and resolution settings.

    5. Up to 76.9 kSPS (Up to 15 kSPS at Maximum Resolution): The ADC can sample analog signals at a maximum rate of 76.9 kilosamples per second (kSPS) with reduced resolution. At maximum resolution (10-bit), the maximum sampling rate is limited to 15 kSPS.

    6. 6 Multiplexed Single-Ended Input Channels: The ADC supports up to 6 single-ended input channels, allowing the microcontroller to sample multiple analog signals sequentially.

    7. 2 Additional Multiplexed Single-Ended Input Channels (TQFP and QFN/MLF Package only): In certain package variants (TQFP and QFN/MLF), there are two additional single-ended input channels available for sampling analog signals.

    8. Temperature Sensor Input Channel: The ADC includes a dedicated input channel for measuring the temperature using an internal temperature sensor integrated into the microcontroller.

    9. Optional Left Adjustment for ADC Result Readout: The ADC result can be left-adjusted, allowing easier interfacing with certain external devices.

    10. 0 - VCC ADC Input Voltage Range: The ADC can accept input voltages in the range of 0 to the supply voltage (VCC) of the microcontroller.

    11. Selectable 1.1V ADC Reference Voltage: The ADC can utilize an internal 1.1V reference voltage for conversions, providing a stable reference for accurate measurements.

    12. Free Running or Single Conversion Mode: The ADC can operate in either free-running mode, continuously sampling inputs, or single conversion mode, where it performs a single conversion upon request.

    13. Interrupt on ADC Conversion Complete: The microcontroller can generate an interrupt when an ADC conversion is completed, allowing the CPU to perform other tasks while waiting for conversions to finish.

    14. Sleep Mode Noise Canceler: This feature helps to reduce noise during ADC conversions while the microcontroller is in sleep mode, ensuring accurate and reliable measurements even in low-power states.

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

    | ADPS2 | ADPS1 | ADPS0 |           Division Factor          |
    |-------|-------|-------|------------------------------------|
    |   0   |   0   |   0   |                  0                 |
    |   0   |   0   |   1   |                  2                 |
    |   0   |   1   |   0   |                  4                 |
    |   0   |   1   |   1   |                  8                 |
    |   1   |   0   |   0   |                 16                 |
    |   1   |   0   |   1   |                 32                 |
    |   1   |   1   |   0   |                 64                 |
    |   1   |   1   |   1   |                128                 |

 - Bit 3 – ADIE: ADC Interrupt Enable
 - Bit 4 – ADIF: ADC Interrupt Flag
 - Bit 5 – ADATE: ADC Auto Trigger Enable
 - Bit 6 – ADSC: ADC Start Conversion
 - Bit 7 – ADEN: ADC Enable 

#### 2.3 ADCL and ADCH – The ADC Data Register
 - ADC9:0: ADC Conversion Result

#### 2.4 ADCSRB – ADC Control and Status Register B
 - Bit 2:0 – ADTS2:0: ADC Auto Trigger Source

    | ADTS2 | ADTS1 | ADTS0 |           Trigger Source           |
    |-------|-------|-------|------------------------------------|
    |   0   |   0   |   0   | Free Running mode                  |
    |   0   |   0   |   1   | Analog Comparator                  |
    |   0   |   1   |   0   | External Interrupt Request 0       |
    |   0   |   1   |   1   | Timer/Counter0 Compare Match A     |
    |   1   |   0   |   0   | Timer/Counter0 Overflow            |
    |   1   |   0   |   1   | Timer/Counter1 Compare Match B     |
    |   1   |   1   |   0   | Timer/Counter1 Overflow            |
    |   1   |   1   |   1   | Timer/Counter1 Capture Event       |

 - Bit 6 – ACME: Analog Comparator Multiplexer Enable
 - Bit 7, 5:3 – Res: Reserved Bits

#### 2.5 DIDR0 – Digital Input Disable Register 0
 - Bit 5:0 – ADC5D..ADC0D: ADC5..0 Digital Input Disable
 - Bits 7:6 – Res: Reserved Bits


