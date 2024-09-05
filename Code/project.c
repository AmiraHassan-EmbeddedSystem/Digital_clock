/*
 * File:   project.c
 * Author: ah427
 *
 * Created on 21 ?????, 2024, 08:41 ?
 */

#include <xc.h>
#include "project.h"

#define _XTAL_FREQ 80000000UL

// Define the initial time
uint8 hours = 0, minutes = 0, seconds = 0;
uint8 counter = 0;

// Function prototypes
void initialization(void);

void main(void) {
    // Initialize GPIO ports and settings
    initialization();
    for(hours = 0; hours<24; hours++){
        for(minutes = 0; minutes<60; minutes++){
            for(seconds = 0; seconds<60; seconds++){
                for (counter = 0; counter < 25; counter++) {
                    // Display hour tens
                    gpio_port_write_logic(GPIO_PORTD, 0x3E);
                    if( ((uint8)(hours / 10)) == 0 ){
                        gpio_port_write_logic(GPIO_PORTC, 0xC0);
                    }
                    else{
                    gpio_port_write_logic(GPIO_PORTC, (uint8)(hours / 10)); // Display the tens place of hours
                    }
                    __delay_us(750);

                    // Display hour units
                    gpio_port_write_logic(GPIO_PORTD, 0x3D);
                    if( ((uint8)(hours % 10)) == 0 ){
                        gpio_port_write_logic(GPIO_PORTC, 0xC0);
                    }
                    else{
                    gpio_port_write_logic(GPIO_PORTC, (uint8)(hours % 10)); // Display the units place of hours
                    }
                    __delay_us(750);

                    // Display minute tens
                    gpio_port_write_logic(GPIO_PORTD, 0x3B);
                    if( ((uint8)(minutes / 10)) == 0 ){
                        gpio_port_write_logic(GPIO_PORTC, 0xC0);
                    }
                    else{
                    gpio_port_write_logic(GPIO_PORTC, (uint8)(minutes / 10)); // Display the tens place of minutes

                    }
                    __delay_us(750);
                    // Display minute units
                    gpio_port_write_logic(GPIO_PORTD, 0x37);
                    if( ((uint8)(minutes % 10)) == 0 ){
                        gpio_port_write_logic(GPIO_PORTC, 0xC0);
                    }
                    else{
                    gpio_port_write_logic(GPIO_PORTC, (uint8)(minutes % 10)); // Display the units place of minutes

                    }
                    __delay_us(750);
                    // Display second tens
                    gpio_port_write_logic(GPIO_PORTD, 0x2F);
                    if( ((uint8)seconds / 10) == 0 ){
                        gpio_port_write_logic(GPIO_PORTC, 0xC0);
                    }
                    else{
                        gpio_port_write_logic(GPIO_PORTC, (uint8)(seconds / 10)); // Display the tens place of seconds
                    }
                    __delay_us(750);

                    // Display second units
                    gpio_port_write_logic(GPIO_PORTD, 0x1F);
                    if( ((uint8)seconds % 10) == 0 ){
                        gpio_port_write_logic(GPIO_PORTC, 0xC0);
                    }
                    else{
                        gpio_port_write_logic(GPIO_PORTC, (uint8)(seconds % 10)); // Display the units place of seconds
                    }
                    __delay_us(750);
                }
            }
        }
    }
    
    
}

void initialization(void) { 
    gpio_port_direction_initialize(GPIO_PORTC, 0x00); // Set PORTC as output
    gpio_port_direction_initialize(GPIO_PORTD, 0x00); // Set PORTD as output


    gpio_port_write_logic(GPIO_PORTC, 0x00);  // Initial state for PORTC
    gpio_port_write_logic(GPIO_PORTD, 0x00); // Initial state for PORTD
}
