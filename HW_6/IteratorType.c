#include "IteratorType.h"

/*
Name: clearIterator
Process: deallocates memory for Iterator linked list
Function input/parameters: pointer to iterator (IteratorType *)
Function output/parameters: none
Function output/returned: NULL
Device input/---: none
Device output/---: none
Dependencies: clearLinkedList, free
*/
IteratorType *clearIterator( IteratorType *iterator )
   {
    clearLinkedList( iterator->list );

    free( iterator );

    return NULL;
   }

/*
Name: displayIterator
Process: displays iterator in order with current student name in brackets,
         current item must be displayed in brackets
         if list is empty, displays "Iterator Empty - No Data Displayed"
Function input/parameters: iterator (const Iterator)
Function output/parameters: none
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: printf
*/
void displayIterator( const IteratorType iterator )
   {
    int index = 0, listSize = getLLSize( *iterator.list );
    StudentNodeType student;
    StudentLinkedListType *list = iterator.list;

    if( !iteratorIsEmpty( iterator ) )
       {
        while( index < listSize )
           {
            getNodeAtLocation( &student, *list, index );

            if( index == iterator.currentIndex )
               {
                printf( "[%s]; ", student.name );
               }

            else
               {
                printf( "%s; ", student.name );
               }

            index++;
           }
       }

    else
       {
        printf( "\nIterator Empty - No Data Displayed\n" );
       }

    printf( "\n" );
   }

/*
Name: getAtCurrent
Process: if available, accesses data at current index and returns true,
         otherwise, returns false
Function input/parameters: iterator (const Iterator)
Function output/parameters: returned student data (StudentDataType *)
Function output/returned: Boolean result of operation (bool)
Device input/---: none
Device output/---: none
Dependencies: getNodeAtLocation
*/
bool getAtCurrent( StudentNodeType *returnVal, const IteratorType iterator )
   {
    StudentLinkedListType *list = iterator.list;

    return getNodeAtLocation( returnVal, *list, iterator.currentIndex );
   }

/*
Name: hasNext
Process: if it is possible for the current index to move forward in the array,
         and the array is not empty, returns true, otherwise returns false
Function input/parameters: iterator (const Iterator)
Function output/parameters: none
Function output/returned: Boolean result of operation (bool)
Device input/---: none
Device output/---: none
Dependencies: getLLSize, isEmpty
*/
bool hasNext( const IteratorType iterator )
   {
    int listSize = getLLSize( *iterator.list );

    return !iteratorIsEmpty( iterator ) && iterator.currentIndex < listSize - 1;
   }

/*
Name: hasPrev
Process: if it is possible for the current index to move backward in the array,
         and the array is not empty, returns true, otherwise returns false
Function input/parameters: iterator (const Iterator)
Function output/parameters: none
Function output/returned: Boolean result of operation (bool)
Device input/---: none
Device output/---: none
Dependencies: isEmpty
*/
bool hasPrev( const IteratorType iterator )
   {
    return !iteratorIsEmpty( iterator ) && iterator.currentIndex > 0;
   }

/*
Name: initializeIterator
Process: initializes iterator data as needed
         and initializes Student Data Engine
Function input/parameters: none
Function output/parameters: none
Function output/returned: pointer to initialized iterator ADT (IteratorType *)
Device input/---: none
Device output/---: none
Dependencies: malloc, initializeLinkedList
*/
IteratorType *initializeIterator()
   {
    IteratorType *newIterator 
                             = (IteratorType *)malloc( sizeof( IteratorType ) );

    newIterator->currentIndex = 0;

    newIterator->list = initializeLinkedList();

    return newIterator;
   }

