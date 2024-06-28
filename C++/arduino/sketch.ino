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

#include "globals.hpp"
#include "debug.hpp"
#include "EventQueueModule.hpp"
#include "TimerModule.hpp"
#include "Task.hpp"

void setup()
{
#if CFG_DEBUG
    Serial.begin(115200);
#endif

    initEventQueue();
    initTimer();
}

void loop()
{
    EventInfo_t Event;
    EventInfo_t* pRetEvent;

    // Receive an event from the event queue.
    if (receiveEvent(&Event) == 0)
    {
        DEBUG_LVL1("Received event: ");
        DEBUG_LVL1(Event.EventId);
        DEBUG_LVL1(" Task: ");
        DEBUG_LVL1(Event.TaskId);
        DEBUG_LVL1("\n");
        switch (Event.TaskId)
        {
            case FIRST_TASK:
                pRetEvent = TaskWs.TaskRun(&Event);
                break;
            default:
                break;
        }

        if (pRetEvent != NULL)
        {
            // Event was not handled (i.e. dropped).
        }
    }
}