/*
* File: queue.c
* -----------------
* This file implements the queue.h abstraction using an array.
*/

#include <stdio.h>

#include "genlib.h"
#include "strlib.h"
#include "queue.h"

/*
* Constants:
* --------------
* MaxQueueSize -- Maximum number of elements in the queue
*/

#define MaxQueueSize 10

static int ext = 1;


static queueADT ExtendQueue(queueADT queue);
static queueADT ExtendNewQueue(queueADT queue);
static string Copy(void *vp);


/*
* Type: queueCDT
* -----------------------
* This type provides the concrete counterpart to the queueADT.
* The representation used here consists of an array coupled
* with an integer indicating the effective size. This
* representation means that Dequeue must shift the existing 
* elements in the queue.
*/
struct queueCDT {
    void **array;
    int head;
    int tail;
    int len;
    int maxSize;
};

/* Exported entries */
/*
* Function: NewQueue, FreeQueue
* ---------------------------------------------
* NewQueue allocates and initializes the storage for a
* new queue. FreeQueue allows the client to free that 
* storage when it is no longer needed.
*/
queueADT NewQueue(void)
{
    queueADT queue;

    queue = New(queueADT);
    queue->array = (void **) GetBlock(ext * MaxQueueSize * sizeof(long long int));
    queue->head = 0;
    queue->tail = 0;
    queue->len = 0;
    queue->maxSize = ext * MaxQueueSize;
    return (queue);
}

void FreeQueue(queueADT queue)
{
    FreeBlock(queue);
}

/*
* Function: Enqueue
* ---------------------------
* This function adds a new element to the queue.
*/
queueADT Enqueue(queueADT queue, void *obj)
{
    if (queue->len == queue->maxSize) {
        queueADT newq;
        newq = ExtendQueue(queue);
        FreeQueue(queue);
        // printf("new queue maxSize: %d\n", newq->maxSize);
        newq->array[newq->tail] = obj;
        newq->tail = (newq->tail + 1) % newq->maxSize;
        newq->len++;
        return newq;
    }
    queue->array[queue->tail] = obj;
    queue->tail = (queue->tail + 1) % queue->maxSize;
    queue->len++;
    // ShowQueueElement(queue);
    return queue;
}

/*
* Funcitn: Dequeue
* -----------------------
* This function removes and returns the data value at the 
* head of the queue.
*/
void *Dequeue(queueADT queue)
{
    void *result;
    int i;

    if (queue->len == 0) {
        printf("Dequeue of empty queue -- try Enqueue\n");
    }
    result = queue->array[queue->head];
    queue->head = (queue->head + 1) % queue->maxSize;
    queue->len--;
    return (result);
}

/*
* Funciton: QueueLength
* -----------------------------
* This function returns the number of elements in the queue.
*/
int QueueLength(queueADT queue)
{
    return queue->len;
}

void ShowQueueElement(queueADT queue)
{
    int i;

    for (i = 0; i < queue->len; i++) {
        printf("%d:%s, ", (queue->head + i) % queue->maxSize,
                            queue->array[(queue->head + i) % queue->maxSize]);
    }
    printf("MaxSize:%d, len:%d, head:%d tail:%d\n", queue->maxSize, queue->len, queue->head, queue->tail);
}

static queueADT ExtendQueue(queueADT queue)
{
    queueADT newq;
    int i, head, tail, size;

    newq = ExtendNewQueue(queue);
    size = queue->maxSize;
    head = queue->head;
    tail = queue->tail;
    i = 0;
    for (i = 0; i < size; i++) {
        newq->array[i] = queue->array[(head + i) % size];
    }
    newq->head = 0;
    newq->tail = size;
    newq->len = queue->len;
    return newq;
}

static queueADT ExtendNewQueue(queueADT queue)
{
    queueADT newq;

    ext = 2 * (queue->maxSize / MaxQueueSize);
    newq = NewQueue();
    ext = 1;
    return newq;
}

static string Copy(void *vp)
{
    return CopyString(vp);
}