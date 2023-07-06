// header files
#include "StandardConstants.h"
#include "Console_IO_Utility.h"
#include "File_Input_Utility.h"
#include "File_Output_Utility.h"
#include "Arizona_Tax_Utility.h"



// constants
    // none 

// function prototypes
 // make sure to assign types to the output type

   // function: createOutputString
      // create pointers to output string

char createOutputString(char *output, int years, double totalAzTax);

   // function: outputResultsToFile
     // create pointer to the user input and the output string

void outputResultsToFile( const char *user, const char *output); 



// main program
int main()
    {
       
      // initialize variables
         
       
       double totalAzTax, income;
       int years, counting;
       
      // set years to 0
       years = 0;  
       
      // print title
        // the title will be printed with an endline, string, 
        // endline, then the dashed line, and then finishing off with endlines
          // functions: printEndline, printEndlines, printString
  
       printEndline();
       printString( "Dummy tax calculator V0.4" );
       printEndline();
       printString( "============================ " );
       printEndlines(2);

     
     // get input 
       // store input in array with the minimum string length
       // prompt the user for string which will also store answer in the array
         // constants: MIN_STR_LEN
         // functions: promptForString

        char user[MIN_STR_LEN];
        promptForString("Enter file name containing income information: "
                                                                ,user);
        printEndline();
        
       

     // open and check on file
       // open and check file with one function
       // if loop to start off
         // functions: if-loop, openInputFile

       if (openInputFile(user))
         {  
           // initialize years and income variable
           // create a counter
           // prime the loop by the year input, which is defined 
           // by reading integer
             // functions: readIntegerFromFile
 
            counting = 0;

           // iterate through file and read data
           // by checking if it reaches end of file
             // a while loop is needed here
               // functions: checkForEndOfInputFile, while loop
           
            while (!checkForEndOfInputFile())
                 {
                     // capture year and income value
                     // by defining their variables by the read 
                     // Integer function and read Double function
                       // so that way each time, they're being stored
                       // to that variable
                     // functions: readIntegerFromFile, readDoubleFromFile

                      years = readIntegerFromFile();
                      income = readDoubleFromFile();

                     // count the years

                        counting++;

                    // call calculate AZ tax function and assign to variable
                      // that way it is stored properly and implicitly declared
                    // functions: calculateArizonaTax( income )
                      
                      totalAzTax = calculateArizonaTax( income );
                    
                        years++;

                 
                    // create output string outside of loop
                      // initialize array
                      char output[MAX_STR_LEN];

 
                      // call output string function that creates string 
                        // with the output string, years, and the tax
                      // functions: createOutputString

                      createOutputString(output, years, totalAzTax);

                    // call results function that prints the output string
                      // to a file
                    // functions: outputResultsToFile

                      outputResultsToFile(user, output);


                   // reprime loop for year so that the loop can reach whole file
                     // functions: readIntegerFromFile

                      years = readIntegerFromFile();
                    
                  // print strings that demonstrate some kind of action
                  // has been done to the data
                    // functions: printf, printString, printEndline, printEndlines
                }
                

                   printf("Arizona Tax for %d years has been calculated."
                                                            ,counting);
                   printEndlines(2);
                   printString("The results can be viewed in the report files.");
                   printEndlines(2);
                   
                
                   }
                 else
                  {
                     // if file won't open, then tell user that it won't open
                       // functions: printf
                      printf("Sorry, file won't open");
                  }

              // end program
                // tell user that program ended successfully and return 0
                  // functions: printString

                 printString("Program End");
                 return 0;
           }


// supporting functions

/*
Name: createOutputString
Process: creates string to be displayed and output to file;
         only one string can be assembled in the function
Function input/parameters:  the output string pointer, tax year and income
Function output/parameters: the generated output string (char *)
Function output/returned: none
Function input/keyboard: none
Device output/file: none
Dependencies: sprintf
*/

char createOutputString(char *output, int years, double totalAzTax)
    {
       // initialize variable that will hold string
       

       // assign variable to the string that will printed
        // print the numbers through include types and variables 
        // that go with type
          // realized that sprintf is dependency
        // functions: sprintf

       sprintf(output,
                       "For the tax year %d total AZ tax to be payed is %.2f $"
                                                    ,years,totalAzTax);
       
  return 1;       
    }

/*
Name: outputResultsToFile
Process: opens file for output, writes string to file with endline,
         closes file
Function input/parameters: file name (const char *), 
                           output string (const char *)
Function output/parameters: none
Function output/returned: none
Function input/keyboard: none
Device output/file: none
Dependencies: File Output Utility tools
*/
void outputResultsToFile( const char *user, const char *output )
    {
       // use openOutputFile function to successfully open file
         // functions: openOutputFile

         openOutputFile( user );
         // write the output to a string in a file
           // functions: writeStringToFile

         writeStringToFile( output );
         writeEndlineToFile();

        // close file successfully
          // functions: closeOutputFile

         closeOutputFile();
    }
