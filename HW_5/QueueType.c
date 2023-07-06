// header file
#include "QueueType.h"


QueueType *clearQueue( QueueType *queue )
   {
    // clear the queue
      // function: clearArray
    return clearArray(queue);
   }

QueueType *initializeQueue( int initialCapacity )
   {
        // return the initialized array
          // function: initializedArray
     return initializeArray(initialCapacity);
   }

bool dequeueAdtData( StudentDataType *returnedValue, QueueType *queue )
   {
      // return the data to the beginning of the queue
        // function: removeArrayDataAtLocation
        return removeArrayDataAtLocation(returnedValue, queue, 0);
   }

bool enqueueAdtData( QueueType *queue, const StudentDataType newData )
   {
    // returns data to the end of the queue
      // function: insertArrayAdtDataBeforeLocation
     return insertArrayAdtDataBeforeLocation(queue, newData, queue->size);
   }

bool enqueueRawData( QueueType *queue, const char *name, char gender,
                                                    int studentId, double gpa )
    {   
       // add the data to the end of the queue
         // function: insertArrayRawDataBeforeLocation
           return insertArrayRawDataBeforeLocation(queue, name, gender, 
                                                           studentId, gpa, 0); 
    }

bool peekQueue( StudentDataType *returnVal, const QueueType queue )
   {
      // put data in front of the queue
        // function: getElementAtLocation
         return getElementAtLocation(returnVal, queue, queue.size - 1);
   }

bool queueIsEmpty( const QueueType queue )
   {
      // determine if the queue array is empty
        // function: arrayIsEmpty
     return arrayIsEmpty(queue);
   }