/* 
 * File:   MCAL_GPIO.h
 * Author: AHMED MAGDY ELZAYADY
 *
 * Created on NOVEMBER 25, 2023, 7:20 PM
 */
#include "MCAL_GPIO.h"
/*ARRAY OF ADDRESS OF TRIS REGISTERS*/
volatile uint8_tt *tris_registers[] = {&TRISA, &TRISB, &TRISC, &TRISD, &TRISE};
/*ARRAY OF ADDRESS OF LAT REGISTERS*/
volatile uint8_tt *lat_registers[] = {&LATA, &LATB, &LATC, &LATD, &LATE};
/*ARRAY OF ADDRESS OF PORT REGISTERS*/
volatile uint8_tt *port_registers[] = {&PORTA,&PORTB, &PORTC, &PORTD, &PORTE};

/**
 * E_OK -> THE FUNCTION DONE SUCCESSFULLY
 * E_NOT_OK -> THE FUNCTION FAILD
 * @param _pin_configration
 * @return status of the function
 * THIS FUNCTION SET THE DIRECTION OF THE DESIRED PIN
 */

#if GPIO_PORT_PIN_CONFIGRATIONS==CONFIG_ENABLE

Std_ReturnType GPIO_SET_PIN_DIRECTION(const pin_config_tt *_pin_configration) {
    Std_ReturnType ret = E_OK;
    if (NULL == _pin_configration || _pin_configration->pin > MAX_PIN_NUMBER - 1) {
        ret = E_NOT_OK;
    } else {
        switch (_pin_configration->direction) {

            case GPIO_OUTPUT:
                CLEAR_BIT(*tris_registers[_pin_configration->port], _pin_configration->pin);
                break;

            case GPIO_INPUT:
                SET_BIT(*tris_registers[_pin_configration->port], _pin_configration->pin);

            default:
                ret = E_NOT_OK;
        }
    }
    return ret;
}
#endif

/**
 * E_OK -> THE FUNCTION DONE SUCCESSFULLY
 * E_NOT_OK -> THE FUNCTION FAILD
 * @param _pin_configration
 * @param logic
 * @return status of the function
 * THIS FUNCTION STATE THE VALUE OF THE DESIRED OIN
 */
#if GPIO_PORT_PIN_CONFIGRATIONS==CONFIG_ENABLE

Std_ReturnType GPIO_SET_PIN_VALUE(const pin_config_tt *_pin_configration, uint8_tt logic) {

    Std_ReturnType ret = E_OK;
    if (NULL == _pin_configration || _pin_configration->pin > MAX_PIN_NUMBER - 1) {
        ret = E_NOT_OK;
    } else {
        switch (logic) {
            case GPIO_HIGH:
                SET_BIT(*lat_registers[_pin_configration->port], _pin_configration->pin);
                break;
            case GPIO_LOW:
                CLEAR_BIT(*lat_registers[_pin_configration->port], _pin_configration->pin);
            default:
                ret = E_NOT_OK;
        }
    }

    return ret;
}
#endif

/**
 * E_OK -> THE FUNCTION DONE SUCCESSFULLY
 * E_NOT_OK -> THE FUNCTION FAILD
 * @param _Pin_configration
 * @param logic
 * @return status of the function
 * THIS FUNCTION READ THE VALUE OF THE DESIRED PIN
 */
#if GPIO_PORT_PIN_CONFIGURATIONS==CONFIG_DISENABLE
Std_ReturnType GPIO_READ_PIN_VALUE(const pin_config_tt *_pin_config, logic_tt *logic){
    Std_ReturnType ret = E_OK;
    if(NULL == _pin_config || NULL == logic || _pin_config->pin > MAX_PIN_NUMBER-1){
        ret = E_NOT_OK;
    }
    else{
        *logic = READ_BIT(*port_registers[_pin_config->port], _pin_config->pin);
    }
    return ret;
}
#endif

/**
 * E_OK -> THE FUNCTION DONE SUCCESSFULLY
 * E_NOT_OK -> THE FUNCTION FAILD
 * @param _pin_configration
 * @param direction
 * @return status of the function
 * THIS FUNCTION READ THE VALUE OF THE DESIRED PIN
 */
#if GPIO_PORT_PIN_CONFIGRATIONS==CONFIG_ENABLE

Std_ReturnType GPIO_GET_PIN_DIRECTION(const pin_config_tt *_pin_configration, pin_direction_tt *direction) {

    Std_ReturnType ret = E_OK;
    if (NULL == _pin_configration || NULL == direction) {
        ret = E_NOT_OK;
    } else {
        *direction = READ_BIT(*tris_registers[_pin_configration->port], _pin_configration->pin);

    }
    return ret;
}
#endif
/**
 * E_OK -> THE FUNCTION DONE SUCCESSFULLY
 * E_NOT_OK -> THE FUNCTION FAILD
 * @param _pin_configration
 * @return status of the function
 * THIS FUNCTION TOOGLE THE VALUE OF THE DESIRED PIN
 */
#if GPIO_PORT_PIN_CONFIGRATIONS==CONFIG_ENABLE

