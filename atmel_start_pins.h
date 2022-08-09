/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */
#ifndef ATMEL_START_PINS_H_INCLUDED
#define ATMEL_START_PINS_H_INCLUDED

#include <hal_gpio.h>

// SAMS70 has 4 pin functions

#define GPIO_PIN_FUNCTION_A 0
#define GPIO_PIN_FUNCTION_B 1
#define GPIO_PIN_FUNCTION_C 2
#define GPIO_PIN_FUNCTION_D 3

#define SDA0 GPIO(GPIO_PORTA, 3)
#define SCL0 GPIO(GPIO_PORTA, 4)
#define nGPIOX_INT GPIO(GPIO_PORTA, 5)
#define Button_2 GPIO(GPIO_PORTA, 7)
#define Button_4 GPIO(GPIO_PORTA, 24)
#define Button_0 GPIO(GPIO_PORTD, 0)
#define HALL_3 GPIO(GPIO_PORTD, 7)
#define HALL_2 GPIO(GPIO_PORTD, 8)
#define HALL_1 GPIO(GPIO_PORTD, 9)
#define WIFIEN GPIO(GPIO_PORTD, 21)
#define Button_5 GPIO(GPIO_PORTD, 22)
#define Button_3 GPIO(GPIO_PORTD, 24)
#define Button_1 GPIO(GPIO_PORTD, 31)

#endif // ATMEL_START_PINS_H_INCLUDED
