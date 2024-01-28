/* 
 * File:   ECU_Seven_Segment.h
 * Author: FuTuRe
 *
 * Created on December 12, 2023, 8:03 PM
 */

#ifndef ECU_SEVEN_SEGMENT_H
#define	ECU_SEVEN_SEGMENT_H

/*includes section*/

#include "ECU_Seven_Segment_cfg.h"
#include "../../MCAL_Layer/GPIO/MCAL_GPIO.h"


/*macros section*/

#define SEVEN_SEGMENT_ANODE_MODE        0x00
#define SEVEN_SEGMENT_CATHOD_MODE       0x01
/* datatype section*/

typedef struct {
    
    pin_config_tt seven_segment_pins[4];
    uint8_tt seven_segment_mode ;
    
}seven_segment_config_t;



/*APIs sections*/

Std_ReturnType SEVEN_SEGMENT_INIT(const seven_segment_config_t *seg);
Std_ReturnType SEVEN_SEGMENT_WRITE_NUMBER(const seven_segment_config_t *seg,uint8_tt number);




#endif	/* ECU_SEVEN_SEGMENT_H */

