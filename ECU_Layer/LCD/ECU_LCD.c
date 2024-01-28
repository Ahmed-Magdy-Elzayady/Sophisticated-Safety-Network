#include "ECU_LCD.h"
#include <string.h>

/**
 * 
 * @param lcd_4b
 * @return 
 */
Std_ReturnType LCD_4BIT_INIT(const lcd_4bit_t *lcd_4b)
{

       Std_ReturnType ret = E_NOT_OK;
       uint8_tt counter = 0;
       if (NULL == lcd_4b) {

              ret = E_NOT_OK;
       } else {
              GPIO_PIN_INIT(&(lcd_4b->lcd_4b_RS));
              GPIO_PIN_INIT(&(lcd_4b->lcd_4b_EN));
              for (counter = 0; counter < 4; counter++) {
                     GPIO_PIN_INIT(&(lcd_4b->lcd_4b_data[counter]));
              }

              __delay_ms(20);
              LCD_4BIT_SEND_CMD(lcd_4b, _LCD_8BIT_MODE_2_LINE);
              __delay_ms(5);
              LCD_4BIT_SEND_CMD(lcd_4b, _LCD_8BIT_MODE_2_LINE);
              __delay_us(150);
              LCD_4BIT_SEND_CMD(lcd_4b, _LCD_8BIT_MODE_2_LINE);
              LCD_4BIT_SEND_CMD(lcd_4b, _LCD_CLEAR);
              LCD_4BIT_SEND_CMD(lcd_4b, _LCD_RETURN_HOME);
              LCD_4BIT_SEND_CMD(lcd_4b, _LCD_ENTRY_MODE_INC_SHIFT_OFF);
              LCD_4BIT_SEND_CMD(lcd_4b, _LCD_DISPLAY_ON_UNDERLINE_ON_CURSOR_OFF);
              LCD_4BIT_SEND_CMD(lcd_4b, _LCD_DDRAM_START);

              ret = E_OK;
       }

       return ret;

}

/**
 * 
 * @param lcd_4b
 * @param command
 * @return 
 */
Std_ReturnType LCD_4BIT_SEND_CMD(const lcd_4bit_t *lcd_4b, uint8_tt command)
{

       Std_ReturnType ret = E_NOT_OK;
       if (NULL == lcd_4b) {

              ret = E_NOT_OK;

       } else {

              GPIO_SET_PIN_VALUE(&(lcd_4b->lcd_4b_RS), GPIO_LOW);
              LCD_4BIT_SEND_4BITS(lcd_4b, (command >> 4));
              LCD_4BIT_SEND_ENABLE_SIGNAL(lcd_4b);
              LCD_4BIT_SEND_4BITS(lcd_4b, command);
              LCD_4BIT_SEND_ENABLE_SIGNAL(lcd_4b);

              ret = E_OK;
       }
}

/**
 * 
 * @param lcd_4b
 * @param charactre
 * @return 
 */
Std_ReturnType LCD_4BIT_WRITE_CHAR(const lcd_4bit_t *lcd_4b, uint8_tt charactre)
{

       Std_ReturnType ret = E_NOT_OK;
       if (NULL == lcd_4b) {

              ret = E_NOT_OK;
       } else {
              GPIO_SET_PIN_VALUE(&(lcd_4b->lcd_4b_RS), GPIO_HIGH);
              LCD_4BIT_SEND_4BITS(lcd_4b, (charactre >> 4));
              LCD_4BIT_SEND_ENABLE_SIGNAL(lcd_4b);
              LCD_4BIT_SEND_4BITS(lcd_4b, charactre);
              LCD_4BIT_SEND_ENABLE_SIGNAL(lcd_4b);

              ret = E_OK;
       }
}

/**
 * 
 * @param lcd_4b
 * @param row
 * @param column
 * @param charactre
 * @return 
 */
Std_ReturnType LCD_4BIT_WRITE_CHAR_POSITION(const lcd_4bit_t *lcd_4b, uint8_tt row, uint8_tt column, uint8_tt charactre)
{
       Std_ReturnType ret = E_NOT_OK;
       if (NULL == lcd_4b) {

              ret = E_NOT_OK;
       } else {

              LCD_4BIT_SET_CURSOR_POSITION(lcd_4b, row, column);
              LCD_4BIT_WRITE_CHAR(lcd_4b, charactre);
              ret = E_OK;
       }
}

