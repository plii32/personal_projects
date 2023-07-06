// header file
#include "StackType.h"

/*
Name: clearStack
Process: deallocates memory for StackType(aka ArrayType)
Function input/parameters: pointer to stack ADT (StackType *)
Function output/parameters: NULL
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: clearStudentArrayType
*/
StackType *clearStack( StackType *stack )
   {
    return clearLinkedList( stack );
   }

/*
Name: initializeStack
Process: initializes stack data for StackType(aka ArrayType)
Function input/parameters: initial capacity (int)
Function output/parameters: NULL
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: initializeStudentArrayType
*/
StackType *initializeStack( int initialCapacity )
   {
    return initializeLinkedList( initialCapacity );
   }

/*
Name: peekAdtData
Process: returns value as ADT from top of stack, does not pop from stack
Function input/parameters: pointer to stack (StackType *)
Function output/parameters: returned value (StudentNodeType *)
Function output/returned: Boolean result of operation
Device input/---: none
Device output/---: none
Dependencies: getDataAtLocation
*/
bool peekStack( StudentNodeType *returnVal, StackType *stack )
   {
    int stackSize = getLLSize( *stack );

    return getNodeAtLocation( returnVal, *stack, stackSize - 1 );
   }

/*
Name: popAdtData
Process: returns value as ADT from top of stack, pops from stack
Function input/parameters: pointer to stack (StackType *)
Function output/parameters: returned value (StudentNodeType *)
Function output/returned: Boolean result of operation
Device input/---: none
Device output/---: none
Dependencies: removeNodeAtLocation
*/
bool popAdtData( StudentNodeType *returnVal, StackType *stack )
   {
    int stackSize = getLLSize( *stack );

    return removeLLDataAtLocation( returnVal, stack, stackSize - 1 );
   }

/*
Name: pushAdtData
Process: pushes ADT value onto stack
Function input/parameters: pointer to stack (StackType *),
                           student data (const StudentNodeType)
Function output/parameters: none
Function output/returned: Boolean result of operation
Device input/---: none
Device output/---: none
Dependencies: pushRawData
*/
bool pushAdtData( StackType *stack, const StudentNodeType student )
   {
    return pushRawData( stack, student.name, student.gender, 
                                               student.studentId, student.gpa );
   }

/*
Name: pushRawData
Process: pushes individual data values onto stack
Function input/parameters: pointer to stack (StackType *),
                           student name (const char *),
                           student gender (char),
                           student ID (int),
                           student gpa (double),
Function output/parameters: pointer to updated stack (StackeType *)
Function output/returned: Boolean result of operation
Device input/---: none
Device output/---: none
Dependencies: insertRawDataAfterLocation
*/
bool pushRawData( StackType *stack, const char *name, char gender, 
                                                     int studentId, double gpa )
   {
    int listSize = getLLSize( *stack );

    if( stackIsEmpty( *stack ) )
       {
        return insertLLRawDataAfterLocation( stack, name, gender, 
                                                            studentId, gpa, 0 );        
       }

    return insertLLRawDataAfterLocation( stack, name, gender, 
                                                 studentId, gpa, listSize - 1 );
   }

/*
Name: stackIsEmpty
Process: returns true if stack is empty, false otherwise
Function input/parameters: stack (const StackType)
Function output/parameters: NULL
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: none
*/
bool stackIsEmpty( const StackType stack )
   {
    return linkedListIsEmpty( stack );
   }

   
