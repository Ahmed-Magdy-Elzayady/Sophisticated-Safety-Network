/* 
 * File:   MCAL_GPIO.h
 * Author: AHMED MAGDY ELZAYADY
 *
 * Created on NOVEMBER 25, 2023, 7:20 PM
 */
#ifndef MCAL_STD_TYPES_H
#define	MCAL_STD_TYPES_H

#include "STD_Libraries.h"
#include "compiler.h"

/********************************Function like macro********************************/

/*******************************data type declaration********************************/
typedef unsigned char                   uint8_tt;
typedef unsigned short int              uint16_tt;
typedef unsigned long int               uint32_tt;
typedef signed char                     sint8_tt;
typedef signed short int                sint16_tt;
typedef signed long int                 sint32_tt;
typedef uint8_tt                        Std_ReturnType;


/*********************************Macro Declaration*********************************/
#define STD_ON                          0x01
#define STD_OFF                         0x00


#define E_OK                            0x01
#define E_NOT_OK                        0x00


#define HIGH                            0x01
#define LOW                             0x00

/********************************function declaration *******************************  */

#endif	/* MCAL_STD_TYPES_H */

