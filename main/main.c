/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

const int BTN = 18;
const int LED = 12;

const int FASE_1 = 28;
const int FASE_2 = 27;
const int FASE_3 = 26;
const int FASE_4 = 22;


int main() {
    stdio_init_all();

    gpio_init(BTN);
    gpio_set_dir(BTN, GPIO_IN);
    gpio_pull_up(BTN);

    gpio_init(LED);
    gpio_set_dir(LED, GPIO_OUT);

    gpio_init(FASE_1);
    gpio_set_dir(FASE_1, GPIO_OUT);
    
    gpio_init(FASE_2);
    gpio_set_dir(FASE_2, GPIO_OUT);
    
    gpio_init(FASE_3);
    gpio_set_dir(FASE_3, GPIO_OUT);

    gpio_init(FASE_4);
    gpio_set_dir(FASE_4, GPIO_OUT);

    while (true) {
        if (gpio_get(BTN) == 0) {
            gpio_put(LED, 1);
            sleep_ms(5);

            for(int i = 0; i < 512; i++) {
                gpio_put(FASE_1, 1);
                sleep_ms(5);
                gpio_put(FASE_1, 0);
                gpio_put(FASE_2, 1);
                sleep_ms(5);
                gpio_put(FASE_2, 0);
                gpio_put(FASE_3, 1);
                sleep_ms(5);
                gpio_put(FASE_3, 0);
                gpio_put(FASE_4, 1);
                sleep_ms(5);
                gpio_put(FASE_4, 0);
            }

            gpio_put(LED, 0);
            printf("Button pressed!\n");
            sleep_ms(5);
        }
        
    }
}
