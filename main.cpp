//
// main.cpp
// Copyright (C) 2018 Marius Greuel. All rights reserved.
//
// Blink Example for STM32F103C8 Blue Pill
//

#include <stdint.h>
#include <stm32f1xx.h>

// Poor-mans delay in ms
static void Delay(uint32_t duration)
{
    volatile uint32_t count = 400 * duration;
    while (count > 0)
    {
        count--;
    }
}

int main(void)
{
    // Enable clock on I/O port C
    RCC->APB2ENR = RCC_APB2ENR_IOPCEN;

    // Set PC13 to output
    GPIOC->CRH = (GPIOC->CRH & ~(GPIO_CRH_MODE13 | GPIO_CRH_CNF13)) | GPIO_CRH_MODE13;

    while (1)
    {
        // Set PC13 high
        GPIOC->BSRR = GPIO_BSRR_BS13;
        Delay(500);

        // Reset PC13 low
        GPIOC->BSRR = GPIO_BSRR_BR13;
        Delay(500);
    }

    return 0;
}
