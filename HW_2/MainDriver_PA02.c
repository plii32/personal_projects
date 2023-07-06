// header file
#include "StudentUtilities.h"

// local constants for program
const int MAX_NUM_STUDENTS = 60;

int main()
   {
    // initialize function/program

       // initialize variables
       int searchIndex, numStudentsOrig, numStudentsRmvd;
       int capacity = MAX_NUM_STUDENTS;
       char fileName[ STD_STR_LEN ];
       StudentDataType originalArray[ MAX_NUM_STUDENTS ];
       StudentDataType originalWithRemoved[ MAX_NUM_STUDENTS ];
       StudentDataType bubbleSortArray[ MAX_NUM_STUDENTS ];
       StudentDataType insertionSortArray[ MAX_NUM_STUDENTS ];
       StudentDataType selectionSortArray[ MAX_NUM_STUDENTS ];
       StudentDataType tempElement;

       // show title
          // function: showTitle
       showTitle();

    // get input

       // get file name
          // function: getFileName
       getFileName( fileName );
       
       // upload student data
          // function: uploadStudentData
       numStudentsOrig = uploadStudentData( originalArray, capacity, fileName );

    // process data

       // display original list

       // find element
       searchIndex = 35;
       findElement( &tempElement, originalArray, 
                                    numStudentsOrig, originalArray[ searchIndex ] );
       printf( "Element found: %s, %c, %d, %10.5f\n", tempElement.name, 
                                                      tempElement.gender, 
                                                      tempElement.studentId, 
                                                      tempElement.gpa );

       // remove element
       searchIndex = 20;
       numStudentsRmvd = numStudentsOrig;
       copyArray( originalWithRemoved, originalArray, numStudentsOrig );
       removeElement( &tempElement, originalWithRemoved, 
                                    &numStudentsRmvd, originalArray[ searchIndex ] );

       printf( "Element removed: %s, %c, %d, %10.5f\n", tempElement.name, 
                                                        tempElement.gender, 
                                                        tempElement.studentId, 
                                                        tempElement.gpa );

       
       // bubble sort
          // function: copyArray, runBubbleSort
       copyArray( bubbleSortArray, originalArray, numStudentsOrig );
       runBubbleSort( bubbleSortArray, numStudentsOrig );
       
       // insertion sort
          // function: copyArray, runInsertionSort
       copyArray( insertionSortArray, originalArray, numStudentsOrig );
       runInsertionSort( insertionSortArray, numStudentsOrig );

       // selection sort
          // function: copyArray, runSelectionSort
       copyArray( selectionSortArray, originalArray, numStudentsOrig );
       runSelectionSort( selectionSortArray, numStudentsOrig );

    // display results

       // display original list
          // function: displayData
       displayData( originalArray, numStudentsOrig, "Original Array" );

       // display original list with removed item
          // function: displayData
       displayData( originalWithRemoved, 
                               numStudentsRmvd, "Array with one item removed" );

       // display bubble sorted data
          // function: displayData
       displayData( bubbleSortArray, numStudentsOrig, "Bubble Sort Result" );

       // display insertion sorted data
          // function: displayData
       displayData( insertionSortArray, 
                                     numStudentsOrig, "Insertion Sort Result" );

       // display selection sorted data
          // function: displayData
       displayData( selectionSortArray, 
                                     numStudentsOrig, "Selection Sort Result" );

    // end program

       // report end program
          // function: printf
       printf( "\nProgram End\n" );

       // return program success
       return 0;
   }


