// header files
#include <stdio.h>
#include "File_Input_Utility.h"
#include "BST_Utility.h"

// constant definitions
   // none

ContractorType *addItem( ContractorType *rootPtr );

ContractorType *cleanFree( ContractorType *ptr );

void copyTreeExample( ContractorType *rootPtr );

void findItem( ContractorType *rootPtr );

ContractorType *removeBusiness( ContractorType *rootPtr );

void displaySelectedData( ContractorType *rootPtr );

// main function
int main( int argc, char *argv[] )
   {
    ContractorType *rootPtr;
    char fileName[ STD_STR_LEN ] = "ContractorData_20.csv";
    char userResponse;
    bool runProgram = true;

    // set title
    // initialize iterator
    initializeBST( &rootPtr );

    // upload data
       // function: getDataFromFile
    rootPtr = getDataFromFile( fileName );

    do
       {
        printf( "\nBinary Search Tree Test Program\n" );
        printf(   "===============================\n" );

        printf( "1) (A)dd or Replace Item\n" );
        printf( "2) (F)ind Item\n" );
        printf( "3) (R)emove Item\n" );
        printf( "4) (C)opy Tree\n" );
        printf( "5) Display Data (I)n Order\n" );
        printf( "6) Display Data Pos(t) Order\n" );
        printf( "7) Display Data Pr(e) Order\n" );
        printf( "8) Display (S)elected Data\n" );
        printf( "9) End (P)rogram\n" );

        printf( "\nEnter selection: " );
        scanf( "%c", &userResponse );
        fflush( stdin );

        switch( userResponse )
           {
            case '1': case 'a': case 'A':
               rootPtr = addItem( rootPtr );
               break;

            case '2': case 'f': case 'F':
               findItem( rootPtr );
               break;

            case '3': case 'r': case 'R':
               rootPtr = removeBusiness( rootPtr );
               break;

            case '4': case 'c': case 'C':
               copyTreeExample( rootPtr );
               break;

            case '5': case 'i': case 'I':
               printf( "\nDisplay in order:\n" );
               displayInOrder( rootPtr );
               break;

            case '6': case 't': case 'T':
               printf( "\nDisplay post order:\n" );
               displayPostOrder( rootPtr );
               break;

            case '7': case 'e': case 'E':
               printf( "\nDisplay pre order:\n" );
               displayPreOrder( rootPtr );
               break;

            case '8': case 's': case 'S':
               displaySelectedData( rootPtr );
               break;

            case '9': case 'p': case 'P':
               runProgram = false;
               break;

            default:
               printf( "Incorrect entry, Try again\n" );
               break;               
           }
       }
    while( runProgram );
    
    // end program

       // clear BST
          // function: clearTree
       rootPtr = clearTree( rootPtr );

       // show program end
          // function: printf
       printf( "\nEnd Program\n" );

       // return success
       return 0;
   }

/*
Name: addItem
Process: prompts user for individual input, then loads to tree
Function input/parameters: pointer to root node (ContractorType *)
Function output/parameters: none
Function output/returned: root/link to recursive pointer (ContractorType *)
Device input/keyboard: prompts user as needed
Device output/monitor: displays data as specified
Dependencies: printf, scanf, gets, insertRawData, fflush
*/ContractorType *addItem( ContractorType *rootPtr )
   {
    int licNum;
    char bizName[ STD_STR_LEN ];
    char clsCode[ TINY_STR_LEN ];
    char clsDetail[ STD_STR_LEN ];
    char city[ MIN_STR_LEN ];

    printf( "\nAdd Item Module\n" );

    printf( "Enter license number: " );
    scanf( "%d", &licNum );
    fflush( stdin );

    printf( "Enter business name: " );
    gets( bizName );

    printf( "Enter class code: " );
    gets( clsCode );

    printf( "Enter class detail: " );
    gets( clsDetail );

    printf( "Enter city: " );
    gets( city );

    rootPtr = insertRawData( rootPtr, licNum, 
                                            bizName, clsCode, clsDetail, city );

    printf( "\nItem added to BST\n" );

    return rootPtr;
   }

