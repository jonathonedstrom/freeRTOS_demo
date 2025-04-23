/*
 * @file mcu.c
 *
 * @brief Microcontroller hardware initialization/configuration resources
 *
 * @author jonathon.edstrom
 */


/*------------------------------------------------------------
                          Includes
-------------------------------------------------------------*/
// standard includes
#include "stdbool.h"

/* Kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"

/* Demo includes. */
#include "partest.h"
#include "demo-tasks.h"
#include "conf_example.h"

/* ASF includes. */
#include "sysclk.h"


/*------------------------------------------------------------
                      Public Functions
-------------------------------------------------------------*/

/*-----------------------------------------------------------*/
void MCU_Init( void )
{
    // ASF function to setup clocking.
    sysclk_init();

    // Ensure all priority bits are assigned as preemption priority bits.
    NVIC_SetPriorityGrouping(0);

    // Atmel library function to setup for the evaluation kit being used.
    board_init();

    // Perform any initialization required by the partest LED IO functions.
    vParTestInitialise();
}