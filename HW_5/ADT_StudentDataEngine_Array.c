// header files
#include "ADT_StudentDataEngine_Array.h"
#include "StandardConstants.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// functions

bool arrayIsEmpty( const StudentArrayType array )
   {
     // if the size is zero
     if(array.size == 0)
      {
        // return true
        return true;
      }
     // otherwise return false
     return false;
   }

void checkForResize( StudentArrayType *adtArray )
   {
     // initialize variables
     int  index;
     // create a new array
     StudentDataType *newArray;
     // test if size is at capacity
     if(adtArray->size == adtArray->capacity)
      {
        // double the capacity
         adtArray->capacity = (adtArray->capacity *PRECISION);
        // dynamically allocate memory for the new array
         // function: malloc
        newArray = (StudentDataType*)malloc(sizeof(StudentDataType) \
                                                     *adtArray->capacity);
        // loop through the array
        for(index = 0; index < adtArray->size; index++)
         {
           // copy new size to array
            // function: deepCopyElement
           deepCopyElement(&newArray[index], adtArray->array[index]);
         }
        // free up space for array
         // function: free
        free(adtArray->array);
        // set the new to the old array
        adtArray->array = newArray;
    }
   }

StudentArrayType *clearArray( StudentArrayType *arrayPtr )
   {
     // clear the array
       // function: free
       free(arrayPtr->array);
     // clear the array pointer
       // function: free
       free(arrayPtr);
     // return NULL
       return NULL;
   }

void copyArray( StudentArrayType *dest, const StudentArrayType src )
   {
     // initialize variables
     int element;
     // test if the capacity of dest is less than src
     for(element = 0; element < src.size; element++)
      {
        // check for resizing
         // function: checkForResize
        checkForResize(dest);
        // update the size
         // function: deepCopyElement
        deepCopyElement(&dest->array[element], src.array[element]);
        // increment size
        dest->size = dest->size + 1;
      }
   }

void deepCopyElement( StudentDataType *dest, const StudentDataType src )
   {
     // assign src elements to dest elements
       // copy name from src to dest
         // function: strcpy
         strcpy(dest->name, src.name);
       // copy gender from src to dest
         dest->gender = src.gender;
       // copy student id from src to dest
         dest->studentId = src.studentId;
       // copy gpa from src to dest
         dest->gpa = src.gpa;
   }

void displayArrayData( const StudentArrayType adtArray, const char *subTitle )
   {
     // initialize variables
     int newIndex;
     StudentDataType data;
     // check if the array is empty
     if(adtArray.size != 0)
      {
        // print the title
         // function: printf
        printf("\nDisplay Title - %s\n", subTitle);

        // loop through the array
        for(newIndex = 0; newIndex < adtArray.size; newIndex++)
         {
           // assign data to element
           data = adtArray.array[newIndex];
           // print the array
             // function: printf
           printf("[ %d ]: %s, %c, %d, %0.5f\n", newIndex, data.name, \
                   data.gender, data.studentId, data.gpa);
         }
      }
      else
      {
        printf("Data not found - Data Aborted\n");
      }
   }

bool getElementAtLocation( StudentDataType *returnVal,
                            const StudentArrayType adtArray, int listLocation)
   {
       // check if index is in bounds
       if(listLocation >= 0 && listLocation < adtArray.size)
        {
          // copy from array to returnVal
           // function: deepCopyElement
          deepCopyElement(returnVal, adtArray.array[listLocation]);
          // return true
          return true;
        }
        // set the return value to zero
         // function: setEmptyElementData
        setEmptyElementData(returnVal);
        // return false
        return false;
   }

StudentArrayType *initializeArray( int initialCapacity )
   {
     // create the array pointer
     StudentArrayType *newArray;
      // dynamically allocate space for new pointer
       // function: malloc
     newArray = (StudentArrayType*)malloc(sizeof(StudentDataType));
     // assign the array capacity to the initialCapacity
     newArray->capacity = initialCapacity;
     // initialize array size to zero
     newArray->size = 0;
     // allocate the array itself
       // function: malloc
     newArray->array = (StudentDataType*)malloc(sizeof(StudentDataType) \
                                               * newArray->capacity);
     // return array pointer
     return newArray;
   }

bool insertArrayAdtDataAfterLocation( StudentArrayType *adtArray,
                              const StudentDataType student, int listLocation )
    {
      // return insertArrayRawDataEngine at locCode = 2
       return insertArrayRawDataEngine(adtArray, student.name, student.gender, student.studentId, \
                                          student.gpa, listLocation, AFTER_LOCATION);
    }

