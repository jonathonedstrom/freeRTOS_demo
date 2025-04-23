/*
 * @file mcu.h
 *
 * @brief Header file for initializing the microcontroller hardware resources
 *
 * @author jonathon.edstrom
 */
#ifndef MCU_H_
#define MCU_H_

#ifndef _STDBOOL_H
    #error "Must include stdbool.h before mcu.h"
#endif

/**
 * @function MCU_Init
 *
 * @brief Initialize the hardware resources for the microcontroller
 *
 * @param void
 *
 * @return void (no return value)
 */
void MCU_Init( void );

#endif /* MCU_H_ */