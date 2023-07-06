// header files
#include "StudentUtilities.h"

// local constant definitions
const char SEMI_COLON = ';';

bool addElementWithData( StudentDataType array[], int *size, int capacity,
                     const char *name, char gender, int studentId, double gpa )
   {
       // test if array is at capacity
       if(*size < capacity)
        {
          // if capacity isn't reached, then add data to array

          // add the name to array
           // function: strcpy
          strcpy(array[*size].name, name);
         // add the gender to array
          array[*size].gender = gender;
         // add the student id to array
          array[*size].studentId = studentId;
         // add the gpa to the array
          array[*size].gpa = gpa;
          // increment the size
          *size = *size + 1;
          // return true
          return true;
        }
       // otherwise return false
       return false;
   }

bool addElementFromElement( StudentDataType array[],
                          int *size, int capacity, const StudentDataType student )
   {
     // return the boolean result addElementWithData function
     return addElementWithData(array, size, capacity, student.name, \
                         student.gender, student.studentId, student.gpa );

   }
void copyArray( StudentDataType dest[], const StudentDataType src[], int size )
   {
      // initialize variables
      int index;
      // loop through Array
      for(index = 0; index < size; index++)
        {
          // copy each individual element from src and store in dest
            // function: deepCopy
          deepCopy(&dest[index], src[index]);
        }

   }
void deepCopy( StudentDataType *dest, const StudentDataType src )
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
void displayData( const StudentDataType array[],
                                                  int size, const char *subTitle )
   {
       // initialize variables
       int showIndex;
       // test to see if array is empty
       if(size == 0)
        {
           // if it is, display error message
            // function: printf
           printf("Data not found - Display aborted\n");
        }
        else
        {
           // otherwise display title
             // function printf
           printf("\nDisplay Data - %s\n", subTitle);
          // loop through the array
          for(showIndex = 0; showIndex < size; showIndex++)
            {
              // print the array using printf
              printf("[ %d ]: %s, %c, %d,  %0.5f\n", showIndex, \
                   array[showIndex].name, array[showIndex].gender, \
                       array[showIndex].studentId, array[showIndex].gpa );
            }
        }




   }
bool findElement( StudentDataType *foundElement,
      const StudentDataType array[], int size, const StudentDataType searchValue )
   {
     // initialize variables
     int newIndex;
     // loop through array
     for(newIndex = 0; newIndex < size; newIndex++)
      {
        // test to see if searchValue is found
          // function: strcmp
        if(strcmp(array[newIndex].name, searchValue.name) == 0)
         {
           // if so, copy elements
             // function: deepCopy
           deepCopy(foundElement, array[newIndex]);
           // return true
           return true;
         }
         else
          {
            // set foundElement to zero
              // function: setEmptyElementData
            setEmptyElementData(foundElement);
          }
        // end loop
      }
      // otherwise return false
      return false;
   }
void getFileName( char *fileName )
   {
     // prompt user for file name
       // function: printf
       printf("Enter file name: ");

     // store in variable
       // function: scanf
       scanf("%s", fileName);


   }
bool removeElement( StudentDataType *removedElement,
             StudentDataType array[], int *size, const StudentDataType searchVal )
  {
     // initialize variables
     int index, updatedIndex;
     // loop through the array
     for(index = 0; index < *size; index++)
       {
         // tests if element is the search value
           // function: strcmp
         if(strcmp(array[index].name, searchVal.name) == 0)
           {
             // if found, store the element to removeElement
               // function: deepCopy
             deepCopy(removedElement, array[index]);
             // shift all data down by decrementing the size
             *size = *size - 1;
             // loop through the updated array
             for(updatedIndex = index; updatedIndex < *size; updatedIndex++)
               {
                 // copy updated array to the dest array
                 // function: deepCopy
                 deepCopy(&array[updatedIndex], array[updatedIndex + 1]);
               }
             // return true
             return true;
           }
           else
           {
             // set removedElement to zero
              // function: setEmptyElementData
             setEmptyElementData(removedElement);
           }
        // end loop
       }
       // return false
       return false;
  }
