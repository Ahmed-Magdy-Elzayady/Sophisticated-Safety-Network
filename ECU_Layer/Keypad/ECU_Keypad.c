#include "ECU_Keypad.h"


static const uint8_tt keypad_values[KEYPAD_ROWS_NUMBER][KEYPAD_COLUMNS_NUMBER] = {


    {7, 8, 9, '/'},
    {4, 5, 6, '*'},
    {1, 2, 3, '-'},
    {'#', 0, '=', '+'}
};

/**
 * 
 * @param keypad
 * @return 
 */

Std_ReturnType KEYPAD_INIT(const keypad_config_t *keypad) {

    Std_ReturnType ret = E_NOT_OK;
    uint8_tt counter_row = 0;
    uint8_tt counter_columns = 0;
    if (NULL == keypad) {
        ret = E_NOT_OK;
    } else {
        for (counter_row = 0; counter_row <= KEYPAD_ROWS_NUMBER; counter_row++) {

            ret = GPIO_SET_PIN_DIRECTION(&(keypad->keypad_rows_pins[counter_row]));
            ret = GPIO_SET_PIN_VALUE(&(keypad->keypad_rows_pins[counter_row]), GPIO_LOW);
        }
        for (counter_columns = 0; counter_columns <= KEYPAD_COLUMNS_NUMBER; counter_columns++) {
            ret = GPIO_SET_PIN_DIRECTION(&(keypad->keypad_columns_pins[counter_columns]));
        }
        ret = E_OK;
    }
    return ret;
}

Std_ReturnType KEYPAD_GET_VALUE(const keypad_config_t *keypad, uint8_tt *_value) {
    Std_ReturnType ret = E_NOT_OK;
    uint8_tt row_counter = 0, colums_counter = 0, counter = 0;
    uint8_tt column_logic = 0;

    if ((NULL == keypad) || (NULL == _value)) {
        ret = E_NOT_OK;
    } else {

        for (row_counter = 0; row_counter < KEYPAD_ROWS_NUMBER; row_counter++) {

            for (counter = 0; counter < KEYPAD_ROWS_NUMBER; counter++) {
                GPIO_SET_PIN_VALUE(&(keypad->keypad_rows_pins[counter]), GPIO_LOW);
            }
            GPIO_SET_PIN_VALUE(&(keypad->keypad_rows_pins[row_counter]), GPIO_HIGH);
            for(colums_counter=0;colums_counter<KEYPAD_COLUMNS_NUMBER;colums_counter++){
                
                GPIO_READ_PIN_VALUE(&(keypad->keypad_columns_pins[colums_counter]),&column_logic);
                if(GPIO_HIGH==column_logic){
                    *_value=keypad_values[row_counter][colums_counter];
                    
                }
                
            
                
            }
        }
        ret=E_OK;
    }
    return ret;

}






