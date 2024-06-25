#ifndef TASK_HPP
#define TASK_HPP

#include "EventQueueModule.hpp"

/***********************************************************************************
 * Definitions and Macros
 ***********************************************************************************/


/***********************************************************************************
 * Typedefs
 ***********************************************************************************/


/***********************************************************************************
 * Enumerations and Structures
 ***********************************************************************************/


/***********************************************************************************
 * Class Definition
 ***********************************************************************************/
class Task
{
private:
    enum TaskStates
    {
        TASK_FIRST_STATE = 0,
        TASK_SECOND_STATE,
        NUM_TASK_STATES
    };

    EventInfo_t* TaskFirstState(EventInfo_t* pEvent);
    EventInfo_t* TaskSecondState(EventInfo_t* pEvent);

    typedef EventInfo_t* (Task::*TaskStateMachine)(EventInfo_t* pEvent);

    TaskStateMachine TaskFsm[NUM_TASK_STATES] = {&Task::TaskFirstState,
                                                 &Task::TaskSecondState
                                                };

    // Private variables

    // Private functions

public:
    Task();
    EventInfo_t* TaskRun(EventInfo_t* pEvent);

    // Public functions
};

#endif