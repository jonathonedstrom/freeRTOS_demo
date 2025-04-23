/**
 * @file main.c
 *
 * @brief Example Project demonstrating use of FreeRTOS
 *
 * @author jonathon.edstrom
 */


/*------------------------------------------------------------
                          Includes
-------------------------------------------------------------*/
// standard includes
#include "stdbool.h"
#include "stdint.h"

// hardware includes
#include "mcu.h"

// system (OS) includes
#include "scheduler.h"

// application includes
#include "led_controller.h"


/*-----------------------------------------------------------*/
int main(void)
{
    // Initialize microcontroller hardware
    MCU_Init();

    // Initialize Application Modules
    bool didInitOk = LED_Init();
    
    // Start Scheduler if all checks passed
    if( didInitOk )
    {
        SCH_StartScheduler();
    }

    // if we reached this point, initialization failed
    for(;;)
    {
    }
}