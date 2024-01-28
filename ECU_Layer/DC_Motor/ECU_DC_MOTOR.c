#include "ECU_DC_MOTOR.h"






Std_ReturnType DC_MOTOR_INIT(const dc_motor_config_t *_dc_motor){
    
    Std_ReturnType ret=E_NOT_OK;
    if(NULL==_dc_motor){
        
        ret=E_NOT_OK;
    }
    else {
        
        GPIO_SET_PIN_DIRECTION(&(_dc_motor->dc_motor_cfg[DC_MOTOR_PIN_ONE]));
         GPIO_SET_PIN_DIRECTION(&(_dc_motor->dc_motor_cfg[DC_MOTOR_PIN_TWO]));
        
    }
    
    
    return ret;
    
}


Std_ReturnType DC_MOTOR_TURN_RIGHT(const dc_motor_config_t *_dc_motor){
    
    
    Std_ReturnType ret=E_NOT_OK;
    if(NULL==_dc_motor){
        
        ret=E_NOT_OK;
    }
    else {
        
        GPIO_SET_PIN_VALUE(&(_dc_motor->dc_motor_cfg[DC_MOTOR_PIN_ONE]),GPIO_HIGH);
        GPIO_SET_PIN_VALUE(&(_dc_motor->dc_motor_cfg[DC_MOTOR_PIN_TWO]),GPIO_LOW);
        
        
          ret=E_OK;
    }
    return ret;
    
}
Std_ReturnType DC_MOTOR_TURN_LEFT(const dc_motor_config_t *_dc_motor){
    
    
    Std_ReturnType ret=E_NOT_OK;
    if(NULL==_dc_motor){
        
        ret=E_NOT_OK;
    }
    else {
        
        GPIO_SET_PIN_VALUE(&(_dc_motor->dc_motor_cfg[DC_MOTOR_PIN_ONE]),GPIO_LOW);
        GPIO_SET_PIN_VALUE(&(_dc_motor->dc_motor_cfg[DC_MOTOR_PIN_TWO]),GPIO_HIGH);
        
          ret=E_OK;
    }
    return ret;
    
    
}
Std_ReturnType DC_MOTOR_STOP(const dc_motor_config_t *_dc_motor){
    
    
    
    Std_ReturnType ret=E_NOT_OK;
    if(NULL==_dc_motor){
        
        ret=E_NOT_OK;
    }
    else {
       GPIO_SET_PIN_VALUE(&(_dc_motor->dc_motor_cfg[DC_MOTOR_PIN_ONE]),GPIO_LOW);
          GPIO_SET_PIN_VALUE(&(_dc_motor->dc_motor_cfg[DC_MOTOR_PIN_TWO]),GPIO_LOW);
       
        ret=E_OK;
    }
    
    
    return ret;
    
    
    
}