/*
Name: insertAdtDataAtBeginning
Process: inserts ADT data at beginning of iterator 
         and returns true if successful, otherwise returns false,
         does not update current index
Function input/parameters: pointer to iterator (IteratorType *),
                           value to be added (const StudentNodeType)
Function output/parameters: pointer to updated iterator (IteratorType *)
Function output/returned: Boolean result of the operation (bool)
Device input/---: none
Device output/---: none
Dependencies: insertLLAdtDataBeforeLocation (one line of code)
*/
bool insertAdtDataAtBeginning( IteratorType *iterator, 
                                                 const StudentNodeType student )
   {
    return insertLLAdtDataBeforeLocation( iterator->list, student, 0 );
   }

/*
Name: insertAdtDataAtCurrent
Process: inserts ADT data at beginning of iterator 
         and returns true if successful, otherwise returns false
Function input/parameters: pointer to iterator (IteratorType *),
                           value to be added (const StudentNodeType)
Function output/parameters: pointer to updated iterator (IteratorType *)
Function output/returned: Boolean result of the operation (bool)
Device input/---: none
Device output/---: none
Dependencies: insertLLAdtDataBeforeLocation (one line of code)
*/
bool insertAdtDataAtCurrent( IteratorType *iterator, 
                                                 const StudentNodeType student )
   {
    return insertLLAdtDataBeforeLocation( iterator->list, 
                                              student, iterator->currentIndex );
   }

/*
Name: insertAdtDataAtEnd
Process: inserts ADT data at end of iterator 
         and returns true if successful, otherwise returns false,
         does not update current index
Function input/parameters: pointer to iterator (IteratorType *),
                           value to be added (const StudentNodeType)
Function output/parameters: pointer to updated iterator (IteratorType *)
Function output/returned: Boolean result of the operation (bool)
Device input/---: none
Device output/---: none
Dependencies: getLLSize, insertLLAdtDataAfterLocation
*/
bool insertAdtDataAtEnd( IteratorType *iterator, 
                                                 const StudentNodeType student )
   {
    int listSize = getLLSize( *iterator->list );

    return insertLLAdtDataAfterLocation( iterator->list, 
                                                        student, listSize - 1 );
   }

/*
Name: insertRawDataAtBeginning
Process: inserts individual values at beginning of iterator 
         and returns true if successful, otherwise returns false,
         does not update current index
Function input/parameters: pointer to iterator (IteratorType *),
                           student name (const char *),
                           student gender (char),
                           student ID (int),
                           student gpa (double)
Function output/parameters: pointer to updated iterator (IteratorType *)
Function output/returned: Boolean result of the operation (bool)
Device input/---: none
Device output/---: none
Dependencies: insertLLRawDataBeforeLocation
*/
bool insertRawDataAtBeginning( IteratorType *iterator, const char *name,
                                   char gender, int studentId, double gpa )

   {
    return insertLLRawDataBeforeLocation( iterator->list, name, gender, 
                                                            studentId, gpa, 0 );
   }

/*
Name: insertRawDataAtCurrent
Process: inserts individual values at current index of iterator 
         and returns true if successful, otherwise returns false
Function input/parameters: pointer to iterator (IteratorType *),
                           student name (const char *),
                           student gender (char),
                           student ID (int),
                           student gpa (double)
Function output/parameters: pointer to updated iterator (IteratorType *)
Function output/returned: Boolean result of the operation (bool)
Device input/---: none
Device output/---: none
Dependencies: insertLLRawDataBeforeLocation (one line of code)
*/
bool insertRawDataAtCurrent( IteratorType *iterator, const char *name,
                                   char gender, int studentId, double gpa )

   {
    return insertLLRawDataBeforeLocation( iterator->list, 
                         name, gender, studentId, gpa, iterator->currentIndex );
   }
/*
Name: insertRawDataAtEnd
Process: inserts individual values at end of iterator 
         and returns true if successful, otherwise returns false,
         does not update current index
Function input/parameters: pointer to iterator (IteratorType *),
                           student name (const char *),
                           student gender (char),
                           student ID (int),
                           student gpa (double)
Function output/parameters: pointer to updated iterator (IteratorType *)
Function output/returned: Boolean result of the operation (bool)
Device input/---: none
Device output/---: none
Dependencies: getLLSize, insertLLRawDataAfterLocation
*/
bool insertRawDataAtEnd( IteratorType *iterator, const char *name,
                                   char gender, int studentId, double gpa )

   {
    int listSize = getLLSize( *iterator->list );

    return insertLLRawDataAfterLocation( iterator->list, name, gender, 
                                                 studentId, gpa, listSize - 1 );
   }

