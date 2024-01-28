/*
 * File:   SMART SECURITY SYSTEM
 * Author: Ahmed Magdy Elzayady
 * linked-in profile: https://www.linkedin.com/in/ahmed-magdy-elzayady/
 * Created on JAN 28, 2024, 12:06 AM
 */

#include "application.h"
/*Datatype Declaration*/

uint8_tt Correct_Password[3] = {1, 2, 3};
uint8_tt Enteered_pass[3];
uint8_tt counter, sec = 5, counter2;
uint8_tt Key_Value = '#';
uint8_tt Converted_pass[4];
uint8_tt convertred_sec[4];
uint8_tt flag1, flag2;

/*The Application*/
int main()
{
       Application_Init();
       Welcome_Message();
       __delay_ms(4000);
       LCD_8BIT_SEND_CMD(&lcd_one, _LCD_CLEAR);
       __delay_ms(1000);
       while (1) {
              SEVEN_SEGMENT_WRITE_NUMBER(&(seg_one), 3 - flag1);
              LCD_8BIT_WRITE_STRING_POSITION(&(lcd_one), 1, 1, "Enter Pass:");
              for (counter = 0; counter <= 2; counter++) {
                     while (flag2 == 0) {
                            KEYPAD_GET_VALUE(&keypad_one, &Key_Value);
                            if (Key_Value == '#') {
                                   LCD_8BIT_WRITE_STRING_POSITION(&(lcd_one), 1, 12 + counter, " ");
                                   LCD_8BIT_WRITE_STRING_POSITION(&(lcd_one), 1, 13 + counter, " ");

                            } else {
                                   Enteered_pass[counter] = Key_Value;
                                   CONVERT_UINT8_TO_STRING(Key_Value, Converted_pass);
                                   LCD_8BIT_WRITE_STRING_POSITION(&(lcd_one), 1, 12 + counter, Converted_pass);
                                   LCD_8BIT_WRITE_STRING_POSITION(&(lcd_one), 1, 12 + counter, "*");
                                   flag2++;
                                   Key_Value = '#';
                            }
                     }
                     flag2 = 0;
                     __delay_ms(1000);
              }
              if ((Enteered_pass[0] == Correct_Password[0]) && (Enteered_pass[1] == Correct_Password[1]) && (Enteered_pass[2] == Correct_Password[2])) {
                     LCD_8BIT_SEND_CMD(&lcd_one, _LCD_CLEAR);
                     LCD_8BIT_WRITE_STRING_POSITION(&(lcd_one), 1, 1, "CORRECT PASS");
                     LED_TURN_ON(&led_one);
                     __delay_ms(3000);
                     LED_TURN_OFF(&led_one);
                     LED_TURN_OFF(&led_two);
                     DC_MOTOR_TURN_RIGHT(&(motor_one));
                     __delay_ms(500);
                     DC_MOTOR_STOP(&(motor_one));
              } else {
                     flag1++;
                     LCD_8BIT_WRITE_STRING_POSITION(&(lcd_one), 1, 1, "please try again:");
                     if (flag1 == 1 || flag1 == 2 || flag1 == 3) {
                            SEVEN_SEGMENT_WRITE_NUMBER(&(seg_one), (3 - flag1));
                     }
                     if (flag1 == 3) {
                            LCD_8BIT_WRITE_STRING_POSITION(&lcd_one, 1, 1, "You are blocked for ");
                            LCD_8BIT_WRITE_STRING_POSITION(&lcd_one, 2, 1, "five seconds");
                            CONVERT_UINT8_TO_STRING(sec, convertred_sec);
                            LCD_8BIT_WRITE_STRING_POSITION(&(lcd_one), 2, 14, convertred_sec);
                            for (counter2 = 0; counter2 < 5; counter2++) {
                                   sec--;
                                   __delay_ms(1000);
                                   CONVERT_UINT8_TO_STRING(sec, convertred_sec);
                                   LCD_8BIT_WRITE_STRING_POSITION(&(lcd_one), 2, 14, convertred_sec);
                            }
                            sec = 5;
                            flag1 = 0;
                     }
                     LED_TURN_OFF(&led_one);
                     LED_TURN_ON(&led_two);
                     __delay_ms(500);
                     LED_TURN_OFF(&led_two);
                     DC_MOTOR_TURN_LEFT(&(motor_one));
                     __delay_ms(500);
                     DC_MOTOR_STOP(&(motor_one));
                     if (flag1 == 2 || flag1 == 3) {
                            DC_MOTOR_STOP(&(motor_one));

                     }
                     LCD_8BIT_SEND_CMD(&lcd_one, _LCD_CLEAR);
                     __delay_ms(1000);
              }
       }
       return (EXIT_SUCCESS);
}

void Application_Init(void)
{
       Std_ReturnType ret = E_NOT_OK;
       ECU_LAYER_INITI();
}

void Welcome_Message(void)
{
       LCD_8BIT_WRITE_STRING_POSITION(&(lcd_one), 1, 5, "Welcome To Our");
       LCD_8BIT_WRITE_STRING_POSITION(&(lcd_one), 2, 7, "Security");
       LCD_8BIT_WRITE_STRING_POSITION(&(lcd_one), 3, 8, "System");
}