/**
 * 
 * @param lcd_4b
 * @param str
 * @return 
 */
Std_ReturnType LCD_4BIT_WRITE_STRING(const lcd_4bit_t *lcd_4b, uint8_tt *str)
{

       Std_ReturnType ret = E_NOT_OK;
       if (NULL == lcd_4b || NULL == str) {

              ret = E_NOT_OK;
       } else {
              while (*str) {
                     LCD_4BIT_WRITE_CHAR(lcd_4b, *str);
                     str++;
              }
              ret = E_OK;
       }
}

/**
 * 
 * @param lcd_4b
 * @param row
 * @param column
 * @param str
 * @return 
 */
Std_ReturnType LCD_4BIT_WRITE_STRING_POSITION(const lcd_4bit_t *lcd_4b, uint8_tt row, uint8_tt column, uint8_tt *str)
{

       Std_ReturnType ret = E_NOT_OK;
       if (NULL == lcd_4b || NULL == str) {
              ret = E_NOT_OK;
       } else {

              LCD_4BIT_SET_CURSOR_POSITION(lcd_4b, row, column);
              LCD_4BIT_WRITE_STRING(lcd_4b, str);
              ret = E_OK;
       }
}

/**
 * 
 * @param lcd_4b
 * @param row
 * @param column
 * @param custom_char
 * @param CGR_pos
 * @return 
 */
Std_ReturnType LCD_4BIT_WRITE_CUSTOM_CHAR(const lcd_4bit_t* lcd_4b, uint8_tt row, uint8_tt column, uint8_tt custom_char[], uint8_tt CGR_pos)
{

       Std_ReturnType ret = E_NOT_OK;
       if (NULL == lcd_4b) {

              ret = E_NOT_OK;
       } else {



              ret = E_OK;
       }

       return ret;

}

/**
 * 
 * @param lcd_4b
 * @param command
 * @return 
 */
Std_ReturnType LCD_4BIT_SEND_4BITS(const lcd_4bit_t *lcd_4b, uint8_tt command1_data)
{

       Std_ReturnType ret = E_NOT_OK;
       uint8_tt counter;
       if (NULL == lcd_4b) {

              ret = E_NOT_OK;
       } else {
              for (counter = 0; counter < 4; counter++) {
                     GPIO_SET_PIN_VALUE(&(lcd_4b->lcd_4b_data[counter]), (command1_data >> counter)&(uint8_tt) 0x01);
              }
              ret = E_OK;
       }
       return ret;
}

/**
 * 
 * @param lcd_4b
 * @return 
 */
Std_ReturnType LCD_4BIT_SEND_ENABLE_SIGNAL(const lcd_4bit_t *lcd_4b)
{

       Std_ReturnType ret = E_NOT_OK;
       if (NULL == lcd_4b) {

              ret = E_NOT_OK;
       } else {

              GPIO_SET_PIN_VALUE(&(lcd_4b->lcd_4b_EN), GPIO_HIGH);
              __delay_us(5);
              GPIO_SET_PIN_VALUE(&(lcd_4b->lcd_4b_EN), GPIO_LOW);

              ret = E_OK;
       }

       return ret;

}

/**
 * 
 * @param lcd_4b
 * @param row
 * @param column
 * @return 
 */
Std_ReturnType LCD_4BIT_SET_CURSOR_POSITION(const lcd_4bit_t *lcd_4b, uint8_tt row, uint8_tt column)
{


       column--;
       Std_ReturnType ret = E_NOT_OK;
       if (NULL == lcd_4b) {

              ret = E_NOT_OK;

       } else {

              switch (row) {

              case ROW1:
                     LCD_4BIT_SEND_CMD(lcd_4b, (0x80 + column));
                     break;
              case ROW2:
                     LCD_4BIT_SEND_CMD(lcd_4b, (0XC0 + column));
                     break;
              default:;

              }
              ret = E_OK;
       }
       return ret;


}
/***************************************************************************************************************************************/

/**
 * 
 * @param lcd_8b
 * @return 
 */
