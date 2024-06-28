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

#include "TimerModule.hpp"
#include "EventQueueModule.hpp"

/***********************************************************************************
 * Variable Definitions
 **********************************************************************************/


/***********************************************************************************
 * Function Definitions
 **********************************************************************************/

/**
 * @brief Interrupt service routine for timer interrupts.
 */
void TimerIsrHandler()
{

}

/**
 * @brief Initializes the timer module.
 */
void initTimer()
{

}

/**
 * @brief Stops a currently running timer.
 * @param TimerId Timer Id to be stopped.
 */
void stopTimer(TimerId_t TimerId)
{

}

/**
 * @brief Starts a timer that will periodically trigger an interrupt.
 * @param DurationInMs Time elapsed between interrupts in milliseconds.
 * @param TaskId Task that requested the timer.
 */
TimerId_t startTimer(TimerDur_t DurationInMs, TaskId_t TaskId)
{

}