void runBubbleSort( StudentDataType array[], int size )
   {
      // initialize variables
      int inner, outer;
      // loop through the array
      for(outer = 0; outer < size - 1; outer++)
       {
         // loop to compare each element
         for(inner = 0; inner < size - 1; inner++)
           {
             // test to see if element is bigger than the last element
              // function: strcmp
             if(strcmp(array[inner].name, array[inner + 1].name) > 0)
              {
                // switch the two elements if true
                  // function: swapElements
                swapElements(array, inner, (inner + 1));
              }
            // end second loop
           }
        // end first loop
       }

   }
void runInsertionSort( StudentDataType array[], int size )
   {
     // initialize variables
   int key, newData = 1;
   StudentDataType temp;
   // loop through the Array
   while(newData < size)
    {
      // store the array element to the temp
       // function: deepCopy
      deepCopy(&temp, array[newData]);
      // assign a key to compare
      key = newData;
      // while the key is smaller than element and larger than zero
       // function: strcmp
      while(key > 0 && strcmp(temp.name, array[key - 1].name) < 0)
       {
         // next element overwrites current elements
           // function: deepCopy
         deepCopy(&array[key], array[key - 1]);
         // decrememt the key
         key--;
       }
      // store the temp in the array
       // function: deepCopy
       array[key] = temp;
       //deepCopy(&array[key], temp);
      // increment the index
       newData++;
   }

   }
void runSelectionSort( StudentDataType array[], int size )
   {
     // initialize variables
     int minVal, numVals, nextVal;
     // loop through the elements
     for(numVals = 0; numVals < size - 1; numVals++)
      {
        // set first element as minimum
        minVal = numVals;
        // loop from next element to compare with current element
        for(nextVal = numVals + 1; nextVal < size; nextVal++)
          {
            // test to see if minimum is less than current elements
              // function: strcmp
            if(strcmp(array[minVal].name, array[nextVal].name) > 0)
             {
               // set current element as minimum if true
               minVal = nextVal;
               // end test
             }
          }
        // swap the elements
         // function: swapElements
       swapElements(array, numVals, minVal);
      }
   }
void setEmptyElementData( StudentDataType *element )
   {
     // set the name to null
     element->name[0] = NULL_CHAR;
     // set gender to X
     element->gender = 'X';
     // set studentId to 0
     element->studentId = 0;
     // set gpa to 0
     element->gpa = 0;

   }
void showTitle()
   {
     // print the title
       // function: printf
      printf("Data Management with N-Squared Sorting\n");
      printf("======================================\n");
   }
void swapElements( StudentDataType array[], int leftIndex, int rightIndex )
   {
         // initialize variables
         StudentDataType temp;
         // left element is stored in a temp
         temp = array[leftIndex];
         // left element is swapped with right element
           // function: deepCopy
         deepCopy(&array[leftIndex], array[rightIndex] );
         // right element is stored in temp
         array[rightIndex] = temp;

   }
int uploadStudentData( StudentDataType studentDataArray[],
                                            int capacity, const char *fileName )
   {
    char inputName[ STD_STR_LEN ];
    int inputStudentId, size = 0;
    char inputGender;
    double inputGpa;
    bool notFull = true;

    if( openInputFile( fileName ) )
       {
        // read prime
        readStringToDelimiterFromFile( SEMI_COLON, inputName );

        while( !checkForEndOfInputFile() && notFull )
           {
            inputStudentId = readIntegerFromFile();
            readCharacterFromFile();

            inputGender = readCharacterFromFile();
            readCharacterFromFile();

            inputGpa = readDoubleFromFile();

            notFull = addElementWithData( studentDataArray, &size, capacity,
                             inputName, inputGender, inputStudentId, inputGpa );
            // read re-prime
            readStringToDelimiterFromFile( SEMI_COLON, inputName );
           }


        closeInputFile();
       }

    return size;
   }
