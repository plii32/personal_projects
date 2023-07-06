#ifndef ITERATOR_TYPE_H
#define ITERATOR_TYPE_H

// header files
#include "ADT_StudentDataEngine_LL.h"

// Data structure(s)
typedef struct IteratorStruct
   {
    StudentLinkedListType *list;

    int currentIndex;
   } IteratorType;

// Prototypes

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
IteratorType *clearIterator( IteratorType *iterator );

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
void displayIterator( const IteratorType iterator );

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
bool getAtCurrent( StudentNodeType *returnVal, const IteratorType iterator );

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
bool hasNext( const IteratorType iterator );

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
bool hasPrev( const IteratorType iterator );

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
IteratorType *initializeIterator();

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
                                                const StudentNodeType student );

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
                                                const StudentNodeType student );

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
                                                const StudentNodeType student );

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
                                       char gender, int studentId, double gpa );

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
                                       char gender, int studentId, double gpa );


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
                                       char gender, int studentId, double gpa );

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
bool iteratorIsEmpty( const IteratorType iterator );

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
bool moveNext( IteratorType *iterator );

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
bool movePrev( IteratorType *iterator );

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
                                                       IteratorType *iterator );

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
bool setCurrentAtBeginning( IteratorType *iterator );

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
bool setCurrentAtEnd( IteratorType *iterator );


#endif   // ITERATOR_TYPE_H

