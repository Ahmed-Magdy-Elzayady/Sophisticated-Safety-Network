# Sophisticated Safety Network
Sophisticated Safety Network USING PIC18F4620 MICROCONTROLLER

# How This Project Work?
-----------------------------------------------------------------------------------------------------
Certainly! Here's the revised version with suitable emojis at the end of each statement:

A robust access control system has been implemented with user-friendly features:

1. Password entry is facilitated through a convenient keypad interface. ⌨️
2. The system verifies the entered password against the correct one stored in an array. ✅
3. Upon successful entry, the motor elegantly rotates right, symbolizing the door's opening. Simultaneously, a reassuring green LED lights up to confirm the correct password. ✅👍
4. In the event of an incorrect password, users are kindly prompted to try again. The motor gracefully rotates left, indicating the door's closure, while a noticeable red LED signals the unsuccessful attempt. ❌👎
5. To ensure security, users have three attempts to enter the password within a five-second window. 👌
6. If more than three incorrect attempts are made, the system enters a temporary block mode for 5 seconds, communicating this delay with a firm indicator. 🚫⏳
7. After the brief pause, users are welcomed to retry entering the password, fostering a positive and user-friendly experience. 😊

## APIs Reference



| Parameter | Type     | Description                |
| :-------- | :------- | :------------------------- |
| `SEVEN_SEGMENT_WRITE_NUMBER` | `Std_ReturnType` | write number on 7segment |

| Parameter | Type     | Description                |
| :-------- | :------- | :------------------------- |
| `LCD_8BIT_SEND_CMD` | `Std_ReturnType` | send Command to the LCD |

| Parameter | Type     | Description                |
| :-------- | :------- | :------------------------- |
| `LCD_8BIT_WRITE_STRING_POSITION` | `Std_ReturnType` |Write a string on the lcd in specific  pos. |

| Parameter | Type     | Description                |
| :-------- | :------- | :------------------------- |
| `KEYPAD_GET_VALUE` | `Std_ReturnType` | Get the enterered value by user using keypad|


| Parameter | Type     | Description                |
| :-------- | :------- | :------------------------- |
| `CONVERT_UINT8_TO_STRING` | `void` | Convert uint8 type to string to display numbers on LCD |



| Parameter | Type     | Description                |
| :-------- | :------- | :------------------------- |
| `LED_TURN_ON` | `Std_ReturnType` |Turn The Led on|


| Parameter | Type     | Description                |
| :-------- | :------- | :------------------------- |
| `DC_MOTOR_TURN_LEFT` | `Std_ReturnType` |Turn the motor to right|

| Parameter | Type     | Description                |
| :-------- | :------- | :------------------------- |
| `DC_MOTOR_STOP` | `Std_ReturnType` |Stop the motor from rotating|






#### Get item


| Parameter | Type     | Description                       |
| :-------- | :------- | :-------------------------------- |
| `Correct_Password[3]`      | `uint8` |store the correct pass to open the door |

| Parameter | Type     | Description                       |
| :-------- | :------- | :-------------------------------- |
| `Enteered_pass[3]`      | `uint8` |store the pass entered by user |

| Parameter | Type     | Description                       |
| :-------- | :------- | :-------------------------------- |
| `sec`      | `uint8` |var used for the time of blocking|


| Parameter | Type     | Description                       |
| :-------- | :------- | :-------------------------------- |
| `counter`      | `uint8` |iterator for the looping of the keypad |

| Parameter | Type     | Description                       |
| :-------- | :------- | :-------------------------------- |
| `counter2`      | `uint8` |iterator for the time of blocking |


| Parameter | Type     | Description                       |
| :-------- | :------- | :-------------------------------- |
| `Key_Value`      | `uint8` |store the value entered by the user using keypad |

| Parameter | Type     | Description                       |
| :-------- | :------- | :-------------------------------- |
| `Converted_pass[4]`      | `uint8` | store the pass entered by user after Convert it to srting|


| Parameter | Type     | Description                       |
| :-------- | :------- | :-------------------------------- |
| `convertred_sec[4]`      | `uint8` | store the time of blocking after Convert it to srting|

| Parameter | Type     | Description                       |
| :-------- | :------- | :-------------------------------- |
| `flag`      | `uint8` |indicator of the number wrong times of enter pass|


| Parameter | Type     | Description                       |
| :-------- | :------- | :-------------------------------- |
| `flag2`      | `uint8` |parameter of the while loop of the keypad to make a pooling |



## Authors

- [@Ahmed_Elzayady](https://www.linkedin.com/in/ahmed-magdy-elzayady/)


## 🚀 About Me
I’m currently learning Embedded Systems

👨‍💻 All of my projects are available at https://github.com/Ahmed-Magdy-Elzayady

📝 I regularly write articles on https://www.linkedin.com/in/ahmed-magdy-elzayady/

📫 How to reach me ahmed.m.elzayady@gmail.com




## Screenshots

![App Screenshot](https://i.postimg.cc/K8tn8x9p/Screenshot-2024-01-28-183715.png)


## 🛠 Skills
C programming\
C++ programming\
microcontroller interface \
computer Archeticture\
problem solving



## Support

For support, email ahmed.m.elzayady@gmail.com 

