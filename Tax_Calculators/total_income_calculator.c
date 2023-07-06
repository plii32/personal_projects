// header file 
# include "Console_IO_Utility.h"
# include "File_Input_Utility.h"
# include "File_Output_Utility.h"
# include "StandardConstants.h"
# include <stdlib.h> 
# include <time.h>

// global constants
const int MIN_RAND_COUNT = 1;
const int MAX_RAND_COUNT = 10;
const int MIN_RAND_LIMIT = 1;
const int MAX_RAND_LIMIT = 100000;
const int VALUES_IN_ONE_LINE = 5;


// function prototypes

int calculateTotal(int arrayRand[], int arraySize);

void displayResults(int arraySize, int cal);

void downloadRandomValues(const char providedFile[], int minVal, int maxVal);

int getRandBetween(int minLimit, int maxLimit);

void printTitle();

int uploadData(const char *providedFile, int *arrayRand);


// main program
int main()
   {
      // initialize variables
          char providedFile[STD_STR_LEN];
          int arrayRand[MAX_RAND_COUNT], arraySize;
          int cal = 0;

          //seed the rand
          srand(time(NULL));

          
          
      // print title
        // functions: printTitle
          printTitle();

      // get input
        // functions: promptForString
         
         promptForString("Enter the file name for random data generation: ", providedFile);
         printEndline();
         
         
          
       
      // check if file exists and opens file at same time
        // functions: openInputFile, downloadRandomValues, closeInputFile

           if (!openInputFile(providedFile))
             {
               // if file doesn't exist, then create a file with random values
                 // functions: downloadRandomValues
               downloadRandomValues(providedFile, MIN_RAND_LIMIT, MAX_RAND_LIMIT);
             }
             else
             {  
                // if file exists then close the file
                  // function: closeInputFile

                  closeInputFile();
                            
            }
            // if file exists, use provided values from file to calculate sum
              // function: uploadData
              
             arraySize = uploadData(providedFile, arrayRand);
     
             // check if there is data in the file
             if(arraySize > 0)
               {
                // if there is data, calculate the sum
                 // function: calculateTotal

                 cal = calculateTotal(arrayRand, arraySize); 
                 
               }
            
           

        // display results and then print endline
          // functions: displayResults, printEndline

             displayResults(arraySize, cal);
             printEndline();

      // end program
        // function: printf

             printf("End Program");
             return 0;   
    }


// supporting functions
/*
Name: calculateTotal
Process: uses the array and counter to sum the array
Function input/parameters:  a counter, and the array
Function output/parameters: the sum of all the values in array
Function output/returned: none
Function input/keyboard: none
Device output/file: none
Dependencies: none
*/
int calculateTotal(int arrayRand[], int arraySize)
   {
      // initialize variables
     int sumArray, counting;

     // set the sum variable
     sumArray = 0;
     
     // if counter is less than the array size, add each integer to another
     for (counting = 0; counting < arraySize; counting++)
        {
           sumArray = sumArray + arrayRand[counting];
        }
      // return sum variable
      return sumArray;  
   }
/*
Name: displayResults
Process: creates two strings that display amount of incomes and total income
Function input/parameters:  arraySize, cal
Function output/parameters: the generated output string
Function output/returned: none
Function input/keyboard: none
Device output/file: none
Dependencies: printf, printEndline
*/
void displayResults(int arraySize, int cal)
    { 
      
      // if values are greater than zero, then display strings
       // functions: printf, printEndline
      if(arraySize > 0)
        {
          printf("Total Sources of income: %d", arraySize);
          printEndline();
          printf("Total income           : %d",  cal);
          printEndline();

        }
      else
       {
         // print error message if file can't be found
           // printf
         printf("\nERROR: Data file not found. Program aborted.\n");


       }
       
   }

/*
Name: downloadRandomValues
Process: finds random number between minimum value and maximum value and opens
         input file, where a number of random integers are generated as comma 
         delimited values and then closes file
Function input/parameters:  the input file, minimum value and maximum value
Function output/parameters: none
Function output/returned: none
Function input/keyboard: none
Device output/file: none
Dependencies: openOutputFile, getRandBetween, readIntegerFromFile
*/
void downloadRandomValues(const char providedFile[], int minVal, int maxVal)
    {   
        // initialize variables
         int gogo, count, val;
         
         // priming get rand between min and max value
           // function: getRandBetween
         gogo = getRandBetween(MIN_RAND_COUNT, MAX_RAND_COUNT);

         // open an output file and check if successful
         if(openOutputFile(providedFile))
           {
            // for every value that's generated, increment count
            // then generate next number until count is greater than value
              for(count = 0; count < gogo; count++)
               {
                // generate next value
                 // function: getRandBetween

                 val = getRandBetween(minVal, maxVal);

                // check if file needs comma
                 // function: writeCharactersToFile
                 if(count > 0)
                  {
          
                    writeCharactersToFile(1, COMMA);
                    writeCharactersToFile(1, SPACE);
                  }
                  // check if file needs endline
                   // functions: writeEndlineToFile
                 if (count > 0 && count % VALUES_IN_ONE_LINE == 0)
                   {
                     
                     writeEndlineToFile();

                   }
                  // write the next integer to file
                   // function: writeIntegerToFile
                 writeIntegerToFile(val);
                 
               }
            
           }
           //close output file
         closeOutputFile();
      }

/*
Name: getRandBetween
Process: gets random number between two specific values
Function input/parameters: minimum value and maximum value
Function output/parameters: randomized value
Function output/returned: none
Function input/keyboard: none
Device output/file: none
Dependencies: rand()
*/
int getRandBetween(int minLimit, int maxLimit)
   {
       
      // return the random value with formula given in lab
        // function: rand()
       return (rand() % (maxLimit-minLimit)+1) + minLimit;
       
   }
/*
Name: printTitle
Process: prints title of program
Function input/parameters:  none
Function output/parameters: none
Function output/returned: none
Function input/keyboard: none
Device output/file: none
Dependencies: printString, printEndline
*/
void printTitle() 
   {
      // print title
        // functions: printString, printEndline
          printString("Total Income From File Calculator");
          printEndline();
          printString("=================================");
          printEndline();


   }
/*
Name: uploadData
Process: opens input file, reads file and then uploads contents to array
         closes file and then returns amount of values
Function input/parameters: input file, arrayRand
Function output/parameters: none
Function output/returned: counter variable
Function input/keyboard: none
Device output/file: none
Dependencies: openInputFile, checkForEndOfInputFile, readCharacterFromFile
              readIntegerFromFile, closeInputFile
*/
int uploadData(const char *providedFile, int *arrayRand)
   {
      //create two counters, one for the integer, and one for commas
      int count = 0;
      int numcount = 0;
      
      
      // open input file
       // function: openInputFile
         if(openInputFile(providedFile))
           {
            // for each integer, assign to index
             arrayRand[count] = readIntegerFromFile();

            // increment the counters
             count++;
             numcount++;

            // read the character(comma)
             readCharacterFromFile();

             // loop through file
             while(!checkForEndOfInputFile())
               {
                // assign the next read integer to index in the array
                  // readIntegerFromFile
                  arrayRand[count] = readIntegerFromFile();

                  // increment the counters
                  count++;
                  numcount++;

                  // read the next comma
                   // function: readCharacterFromFile

                  readCharacterFromFile();  
                  
               }
              
           }
       // close input file and return number of integers in array
         // function: closeInputFile
      closeInputFile();
      return numcount;
   }