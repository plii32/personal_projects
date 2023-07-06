#ifndef STUDENT_UTILITIES_H
#define STUDENT_UTILITIES_H

// header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "File_Input_Utility.h"
#include "StandardConstants.h"

// data structures
typedef struct StudentDataStruct
   {
    char name[ STD_STR_LEN ];

    char gender;

    int studentId;

    double gpa;
   } StudentDataType;

typedef struct StudentArrayStruct
   {
    StudentDataType *array;

    int size;

    int capacity;
   } StudentArrayType;

// Prototypes

/*
Name: addElementWithData
Process: adds all individual data values to the StudentArrayType ADT,
         always checks for resize prior to adding the value
Function input/parameters: pointer to data array type (StudentArrayType *),
                           student name (const char *),
                           student gender (char),
                           student ID (int),
                           student gpa (double)
Function output/parameters: updated pointer to data array (StudentArrayType *)
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: checkForResize, strcpy
*/
void addElementWithData( StudentArrayType *adtArray, const char *name, 
                                       char gender, int studentId, double gpa );

/*
Name: addElementFromElement
Process: adds data from element to the StudentArrayType ADT,
         uses supporting function
Function input/parameters: pointer to data array type (StudentArrayType *), 
                           size and capacity (int),
                           source element (const StudentDataType)
Function output/parameters: pointer to updated array type (StudentArrayType *)
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: addElementWithData - function uses one code statement
*/
void addElementFromElement( StudentArrayType *adtArray, 
                                                const StudentDataType student );

/*
Name: checkForResize
Process: checks if array needs to be resized, 
         resizes (increases capacity of) array to double capacity
Function input/parameters: pointer to student array ADT (StudentArrayType *)
Function output/parameters: updated pointer 
                            to student array ADT (StudentArrayType *)
                            if resize has taken place, 
                            otherwise ADT is unchanged
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: malloc, sizeof (C keyword), deepCopy, free
*/
void checkForResize( StudentArrayType *adtArray );

/*
Name: clearStudentArrayType
Process: returns allocated memory for both StudentArrayType ADT
         and encapsulated StudentDataType back to operating system,
         returns NULL to calling function
Function input/parameters: pointer to student array ADT (StudentArrayType *)
Function output/parameters: none
Function output/returned: NULL
Device input/---: none
Device output/---: none
Dependencies: free
*/
StudentArrayType *clearStudentArrayType( StudentArrayType *arrayPtr );

/*
Name: copyArrayType
Process: copies elements from one StudentArrayType ADT to another,
         resets array size as needed,
         also resets array capacity as needed if destination array type
         capacity is less than capacity of source StudentArrayType ADT
Function input/parameters: source array type(const StudentArrayType)
Function output/parameters: pointer to destination array type 
                                                            (StudentArrayType *)
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: checkForResize, deepCopy
*/
void copyArrayType( StudentArrayType *dest, const StudentArrayType src );

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
Function input/parameters: student array type (const StudentArrayType),
                           subtitle (const char *)
Function output/parameters: none
Function output/returned: none
Device input/---: none
Device output/monitor: data displayed as specified
Dependencies: printf
*/
void displayData( const StudentArrayType adtArray, const char *subTitle );

/*
Name: findElement
Process: finds element value in StudentArrayType ADT if it is there,
         saves data in parameter value and returns true,
         otherwise sets data in parameter to empty and returns false
Function input/parameters: student array type (const StudentArrayType),
                           search value (const StudentDataType)
Function output/parameters: value if found, 
                            otherwise, value set to empty (StudentDataType *)
Function output/returned: Boolean result of operation
Device input/---: none
Device output/---: none
Dependencies: strcmp, deepCopy, setEmptyElementData
*/
bool findElement( StudentDataType *foundElement, 
           const StudentArrayType adtArray, const StudentDataType searchValue );

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
Name: initializeStudentArrayType
Process: dynamically creates StudentArrayType ADT instance
         along with dynamically allocating the array within it
Function input/parameters: given initial capacity (int)
Function output/parameters: none
Function output/returned: pointer to student type array (StudentArrayType *)
Device input/---: none
Device output/---: none
Dependencies: malloc, sizeof (C keyword)
*/
StudentArrayType *initializeStudentArrayType( int initialCapacity );

