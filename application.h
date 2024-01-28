/*
 * File:   SMART SECURITY SYSTEM
 * Author: Ahmed Magdy Elzayady
 * linked-in peofile: https://www.linkedin.com/in/ahmed-magdy-elzayady/
 * Created on JAN 27, 2024, 12:06 AM
 */


#ifndef APPLICATION_H
#define	APPLICATION_H

#include "ECU_Layer/ECU_layer_INIT.h"

/*datatype declaration*/

extern keypad_config_t keypad_one;
extern lcd_8bit_t lcd_one;
extern led_config_t led_one;
extern seven_segment_config_t seg_one;
extern dc_motor_config_t motor_one;
extern led_config_t led_two;



/*APIs Declaration*/
void Application_Init(void);
void Welcome_Message(void);

#endif	/* APPLICATION_H */

