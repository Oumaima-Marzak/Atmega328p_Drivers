/**
 * @author Oumaima MArzak
 * @file twi.c
 * @brief TWI (I²C) master driver for ATmega328P.
 */

#include "twi.h"


/* ---------------------- MASTER MODE --------------------- */

/**
 * @brief  Initializes the TWI (I²C) peripheral in master mode.
 *
 * @param  scl_freq  Desired SCL clock frequency in Hz (e.g. 100000 for 100 kHz).
 * @param  prescaler Prescaler value: 1, 4, 16, or 64.
 *
 * @note   The bitrate is computed as:
 *         SCL = F_CPU / (16 + 2 * TWBR * prescaler)
 *         Invalid prescaler values return an error.
 *
 * @return TWI_OK                       Initialization successful.
 * @return TWI_PRESCALER_CONFIG_ERROR   Invalid prescaler configuration.
 */
TWI_Status_t TWI_init(Unt32 scl_freq, Unt16 prescaler) 
{
    TWI_Status_t Error = TWI_OK;

    Uch8 presc_val = 1;

    switch (prescaler) 
    {
        case PRESCALER_1:  
            presc_val = 1; 
            TWSR = 0x00;
            break;
        
        case PRESCALER_4:  
            presc_val = 4;
            TWSR = 0x01;
            break;
        
        case PRESCALER_16: 
            presc_val = 16; 
            TWSR = 0x02;
            break;
        
        case PRESCALER_64: 
            presc_val = 64; 
            TWSR = 0x03;
            break;
        
        default:
            Error = TWI_PRESCALER_CONFIG_ERROR;
            break;

    }

    // The SCL frequency generated according to the following equation (based on the datasheet)
    Unt32 value = (((F_CPU / scl_freq) - 16) / (2 * presc_val)); 
    if (value > 255) value = 255;
    TWBR = (Uch8)value;

    // Enable TWI
    TWCR = (1 << TWEN); 

    return Error;
}


/**
 * @brief  Generates a START or REPEATED START condition on the TWI bus.
 *
 * @details Clears the TWINT flag to begin transmission of a START condition.
 *          Waits until the START is transmitted and acknowledged by hardware.
 *
 * @return TWI_OK          START transmitted successfully.
 * @return TWI_ERROR_START START not acknowledged by hardware.
 * @return TWI_TIMEOUT     Timeout waiting for TWINT flag.
 */
TWI_Status_t TWI_start_transmit() 
{
    
    TWI_Status_t Error = TWI_OK;
    
    // Send START
    TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);

    Unt16 timeout = TWI_TIMEOUT_LIMIT;

    // Wait for TWINT flag set - This indicates that the START condition has been transmitted
    TWI_WAIT_FLAG(timeout, Error);

    /* Check value of TWI status register. Mask prescaler bits. If status different from START/R START codes go to ERROR */

    Uch8 status = TWSR & 0xF8;

    if ((status != TWI_START) && (status != TWI_REP_START)) 
    {
        Error = TWI_ERROR_START;
    }

    return Error;

}

/**
 * @brief  Transmits the 7-bit slave address with the Read/Write bit.
 *
 * @param  SLA  7-bit slave address.
 * @param  R_W  Read/Write bit (0 = write, 1 = read).
 *
 * @details Sends the address packet on the bus after a START condition.
 *          Waits for ACK/NACK from the addressed slave.
 *
 * @return TWI_OK             Slave acknowledged address.
 * @return TWI_ERROR_SLA_NACK Slave did not acknowledge.
 * @return TWI_TIMEOUT        Timeout waiting for TWINT flag.
 */
TWI_Status_t TWI_address_packet_transmit(Uch8 SLA, bool R_W)
{
    TWI_Status_t Error = TWI_OK;
    
    // Add R/W bit to 7-bit slave address
    Uch8 address_packet = ( SLA << 1 ) | R_W;

    // Load the address packet to the data register (TWDR)
    TWDR = address_packet;
    
    //Clear TWINT bit in TWCR to start transmission of address
    TWCR = (1 << TWINT) | (1 << TWEN);
    
    Unt16 timeout = TWI_TIMEOUT_LIMIT;
    // Wait for TWINT flag set. This indicates that the @ packet has been transmitted, and ACK/NACK has been received.
    TWI_WAIT_FLAG(timeout, Error);

    
    /* Check the receive of the ACK from slave;
       by checking the value of TWI status register. 
       Mask prescaler bits. If status different from MT_SLA_ACK or MR_SLA_ACK go to ERROR */

    Uch8 status = TWSR & 0xF8;

    if ((status == TWI_MT_SLA_NACK) || (status == TWI_MR_SLA_NACK))
    {
        Error = TWI_ERROR_SLA_NACK;
    } 

    return Error;
}

/**
 * @brief  Transmits one data byte in master-transmitter mode.
 *
 * @param  data  Data byte to transmit.
 *
 * @details Writes the byte to TWDR, clears TWINT to start transmission,
 *          and waits for the ACK from the slave device.
 *
 * @return TWI_OK              Data transmitted and ACK received.
 * @return TWI_ERROR_DATA_NACK Data transmitted but NACK received.
 * @return TWI_TIMEOUT         Timeout waiting for TWINT flag.
 */