/*
Name: iteratorIsEmpty
Process: returns true if iterator is empty, false otherwise
Function input/parameters: iterator (const IteratorType)
Function output/parameters: none
Function output/returned: Boolean result of specified test
Device input/---: none
Device output/---: none
Dependencies: none
*/
bool iteratorIsEmpty( const IteratorType iterator )
   {
    return linkedListIsEmpty( *iterator.list );
   }

/*
Name: moveNext
Process: if it is possible to move forward in the array, 
         increments the current index and returns true,
         otherwise returns false
Function input/parameters: iterator (IteratorType *)
Function output/parameters: none
Function output/returned: Boolean result of the operation (bool)
Device input/---: none
Device output/---: none
Dependencies: hasNext
*/
bool moveNext( IteratorType *iterator )
   {
    if( hasNext( *iterator ) )
       {
        iterator->currentIndex++;

        return true;
       }

    return false;
   }

/*
Name: movePrev
Process: if it is possible to move backward in the array, 
         decrements the current index and returns true,
         otherwise returns false
Function input/parameters: iterator (IteratorType *)
Function output/parameters: none
Function output/returned: Boolean result of the operation (bool)
Device input/---: none
Device output/---: none
Dependencies: hasPrev
*/
bool movePrev( IteratorType *iterator )
   {
    if( hasPrev( *iterator ) )
       {
        iterator->currentIndex--;

        return true;
       }

    return false;
   }

/*
Name: removeAdtDataFromCurrent
Process: if data is available, it is removed from the current location
         and the function returns true, otherwise it returns false
Function input/parameters: pointer to iterator (IteratorType *)
Function output/parameters: value to be returned (StudentNodeType *),
                            pointer to updated iterator (IteratorType *)
Function output/returned: Boolean result of the operation (bool)
Device input/---: none
Device output/---: none
Dependencies: removeDataAtLocation
*/
bool removeAdtDataFromCurrent( StudentNodeType *returnVal, 
                                                        IteratorType *iterator )
   {
    bool lastValue = !hasNext( *iterator );

    bool returnBool = removeLLDataAtLocation( returnVal, 
                                       iterator->list, iterator->currentIndex );

    if( returnBool && lastValue )
       {
        iterator->currentIndex--;
       }

    return returnBool;    
   }

/*
Name: setCurrentAtBeginning
Process: sets current location at beginning
         and returns true if successful, otherwise returns false
Function input/parameters: pointer to iterator (IteratorType *)
Function output/parameters: pointer to updated iterator (IteratorType *)
Function output/returned: Boolean result of the operation (bool)
Device input/---: none
Device output/---: none
Dependencies: isEmpty
*/
bool setCurrentAtBeginning( IteratorType *iterator )
   {
    if( !iteratorIsEmpty( *iterator ) )
       {
        iterator->currentIndex = 0;

        return true;
       }

    return false;
   }

/*
Name: setCurrentAtEnd
Process: sets current location at end
         and returns true if successful, otherwise returns false
Function input/parameters: pointer to iterator (IteratorType *)
Function output/parameters: pointer to updated iterator (IteratorType *)
Function output/returned: Boolean result of the operation (bool)
Device input/---: none
Device output/---: none
Dependencies: isEmpty, moveNext
*/
bool setCurrentAtEnd( IteratorType *iterator )
   {
    int listSize = getLLSize( *iterator->list );

    if( !iteratorIsEmpty( *iterator ) )
       {
        iterator->currentIndex = listSize - 1;

        return true;
       }

    return false;
   }


