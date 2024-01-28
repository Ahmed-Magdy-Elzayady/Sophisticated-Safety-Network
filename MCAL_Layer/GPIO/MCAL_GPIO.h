/* 
 * File:   MCAL_GPIO.h
 * Author: AHMED MAGDY ELZAYADY
 *
 * Created on NOVEMBER 25, 2023, 7:20 PM
 */

#ifndef MCAL_GPIO_H
#define	MCAL_GPIO_H

/*Section :includes */
#include "C:\Program Files\Microchip\xc8\v2.45\pic\include\proc\pic18f4620.h"
#include "../MCAL_STD_TYPES.h"
#include "../device_config.h"
#include "MCAL_GPIO_CFG.h"

/*Macro Declaration*/
#define BIT_MASK                        (uint8_tt)1
#define MAX_PORT_NUMBER                           5
#define MAX_PIN_NUMBER                            8

/*Function like macro*/
#define HWREG8(_x)                  (*((volatile uint8_t*)(_x)))
#define SET_BIT(REG,BIT_POSN)       (REG|=(BIT_MASK<<BIT_POSN))
#define CLEAR_BIT(REG,BIT_POSN)     (REG&=~(BIT_MASK <<BIT_POSN))
#define TOOGLE_BIT(REG,BIT_POSN)    (REG^=(BIT_MASK <<BIT_POSN))
#define READ_BIT(REG,BIT_POSN)      ((REG>>BIT_POSN)&BIT_MASK )

/*data type declaration*/
typedef enum {
    GPIO_LOW = 0,
    GPIO_HIGH

} logic_tt;

typedef enum {
    PORTA_INDEX = 0,
    PORTB_INDEX,
    PORTC_INDEX,
    PORTD_INDEX,
    PORTE_INDEX

} PORT_NUMBER_tt;

typedef enum {
    GPIO_OUTPUT = 0,
    GPIO_INPUT

} pin_direction_tt;

typedef enum {
    GPIO_PIN0 = 0,
    GPIO_PIN1,
    GPIO_PIN2,
    GPIO_PIN3,
    GPIO_PIN4,
    GPIO_PIN5,
    GPIO_PIN6,
    GPIO_PIN7,


}pin_index_tt;

typedef struct {
    uint8_tt port : 3;          /*@ref PORT_NUMBER_tt */
    uint8_tt pin : 3;           /*@ref pin_index_tt */
    uint8_tt direction : 1;     /*@ref pin_direction_tt */
    uint8_tt logic : 1   ;       /*@ref logic_tt */

} pin_config_tt;

/*function declaration */
Std_ReturnType GPIO_SET_PIN_DIRECTION(const pin_config_tt *_pin_configration);                   /* TESTED SUCCESSFULLY AND RETURN E_OK*/
Std_ReturnType GPIO_SET_PIN_VALUE(const pin_config_tt *_pin_configration, uint8_tt logic);       /* TESTED SUCCESSFULLY AND RETURN E_OK*/
Std_ReturnType GPIO_READ_PIN_VALUE(const pin_config_tt *_Pin_configration, logic_tt *logic);     /* TESTED SUCCESSFULLY AND RETURN E_OK*/
Std_ReturnType GPIO_GET_PIN_DIRECTION(const pin_config_tt * _pin_configration, pin_direction_tt *direction); /* TESTED SUCCESSFULLY AND RETURN E_OK*/
Std_ReturnType GPIO_TOOGLE_PIN_VALUE(const pin_config_tt *_pin_configration);  /* TESTED SUCCESSFULLY AND RETURN E_OK*/
Std_ReturnType GPIO_PIN_INIT(const pin_config_tt *_pin_configration);


Std_ReturnType GPIO_SET_PORT_DIRECTION(PORT_NUMBER_tt port, uint8_tt value);   /* TESTED SUCCESSFULLY AND RETURN E_OK*/
Std_ReturnType GPIO_SET_PORT_VALUE(PORT_NUMBER_tt port, uint8_tt logic);        /* TESTED SUCCESSFULLY AND RETURN E_OK*/
Std_ReturnType GPIO_READ_PORT_VALUE(PORT_NUMBER_tt port, uint8_tt *value);       /* TESTED SUCCESSFULLY AND RETURN E_OK*/
Std_ReturnType GPIO_GET_PORT_DIRECTION(PORT_NUMBER_tt port, pin_direction_tt *direction); /* TESTED SUCCESSFULLY AND RETURN E_OK*/
Std_ReturnType GPIO_TOOGLE_PORT_VALUE(PORT_NUMBER_tt port); /* TESTED SUCCESSFULLY AND RETURN E_OK*/








#endif	/* MCAL_GPIO_H */

