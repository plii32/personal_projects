// header files
#include "ADT_StudentDataEngine_Array.h"
#include "IteratorType.h"

bool appendAdtDataAtEnd( IteratorType *iterator, 
                                                const StudentDataType student )
    {
      // return insertArrayAdtDataAfterLocation that points to end of array
        return insertArrayAdtDataAfterLocation(iterator->array, student, 
                                                   iterator->array->size - 1);
    }

bool appendRawDataAtEnd( IteratorType *iterator, const char *name,
                                       char gender, int studentId, double gpa )
    {
      // return insertArrayRawDataAfterLocation at the end of the array
         return insertArrayRawDataAfterLocation(iterator->array, name, gender,
                                          studentId, gpa, iterator->array->size - 1);
    }

IteratorType *clearIterator( IteratorType *iterator )
   {
      // clear the array
      // function: clearArray
      clearArray(iterator->array);
     // clear the pointer
       // function: free
      free(iterator);
     // return null
      return NULL;
   }

void displayIterator( const IteratorType iterator )
   {
    
    // initialize variables
     int iterIndex;
     StudentDataType blankStudent;
     // if the iterator is empty
       // function: iteratorIsEmpty
     if(iteratorIsEmpty(iterator))
       {
         // display the error message 
           // function: printf
           printf("Iterator Empty - No Data Displayed\n");
       }
     else 
       {
         // loop through the array
         for(iterIndex = 0; iterIndex < iterator.array->size; iterIndex++)
           {
             // assign element to a temp
               // function: getElementAtLocation
              getElementAtLocation(&blankStudent, *iterator.array, iterIndex);
              // if the new index matches the current index
              if(iterator.currentIndex == iterIndex)
               {
                // print the element in brackets
                printf("[%s]; ", blankStudent.name);
               }
              else
               {
                // otherwise print without brackets
                 printf("%s; ", blankStudent.name);
               }
           }
           // print the new line 
             // function: printf
          printf("\n");
       }
       
   }

bool getAtCurrent( StudentDataType *returnVal, const IteratorType iterator )
   {   
     // return the getElementAtLocation at the current index
     return getElementAtLocation(returnVal, *iterator.array, iterator.currentIndex);
   }

bool hasNext( const IteratorType iterator )
   {
      // check if the iterator is not empty and that the current index is smaller
       //  than the array size
     if(!iteratorIsEmpty(iterator) && \
                            iterator.currentIndex + 1 < iterator.array->size)
       {
         // return true
         return true;
       }
         // otherwise return false
         return false; 
   }

bool hasPrev( const IteratorType iterator )
   {
     // check if iterator is empty and if index is over zero
     if(!iteratorIsEmpty(iterator) && iterator.currentIndex > 0)
       {
         // return true
         return true;
       }
       // otherwise return false
       return false; 
   }

IteratorType *initializeIterator( int initialCapacity )
   {
     // initialize variables
     IteratorType *newIter;
     // allocate space for the pointer
       // function: malloc
     newIter = (IteratorType*)malloc(sizeof(IteratorType));
     // set the current index to zero
     newIter->currentIndex = 0;
     // initialize the data
       // function: initializeArray
     newIter->array = initializeArray(initialCapacity);
     // return the pointer
     return newIter;
   }

bool insertAdtDataAtBeginning( IteratorType *iterator,
                                                const StudentDataType student )
    {
      // return insertArrayAdtDataBeforeLocation at the beginning of array
        return insertArrayAdtDataBeforeLocation(iterator->array, student, 0);
    }

bool insertAdtDataAtCurrent( IteratorType *iterator,
                                                const StudentDataType student )
    {
      // return insertArrayAdtDataBeforeLocation at the current index
         return insertArrayAdtDataBeforeLocation(iterator->array, student, 
                                                       iterator->currentIndex);
    }

bool insertRawDataAtBeginning( IteratorType *iterator, const char *name,
                                       char gender, int studentId, double gpa )
    {
      // return insertArrayRawDataBeforeLocation at the beginning
         return insertArrayRawDataBeforeLocation(iterator->array, name, gender,
                                                            studentId, gpa, 1);
    }

bool setRawDataAtCurrent( IteratorType *iterator, const char *name,
                                       char gender, int studentId, double gpa )
    {
      // return insertArrayRawDataBeforeLocation at the end of the array
        return insertArrayRawDataBeforeLocation(iterator->array, name, gender, 
                                  studentId, gpa, iterator->currentIndex - 1); 
    }

bool iteratorIsEmpty( const IteratorType iterator )
    {
      // return arrayIsEmpty using the iterator's array
             return arrayIsEmpty(*iterator.array);
    }

bool moveNext( IteratorType *iterator )
   {
      // if it's possible to move forward
        // function: hasNext
     if(hasNext(*iterator))
       {
        // increment the current index
         iterator->currentIndex++;
         // return true
         return true;
       }
       // otherwise return false
     return false;
       
   }

bool movePrev( IteratorType *iterator )
   {
     // check if it's capable of moving backwards
       // function: hasPrev
     if(hasPrev(*iterator))
       {
         // decrement the current index
         iterator->currentIndex--;
         // return true
         return true;
       }
       // otherwise return false
       return false;
   }

bool removeAdtDataFromCurrent( StudentDataType *returnVal,
                                                       IteratorType *iterator )
    {
       // check if it's not possible to go to next element
         // function: hasNext
       if(!hasNext(*iterator))
         {
           // decrement the index
           iterator->currentIndex--;
           // for the first removed current element, start at next index
            // function: removeArrayDataAtLocation
            return  removeArrayDataAtLocation(returnVal, iterator->array, iterator->currentIndex + 1);
         }
       // for the second removed current element, start at the beginning
        // function: removeArrayDataAtLocation
       return  removeArrayDataAtLocation(returnVal, iterator->array, iterator->currentIndex);
    }

bool setCurrentAtBeginning( IteratorType *iterator )
   {
     // if the array is not empty
       // function: iteratorIsEmpty
     if(!iteratorIsEmpty(*iterator))
       {
         // set current location to first location
         iterator->currentIndex = 0; 
         // return true
         return true;
       }
       // otherwise return false
       return false;
   }

bool setCurrentAtEnd( IteratorType *iterator )
   {
      // if array is not empty
        // function: iteratorIsEmpty
     if(!iteratorIsEmpty(*iterator))
       {
        // set current location to last location
         iterator->currentIndex = iterator->array->size - 1;
        // return true
         return true;
       }
     // otherwise return false
     return false;
   }