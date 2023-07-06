#ifndef QUEUE_TYPE_H
#define QUEUE_TYPE_H

// header file(s)
#include "ADT_StudentDataEngine_LL.h"

// local constant(s)

// data structure(s)
typedef StudentLinkedListType QueueType;

// prototypes

/*
Name: clearQueue
Process: deallocates memory for QueueType (aka StudentLinkedListType)
Function input/parameters: pointer to queue ADT (QueueType *)
Function output/parameters: none
Function output/returned: NULL
Device input/---: none
Device output/---: none
Dependencies: clearStudentArrayType
*/
QueueType *clearQueue( QueueType *queue );

/*
Name: initializeQueue
Process: initializes Student Data Engine
Function input/parameters: none
Function output/parameters: none
Function output/returned: pointer to initialized queue pointer (QueueType *)
Device input/---: none
Device output/---: none
Dependencies: initializeLinkedList
*/
QueueType *initializeQueue();

/*
Name: dequeueAdtData
Process: returns data from front of queue
Function input/parameters: pointer to queue (QueueType *)
Function output/parameters: returned value if available (StudentNodeType *),
                            or empty value otherwise,
                            pointer to updated queue ADT (QueueType *)
Function output/returned: Boolean result of specified operation (bool)
Device input/---: none
Device output/---: none
Dependencies: removeDataAtLocation
*/
bool dequeueAdtData( StudentNodeType *returnedValue, QueueType *queue );

/*
Name: enqueueAdtData
Process: adds data as ADT to end of queue
Function input/parameters: pointer to queue (QueueType *),
                           data to be enqueued (const StudentNodeType)
Function output/parameters: pointer to updated queue ADT (QueueType *)
Function output/returned: Boolean result of specified operation (bool)
Device input/---: none
Device output/---: none
Dependencies: insertDataAdtBeforeLocation
*/
bool enqueueAdtData( QueueType *queue, const StudentNodeType newData );

/*
Name: enqueueRawData
Process: adds data as individual values to end of queue, updates rear index
Function input/parameters: pointer to queue (QueueType *),
                           student name (const char *),
                           student gender (char),
                           student ID (int),
                           student gpa (double),
Function output/parameters: pointer to updated queue ADT (QueueType *)
Function output/returned: Boolean result of specified operation (bool)
Device input/---: none
Device output/---: none
Dependencies: insertRawDataBeforeLocation
*/
bool enqueueRawData( QueueType *queue, const char *name, char gender, 
                                                    int studentId, double gpa );

/*
Name: peekQueue
Process: returns data from front of queue without dequeueing it
Function input/parameters: pointer to queue (QueueType *)
Function output/parameters: returned value if available,
                            or empty value otherwise,
                            pointer to updated queue ADT (QueueType *)
Function output/returned: Boolean result of specified operation (bool)
Device input/---: none
Device output/---: none
Dependencies: getDataAtIndex
*/
bool peekQueue( StudentNodeType *returnVal, const QueueType queue );

/*
Name: queueIsEmpty
Process: returns true if queue array is empty, false otherwise
Function input/parameters: queue (const QueueType)
Function output/parameters: none
Function output/returned: Boolean result of specified operation (bool)
Device input/---: none
Device output/---: none
Dependencies: none
*/
bool queueIsEmpty( const QueueType queue );


#endif   // QUEUE_TYPE_H
