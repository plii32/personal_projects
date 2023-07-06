#ifndef STUDENT_UTILITIES_H
#define STUDENT_UTILITIES_H

// header files
#include <stdio.h>
#include <string.h>
#include "File_Input_Utility.h"
#include "StandardConstants.h"

// data structure
typedef struct StudentDataStruct
   {
    char name[ STD_STR_LEN ];

    char gender;

    int studentId;

    double gpa;
   } StudentDataType;

// Prototypes

/*
Name: addElementWithData
Process: adds all individual data values to StudentDataType array 
         if capacity has not been exceeded,
         returns true upon success, false otherwise
Function input/parameters: data array (StudentDataType []), 
                           size and capacity (int),
                           student name (const char *),
                           student gender (char),
                           student ID (int),
                           student gpa (double)
Function output/parameters: updated data array (StudentDataType []),
                            updated size (int *)
Function output/returned: Boolean result of operation as specified
Device input/---: none
Device output/---: none
Dependencies: strcpy
*/
bool addElementWithData( StudentDataType array[], int *size, int capacity,
                     const char *name, char gender, int studentId, double gpa );

/*
Name: addElementFromElement
Process: adds data from element to StudentDataType array,
         uses supporting function 
Function input/parameters: data array (StudentDataType []), 
                           size and capacity (int),
                           source element (const StudentDataType)
Function output/parameters: updated data array (StudentDataType []),
                            updated size (int *)
Function output/returned: Boolean result of operation as specified
Device input/---: none
Device output/---: none
Dependencies: addElementWithData - function uses one code statement
*/
bool addElementFromElement( StudentDataType array[], 
                       int *size, int capacity, const StudentDataType student );

/*
Name: copyArray
Process: copies elements from one array to another
Function input/parameters: source array (const StudentDataType []), size (int)
Function output/parameters: destination array (StudentDataType)
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: deepCopy
*/
void copyArray( StudentDataType dest[], const StudentDataType src[], int size );

/*
Name: deepCopy
Process: copies all individual values from StudentDataType source
Function input/parameters: source element (const StudentDataType)
Function output/parameters: pointer to destination value (StudentDataType *)
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: strcpy
*/
void deepCopy( StudentDataType *dest, const StudentDataType src );

/*
Name: displayData
Process: displays comma-delimited element data in array if array is not empty,
         otherwise displays "Data not found - Display aborted",
         allows for subtitle to be added to "Display Data - "
Function input/parameters: student data array (const StudentDataType []),
                           size (int), subtitle (const char *)
Function output/parameters: none
Function output/returned: none
Device input/---: none
Device output/monitor: data displayed as specified
Dependencies: printf
*/
void displayData( const StudentDataType array[], 
                                               int size, const char *subTitle );

/*
Name: findElement
Process: finds element value in array if it is there,
         saves data in parameter value and returns true,
         otherwise sets data in parameter to empty and returns false,
         must use name as the key
Function input/parameters: student data array (const StudentDataType []),
                           size (int), search value (const StudentDataType)
Function output/parameters: value if found, 
                            otherwise, value set to empty (StudentDataType *)
Function output/returned: Boolean result of operation
Device input/---: none
Device output/---: none
Dependencies: strcmp, deepCopy, setEmptyElementData
*/
bool findElement( StudentDataType *foundElement, 
   const StudentDataType array[], int size, const StudentDataType searchValue );

/*
Name: getFileName
Process: prompts user for file name, captures file name, 
         returns as parameter
Function input/parameters: none
Function output/parameters: captured file name (char *)
Function output/returned: none
Device input/keyboard: user data entry
Device output/monitor: user prompt as specified
Dependencies: printf, scanf
*/
void getFileName( char *fileName );

/*
Name: removeElement
Process: searches for element, if found, sets data into parameter value,
         shifts all remaining data down, and returns true,
         otherwise sets data in parameter to empty and returns false
Function input/parameters: student data array (StudentDataType []),
                           size (int), search value (const StudentDataType)
Function output/parameters: updated student data array (StudentDataType []),
                            value if found and removed, 
                            otherwise, value set to empty (StudentDataType *),
                            updated size (int *)
Function output/returned: Boolean result of operation as specified
Device input/---: none
Device output/---: none
Dependencies: strcmp, deepCopy, setEmptyElementData
*/
bool removeElement( StudentDataType *removedElement, 
          StudentDataType array[], int *size, const StudentDataType searchVal );

/*
Name: runBubbleSort
Process: sorts data using bubble sort algorithm
Function input/parameters: student data array (StudentDataType []), size (int)
Function output/parameters: updated student data array (StudentDataType [])
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: strcmp, swapElements
*/
void runBubbleSort( StudentDataType array[], int size );

/*
Name: runInsertionSort
Process: sorts data using insertion sort algorithm
Function input/parameters: student data array (StudentDataType []), size (int)
Function output/parameters: updated student data array (StudentDataType [])
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: deepCopy, strcmp
*/
void runInsertionSort( StudentDataType array[], int size );

/*
Name: runSelectionSort
Process: sorts data using selection sort algorithm
Function input/parameters: student data array (StudentDataType []), size (int)
Function output/parameters: updated student data array (StudentDataType [])
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: strcmp, swapElements
*/
void runSelectionSort( StudentDataType array[], int size );

/*
Name: setEmptyElementData
Process: sets student data type to empty or default values
Function input/parameters: none
Function output/parameters: student data value (StudentDataType *)
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: none
*/
void setEmptyElementData( StudentDataType *element );

/*
Name: showTitle
Process: displays program title with thick underline,
         "Data Management with N-Squared Sorting"
Function input/parameters: none
Function output/parameters: none
Function output/returned: none
Device input/---: none
Device output/monitor: displays title as specified
Dependencies: printf
*/
void showTitle();

/*
Name: swapElements
Process: swaps elements within an array
Function input/parameters: left and right indices to be swapped
Function output/parameters: updated array with swapped values 
                           (StudentDataType [])
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: deepCopy
*/
void swapElements( StudentDataType array[], int leftIndex, int rightIndex );

/*
Name: uploadStudentData
Process: uploads data from given file to student data array,
         returns number of items found;
         stops uploading process if array shows full
Function input/parameters: capacity (int) and file name (const char *)
Function output/parameters: updated array with uploaded values 
                           (StudentDataType [])
Function output/returned: number of items uploaded (int)
Device input/---: none
Device output/---: none
Dependencies: openInputFile, readStringToDelimiterFromFile,
              checkForEndOfInputFile, readIntegerFromFile, 
              readCharacterFromFile, readDoubleFromFile,
              addElementWithData, closeInputFile
*/
int uploadStudentData( StudentDataType studentDataArray[], 
                                           int capacity, const char *fileName );

#endif   // STUDENT_UTILITIES_H