Std_ReturnType GPIO_TOOGLE_PIN_VALUE(const pin_config_tt *_pin_configration) {

    Std_ReturnType ret = E_OK;
    if (NULL == _pin_configration || _pin_configration->pin > MAX_PIN_NUMBER - 1) {
        ret = E_NOT_OK;
    } else {
        TOOGLE_BIT(*lat_registers[_pin_configration->port], _pin_configration->pin);
    }
    return ret;
}
#endif
/**
 * E_OK -> THE FUNCTION DONE SUCCESSFULLY
 * E_NOT_OK -> THE FUNCTION FAILD
 * @param _pin_configration
 * @param direction_state
 * @return status of the function
  * THIS FUNCTION SET THE DIRECTION OF THE DESIRED PORT
 */
#if GPIO_PORT_PIN_CONFIGRATIONS==CONFIG_ENABLE

Std_ReturnType GPIO_SET_PORT_DIRECTION(PORT_NUMBER_tt port, uint8_tt value) {

    Std_ReturnType ret = E_OK;
    if (port > MAX_PORT_NUMBER - 1) {
        ret = E_NOT_OK;
    } else {
        *tris_registers[port] = value;
    }
    return ret;
}
#endif
/**
 * E_OK -> THE FUNCTION DONE SUCCESSFULLY
 * E_NOT_OK -> THE FUNCTION FAILD
 * @param port
 * @param logic
 * @return status of the function
 *  THIS FUNCTION SET THE VALUE OF THE DESIRED PIN
 */
#if GPIO_PORT_PIN_CONFIGRATIONS==CONFIG_ENABLE

Std_ReturnType GPIO_SET_PORT_VALUE(PORT_NUMBER_tt port, uint8_tt logic) {
    Std_ReturnType ret = E_OK;
    if (port > MAX_PORT_NUMBER - 1) {
        ret = E_NOT_OK;
    } else {
        *lat_registers[port] = logic;
    }
    return ret;
}
#endif
/**
 * E_OK -> THE FUNCTION DONE SUCCESSFULLY
 * E_NOT_OK -> THE FUNCTION FAILD
 * @param port
 * @param value
 * @return status of the function
 * THIS FUNCTION READ THE VALUE OF THE DESIRED PORT
 */
#if GPIO_PORT_PIN_CONFIGRATIONS==CONFIG_ENABLE

Std_ReturnType GPIO_READ_PORT_VALUE(PORT_NUMBER_tt port, uint8_tt *value) {

    Std_ReturnType ret = E_OK;
    if (port > MAX_PORT_NUMBER - 1 || NULL == value) {
        ret = E_NOT_OK;
    } else {
        *value = *lat_registers[port];

    }
    return ret;
}
#endif

/**
 * E_OK -> THE FUNCTION DONE SUCCESSFULLY
 * E_NOT_OK -> THE FUNCTION FAILD
 * @param port
 * @param direction
 * @return status of the function
 * THIS FUNCTION GET THE DIRECTION OF THE DESIRED PORT
 */
#if GPIO_PORT_PIN_CONFIGRATIONS==CONFIG_ENABLE

Std_ReturnType GPIO_GET_PORT_DIRECTION(PORT_NUMBER_tt port, pin_direction_tt *direction) {
    Std_ReturnType ret = E_OK;
    if (port > MAX_PORT_NUMBER - 1 || NULL == direction) {
        ret = E_NOT_OK;
    } else {
        *direction = *tris_registers[port];
    }
    return ret;
}
#endif

/**
 * E_OK -> THE FUNCTION DONE SUCCESSFULLY
 * E_NOT_OK -> THE FUNCTION FAILD
 * @param port
 * @return status of the function
 *  THIS FUNCTION TOOGLE THE VALUE OF THE DESIRED PORT
 */
#if GPIO_PORT_PIN_CONFIGRATIONS==CONFIG_ENABLE

Std_ReturnType GPIO_TOOGLE_PORT_VALUE(PORT_NUMBER_tt port) {
    Std_ReturnType ret = E_OK;
    if (port > MAX_PORT_NUMBER - 1) {
        ret = E_NOT_OK;
    } else {
        *lat_registers[port] ^= 0XFF;
    }
    return ret;
}
#endif


/**
 * E_OK -> THE FUNCTION DONE SUCCESSFULLY
 * E_NOT_OK -> THE FUNCTION FAILD
 * @param -pin_configration
 * @return status of the function
 *  THIS FUNCTION init the pin state
 */
#if GPIO_PORT_PIN_CONFIGRATIONS==CONFIG_ENABLE

Std_ReturnType GPIO_PIN_INIT(const pin_config_tt *_pin_configration) {

    Std_ReturnType ret=E_OK;
    if(NULL== _pin_configration || _pin_configration->pin>MAX_PIN_NUMBER-1){
    
    
        ret=E_NOT_OK;
    }
    
    else {
    
        ret=GPIO_SET_PIN_DIRECTION(_pin_configration);
        ret=GPIO_SET_PIN_VALUE(_pin_configration,_pin_configration->logic);
    
    }
    
    return ret;


}

#endif



