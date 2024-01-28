/* 
 * File:   MCAL_GPIO.h
 * Author: AHMED MAGDY ELZAYADY
 *
 * Created on NOVEMBER 25, 2023, 7:20 PM
 */
#include "ECU_Led.h"

/**
 * E_OK -> THE FUNCTION DONE SUCCESSFULLY
 * E_NOT_OK -> THE FUNCTION FAILD
 * @param _led_config
 * @return status of the function
 */

#if GPIO_PORT_PIN_CONFIGRATIONS==CONFIG_ENABLE
Std_ReturnType LED_TURN_ON(led_config_t *_led_config) {

    Std_ReturnType ret = E_OK;
    if (NULL == _led_config) {
        ret = E_NOT_OK;

    }
    else {
        pin_config_tt pin_object={
            .port=_led_config->port_name,.pin=_led_config->pin_number,
            .direction=GPIO_OUTPUT,.logic=_led_config->led_status
        };
        
        GPIO_SET_PIN_DIRECTION(&pin_object);
        GPIO_SET_PIN_VALUE(&pin_object,GPIO_HIGH);
        
    }

    return ret;
}
#endif

/**
 * E_OK -> THE FUNCTION DONE SUCCESSFULLY
 * E_NOT_OK -> THE FUNCTION FAILD
 * @param _led_config
 * @return status of the function
 */

#if GPIO_PORT_PIN_CONFIGRATIONS==CONFIG_ENABLE
Std_ReturnType LED_TURN_OFF(led_config_t *_led_config) {
    Std_ReturnType ret = E_OK;
    if (NULL == _led_config) {
        ret = E_NOT_OK;

    }
    else {

     pin_config_tt pin_object={
            .port=_led_config->port_name,.pin=_led_config->pin_number,
            .direction=GPIO_OUTPUT,.logic=_led_config->led_status
        };
        
        GPIO_SET_PIN_DIRECTION(&pin_object);
        GPIO_SET_PIN_VALUE(&pin_object,GPIO_LOW);

    }

    return ret;
}
#endif
/**
 * E_OK -> THE FUNCTION DONE SUCCESSFULLY
 * E_NOT_OK -> THE FUNCTION FAILD
 * @param _led_config
 * @return status of the function
 */

#if GPIO_PORT_PIN_CONFIGRATIONS==CONFIG_ENABLE
Std_ReturnType LED_TOOGLE(led_config_t *_led_config) {
    Std_ReturnType ret = E_OK;
    if (NULL == _led_config) {
        ret = E_NOT_OK;

    }
    else {

         pin_config_tt pin_object={
            .port=_led_config->port_name,.pin=_led_config->pin_number,
            .direction=GPIO_OUTPUT,.logic=_led_config->led_status
        };
        
        GPIO_SET_PIN_DIRECTION(&pin_object);
        GPIO_TOOGLE_PIN_VALUE(&pin_object);
       
    }

    return ret;
}

#endif