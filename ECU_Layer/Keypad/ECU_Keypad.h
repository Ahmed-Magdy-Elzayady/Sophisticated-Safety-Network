/* 
 * File:   ECU_Keypad.h
 * Author: FuTuRe
 *
 * Created on December 14, 2023, 3:56 PM
 */

#ifndef ECU_KEYPAD_H
#define	ECU_KEYPAD_H

#include "ECU_Keypad_cfg.h"
#include "../../MCAL_Layer/GPIO/MCAL_GPIO.h"



/*MAcros section*/

#define KEYPAD_ROWS_NUMBER              4
#define KEYPAD_COLUMNS_NUMBER           4


/*datatype section*/
typedef struct {
    
    pin_config_tt keypad_rows_pins[KEYPAD_ROWS_NUMBER];
    pin_config_tt keypad_columns_pins[KEYPAD_COLUMNS_NUMBER];
    
    
}keypad_config_t;


/*APIs section*/

Std_ReturnType KEYPAD_INIT(const keypad_config_t *keypad);
Std_ReturnType KEYPAD_GET_VALUE(const keypad_config_t *keypad,uint8_tt *_value);










#endif	/* ECU_KEYPAD_H */