/*
Name: cleanFree
Process: checks if pointer is not NULL, then frees as neede
Function input/parameters: pointer to root node (ContractorType *)
Function output/parameters: none
Function output/returned: NULL
Device input/---: none
Device output/---: none
Dependencies: free
*/ContractorType *cleanFree( ContractorType *ptr )
   {
    if( ptr != NULL )
       {
        free( ptr );
       }

    return NULL;
   }

/*
Name: copyTreeExample
Process: shows original tree, copies tree, then shows copied display
Function input/parameters: pointer to root node (ContractorType *) 
Function output/parameters: none
Function output/returned: none
Device input/---: none
Device output/monitor: displays as specified
Dependencies: printf, displayInOrder, clearTree, fflush
*/
void copyTreeExample( ContractorType *rootPtr )
   {
    ContractorType *cpdTreePtr;

    printf( "\nCopy Tree Module\n" );

    printf( "Original Tree Displayed:\n" );
    displayInOrder( rootPtr );

    cpdTreePtr = copyTree( rootPtr );

    printf( "Copied Tree Displayed:\n" );
    displayInOrder( cpdTreePtr );

    clearTree( cpdTreePtr );

    fflush( stdin );
   }

/*
Name: findItem
Process: prompts user for item name, finds and displays if available,
         otherwise displays "Business not found"
Function input/parameters: pointer to root node (ContractorType *)
Function output/parameters: none
Function output/returned: none
Device input/keyboard: prompts user as needed
Device output/monitor: displays data as specified
Dependencies: printf, scanf, contractorDataToString, search, fflush
*/
void findItem( ContractorType *rootPtr )
   {
    ContractorType *resultPtr;
    char resultStr[ HUGE_STR_LEN ];
    char bizName[ STD_STR_LEN ];

    printf( "\nFind Item Module\n" );

    printf( "Enter segment of business name: " );
    scanf( "%s", bizName );
    
    resultPtr = search( rootPtr, bizName );

    if( resultPtr != NULL )
       {
        contractorDataToString( resultStr, *resultPtr );

        printf( "Business found: %s\n", resultStr );
       }

    else
       {
        printf( "Business not found\n" );
       }

    fflush( stdin );
   }

/*
Name: removeBusiness
Process: prompts user for item name, finds and verifies item to be removed,
         then removes as prompted
Function input/parameters: pointer to root node (ContractorType *)
Function output/parameters: none
Function output/returned: pointer to updated root node (ContractorType *)
Device input/keyboard: prompts user as needed
Device output/monitor: displays data as specified
Dependencies: printf, scanf, contractorDataToString, search, removeItem, fflush
*/
ContractorType *removeBusiness( ContractorType *rootPtr )
   {
    ContractorType *resultPtr;
    ContractorType result;
    char resultStr[ HUGE_STR_LEN ];
    char bizName[ STD_STR_LEN ];
    char response;

    printf( "\nRemove Item Module\n" );

    printf( "Enter segment of business name: " );
    scanf( "%s", bizName );
    
    resultPtr = search( rootPtr, bizName );

    if( resultPtr != NULL )
       {
        contractorDataToString( resultStr, *resultPtr );

        fflush( stdin );
        printf( "Remove %s (y/n)?: ", resultStr );

        scanf( "%c", &response );

        if( response == 'y' || response == 'Y' )
           {
            rootPtr = removeItem( &result, rootPtr, bizName );

            printf( "\nBusiness %s removed\n", result.businessName );
           }

        else
           {
            printf( "\nBusiness %s not removed\n", bizName );
           }
       }

    else
       {
        printf( "Business not found\n" );
       }

    fflush( stdin );

    return rootPtr;
   }

/*
Name: displaySelectedData
Process: prompts user for item name, then displays all items
         beginning with the provided string segment
Function input/parameters: pointer to root node (ContractorType *)
Function output/parameters: none
Function output/returned: none
Device input/keyboard: prompts user as needed
Device output/monitor: displays data as specified
Dependencies: printf, scanf, fflush, displaySelectionInOrder
*/
void displaySelectedData( ContractorType *rootPtr )
   {
    char bizName[ STD_STR_LEN ];

    printf( "\nDisplay Business Selection Module\n" );

    printf( "Enter segment of business name: " );
    scanf( "%s", bizName );

    fflush( stdin );

    printf( "\nSelected Data Displayed:\n" );
    displaySelectionInOrder( rootPtr, bizName );
   }


