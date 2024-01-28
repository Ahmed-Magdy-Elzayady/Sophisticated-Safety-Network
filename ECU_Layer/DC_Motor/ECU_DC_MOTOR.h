/* 
 * File:   ECU_DC_MOTOR.h
 * Author: FuTuRe
 *
 * Created on December 10, 2023, 6:05 PM
 */

#ifndef ECU_DC_MOTOR_H
#define	ECU_DC_MOTOR_H

/*include section*/
#include "ECU_DC_MOTOR_cfg.h"
#include"../../MCAL_Layer/GPIO/MCAL_GPIO.h"




/*MACROS SECTION*/

#define DC_MOTOR_OFF                    0x00
#define DC_MOTOR_ON                     0x01

#define DC_MOTOR_PIN_ONE                0x00
#define DC_MOTOR_PIN_TWO                0x01


/*DATA TYPE SECTION*/



typedef struct {
    
    pin_config_tt dc_motor_cfg[2];
    
}dc_motor_config_t;


/*interfaces section*/


Std_ReturnType DC_MOTOR_INIT(const dc_motor_config_t *_dc_motor);
Std_ReturnType DC_MOTOR_TURN_RIGHT(const dc_motor_config_t *_dc_motor);
Std_ReturnType DC_MOTOR_TURN_LEFT(const dc_motor_config_t *_dc_motor);
Std_ReturnType DC_MOTOR_STOP(const dc_motor_config_t *_dc_motor);




#endif	/* ECU_DC_MOTOR_H */