/*
Name: removeElement
Process: searches for element, if found, sets data into parameter value,
         shifts all remaining elements down, and returns true,
         otherwise sets data in parameter to empty and returns false
Function input/parameters: pointer to student array type (StudentArrayType *),
                           search value (const StudentDataType)
Function output/parameters: updated pointer to student array type 
                            (StudentArrayType *),
                            value if found and removed, 
                            otherwise, value set to empty (StudentDataType *)
Function output/returned: Boolean result of operation as specified
Device input/---: none
Device output/---: none
Dependencies: strcmp, deepCopy, setEmptyElementData
*/
bool removeElement( StudentDataType *removedElement, 
                  StudentArrayType *adtArray, const StudentDataType searchVal );

/*
Name: runMerge
Process: merges StudentArrayType ADT subsets brought in between a low, middle, 
         and high index segment of the StudentArrayType ADT,
         must dynamically create (and release) one internal array
         must use three array transfer loops
Function input/parameters: pointer to student array type (StudentArrayType *), 
                           low index, middle index, high index (int)                           
Function output/parameters: pointer to updated student array type
                                                            (StudentArrayType *)
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: malloc, sizeof (C keyword), deepCopy, free
*/
void runMerge( StudentArrayType *adtArray, 
                                 int lowIndex, int middleIndex, int highIndex );

/*
Name: runMergeSort
Process: sorts StudentArrayType ADT using merge sort algorithm,
         calls helper function with appropriate indices
Function input/parameters: pointer to student array type (StudentArrayType *)
Function output/parameters: pointer to updated student array type 
                                                            (StudentArrayType *)
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: runMergeSortHelper
*/
void runMergeSort( StudentArrayType *adtArray );

/*
Name: runMergeSortHelper
Process: recursively breaks given StudentArrayType ADT segments down 
         to smaller segments between lowIndex and highIndex (inclusive),
         then sorts data using merge operation for segments created
Function input/parameters: pointer to student array type (StudentArrayType *), 
                           low & high inclusive indices (int)
Function output/parameters: pointer to updated student array type 
                                                            (StudentArrayType *)
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: runMergeSortHelper (recursively), runMerge
*/
void runMergeSortHelper( StudentArrayType *adtArray, 
                                                  int lowIndex, int highIndex );

/*
Name: runPartition
Process: partitions StudentArrayType ADT 
         must use the first value as the partition value;
         when this function is complete the partition value is
         in the correct location in the array;
         main loop must iterate from left to right
Function input/parameters: pointer to student array type (StudentArrayType *)
Function output/parameters: pointer to updated student array type 
                                                            (StudentArrayType *)
Function output/returned: partition value index within array
Device input/---: none
Device output/---: none
Dependencies: strcmp, swapElements
*/
int runPartition( StudentArrayType *adtArray, int lowIndex, int highIndex );

/*
Name: runQuickSort
Process: sorts StudentArrayType ADT using quick sort algorithm,
         calls helper with appropriate indices to implement sort
Function input/parameters: pointer to student array type (StudentArrayType *)
Function output/parameters: pointer to updated student array type 
                                                            (StudentArrayType *)
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: runQuickSortHelper
*/
void runQuickSort( StudentArrayType *adtArray );
      
/*
Name: runQuickSortHelper
Process: helper function run with parameters that partition arrays
         on a given (first) element of an array segment,
         then recursively sort left and right sides of given partition value
Function input/parameters: pointer to student array type (StudentArrayType *) 
         low & high inclusive indices (int)
Function output/parameters: pointer to updated student array type 
                                                            (StudentArrayType *)
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: runPartition, runQuickSortHelper (recursively)
*/
void runQuickSortHelper( StudentArrayType *adtArray, 
                                                  int lowIndex, int highIndex );

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
         "Data Management with Log2N Sorting"
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
Process: swaps elements within a StudentArrayType ADT array
Function input/parameters: left and right indices to be swapped
Function output/parameters: updated array with swapped values 
                                                            (StudentArrayType *)
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: deepCopy
*/
void swapElements( StudentArrayType *adtArray, int leftIndex, int rightIndex );

/*
Name: uploadStudentData
Process: uploads data from given file to StudentArrayType ADT,
         returns true if succesful upload, false otherwise
Function input/parameters: file name (const char *)
Function output/parameters: StudentArrayType ADT with uploaded values 
                                                            (StudentArrayType *)
Function output/returned: Boolean result of operation as specified
Device input/---: none
Device output/---: none
Dependencies: openInputFile, readStringToDelimiterFromFile,
              checkForEndOfInputFile, readIntegerFromFile, 
              readCharacterFromFile, readDoubleFromFile,
              addElementWithData, closeInputFile
*/
bool uploadStudentData( StudentArrayType *adtArray, const char *fileName );

#endif   // STUDENT_UTILITIES_H