TWI_Status_t TWI_data_packet_transmit(Uch8 data)
{
    TWI_Status_t Error = TWI_OK;
    
    // Load DATA into TWDR register.
    TWDR = data;
    
    // Clear TWINT bit in TWCR to start transmission of data
    TWCR = (1 << TWEN) | (1 << TWINT);
    
    Unt16 timeout = TWI_TIMEOUT_LIMIT;
    // Wait for TWINT flag set. This indicates that the DATA has been transmitted, and ACK/NACK has been received.
    TWI_WAIT_FLAG(timeout, Error);

    /* Check value of TWI status register. Mask prescaler bits. If status different from MT_DATA_ACK go to ERROR */

    Uch8 status = TWSR & 0xF8;

    if ((status != TWI_MT_DATA_ACK))
    {
        Error = TWI_ERROR_DATA_NACK; 
    }

    return Error;

}


/**
 * @brief  Receives one data byte and sends ACK to request more data.
 *
 * @param[out] data  Pointer to variable that will store the received byte.
 *
 * @details Used in master-receiver mode when more bytes are expected.
 *          The master sends ACK after receiving each byte.
 *
 * @return TWI_OK              Data received and ACK sent.
 * @return TWI_ERROR_DATA_NACK Unexpected status or missing ACK.
 * @return TWI_TIMEOUT         Timeout waiting for TWINT flag.
 */
TWI_Status_t TWI_data_packet_receive_ACK(Uch8 *data)
{
    TWI_Status_t Error = TWI_OK;

    // Send ACK and clear TWINT to start receiving next byte of data
    TWCR = (1 << TWEN) | (1 << TWINT) | (1 << TWEA);

    Unt16 timeout = TWI_TIMEOUT_LIMIT;
    // Wait for TWINT Flag set. This indicates data has been received
    TWI_WAIT_FLAG(timeout, Error);


    // Check TWI status
    Uch8 status = TWSR & 0xF8;
    if (status == TWI_MR_DATA_ACK)
    {
        *data = TWDR;
    }
    else
    {
        Error = TWI_ERROR_DATA_NACK;
    }

    return Error;
}

/**
 * @brief  Receives the final data byte and sends NACK to end reception.
 *
 * @param[out] data  Pointer to variable that will store the received byte.
 *
 * @details Used in master-receiver mode for the last byte of a transfer.
 *          The master sends NACK to signal end of reception.
 *
 * @return TWI_OK              Data received and NACK sent.
 * @return TWI_ERROR_DATA_NACK Unexpected status or missing NACK.
 * @return TWI_TIMEOUT         Timeout waiting for TWINT flag.
 */
TWI_Status_t TWI_data_packet_receive_NACK(Uch8 *data)
{
    TWI_Status_t Error = TWI_OK;

    // Send NACK and clear TWINT
    TWCR = (1 << TWEN) | (1 << TWINT);

    Unt16 timeout = TWI_TIMEOUT_LIMIT;
    // Wait for TWINT Flag set
    TWI_WAIT_FLAG(timeout, Error);


    // Check status
    Uch8 status = TWSR & 0xF8;
    if (status == TWI_MR_DATA_NACK)
    {
        *data = TWDR;
    }
    else
    {
        Error = TWI_ERROR_DATA_NACK;
    }

    return Error;
}

/**
 * @brief  Reads multiple bytes from a slave device (master-receiver mode).
 *
 * @param[out] data  Pointer to buffer where received bytes will be stored.
 * @param[in]  len   Number of bytes to read.
 *
 * @details Reads (len-1) bytes with ACK, then the final byte with NACK.
 *          Stops immediately if an error occurs during reception.
 *
 * @return TWI_OK       All bytes received successfully.
 * @return TWI_* errors Error code returned by lower-level receive functions.
 */
TWI_Status_t TWI_read_data_bytes(Uch8* data, Uch8 len) 
{

    TWI_Status_t Error = TWI_OK;

    for(Uch8 i = 0; i < len; i++) 
    {
        if(i < len - 1) 
        
           Error  = TWI_data_packet_receive_ACK(&data[i]);

        else 
            
            Error = TWI_data_packet_receive_NACK(&data[i]);

        if (Error != TWI_OK)
            return Error;
    }

    return Error;
    
}



/**
 * @brief  Generates a STOP condition to release the TWI bus.
 *
 * @details Sends the STOP condition and waits for TWSTO bit to clear.
 *          Should be called after completing transmission or reception.
 *
 * @return TWI_OK      STOP completed successfully.
 * @return TWI_TIMEOUT Timeout waiting for STOP condition to complete.
 */
TWI_Status_t TWI_stop_transmit() 
{
    TWI_Status_t Error = TWI_OK;
    
    // Send STOP condition
    TWCR = (1 << TWSTO) | (1 << TWEN) | (1 << TWINT);
    
    Unt16 timeout = TWI_TIMEOUT_LIMIT;
    // Wait for STOP to complete
    while (TWCR & (1 << TWSTO))
    {
        if (--timeout == 0)
        {
            Error = TWI_TIMEOUT;
            break;
        } 
    }

    return Error;
}


/* ---------------------- SLAVE MODE (future) ---------------------- */