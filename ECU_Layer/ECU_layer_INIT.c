#include"ECU_layer_INIT.h"



keypad_config_t keypad_one={
  
    .keypad_rows_pins[0].port=PORTA_INDEX,
    .keypad_rows_pins[0].pin=GPIO_PIN0,
    .keypad_rows_pins[0].direction=GPIO_OUTPUT,
    .keypad_rows_pins[0].logic=GPIO_LOW,
    .keypad_rows_pins[1].port=PORTA_INDEX,
    .keypad_rows_pins[1].pin=GPIO_PIN1,
    .keypad_rows_pins[1].direction=GPIO_OUTPUT,
    .keypad_rows_pins[1].logic=GPIO_LOW,
    .keypad_rows_pins[2].port=PORTA_INDEX,
    .keypad_rows_pins[2].pin=GPIO_PIN2,
    .keypad_rows_pins[2].direction=GPIO_OUTPUT,
    .keypad_rows_pins[2].logic=GPIO_LOW,
    .keypad_rows_pins[3].port=PORTA_INDEX,
    .keypad_rows_pins[3].pin=GPIO_PIN3,
    .keypad_rows_pins[3].direction=GPIO_OUTPUT,
    .keypad_rows_pins[3].logic=GPIO_LOW,
    .keypad_columns_pins[0].port=PORTB_INDEX,
    .keypad_columns_pins[0].pin=GPIO_PIN0,
    .keypad_columns_pins[0].direction=GPIO_INPUT,
    .keypad_columns_pins[1].port=PORTB_INDEX,
    .keypad_columns_pins[1].pin=GPIO_PIN1,
    .keypad_columns_pins[1].direction=GPIO_INPUT,
    .keypad_columns_pins[2].port=PORTB_INDEX,
    .keypad_columns_pins[2].pin=GPIO_PIN2,
    .keypad_columns_pins[2].direction=GPIO_INPUT,
    .keypad_columns_pins[3].port=PORTB_INDEX,
    .keypad_columns_pins[3].pin=GPIO_PIN3,
    .keypad_columns_pins[3].direction=GPIO_INPUT, 
};


lcd_8bit_t lcd_one={
  
    .lcd_8b_RS.port=PORTC_INDEX,
    .lcd_8b_RS.direction=GPIO_OUTPUT,
    .lcd_8b_RS.pin=GPIO_PIN0,
    .lcd_8b_RS.logic=GPIO_LOW, 
    .lcd_8b_EN.port=PORTC_INDEX,
    .lcd_8b_EN.direction=GPIO_OUTPUT,
    .lcd_8b_EN.pin=GPIO_PIN1,
    .lcd_8b_EN.logic=GPIO_LOW,
    .lcd_8b_data[0].port=PORTC_INDEX,
    .lcd_8b_data[0].pin=GPIO_PIN2,
    .lcd_8b_data[0].direction=GPIO_OUTPUT,
    .lcd_8b_data[0].logic=GPIO_LOW,
    .lcd_8b_data[1].port=PORTC_INDEX,
    .lcd_8b_data[1].pin=GPIO_PIN3,
    .lcd_8b_data[1].direction=GPIO_OUTPUT,
    .lcd_8b_data[1].logic=GPIO_LOW,
    .lcd_8b_data[2].port=PORTC_INDEX,
    .lcd_8b_data[2].pin=GPIO_PIN4,
    .lcd_8b_data[2].direction=GPIO_OUTPUT,
    .lcd_8b_data[2].logic=GPIO_LOW,
    .lcd_8b_data[3].port=PORTC_INDEX,
    .lcd_8b_data[3].pin=GPIO_PIN5,
    .lcd_8b_data[3].direction=GPIO_OUTPUT,
    .lcd_8b_data[3].logic=GPIO_LOW,
    .lcd_8b_data[4].port=PORTC_INDEX,
    .lcd_8b_data[4].pin=GPIO_PIN6,
    .lcd_8b_data[4].direction=GPIO_OUTPUT,
    .lcd_8b_data[4].logic=GPIO_LOW,
    .lcd_8b_data[5].port=PORTC_INDEX,
    .lcd_8b_data[5].pin=GPIO_PIN7,
    .lcd_8b_data[5].direction=GPIO_OUTPUT,
    .lcd_8b_data[5].logic=GPIO_LOW,
    .lcd_8b_data[6].port=PORTD_INDEX,
    .lcd_8b_data[6].pin=GPIO_PIN0,
    .lcd_8b_data[6].direction=GPIO_OUTPUT,
    .lcd_8b_data[6].logic=GPIO_LOW,
    .lcd_8b_data[7].port=PORTD_INDEX,
    .lcd_8b_data[7].pin=GPIO_PIN1,
    .lcd_8b_data[7].direction=GPIO_OUTPUT,
    .lcd_8b_data[7].logic=GPIO_LOW
};


led_config_t led_one={
    
  .port_name=PORTD_INDEX,
.pin_number=GPIO_PIN7,
.led_status=LED_OFF 
    
};

led_config_t led_two={
    
  .port_name=PORTD_INDEX,
.pin_number=GPIO_PIN6,
.led_status=LED_OFF 
    
};



seven_segment_config_t seg_one={
    
  .seven_segment_mode=  SEVEN_SEGMENT_CATHOD_MODE,
  .seven_segment_pins[0].port=PORTD_INDEX,
  .seven_segment_pins[0].pin=GPIO_PIN2,
  .seven_segment_pins[0].direction=GPIO_OUTPUT,
  .seven_segment_pins[0].logic=GPIO_HIGH,
  
    .seven_segment_pins[1].port=PORTD_INDEX,
  .seven_segment_pins[1].pin=GPIO_PIN3,
  .seven_segment_pins[1].direction=GPIO_OUTPUT,
  .seven_segment_pins[1].logic=GPIO_HIGH,
  
    .seven_segment_pins[2].port=PORTD_INDEX,
  .seven_segment_pins[2].pin=GPIO_PIN4,
  .seven_segment_pins[2].direction=GPIO_OUTPUT,
  .seven_segment_pins[2].logic=GPIO_HIGH,
  
    .seven_segment_pins[3].port=PORTD_INDEX,
  .seven_segment_pins[3].pin=GPIO_PIN5,
  .seven_segment_pins[3].direction=GPIO_OUTPUT,
         .seven_segment_pins[3].logic=GPIO_HIGH
  
};


dc_motor_config_t motor_one={
  
    .dc_motor_cfg[0].port=PORTB_INDEX,
    .dc_motor_cfg[0].pin=GPIO_PIN4,
    .dc_motor_cfg[0].direction=GPIO_OUTPUT,
    
    .dc_motor_cfg[1].port=PORTB_INDEX,
    .dc_motor_cfg[1].pin=GPIO_PIN5,
    .dc_motor_cfg[1].direction=GPIO_OUTPUT,
    
    
};

void ECU_LAYER_INITI(void) {
    Std_ReturnType ret = E_NOT_OK;
    KEYPAD_INIT(&(keypad_one));
    LCD_8BIT_INIT(&(lcd_one));
    SEVEN_SEGMENT_INIT(&(seg_one));
    DC_MOTOR_INIT(&(motor_one));

   
    

}