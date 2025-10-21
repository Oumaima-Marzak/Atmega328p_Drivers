/**
 * @author Oumaima Marzak
 * @file twi.h
 * @brief Public interface for the TWI (I²C) master driver.
 */

#ifndef TWI_H
#define TWI_H

#include "DataTypes.h"

/* 
 * CPU Clock Frequency (Atmega328P)
 */
#ifndef F_CPU
#warning "F_CPU not defined, defaulting to 16 MHz"
#define F_CPU 16000000UL
#endif

typedef enum 
{
    TWI_OK,
    TWI_ERROR_START,
    TWI_ERROR_STOP,

    TWI_ERROR_SLA_NACK,
    TWI_ERROR_DATA_NACK,
    
    TWI_TIMEOUT,
    TWI_PRESCALER_CONFIG_ERROR

} TWI_Status_t;


#define TWI_TIMEOUT_LIMIT  10000
#define TWI_WAIT_FLAG(timeout, errorVar) \
    do { \
        while (!(TWCR & (1 << TWINT))) { \
            if (--timeout == 0) { \
                errorVar = TWI_TIMEOUT; \
                break; \
            } \
        } \
    } while(0)




/* Atmega328P Registers */

// Bit Rate Register
#define TWBR  (*(volatile Uch8*)0xB8)

#define TWBR0 0
#define TWBR1 1
#define TWBR2 2
#define TWBR3 3
#define TWBR4 4
#define TWBR5 5
#define TWBR6 6
#define TWBR7 7

// Status Register 
#define TWSR  (*(volatile Uch8*)0xB9)

#define TWPS0 0
#define TWPS1 1
#define TWS3  3
#define TWS4  4
#define TWS5  5
#define TWS6  6
#define TWS7  7

// Slave Address Register  
#define TWAR  (*(volatile Uch8*)0xBA)

#define TWGCE 0
#define TWA0 1
#define TWA1 2
#define TWA2 3
#define TWA3 4
#define TWA4 5
#define TWA5 6
#define TWA6 7

// Data Register  
#define TWDR  (*(volatile Uch8*)0xBB)

#define TWD0 0
#define TWD1 1
#define TWD2 2
#define TWD3 3
#define TWD4 4
#define TWD5 5
#define TWD6 6
#define TWD7 7

// Control Register  
#define TWCR  (*(volatile Uch8*)0xBC)

#define TWIE  0
#define TWEN  2
#define TWWC  3
#define TWSTO 4
#define TWSTA 5
#define TWEA  6
#define TWINT 7

// Address Mask Register
#define TWAMR (*(volatile Uch8*)0xBD)  

#define TWAM0 0
#define TWAM1 1
#define TWAM2 2
#define TWAM3 3
#define TWAM4 4
#define TWAM5 5
#define TWAM6 6


/* Atmega328P Status Codes */ 
#define TWI_START              0x08
#define TWI_REP_START          0x10

#define TWI_MT_SLA_ACK         0x18
#define TWI_MT_SLA_NACK        0x20
#define TWI_MT_DATA_ACK        0x28
#define TWI_MT_DATA_NACK       0x30

#define TWI_MR_SLA_ACK         0x40
#define TWI_MR_SLA_NACK        0x48
#define TWI_MR_DATA_ACK        0x50
#define TWI_MR_DATA_NACK       0x58

#define TWI_ARB_LOST           0x38

#define TWI_SR_SLA_ACK         0x60
#define TWI_SR_SLA_ARB_LOST    0x68
#define TWI_SR_GCALL_ACK       0x70
#define TWI_SR_DATA_ACK        0x80
#define TWI_SR_DATA_NACK       0x88

#define TWI_SR_STOP            0xA0

#define TWI_ST_SLA_ACK         0xA8
#define TWI_ST_ARB_LOST        0xB0
#define TWI_ST_DATA_ACK        0xB8
#define TWI_ST_DATA_NACK       0xC0
#define TWI_ST_LAST_DATA       0xC8


/* Prescalers */

#define PRESCALER_1     1
#define PRESCALER_4     4
#define PRESCALER_16    16
#define PRESCALER_64    64


// Initialize TWI with desired SCL frequency
TWI_Status_t TWI_init(Unt32 scl_freq, Unt16 prescaler);

// Send START/Repeated START condition
TWI_Status_t TWI_start_transmit();

// MT Mode - Send the address packet (SLA + R/W) & listen to ACK
TWI_Status_t TWI_address_packet_transmit(Uch8 SLA, bool R_W);

// MT Mode - Send the 8 bits data packet & listen to ACK
TWI_Status_t TWI_data_packet_transmit(Uch8 data);

// MR Mode - read the 8 bits of data packet sent from slave & send ACK
TWI_Status_t TWI_data_packet_receive_ACK(Uch8 * data);

// MR Mode - read the last 8 bits of data packet sent from slave & send NACK
TWI_Status_t TWI_data_packet_receive_NACK(Uch8 * data);

// MR Mode - Reads multiple bytes from a slave.
TWI_Status_t TWI_read_data_bytes(Uch8* data, Uch8 len); 

// Send STOP condition
TWI_Status_t TWI_stop_transmit();


#endif
