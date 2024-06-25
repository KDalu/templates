#ifndef EVENT_QUEUE_MODULE_HPP
#define EVENT_QUEUE_MODULE_HPP

#include "globals.hpp"

/***********************************************************************************
 * Definitions and Macros
 ***********************************************************************************/
#define EVENT_QUEUE_LENGTH 1024

/***********************************************************************************
 * Typedefs
 ***********************************************************************************/


/***********************************************************************************
 * Enumerations and Structures
 ***********************************************************************************/
enum EventId_t
{
    TASK_FIRST_EVENT = 0,
    TASK_SECOND_EVENT,
    TIMER_EVENT,
    NUM_EVENTS
};

enum TaskId_t
{
    FIRST_TASK = 0,
    SECOND_TASK,
    NUM_TASKS
};

struct EventInfo_t
{
    EventId_t EventId;
    TaskId_t TaskId;
    union                      // There may be other types of event data in the future
    {
        TimerId_t TimerId;
    };
};

struct EventQueueWs_t
{
    EventInfo_t buffer[EVENT_QUEUE_LENGTH];
    unsigned int head;
    unsigned int tail;
    bool isFull;
    bool queueOverflow;
};

/***********************************************************************************
 * Function Declarations
 ***********************************************************************************/
void initEventQueue();
int sendEvent(EventId_t EventId, TaskId_t TaskId, TimerId_t TimerId = 128);
int receiveEvent(EventInfo_t* pEvent);

#endif