Std_ReturnType LCD_8BIT_INIT(const lcd_8bit_t* lcd_8b)
{

       Std_ReturnType ret = E_NOT_OK;
       uint8_tt counter = 0;
       if (NULL == lcd_8b) {
              ret = E_NOT_OK;
       } else {
              GPIO_PIN_INIT(&(lcd_8b->lcd_8b_RS));
              GPIO_PIN_INIT(&(lcd_8b->lcd_8b_EN));
              for (counter = 0; counter < 8; counter++) {
                     GPIO_PIN_INIT(&(lcd_8b->lcd_8b_data[counter]));
              }
              __delay_ms(20);
              LCD_8BIT_SEND_CMD(lcd_8b, _LCD_8BIT_MODE_2_LINE);
              __delay_ms(5);
              LCD_8BIT_SEND_CMD(lcd_8b, _LCD_8BIT_MODE_2_LINE);
              __delay_us(150);
              LCD_8BIT_SEND_CMD(lcd_8b, _LCD_8BIT_MODE_2_LINE);
              LCD_8BIT_SEND_CMD(lcd_8b, _LCD_CLEAR);
              LCD_8BIT_SEND_CMD(lcd_8b, _LCD_RETURN_HOME);
              LCD_8BIT_SEND_CMD(lcd_8b, _LCD_ENTRY_MODE_INC_SHIFT_OFF);
              LCD_8BIT_SEND_CMD(lcd_8b, _LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_OFF);
              LCD_8BIT_SEND_CMD(lcd_8b, _LCD_DDRAM_START);
              ret = E_OK;
       }
       return ret;
}

/**
 * 
 * @param lcd_8b
 * @param command
 * @return 
 */
Std_ReturnType LCD_8BIT_SEND_CMD(const lcd_8bit_t* lcd_8b, uint8_tt command)
{

       Std_ReturnType ret = E_NOT_OK;
       uint8_tt counter = 0;
       if (NULL == lcd_8b) {
              ret = E_NOT_OK;
       } else {
              GPIO_SET_PIN_VALUE(&(lcd_8b->lcd_8b_RS), GPIO_LOW);
              for (counter = 0; counter < 8; counter++) {
                     GPIO_SET_PIN_VALUE(&(lcd_8b->lcd_8b_data[counter]), (command >> counter)&(uint8_tt) 0x01);
              }
              LCD_8BIT_SEND_ENABLE_SIGNAL(lcd_8b);
              ret = E_OK;
       }
}

/**
 * 
 * @param lcd_8b
 * @param charactre
 * @return 
 */
Std_ReturnType LCD_8BIT_WRITE_CHAR(const lcd_8bit_t* lcd_8b, uint8_tt charactre)
{
       Std_ReturnType ret = E_NOT_OK;
       uint8_tt counter = 0;
       if (NULL == lcd_8b) {
              ret = E_NOT_OK;
       } else {
              GPIO_SET_PIN_VALUE(&(lcd_8b->lcd_8b_RS), GPIO_HIGH);
              for (counter = 0; counter < 8; counter++) {
                     GPIO_SET_PIN_VALUE(&(lcd_8b->lcd_8b_data[counter]), (charactre >> counter)&(uint8_tt) 0x01);
              }
              LCD_8BIT_SEND_ENABLE_SIGNAL(lcd_8b);
              ret = E_OK;
       }
       return ret;
}

/**
 * 
 * @param lcd_8b
 * @param row
 * @param column
 * @param charactre
 * @return 
 */
Std_ReturnType LCD_8BIT_WRITE_CHAR_POSITION(const lcd_8bit_t* lcd_8b, uint8_tt row, uint8_tt column, uint8_tt charactre)
{
       Std_ReturnType ret = E_NOT_OK;
       if (NULL == lcd_8b) {

              ret = E_NOT_OK;
       } else {
              LCD_8BIT_SET_CURSOR_POSITION(lcd_8b, row, column);
              LCD_8BIT_WRITE_CHAR(lcd_8b, charactre);
              ret = E_OK;
       }
}

/**
 * 
 * @param lcd_8b
 * @param str
 * @return 
 */
