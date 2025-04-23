/*
 * @file scheduler.c
 *
 * @brief System scheduler methods using FreeRTOS
 *
 * @author jonathon.edstrom
 */

/*------------------------------------------------------------
                         Constants
-------------------------------------------------------------*/
#define DEFAULT_TASK_STACK_SIZE (64u)
#define DONT_BLOCK (0u)


/*------------------------------------------------------------
                          Includes
-------------------------------------------------------------*/
// standard includes
#include "stdbool.h"

// freeRTOS includes
#include "projdefs.h"
#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"

// this file's header
#include "scheduler.h"


/*------------------------------------------------------------
            FreeRTOS hook (or callback) functions
-------------------------------------------------------------*/
void vApplicationMallocFailedHook(void);
void vApplicationIdleHook(void);
void vApplicationStackOverflowHook(xTaskHandle pxTask, signed char *pcTaskName);
void vApplicationTickHook(void);


/*------------------------------------------------------------
                      Public Functions
-------------------------------------------------------------*/

/*-----------------------------------------------------------*/
bool SCH_CreateTask( void (*ptrTaskFunction)( void* ),
                     const char * const taskName,
                     void *ptrParameters,
                     void * ptrCreatedTask )
{
    // default return value to fail
    BaseType_t xReturned = pdFAIL;
    
    // check parameters are valid
    bool isValid = ( ptrTaskFunction != NULL );
    isValid = isValid && ( taskName != NULL );
    
    if( isValid )
    {
        // attempt to create task
        xReturned = xTaskCreate( ptrTaskFunction,
                                 taskName,
                                 DEFAULT_TASK_STACK_SIZE,
                                 ptrParameters,
                                 tskIDLE_PRIORITY,
                                 ptrCreatedTask );
    }
    
    return ( xReturned == pdPASS );
}


/*-----------------------------------------------------------*/
void SCH_DeleteTask( void * ptrTask )
{
    if( ptrTask != NULL )
    {
        vTaskDelete( ptrTask );
    }
}


/*-----------------------------------------------------------*/
bool SCH_CreateTimer( const char * const timerName,
                      const uint32_t timerPeriodMilliseconds,
                      const bool doAutoReloadTimer,
                      void (*ptrCallbackFunction)( void* ) )
{
    // default return value to fail
    BaseType_t xReturned = pdFAIL;
    
    // check parameters are valid
    bool isValid = ( timerName != NULL );
    isValid = isValid && ( timerPeriodMilliseconds > 0 );
    isValid = isValid && ( ptrCallbackFunction != NULL );
    
    if( isValid )
    {
        TimerHandle_t timerHandle = xTimerCreate( timerName,
                                                  timerPeriodMilliseconds / portTICK_RATE_MS,
                                                  (UBaseType_t)doAutoReloadTimer,
                                                  NULL,
                                                  ptrCallbackFunction );

        xReturned = xTimerStart( timerHandle, DONT_BLOCK );
    }
    
    return ( xReturned == pdPASS );
}


/*-----------------------------------------------------------*/
void SCH_StartScheduler( void )
{
    /* Start the RTOS scheduler. */
    vTaskStartScheduler();

    /* If all is well, the scheduler will now be running, and the following line
    will never be reached.  If the following line does execute, then there was
    insufficient FreeRTOS heap memory available for the idle and/or timer tasks
    to be created.  See the memory management section on the FreeRTOS web site
    for more details. */
    for(;;)
    {
    }
}


/*------------------------------------------------------------
                       FreeRTOS Hooks
-------------------------------------------------------------*/

/*-----------------------------------------------------------*/
void vApplicationMallocFailedHook(void)
{
    /* vApplicationMallocFailedHook() will only be called if
    configUSE_MALLOC_FAILED_HOOK is set to 1 in FreeRTOSConfig.h.  It is a hook
    function that will get called if a call to pvPortMalloc() fails.
    pvPortMalloc() is called internally by the kernel whenever a task, queue,
    timer or semaphore is created.  It is also called by various parts of the
    demo application.  If heap_1.c or heap_2.c are used, then the size of the
    heap available to pvPortMalloc() is defined by configTOTAL_HEAP_SIZE in
    FreeRTOSConfig.h, and the xPortGetFreeHeapSize() API function can be used
    to query the size of free heap space that remains (although it does not
    provide information on how the remaining heap might be fragmented). */
    taskDISABLE_INTERRUPTS();
    for (;;) {
    }
}


/*-----------------------------------------------------------*/
void vApplicationIdleHook(void)
{
    /* vApplicationIdleHook() will only be called if configUSE_IDLE_HOOK is set
    to 1 in FreeRTOSConfig.h.  It will be called on each iteration of the idle
    task.  It is essential that code added to this hook function never attempts
    to block in any way (for example, call xQueueReceive() with a block time
    specified, or call vTaskDelay()).  If the application makes use of the
    vTaskDelete() API function (as this demo application does) then it is also
    important that vApplicationIdleHook() is permitted to return to its calling
    function, because it is the responsibility of the idle task to clean up
    memory allocated by the kernel to any task that has since been deleted. */
}

/*-----------------------------------------------------------*/
void vApplicationStackOverflowHook(xTaskHandle pxTask,
        signed char *pcTaskName)
{
    (void) pcTaskName;
    (void) pxTask;

    /* Run time stack overflow checking is performed if
    configCHECK_FOR_STACK_OVERFLOW is defined to 1 or 2.  This hook
    function is called if a stack overflow is detected. */
    taskDISABLE_INTERRUPTS();
    for (;;) {
    }
}

/*-----------------------------------------------------------*/
void vApplicationTickHook(void)
{
    /* This function will be called by each tick interrupt if
    configUSE_TICK_HOOK is set to 1 in FreeRTOSConfig.h.  User code can be
    added here, but the tick hook is called from an interrupt context, so
    code must not attempt to block, and only the interrupt safe FreeRTOS API
    functions can be used (those that end in FromISR()). */
}

/*-----------------------------------------------------------*/
void assert_triggered(const char *file, uint32_t line)
{
    volatile uint32_t block_var = 0, line_in;
    const char *file_in;

    /* These assignments are made to prevent the compiler optimizing the
    values away. */
    file_in = file;
    line_in = line;
    (void) file_in;
    (void) line_in;

    taskENTER_CRITICAL();
    {
        while (block_var == 0) {
            /* Set block_var to a non-zero value in the debugger to
            step out of this function. */
        }
    }
    taskEXIT_CRITICAL();
}