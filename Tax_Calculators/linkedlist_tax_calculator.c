// header files
#include <stdio.h>
#include <stdlib.h>
#include "Console_IO_Utility.h"
#include "File_Output_Utility.h"
#include "File_Input_Utility.h"

// global constants
    // enumerator for column indexes
enum TableColumns { COLUMN_A, COLUMN_B, COLUMN_C, COLUMN_D, COLUMN_E };
    // enumarator for filing type
enum FilingFlag { MARRIED, SINGLE, NONE };
    // conversion into percent rate
const double PERCENT_CONVERSION = 0.01;
    // tax table properties
const char TAX_TABLE_R_COUNT = 4;
const char TAX_TABLE_C_COUNT = 5;
    // on demand data files
const char MARRIED_TAX_DATA[] = "married.csv";
const char SINGLE_TAX_DATA[] =  "single.csv";
const int TAX_DATA_TITLE_SIZE = 60;
    // output table columns size
const int OUT_TABLE_COLUMN_SIZE = 15;

// A linked list node
typedef struct Node
   { 
     int money;
     struct Node *next; 
     

   } singleLinkNode;

// function prototypes
double calculateTax(double taxArray[TAX_TABLE_R_COUNT][TAX_TABLE_C_COUNT],
                                                           int userIncome);
int calculateTotal(singleLinkNode *Node);
void displayCorrectTable(double taxArray[TAX_TABLE_R_COUNT][TAX_TABLE_C_COUNT]);                                                        
void displayTaxTable(double taxArray[TAX_TABLE_R_COUNT][TAX_TABLE_C_COUNT],
                                                      int fileType);
int getTaxReturnType(); 
void printProgramTitle();
void skipOneRow();  
singleLinkNode *uploadDataIntoLL(const char* fileName);
void uploadTaxTable(const char* fileName, 
                    double taxArray[TAX_TABLE_R_COUNT][TAX_TABLE_C_COUNT]);                                                  

int main(int argc, char **argv)
   {
      // initialize variables
        double taxArray[TAX_TABLE_R_COUNT][TAX_TABLE_C_COUNT];
        int  taxType;
        char fileName[STD_STR_LEN];
        double totalTaxes, userIncome;
        singleLinkNode *newLink;

        // set the total taxes variable to zero
        totalTaxes = ZERO_VALUE;

      // show title
        // function: printProgramTitle, printEndline
         printProgramTitle();
         printEndline();

      // get input
        // ask for the file containing the data
          // function: promptForString
        promptForString("Provide file containing your income: ", fileName);

        // put data in linked list
        newLink = uploadDataIntoLL(fileName);

        // prompt user for marital status
        taxType = getTaxReturnType();
        printEndline();

        // calculate the total income 
        userIncome = calculateTotal(newLink);

        // based on input, determine appropriate tax display 
        // and calculate total taxes
        // if user doesn't put in an income greater than zero
        // then input is invalid
          // functions: uploadTaxTable, displayTaxTable, printf, calculateTax
        if(taxType == SINGLE)
          {
             uploadTaxTable(SINGLE_TAX_DATA, taxArray);
             displayTaxTable(taxArray, taxType);
             printf("\n\n");
             totalTaxes = calculateTax(taxArray, userIncome);

             if(totalTaxes > ZERO_VALUE)
               {
                  printf("Total Income Is: %0.2f", userIncome);
                  printEndline();
                  printf("Total Tax Is: %0.2f ", totalTaxes);
                  printEndline();
                  
      
               }
              else
               {
            
                 printf("Income you provided is invalid.\n\n");

               }

          }
        else if(taxType == MARRIED)
          {
            uploadTaxTable(MARRIED_TAX_DATA, taxArray);
            displayTaxTable(taxArray, taxType);
            printf("\n\n");
            totalTaxes = calculateTax(taxArray, userIncome);

            if(totalTaxes >= ZERO_VALUE)
               {
                  printf("Total Income Is: %0.2f", userIncome);
                  printEndline();
                  printf("Total Tax Is: %0.2f", totalTaxes);
                  printEndline();

               }
              else
               {
                 printf("Income you provided is invalid.\n\n");

               }
          }
        else
          {
             // if user doesn't put in either, program will stop
             printf("Program Aborted.");
   
          }
         

       printEndline();

      // end program
       // function: printf
        printf("End program");
        return 0;
    }

   


