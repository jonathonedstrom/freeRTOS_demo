/*
 * @file scheduler.h
 *
 * @brief Header file for the system scheduler used for creating OS resources such as tasks and timers
 *
 * @author jonathon.edstrom
 */ 
#ifndef SCHEDULER_H_
#define SCHEDULER_H_

#ifndef _STDBOOL_H
    #error "Must include stdbool.h before scheduler.h"
#endif

#ifndef _SYS__STDINT_H
    #error "Must include stdint.h before scheduler.h"
#endif

/**
 * @function SCH_CreateTask
 *
 * @brief Creates a task
 *
 * @param ptrTaskFunction - pointer to the function to create a scheduler task with
 * @param taskName - a descriptive name for the task
 * @param ptrParameters - optional value that is passed as the parameter to the created task
 * @param ptrCreatedTask - pointer to the created task function
 *
 * @return bool - true if the task creation was successful, false otherwise
 */
bool SCH_CreateTask( void (*ptrTaskFunction)( void* ),
                     const char * const taskName,
                     void *ptrParameters,
                     void * ptrCreatedTask );
                     
/**
 * @function SCH_DeleteTask
 *
 * @brief Deletes a task
 *
 * @param ptrTask - pointer to the task to delete
 *
 * @return void (no return value)
 */
void SCH_DeleteTask( void * ptrTask );

/**
 * @function SCH_CreateTimer
 *
 * @brief Creates a timer
 *
 * @param timerName - a descriptive name for the timer
 * @param timerPeriodMilliseconds - the period of the timer in milliseconds
 * @param doAutoReloadTime - if true, the timer will expire repeatedly with a frequency set to the period,
                             if false, the timer will be a one-shot and enter the dormant state after it expires
 * @param ptrCallbackFunction - the function to call when the timer expires
 *
 * @return bool - true if the timer creation was successful, false otherwise
 */
bool SCH_CreateTimer( const char * const timerName,
                      const uint32_t timerPeriodMilliseconds,
                      const bool doAutoReloadTimer,
                      void (*ptrCallbackFunction)( void* ) );

/**
 * @function SCH_StartScheduler
 *
 * @brief Start the scheduler, this function should never return if everything is OK
 *
 * @param void
 *
 * @return void (no return value)
 */
void SCH_StartScheduler( void );

#endif /* SCHEDULER_H_ */