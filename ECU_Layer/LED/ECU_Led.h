/* 
 * File:   MCAL_GPIO.h
 * Author: AHMED MAGDY ELZAYADY
 *
 * Created on NOVEMBER 25, 2023, 7:20 PM
 */

#ifndef ECU_LED_H

#define	ECU_LED_H
/*includes section*/

#include "../../MCAL_Layer/GPIO/MCAL_GPIO.h"
#include "ECU_LED_cfg.h"

/*Macro Declaration*/


/*Function like macro*/

/*data type declaration*/

typedef enum {
    LED_OFF=0,
    LED_ON

}led_state_t;

typedef struct {

    uint8_tt port_name:3; /*@ref */
    uint8_tt pin_number:3;
    uint8_tt led_status:1;
    uint8_tt reserved :1; /* for future work*/

}led_config_t;


/*function declaration */
Std_ReturnType LED_TURN_ON(led_config_t *_led_config);
Std_ReturnType LED_TURN_OFF(led_config_t  *_led_config);
Std_ReturnType LED_TOOGLE(led_config_t  *_led_config);

#endif	/* ECU_LED_H */

