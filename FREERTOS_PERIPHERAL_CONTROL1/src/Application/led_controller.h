/*
 * @file led_controller.h
 *
 * @brief Header file for the application module that handles flashing an LED
 *
 * @author jonathon.edstrom
 */ 
#ifndef LED_CONTROLLER_H_
#define LED_CONTROLLER_H_

#ifndef _STDBOOL_H
    #error "Must include stdbool.h before led_controller.h"
#endif

/**
 * @function LED_Init
 *
 * @brief Initialize the LED controller application module
 *
 * @param void
 *
 * @return bool - true if initialization was successful, false otherwise
 */
bool LED_Init( void );

#endif /* LED_CONTROLLER_H_ */