#include "EventQueueModule.hpp"
#include "TimerModule.hpp"

/***********************************************************************************
 * Variable Definitions
 ***********************************************************************************/
EventQueueWs_t EventQueueWs;

/***********************************************************************************
 * Function Definitions
 ***********************************************************************************/

/**
 * @brief Initializes the EventQueue.
 */
void initEventQueue()
{
    int idx;
    for (idx = 0; idx < EVENT_QUEUE_LENGTH; idx++)
    {
        EventQueueWs.buffer[idx].EventId        = NUM_EVENTS;
        EventQueueWs.buffer[idx].TaskId         = NUM_TASKS;
        EventQueueWs.buffer[idx].TimerId        = TIMER_INACTIVE;
    }
    EventQueueWs.head            = 0;
    EventQueueWs.tail            = 0;
    EventQueueWs.isFull          = false;
    EventQueueWs.queueOverflow   = false;
}

/**
 * @brief Pushes an event into the EventQueue.
 * @param EventId Event type pushed into the queue.
 * @param TaskId Recipient Task of the event.
 * @param TimerId Optional event information.
 * @return 0 - success, 1 - fail
 */
int sendEvent(EventId_t EventId, TaskId_t TaskId, TimerId_t TimerId)
{
    int retVal = 0;
    EventQueueWs_t* pWs = &EventQueueWs;

    // Check if the buffer is full
    if (EventQueueWs.isFull == false)
    {
        pWs->buffer[EventQueueWs.head].EventId      = EventId;
        pWs->buffer[EventQueueWs.head].TaskId       = TaskId;
        pWs->buffer[EventQueueWs.head].TimerId      = TimerId;

        pWs->head = (pWs->head + 1) % EVENT_QUEUE_LENGTH;

        if (pWs->head == pWs->tail)
        {
            // Head is currently pointing to tail which means we just used up the
            // last available slot.
            pWs->isFull = true;
        }
    }
    else
    {
        // Notify caller that function call failed and set queue overflow to true
        // denoting that an event was not sent.
        pWs->queueOverflow = true;
        retVal = 1;
    }

    return retVal;
}

/**
 * @brief Pops an event from the EventQueue.
 * @param pEvent pointer to EventInfo data type where the event will be copied to.
 * @return 0 - success, 1 - fail
 */
int receiveEvent(EventInfo_t* pEvent)
{
    int retVal = 0;
    EventQueueWs_t* pWs = &EventQueueWs;

    // Check if the buffer is not empty
    if ((pWs->head != pWs->tail) || (pWs->isFull == true))
    {
        pEvent->EventId     = pWs->buffer[pWs->tail].EventId;
        pEvent->TaskId      = pWs->buffer[pWs->tail].TaskId;
        pEvent->TimerId     = pWs->buffer[pWs->tail].TimerId;

        pWs->tail = (pWs->tail + 1) % EVENT_QUEUE_LENGTH;
    }
    else
    {
        // Notify the caller that the function call failed.
        retVal = 1;
    }

    return retVal;
}