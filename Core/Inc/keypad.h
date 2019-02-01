// 4x4 Keypad Driver
#ifndef __keypad_H
#define __keypad_H

#include "stm32f7xx_hal.h"
#include "main.h"

uint8_t key_scan();
void keypad_set_row(size_t row);
void keypad_clear_last_pressed();
#endif