#include "ECU_Seven_Segment.h"

Std_ReturnType SEVEN_SEGMENT_INIT(const seven_segment_config_t *seg) {

    Std_ReturnType ret = E_NOT_OK;
    if (NULL == seg) {

        ret = E_NOT_OK;
    } 
    
    else {

        uint8_tt i = 0;
        for (i = 0; i <= 3; i++) {
            GPIO_SET_PIN_DIRECTION(&(seg->seven_segment_pins[i]));
            GPIO_SET_PIN_VALUE(&(seg->seven_segment_pins[i]),seg->seven_segment_pins[i].logic);

        }
        ret = E_OK;
    }
    return ret;
}

Std_ReturnType SEVEN_SEGMENT_WRITE_NUMBER(const seven_segment_config_t *seg, uint8_tt number) {

    Std_ReturnType ret = E_NOT_OK;
    if (NULL == seg || number > 9) {

        ret = E_NOT_OK;
    } 
    
    else {
        GPIO_SET_PIN_VALUE(&(seg->seven_segment_pins[0]), number & 1);
        GPIO_SET_PIN_VALUE(&(seg->seven_segment_pins[1]), (number >> 1) & 1);
        GPIO_SET_PIN_VALUE(&(seg->seven_segment_pins[2]), (number >> 2) & 1);
        GPIO_SET_PIN_VALUE(&(seg->seven_segment_pins[3]), (number >> 3) & 1);
        ret = E_OK;

    }

    return ret;


}