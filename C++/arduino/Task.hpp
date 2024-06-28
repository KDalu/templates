/***********************************************************************************
 * MIT License
 * 
 * Copyright (c) 2024 KDalu
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 ***********************************************************************************/

#ifndef TASK_HPP
#define TASK_HPP

#include "EventQueueModule.hpp"

/***********************************************************************************
 * Definitions and Macros
 **********************************************************************************/


/***********************************************************************************
 * Typedefs
 **********************************************************************************/


/***********************************************************************************
 * Enumerations and Structures
 **********************************************************************************/


/***********************************************************************************
 * Class Definition
 **********************************************************************************/
class Task
{
private:
    enum TaskStates_t
    {
        TASK_FIRST_STATE = 0,
        TASK_SECOND_STATE,
        NUM_TASK_STATES
    };

    EventInfo_t* TaskFirstState(EventInfo_t* pEvent);
    EventInfo_t* TaskSecondState(EventInfo_t* pEvent);

    typedef EventInfo_t* (Task::*TaskStateMachine_t)(EventInfo_t* pEvent);

    TaskStateMachine_t TaskFsm[NUM_TASK_STATES] = {&Task::TaskFirstState,
                                                 &Task::TaskSecondState
                                                };

    // Private variables
    TaskStates_t currentState;

    // Private functions

public:
    Task();
    EventInfo_t* TaskRun(EventInfo_t* pEvent);

    // Public functions
};

extern Task TaskWs;

#endif