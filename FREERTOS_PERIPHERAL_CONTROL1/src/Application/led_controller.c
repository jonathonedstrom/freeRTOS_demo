/*
 * @file led_controller.c
 *
 * @brief Application module that controls an LED
 *
 * @author jonathon.edstrom
 */

/*------------------------------------------------------------
                         Constants
-------------------------------------------------------------*/
#define LED_TIMER_PERIOD_MILLISECONDS (1000u)


/*------------------------------------------------------------
                          Includes
-------------------------------------------------------------*/
// standard includes
#include "stdbool.h"
#include "stdint.h"
#include "stddef.h"

// hardware includes
#include "arduino_due_x.h"
#include "gpio.h"

// system includes
#include "scheduler.h"

// this file's header
#include "led_controller.h"


/*------------------------------------------------------------
                  Local Function Prototypes
-------------------------------------------------------------*/
static void prvLEDTimerCallback( void *pvParameters );


/*------------------------------------------------------------
                      Public Functions
-------------------------------------------------------------*/

/*-----------------------------------------------------------*/
bool LED_Init( void )
{ 
    const bool didInitOk = SCH_CreateTimer( "LED timer",
                                            LED_TIMER_PERIOD_MILLISECONDS,
                                            true,
                                            prvLEDTimerCallback );

    return didInitOk;
}


/*------------------------------------------------------------
                      Private Functions
-------------------------------------------------------------*/

/*-----------------------------------------------------------*/
static void prvLEDTimerCallback( void *pvParameters )
{
    // Just to remove compiler warnings.
    (void) pvParameters;

    // Toggle an LED to show the system is executing.
    gpio_toggle_pin( LED0_GPIO );
}