Std_ReturnType LCD_8BIT_WRITE_STRING(const lcd_8bit_t *lcd_8b, uint8_tt *str)
{
       Std_ReturnType ret = E_NOT_OK;
       if (NULL == lcd_8b || NULL == str) {
              ret = E_NOT_OK;
       } else {
              while (*str) {
                     LCD_8BIT_WRITE_CHAR(lcd_8b, *str);
                     str++;
              }
              ret = E_OK;
       }
}

/**
 * 
 * @param lcd_8b
 * @param row
 * @param column
 * @param str
 * @return 
 */
Std_ReturnType LCD_8BIT_WRITE_STRING_POSITION(const lcd_8bit_t *lcd_8b, uint8_tt row, uint8_tt column, uint8_tt *str)
{
       Std_ReturnType ret = E_NOT_OK;
       if (NULL == lcd_8b || NULL == str) {
              ret = E_NOT_OK;
       } else {
              LCD_8BIT_SET_CURSOR_POSITION(lcd_8b, row, column);
              LCD_8BIT_WRITE_STRING(lcd_8b, str);
              ret = E_OK;
       }
}

Std_ReturnType LCD_8BIT_WRITE_CUSTOM_CHAR(const lcd_8bit_t *lcd_8b, uint8_tt row, uint8_tt column, const uint8_tt custom_char[], uint8_tt CGR_pos)
{
       Std_ReturnType ret = E_NOT_OK;
       uint8_tt counter = 0;
       if (NULL == lcd_8b) {

              ret = E_NOT_OK;
       } else {
              LCD_8BIT_SEND_CMD(lcd_8b, (_LCD_CGRAM_START + (CGR_pos * 8)));
              for (counter = 0; counter < 8; counter++) {
                     LCD_8BIT_WRITE_CHAR(lcd_8b, custom_char[counter]);
              }
              LCD_8BIT_WRITE_CHAR_POSITION(lcd_8b, row, column, CGR_pos);
              ret = E_OK;
       }
       return ret;
}

/**
 * 
 * @param lcd_8b
 * @return 
 */
Std_ReturnType LCD_8BIT_SEND_ENABLE_SIGNAL(const lcd_8bit_t *lcd_8b)
{
       Std_ReturnType ret = E_NOT_OK;
       if (NULL == lcd_8b) {
              ret = E_NOT_OK;
       } else {
              GPIO_SET_PIN_VALUE(&(lcd_8b->lcd_8b_EN), GPIO_HIGH);
              __delay_us(5);
              GPIO_SET_PIN_VALUE(&(lcd_8b->lcd_8b_EN), GPIO_LOW);
              ret = E_OK;
       }

       return ret;

}

/**
 * 
 * @param lcd_8b
 * @param row
 * @param column
 * @return 
 */
Std_ReturnType LCD_8BIT_SET_CURSOR_POSITION(const lcd_8bit_t *lcd_8b, uint8_tt row, uint8_tt column)
{
       column--;
       Std_ReturnType ret = E_NOT_OK;
       if (NULL == lcd_8b) {
              ret = E_NOT_OK;
       } else {
              switch (row) {
              case ROW1:
                     LCD_8BIT_SEND_CMD(lcd_8b, (0x80 + column));
                     break;
              case ROW2:
                     LCD_8BIT_SEND_CMD(lcd_8b, (0XC0 + column));
                     break;
              case ROW3:
                     LCD_8BIT_SEND_CMD(lcd_8b, (0X94 + column));
                     break;
              case ROW4:
                     LCD_8BIT_SEND_CMD(lcd_8b, (0Xd4 + column));
                     break;
              default:;
              }
              ret = E_OK;
       }
       return ret;
}

/**
 * 
 * @param value
 * @param str
 */
void CONVERT_UINT8_TO_STRING(uint8_tt value, uint8_tt *str)
{
       memset(str, '\0', 4);
       sprintf(str, "%i", value);
}

/**
 * 
 * @param value
 * @param str
 */
void CONVERT_UINT16_TO_STRING(uint16_tt value, uint8_tt *str)
{
       memset(str, '\0', 7);
       sprintf(str, "%i", value);
}

/**
 * 
 * @param value
 * @param str
 */
void CONVERT_UINT32_TO_STRING(uint32_tt value, uint8_tt *str)
{
       memset(str, '\0', 12);
       sprintf(str, "%i", value);
}