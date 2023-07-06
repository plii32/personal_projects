// header file 
#include "StackType.h"

StackType *clearStack( StackType *stack )
   {
      // clear the stack
        // function: clearArray
     return clearArray(stack);
   }

StackType *initializeStack( int initialCapacity )
   {
      // intitalize the stack
       // function: initializeArray
     return initializeArray(initialCapacity);
   }

bool peekStack( StudentDataType *returnVal, StackType *stack )
   {
      // puts element to the top of the stack
       // function: getElementAtLocation
     return getElementAtLocation(returnVal, *stack, stack->size - 1);
   }

bool popAdtData( StudentDataType *returnVal, StackType *stack )
   {
      // pop the stack
       // function: removeArrayDataAtLocation
    return removeArrayDataAtLocation(returnVal, stack, stack->size - 1);
   }

bool pushAdtData( StackType *stack, const StudentDataType student )
   {
      // pushes data onto stack
       // function: pushRawData
     return pushRawData(stack, student.name, student.gender, 
                                       student.studentId, student.gpa);  
   }

bool pushRawData( StackType *stack, const char *name, char gender,
                                                    int studentId, double gpa )
    {
        // check if stack is empty
         // function: stackIsEmpty
        if(stackIsEmpty(*stack))
          {
             // push the elements from the beginning
              // function: insertArrayRawDataAfterLocation
              return insertArrayRawDataAfterLocation(stack, name, gender,
                                                          studentId, gpa, 0);
             
          }
          // otherwise push elements from the last element
           // function: insertArrayRawDataAfterLocation
          return insertArrayRawDataAfterLocation(stack, name, gender,studentId,
                                                         gpa, stack->size - 1);
    }

bool stackIsEmpty( const StackType stack )
   {
      // check if stack is empty
       // function: arrayIsEmpty
          return arrayIsEmpty(stack);
   }