bool insertArrayAdtDataBeforeLocation( StudentArrayType *adtArray,
                              const StudentDataType student, int listLocation )
   {
    // return insertArrayDataEngine at locCode = 0
     return insertArrayRawDataEngine(adtArray, student.name, student.gender, \
                               student.studentId, student.gpa, listLocation, BEFORE_LOCATION);
   }

bool insertArrayRawDataEngine( StudentArrayType *adtArray,
          const char *name, char gender, int studentId, double gpa,
                                   int listLocation, LocationCodeType locCode )
    {
             // initialize variables
              int wkgPt;

             // check for resize
               // function: checkForResize
              checkForResize(adtArray);

             // greater than or equal to 0 and less than size || check for listlocation 0 and not at_location
               if((listLocation >= 0 || listLocation < adtArray->size) \
                          ||(listLocation == 0 && locCode != AFTER_LOCATION))
                {  
                  
                  // check for after_location && array size is not 0 
                  if(locCode == AFTER_LOCATION && adtArray->size > 0)
                   {
                     // increment listlocation
                     listLocation++; 
                   }
               // check for not at location
                  if(locCode != AT_LOCATION)
                   {
                     // loop from size down to location
                     for(wkgPt = adtArray->size; wkgPt > listLocation; wkgPt--)
                       {
                         // assign value from one below to current
                           // function: deepCopyElement
                         deepCopyElement(&adtArray->array[wkgPt], 
                                                 adtArray->array[wkgPt - 1]);  
                       }
                   // increment the size
                     adtArray->size++;
                   }
                
              // assign data 
                 // assign the name
                   // function: strcpy
                strcpy(adtArray->array[listLocation].name, name);
                 // assign the gender
                adtArray->array[listLocation].gender = gender;
                 // assign the studentId
                adtArray->array[listLocation].studentId = studentId;
                 // assign the gpa
                adtArray->array[listLocation].gpa = gpa;

              // return true
              return true;
             }
             // otherwise return false
             return false;
           
    }    
    
bool insertArrayRawDataAfterLocation( StudentArrayType *adtArray,
              const char *name, char gender, int studentId,
                                                 double gpa, int listLocation )
   {
    // return the insertArrayRawDataEngine at locCode = 2
      return insertArrayRawDataEngine(adtArray, name, gender, studentId, gpa,
                                                 listLocation, AFTER_LOCATION);
   }
      

bool insertArrayRawDataBeforeLocation( StudentArrayType *adtArray, const char *name,
                     char gender, int studentId, double gpa, int listLocation )
   {
     // return insertRawDataEngine at locCode = 0
      return insertArrayRawDataEngine(adtArray, name, gender, studentId, gpa,
                                              listLocation, BEFORE_LOCATION);
   }

bool removeArrayDataAtLocation( StudentDataType *removedElement,
                                  StudentArrayType *adtArray, int removeIndex )
   {
    // initialize variables
     int newIndex;
     // if index in bounds
     if(removeIndex >= 0 && removeIndex < adtArray->size)
      {
        // save variable at remove index
          // function: deepCopyElement
        deepCopyElement(removedElement, adtArray->array[removeIndex]);
        
        // loop through array starting from remove index to end - 1
        for(newIndex = removeIndex; newIndex < adtArray->size - 1; newIndex++)
          { 
              // move next element into current element
               // function: deepCopyElement
              deepCopyElement(&adtArray->array[newIndex],
                                               adtArray->array[newIndex + 1]);
          }
          // decrease size
          adtArray->size = adtArray->size - 1;

        // return true
        return true;
      }
      // set removedElement to 0
        // function: setEmptyElementData
      setEmptyElementData(removedElement);
      // return false
      return false;
   }

bool setArrayAdtDataAtLocation( StudentArrayType *adtArray,
                              const StudentDataType student, int listLocation )
   {
    // return insertArrayRawDataEngine at locCode = 0
     return insertArrayRawDataEngine(adtArray, student.name, student.gender, 
                   student.studentId, student.gpa,listLocation, AT_LOCATION);
   }

bool setArrayRawDataAtLocation( StudentArrayType *adtArray, const char *name,
                     char gender, int studentId, double gpa, int listLocation )
   {
       // return insertArrayRawDataEngine at locCode = 0
     return insertArrayRawDataEngine(adtArray, name, gender, studentId, gpa,
                                                   listLocation, AT_LOCATION);
   }


void setEmptyElementData( StudentDataType *element )
   {
     // set the name to null
     *element->name = NULL_CHAR;
     // set gender to X
     element->gender = 'X';
     // set studentId to 0
     element->studentId = 0;
     // set gpa to 0
     element->gpa = 0;
   }
