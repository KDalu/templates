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

#include "Task.hpp"
#include "debug.hpp"

/***********************************************************************************
 * Variable Definitions
 ***********************************************************************************/
Task TaskWs = Task();

/***********************************************************************************
 * Function Definitions
 ***********************************************************************************/

/**
 * @brief Initializes the Task workspace.
 */
Task::Task()
{
    currentState = TASK_FIRST_STATE;
}

/**
 * @brief Runs the Task's finite state machine/s.
 */
EventInfo_t* Task::TaskRun(EventInfo_t* pEvent)
{
    EventInfo_t* pRetEvent = pEvent;

    DEBUG_LVL1("Running <Task> state machine.");
    pRetEvent = (this->*TaskFsm[currentState])(pEvent);

    return pRetEvent;
}

/**
 * @brief Handles events while the state machine is at the <First> state.
 */
EventInfo_t* Task::TaskFirstState(EventInfo_t* pEvent)
{
    EventInfo_t* pRetEvent = pEvent;

    DEBUG_LVL1("<Task>: Entered <First> State.");

    switch (pEvent->EventId)
    {
        case TASK_FIRST_EVENT:
            currentState = TASK_SECOND_STATE;
            sendEvent(TASK_SECOND_EVENT, FIRST_TASK);
            pRetEvent = NULL;
            break;
        case TASK_SECOND_EVENT:
            break;
        default:
            break;
    }

    return pRetEvent;
}