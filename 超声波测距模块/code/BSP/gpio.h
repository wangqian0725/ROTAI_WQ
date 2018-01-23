#ifndef _GPIO_H
#define _GPIO_H

#include "stm8s.h"

void gpio_init(void);

#define TPWR_H   GPIO_WriteHigh(GPIOD, GPIO_PIN_3);
#define TPWR_L   GPIO_WriteLow(GPIOD, GPIO_PIN_3);
#define T1_H     GPIO_WriteHigh(GPIOD, GPIO_PIN_2);
#define T1_L     GPIO_WriteLow(GPIOD, GPIO_PIN_2);
#define T2_H     GPIO_WriteHigh(GPIOC, GPIO_PIN_7);
#define T2_L     GPIO_WriteLow(GPIOC, GPIO_PIN_7);
#define PWM_H    GPIO_WriteHigh(GPIOC, GPIO_PIN_5);
#define PWM_L    GPIO_WriteLow(GPIOC, GPIO_PIN_5);
 
#endif