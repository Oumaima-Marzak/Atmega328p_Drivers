/*
*   Author : Oumaima MARZAK
*   
*
*
*
*/

/*
*   The Basic Data types in C langage are in two big categories : 
*               --------------------------------------------
*               |  Integer Values   |   Floating Values    |
*               --------------------------------------------
*               |   int   |   char  |   Float  |   Double  |
*      -----------------------------------------------------
*      |  Size  |2/4 bytes| 1 byte  |  4 Bytes |  8 Bytes  |
*      -----------------------------------------------------     
*               |         |         
*               |         |
*               |         |
*   
*    + Short & Long or signed & unsigned are qualifiers not data types. 
*    + Qualifiers in C are keywords that modify the behavior or properties of other data types. 
*    + They alter the characteristics of a base data type without creating an entirely new type. 
*       
*       - "const" is a qualifier that specifies that a variable's value cannot be changed once it's initialized.
*        
*       - "volatile" indicates that a variable can be modified unexpectedly by other parts of the program.
*        
*       - "signed" and "unsigned" are qualifiers used with integer types to specify whether they can represent both positive 
*       and negative values or only non-negative values.
*        
*       - "long" and "short" are qualifiers used with integer types to modify the range or size of the integer values they 
*       can hold.
*    
*    + Bool is not a standard data type in C89. However, the <stdbool.h> header introduced in the C99 standard defines 
*    the bool, true, and false macros to work with boolean values more explicitly. This header provides a way to work with 
*    boolean values in a clearer and more expressive manner.
*/

#ifndef DATATYPES_H
#define DATATYPES_H


typedef unsigned char            Uch8;   // 1 byte >> 8 bits
typedef unsigned short int       Unt16;  // 2 byte >> 16 bits
typedef unsigned long  int       Unt32;  // 4 byte >> 32 bits
typedef unsigned long  long int  Unt64;  // 8 byte >> 64 bits

typedef struct 
{
    
    Uch8 pin;
    Uch8 ddr;
    Uch8 port;

} PinConfig;

#endif
