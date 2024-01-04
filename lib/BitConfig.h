/*
*   Author : Oumaima MARZAK
*   
*
*
*
*/

/*
*    Truth table for bitwise AND operator (&):
*
*    A   B   A & B
*    0   0     0
*    0   1     0
*    1   0     0
*    1   1     1
*
*    Truth table for bitwise OR operator (|):
*    
*    A   B   A | B
*    0   0     0
*    0   1     1
*    1   0     1
*    1   1     1
*    
*    Truth table for bitwise XOR operator (^):
*
*    A   B   A ^ B
*    0   0     0
*    0   1     1
*    1   0     1
*    1   1     0
*
*    Truth table for one's complement operator (~):
*    A     ~A
*    0      1
*    1      0
*
*
*
*
*
*
*/

#ifndef BITCONFIG_H
#define BITCONFIG_H

#define SET_VAL_BIT(REG , BIT)      REG |= (1 << BIT)        // Set the bit value to 1
#define CLEAR_VAL_BIT(REG , BIT)    REG &= (~(1 << BIT))     // Clear the bit value to 0
#define TOGGLE_VAL_BIT(REG , BIT)   REG ^= (1 << BIT)        // Toggle the bit value
#define READ_BIT_VAL(REG , BIT)     REG  & (1 << BIT)        // Read the bit value that might be 0 or 1 


#endif 