// supporting functions
/*
Name: calculateTax
Process: identifies correct tax bracket using tax data from array and income
         calculates tax using tax data from array as well as with
         formula presented below
         TT = ((TI + Col_C) * Col_D %) + Col_E
         , where
         TT - Total Tax
         TI - Total Income
         Col_C - COLUMN_C (same as maximum limit of previous tax bracket)
         Col_D - COLUMN_D (same as rate, must be converted into %)
         Col_E - COLUMN_E (same as max possible tax for all previous brackets)
         
Function Input/Parameters: tax data aray and total income
Function Output/Parameters: none
Function Output/Returned: total tax
Device Input/Keyboard: none
Device Output/Monitor: none
Dependencies: none
*/   
double calculateTax(double taxArray[TAX_TABLE_R_COUNT][TAX_TABLE_C_COUNT],
                                                           int userIncome)
   {
     // initialize variables
      double totalTax;
      double maxLimit, rate, maxTax;
      int rowSelect = ZERO_VALUE;
      double bracCheck = taxArray[rowSelect][COLUMN_B];

    // checks if the user's income fits within a bracket 
    // and stops after last row
     while(userIncome >= bracCheck && rowSelect < TAX_TABLE_R_COUNT - 1)
         {
           rowSelect++;
           bracCheck = taxArray[rowSelect][COLUMN_B];

         }
      // calculates the tax 
       // set the maximum limit of each bracket to column c
      maxLimit = taxArray[rowSelect][COLUMN_C];

       // converts the rates in column d to a decimal 
      rate = taxArray[rowSelect][COLUMN_D] * PERCENT_CONVERSION;
      
       // sets the max taxes possible of previous brackets to column e
      maxTax = taxArray[rowSelect][COLUMN_E];

       // uses the total tax formula but breaks it down into smaller parts
       // to make the calculation run smoother
      totalTax = maxLimit + userIncome;
      totalTax *= rate;
      totalTax += maxTax;

      return totalTax;
   }
                 
/*
Name: calculateTotal
Process: given header to linked lists, traverses list, accsses data (income)
         adds income to the total sum of incomes, returns total income
Function Input/Parameters: pointer to the head of income list
Function Output/Parameters: none
Function Output/Returned: total income 
Device Input/Keyboard:  none
Device Output/Monitor: none
Dependencies: none
*/
int calculateTotal(singleLinkNode *Node)
   {
     // inititalize variables
     double totalIncome;
     totalIncome = ZERO_VALUE;
     // while iterating through the linked list
     // sum the nodes together 
     // link to next node
     while(Node != NULL)
      {
        totalIncome += Node -> money;
        Node = Node -> next;
      }
      // return total income
     return totalIncome;
   }

/*
Name: displayCorrectTable
Process: displays tax data table
Function Input/Parameters: table containing tax data
Function Output/Parameters: none
Function Output/Returned: none
Device Input/Keyboard: none
Device Output/Monitor: iteratively prints table as shown in examples
Dependencies: printCharacter, printDoubleJustified, printf
*/                       
void displayCorrectTable(double taxArray[TAX_TABLE_R_COUNT][TAX_TABLE_C_COUNT])
    {
      // initialize variables
       int row, column;

          // skips the first row
            // function: skipOneRow
          skipOneRow();

          // iterates through the rows
          for(row = ZERO_VALUE; row < TAX_TABLE_R_COUNT; row++)
             {
               // primes the loop
                // function: printCharacter
                printCharacter( PIPE );
               
               // iterates through columns
               for(column = 0; column < TAX_TABLE_C_COUNT; column++)
                  {
                    // prints the double in that specific index
                     // function: printDoubleJustified
                     printDoubleJustified(taxArray[row][column], PRECISION, 
                                          OUT_TABLE_COLUMN_SIZE, "CENTER");

                    // prints the ending pipe
                     // function: printCharacter
                     printCharacter( PIPE );

                  }
                 printEndline();
              }    

         }


/*
Name: displayTaxTable
Process: based on filling type prints apropriate title for table
         and calls for table to be displayed
Function Input/Parameters: table containing tax data and filing type
Function Output/Parameters: none
Function Output/Returned: none
Device Input/Keyboard: none
Device Output/Monitor: title for table
Dependencies: displayCorrectTable, printf
*/   
void displayTaxTable(double taxArray[TAX_TABLE_R_COUNT][TAX_TABLE_C_COUNT],
                                                      int fileType)
    {
      // if the user is married, print the married title
      // if the user is single, print the single title
        // function: printf
       if ((fileType == MARRIED))
         {
           printf("Table 1. Filing as Married.\n");
           
         }
      else
         {
           printf("Table 1. Filing as Single.\n");
           
         }
         // display the table right after the title
         displayCorrectTable(taxArray);

    }

/*
Name: getTaxReturnType
Process: ask user for input and based on input assigns appropriate filing type
Function Input/Parameters: none
Function Output/Parameters: none
Function Output/Returned: returns filling type either SINGLE or MARRIED
Device Input/Keyboard: character either m/M/s/S
Device Output/Monitor: none
Dependencies: promptForCharacter
*/         
int getTaxReturnType()
   {
     // initialize variables
        int fileType, userStatus;

     // ask what the user's income is 
        // ask for the user's status
          // function: promptForCharacter, printEndline

        userStatus = promptForCharacter("Choose filing type(M/S)?: ");
        

       // if the input is a M or m, assume that the user is married
       // if the user puts in a S or s, assume that the user is single
       // otherwise assume the input is none and display error message
        if ((userStatus == 'M') | (userStatus == 'm'))
          {
             fileType = MARRIED;
             
          }
        else if ((userStatus == 'S') | (userStatus == 's'))
          {
             fileType = SINGLE;
             
          }
        else
          {
            
            fileType = NONE;
            printf("You provided wrong filing type.\n");

          }
      return fileType;
     
     }


