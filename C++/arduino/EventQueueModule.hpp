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

#ifndef EVENT_QUEUE_MODULE_HPP
#define EVENT_QUEUE_MODULE_HPP

#include "globals.hpp"

/***********************************************************************************
 * Definitions and Macros
 **********************************************************************************/
#define EVENT_QUEUE_LENGTH 1024

/***********************************************************************************
 * Typedefs
 **********************************************************************************/


/***********************************************************************************
 * Enumerations and Structures
 **********************************************************************************/
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
 **********************************************************************************/
void initEventQueue();
int sendEvent(EventId_t EventId, TaskId_t TaskId, TimerId_t TimerId = 128);
int receiveEvent(EventInfo_t* pEvent);

#endif