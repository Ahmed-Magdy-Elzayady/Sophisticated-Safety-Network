/* 
 * File:   ECU_LCD.h
 * Author: FuTuRe
 *
 * Created on January 24, 2024, 7:56 PM
 */

#ifndef ECU_LCD_H
#define	ECU_LCD_H

#include "LCD_cnfg.h"
#include "../../MCAL_Layer/GPIO/MCAL_GPIO.h"


/**************datatypes****************/

/*MACROS*/

#define _LCD_CLEAR                                                  0X01
#define _LCD_RETURN_HOME                                            0X02
#define _LCD_ENTRY_MODE_DEC_SHIFT_OFF                               0X04
#define _LCD_ENTRY_MODE_DEC_SHIFT_ON                                0X05
#define _LCD_ENTRY_MODE_INC_SHIFT_OFF                               0X06
#define _LCD_ENTRY_MODE_INC_SHIFT_ON                                0X07
#define _LCD_CURSOR_MOVE_SHIFT_LEFT                                 0X10
#define _LCD_CURSOR_MOVE_SHIFT_RIGHT                                0X14
#define _LCD_DISPLAY_SHIFT_LEFT                                     0X18
#define _LCD_DISPLAY_SHIFT_RIGHT                                    0X1C
#define _LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_OFF                    0X0C
#define _LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_ON                     0X0D
#define _LCD_DISPLAY_ON_UNDERLINE_ON_CURSOR_OFF                     0X0E
#define _LCD_DISPLAY_ON_UNDERLINE_ON_CURSOR_ON                      0X0F
#define _LCD_DISPLAY_OFF_CURSOR_OFF                                 0X08
#define _LCD_8BIT_MODE_2_LINE                                       0X38
#define _LCD_4BIT_MODE_2_LINE                                       0X28
#define _LCD_CGRAM_START                                            0X40
#define _LCD_DDRAM_START                                            0X80
#define ROW1                                                        1
#define ROW2                                                        2
#define ROW3                                                        3
#define ROW4                                                        4

























typedef struct {
    
    pin_config_tt lcd_8b_RS;
    pin_config_tt lcd_8b_EN;
    pin_config_tt lcd_8b_data[8];
    
}lcd_8bit_t;

typedef struct {
    pin_config_tt lcd_4b_RS;
    pin_config_tt lcd_4b_EN;
    pin_config_tt lcd_4b_data[4];
    
}lcd_4bit_t;



/*************************************************FOUR BIT LCD*******************************************/
Std_ReturnType LCD_4BIT_INIT(const lcd_4bit_t *lcd_4b);
Std_ReturnType LCD_4BIT_SEND_CMD(const lcd_4bit_t *lcd_4b,uint8_tt command);
Std_ReturnType LCD_4BIT_WRITE_CHAR(const lcd_4bit_t *lcd_4b,uint8_tt charactre);
Std_ReturnType LCD_4BIT_WRITE_CHAR_POSITION(const lcd_4bit_t *lcd_4b,uint8_tt row,uint8_tt column, uint8_tt charactre);   
Std_ReturnType LCD_4BIT_WRITE_STRING(const lcd_4bit_t *lcd_4b,uint8_tt *str);
Std_ReturnType LCD_4BIT_WRITE_STRING_POSITION(const lcd_4bit_t *lcd_4b,uint8_tt row,uint8_tt column, uint8_tt *str); 
Std_ReturnType LCD_4BIT_WRITE_CUSTOM_CHAR(const lcd_4bit_t *lcd_4b,uint8_tt row,uint8_tt column ,uint8_tt custom_char[],uint8_tt CGR_pos);

/*************************************************EIGHT BIT LCD*******************************************/

Std_ReturnType LCD_8BIT_INIT(const lcd_8bit_t *lcd_8b);
Std_ReturnType LCD_8BIT_SEND_CMD(const lcd_8bit_t *lcd_8b,uint8_tt command);
Std_ReturnType LCD_8BIT_WRITE_CHAR(const lcd_8bit_t *lcd_8b,uint8_tt charactre);
Std_ReturnType LCD_8BIT_WRITE_CHAR_POSITION(const lcd_8bit_t *lcd_8b,uint8_tt row,uint8_tt column, uint8_tt charactre);   
Std_ReturnType LCD_8BIT_WRITE_STRING(const lcd_8bit_t *lcd_8b,uint8_tt *str);
Std_ReturnType LCD_8BIT_WRITE_STRING_POSITION(const lcd_8bit_t *lcd_8b,uint8_tt row,uint8_tt column, uint8_tt *str); 
Std_ReturnType LCD_8BIT_WRITE_CUSTOM_CHAR(const lcd_8bit_t *lcd_8b,uint8_tt row,uint8_tt column ,const uint8_tt custom_char[],uint8_tt CGR_pos);



void CONVERT_UINT8_TO_STRING(uint8_tt value, uint8_tt *str);
void CONVERT_UINT16_TO_STRING(uint16_tt value, uint8_tt *str);
void CONVERT_UINT32_TO_STRING(uint32_tt value, uint8_tt *str);


Std_ReturnType LCD_4BIT_SEND_ENABLE_SIGNAL(const lcd_4bit_t *lcd_4b);
Std_ReturnType LCD_4BIT_SEND_4BITS(const lcd_4bit_t *lcd_4b,uint8_tt command1_data);
Std_ReturnType LCD_4BIT_SET_CURSOR_POSITION(const lcd_4bit_t *lcd_4b,uint8_tt row,uint8_tt column);
Std_ReturnType LCD_8BIT_SEND_ENABLE_SIGNAL(const lcd_8bit_t *lcd_8b);
Std_ReturnType LCD_8BIT_SET_CURSOR_POSITION(const lcd_8bit_t *lcd_8b,uint8_tt row,uint8_tt column);


#endif	/* ECU_LCD_H */