/*
Name: printProgramTitle
Process: displays program title
Function Input/Parameters: none
Function Output/Parameters: none
Function Output/Returned: none
Device Input/Keyboard: none
Device Output/Monitor: title displayed as specified
Dependencies: Console IO Utilities tools OR stdio.h
*/
void printProgramTitle()
    {
       printString("Improved Arizona Tax Calculator");
       printEndline();
       printString("=================================");
       printEndline();

    }

/*
Name: skipOneRow
Process: skips one line of input file
Function Input/Parameters: none
Function Output/Parameters: none
Function Output/Returned: none
Device Input/Keyboard: none
Device Output/Monitor: none
Dependencies: readStringToDelimiterFromFile OR readStringToLineEndFromFile
*/              
void skipOneRow()
    {
      // create an array for the first line
       char firstLine[TAX_DATA_TITLE_SIZE];

       // read it as a new line
         // function: readStringToDelimiterFromFile
       readStringToDelimiterFromFile(NEWLINE_CHAR, firstLine);


    }   

/*
Name: uploadDataIntoLL
Process: opens file for input, uploads values and assigns them linked list,
         closes files, returns head pointer to the list
Function Input/Parameters: file name and 
Function Output/Parameters: none
Function Output/Returned: head pointer to the list
Device Input/Keyboard: none
Device Output/Monitor: none
Dependencies: malloc, sizeof, openInputFile, readIntegerFromFile, 
              checkForEndOfInputFile, readCharacterFromFile, closeInputFile
*/
singleLinkNode *uploadDataIntoLL(const char *fileName)
      {
        // initialize variables
          singleLinkNode *temp = NULL, *Node = NULL, *current = NULL;
        
        // create travel pointer and allocate memory for it
          current = (singleLinkNode *)malloc(sizeof(singleLinkNode));

        // open input file
          if(openInputFile(fileName))
           {
             // have the travel pointer point to the variable that holds data
             current->money  = readIntegerFromFile();

             // continue on to next node through the 'next'
             current->next = NULL;

             // have the head pointer equal the travelling pointer
             Node = current;
             
             // read the characters
               // functions: readCharacterFromFile
             readCharacterFromFile();

             // iterate through loop
               // functions: checkForEndOfInputFile
             while(!checkForEndOfInputFile())
                {
                  // assign the integer to the list
               
                  // create a temporary pointer
                  temp = (singleLinkNode *) malloc(sizeof(singleLinkNode));
                  // have the travelling pointer point to the next pointer
                   // have the next pointer equal the temporary pointer
                  current->next= temp;
                  // assign the temporary pointer to the variable 
                   // that holds the data
                  temp->money = readIntegerFromFile();
                  // continue on to next node through the 'next'
                  temp->next = NULL;
                  // assign the traveling pointer to the temporary pointer
                  current = temp;

                  // read the characters
                  readCharacterFromFile();
               
                }
           }
          // close the file
         closeInputFile();
        // return the new node
          return Node; 

      }

/*
Name: uploadTaxTable
Process: uploads table from file into 2d array
Function Input/Parameters: accepts name of the file which stores tax table
                           and reference to tax data array in which to store
                           tax data (use constants to set size of array)
Function Output/Parameters: tax table as 2D array
Function Output/Returned: none
Device Input/Keyboard: none
Device Output/Monitor: none
Dependencies: closeInputFile, openInputFile, readDoubleFromFile, skipOneRow,
              readCharacterFromFile
*/
void uploadTaxTable(const char* fileName, 
                    double taxArray[TAX_TABLE_R_COUNT][TAX_TABLE_C_COUNT])
    {
       // initialize variables
       int cIndex, rIndex;

       // open input file
       openInputFile(fileName);

       // skip the first row
       skipOneRow();

      // iterate through each location on the file; row and column 
       for(rIndex = ZERO_VALUE; rIndex < TAX_TABLE_R_COUNT; rIndex++)
          {
         for(cIndex = ZERO_VALUE; cIndex < TAX_TABLE_C_COUNT; cIndex++)
            {
              // read each double at specific index
               taxArray[rIndex][cIndex] = readDoubleFromFile();

              // if the column is not a double, assume that it is a comma
               // and read as character
                // function: readCharacterFromFile
               if(cIndex != TAX_TABLE_C_COUNT - 1)
                {
 
                  readCharacterFromFile();

                }
            }
          }
          // close the file
            closeInputFile();
    }