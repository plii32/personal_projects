// header file
#include "TwoThreeUtility.h"

// function implementations
/*
Name: addAndOrganizeData
Process: adds item to a previously established node, 
         in the appropriate location,
         returns pointer to the node
Function input/parameters: working pointer (TwoThreeNode *),
                           new contracter data (ContractorType *)
Function output/parameters: none
Function output/returned: pointer to updated two or three node (TwoThreeNode *)
Device input/---: none
Device output/---: none
Dependencies: strcpy (as needed), createContractorDataFromAdt,
              compareStrings
*/
TwoThreeNode *addAndOrganizeData( TwoThreeNode *wkgPtr, 
                                                       ContractorType *newData )
   {
    // TODO
    return NULL;  // temporary stub return
   }

/*
Name: addItemWithAdtData
Process: adds item to tree given contractor Adt data
Function input/parameters: address of root pointer (TwoThreeNode **),
                           new contracter data (ContractorType *)
Function output/parameters: none
Function output/returned: pointer to root node
Device input/---: none
Device output/---: none
Dependencies: addItemWithAdtDataHelper
*/
TwoThreeNode *addItemWithAdtData( TwoThreeNode *rootPtr,
                                                       ContractorType *newData )
   {
    TwoThreeNode *wkgPtr = rootPtr;

    addItemWithAdtDataHelper( &rootPtr, wkgPtr, newData );

    return rootPtr;
   }

/*
Name: addItemWithAdtDataHelper
Process: helper function adds item to tree given contractor Adt data
Function input/parameters: address of root pointer (TwoThreeNode **),
                           working pointer (TwoThreeNode *),
                           new contracter data (ContractorType *)
Function output/parameters: none
Function output/returned: NULL
Device input/---: none
Device output/---: none
Dependencies: strcpy (as needed), createContractorDataFromAdt,
              compareStrings, addItemWithAdtDataHelper,
              addAndOrganizeData, resolveThreeFourNode
*/
void addItemWithAdtDataHelper( TwoThreeNode **rootPtr, 
                                              TwoThreeNode *wkgPtr,
                                                       ContractorType *newData )
   {
    // TODO

    // no return
   }

/*
Name: addItemWithRawData
Process: adds node with all Contractor data
Function input/parameters: pointer to root node (TwoThreeNode *),
                           license number (int), business name (const char *),
                           class code, class detail, city (const char *)
Function output/parameters: none
Function output/returned: pointer to root node
Device input/---: none
Device output/---: none
Dependencies: createContractorDataWithData, addItemWithAdtDataHelper, free
*/
TwoThreeNode *addItemWithRawData( TwoThreeNode *rootPtr,
                              int licNum, 
                                 const char *bizName, const char *clsCode,
                                       const char *clsDetail, const char *city )
   {
    ContractorType *newData = createContractorDataWithData( licNum, 
                                            bizName, clsCode, clsDetail, city );
    TwoThreeNode *wkgPtr = rootPtr;

    addItemWithAdtDataHelper( &rootPtr, wkgPtr, newData );

    free( newData );

    return rootPtr;
   }

/*
Name: clearTwoThreeNode
Process: deallocates memory for one individual node
         returns NULL,
         does not handle children of node
Function input/parameters: pointer to node (TwoThreeNode *)
Function output/parameters: none
Function output/returned: NULL
Device input/---: none
Device output/---: none
Dependencies: free
*/
TwoThreeNode *clearTwoThreeNode( TwoThreeNode *wkgPtr )
   {
    // TODO

    return NULL;  // temporary stub return
   }

/*
Name: clearTwoThreeTree
Process: deallocates memory for all tree nodes individually, 
         returns NULL
Function input/parameters: pointer to tree (TwoThreeNode *)
Function output/parameters: none
Function output/returned: NULL
Device input/---: none
Device output/---: none
Dependencies: clearTwoThreeNode, clearTwoThreeTree (recursively)
*/
TwoThreeNode *clearTwoThreeTree( TwoThreeNode *wkgPtr )
   {
    // TODO

    return NULL;  // temporary stub return
   }

/*
Name: compareStrings
Process: test for alphabetical difference between two strings,
         returns less than zero if left string 
         is alphabetically less than right string,
         returns equal to zero if left string 
         is alphabetically equal to right string,
         returns greater than zero if left string 
         is alphabetically greater than right string,
         tests all characters as lower case,
         if two strings are alphabetically equal,
         longer string is greater unless they are equal length
Function input/parameters: left and right strings (const char *)
Function output/parameters: none
Function output/returned: result as specified (int)
Device input/---: none
Device output/---: none
Dependencies: toLowerCase, strlen
*/
int compareStrings( const char *leftString, const char *rightString )
   {
    int diff, index = 0;

    while( leftString[ index ] != NULL_CHAR 
                                          && rightString[ index ] != NULL_CHAR )
       {
        diff = toLowerCase( leftString[ index ] ) 
                                          - toLowerCase( rightString[ index ] );

        if( diff != 0 )
           {
            return diff;
           }

        index++;
       }

    return strlen( leftString ) - strlen( rightString );
   }

/*
Name: copyTwoThreeTree
Process: creates duplicate copy of given two three tree
Function input/parameters: pointer to two three tree (TwoThreeNode *)
Function output/parameters: none
Function output/returned: pointer to new copy of two three tree (TwoThreeNode *)
Device input/---: none
Device output/---: none
Dependencies: createEmptyTwoThreeNode, createContractorDataFromAdt,
              copyTwoThreeTree (recursively)
*/
TwoThreeNode *copyTwoThreeTree( TwoThreeNode *wkgPtr )
   {
    // TODO
             
    return NULL;  // temporary stub return
   }

/*
Name: createContractorDataWithData
Process: creates contractor data node from given contractor data items
Function input/parameters: license number (int), business name (const char *),
                           class code, class detail, and city (const char *)
Function output/parameters: none
Function output/returned: pointer to new contractor data (ContractorType *)
Device input/---: none
Device output/---: none
Dependencies: malloc/sizeof, strcpy
*/
ContractorType *createContractorDataWithData( int licNum, const char *bizName, 
                  const char *clsCode, const char *clsDetail, const char *city )
   {
    ContractorType *newPtr 
                         = (ContractorType *)malloc( sizeof( ContractorType ) );

    newPtr->licenseNum = licNum;
 
    strcpy( newPtr->businessName, bizName );
    strcpy( newPtr->classCode, clsCode );
    strcpy( newPtr->classDetail, clsDetail );
    strcpy( newPtr->city, city );

    return newPtr;
   }

/*
Name: createContractorDataFromAdt
Process: creates contractor data node from given contractor Adt
Function input/parameters: source Adt pointer (const ContractorType *)
Function output/parameters: none
Function output/returned: pointer to new contractor data (ContractorType *)
Device input/---: none
Device output/---: none
Dependencies: createContractorDataWithData
*/
ContractorType *createContractorDataFromAdt( const ContractorType *sourcePtr )
   {
    return createContractorDataWithData( sourcePtr->licenseNum, 
                           sourcePtr->businessName, sourcePtr->classCode, 
                                      sourcePtr->classDetail, sourcePtr->city );
   }

/*
Name: createEmptyTwoThreeNode
Process: allocates data for two three node, sets all data to zero or NULL
         as appropriate, returns pointer to node
Function input/parameters: none
Function output/parameters: none
Function output/returned: pointer to created node (TwoThreeNode *)
Device input/---: none
Device output/---: none
Dependencies: malloc/sizeof
*/
TwoThreeNode *createEmptyTwoThreeNode()
   {
    TwoThreeNode *newPtr = (TwoThreeNode *)malloc( sizeof( TwoThreeNode ) );

    newPtr->numItems = ZERO_DATA_ITEMS;

    newPtr->leftData = NULL;
    newPtr->centerData = NULL;
    newPtr->rightData = NULL;

    newPtr->leftChildPtr = NULL;
    newPtr->auxLeftPtr = NULL;
    newPtr->ctrChildPtr = NULL;
    newPtr->auxRightPtr = NULL;
    newPtr->rightChildPtr = NULL;

    newPtr->parentPtr = NULL;

    return newPtr;
   }

/*
Name: createNewChild
Process: creates new child selectably from left or right side of three four node,
         sets all links for the new node, returns pointer to node
Function input/parameters: working and parent pointers (TwoThreeNode *),
                           code to indicate left or right child (SelectionCode)
Function output/parameters: none
Function output/returned: pointer to newly created child
Device input/---: none
Device output/---: none
Dependencies: createContractorDataFromAdt, createEmptyTwoThreeNode
*/
TwoThreeNode *createNewChild( TwoThreeNode *wkgPtr, 
                                 TwoThreeNode *parPtr, SelectionCode childCode )
   {
    TwoThreeNode *newPtr = createEmptyTwoThreeNode();

    if( childCode == LEFT_CHILD_SELECT )
       {
        newPtr->centerData = createContractorDataFromAdt( wkgPtr->leftData );
        newPtr->leftChildPtr = wkgPtr->leftChildPtr;
        newPtr->rightChildPtr = wkgPtr->auxLeftPtr;
       
        if( newPtr->leftChildPtr != NULL )
           {
            newPtr->leftChildPtr->parentPtr = newPtr;
            newPtr->rightChildPtr->parentPtr = newPtr;
           }
       }
   
    else  // assume right child select
       {
        newPtr->centerData = createContractorDataFromAdt( wkgPtr->rightData );
        newPtr->leftChildPtr = wkgPtr->auxRightPtr;
        newPtr->rightChildPtr = wkgPtr->rightChildPtr;

        if( newPtr->rightChildPtr != NULL )
           {
            newPtr->leftChildPtr->parentPtr = newPtr;
            newPtr->rightChildPtr->parentPtr = newPtr;
           }
       }

    newPtr->parentPtr = parPtr;

    newPtr->numItems = ONE_DATA_ITEM;

    return newPtr;
   }

/*
Name: displayDataInOrder
Process: user function to call for in order display,
         uses divider bars above and below display with title on top bar,
         calls helper, must display "Data Not Found - Display Aborted"
         if tree is empty
Function input/parameters: working pointer (TwoThreeNode *),
                           Boolean flag to indicate position and level display
Function output/parameters: none
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: displayDataInOrderHelper, printf
*/
void displayDataInOrder( TwoThreeNode *wkgPtr, bool showLocation )
   {
    int levelCount = 0;

    printf( "\n========== Two Three Tree Display ==========\n" );

    if( wkgPtr != NULL )
       {
        displayDataInOrderHelper( wkgPtr, levelCount, showLocation );

        printf( "\n============================================\n" );
       }

    else
       {
        printf( "\nData Not Found - Display Aborted\n" );
       }
   }

/*
Name: displayDataInOrderHelper
Process: helper function implements in order data display of two three tree,
         if Boolean flag is set, also shows position in node
         and level in tree,
         no display (printf) may be repeated for a given position
         (i.e., one printf for 'C', one printf for 'L', one printf for 'R')
Function input/parameters: working pointer (TwoThreeNode *), level count (int),
                           Boolean flag for level/position (bool)
Function output/parameters: none
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: printf, displayDataInOrderHelper (recursively)
*/
void displayDataInOrderHelper( TwoThreeNode *wkgPtr, 
                                             int levelCount, bool showLocation )
   {
    // TODO

    // no return
   }

/*
Name: initializeTwoThreeTree
Process: returns NULL to initialize tree pointer
Function input/parameters: none
Function output/parameters: none
Function output/returned: NULL
Device input/---: none
Device output/---: none
Dependencies: none
*/
TwoThreeNode *initializeTwoThreeTree()
   {
    return NULL;
   }

/*
Name: resolveThreeFourNode
Process: is passed the most recent node added,
         checks for 3/4 node, if so, breaks it up into separate left and right
         children and passes the center value to the node above,
         when complete, recurses to the parent node to resolve that as needed
Function input/parameters: address of root pointer (TwoThreeNode **),
                           pointer to working pointer (TwoThreeNode *)
Function output/parameters: root pointer address, in case root pointer
                            is updated (TwoThreeNode **)
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: createEmptyTwoThreeNode, createContractorDataFromAdt,
              createNewChild, resolveThreeFourNode (recursively)
*/
void resolveThreeFourNode( TwoThreeNode **rootPtr, TwoThreeNode *wkgPtr )
   {
    // TODO

    // no return
   }

/*
Name: toLowerCase
Process: tests for upper case character, if so, converts to lower case,
         otherwise, takes no action
Function input/parameters: test character (char)
Function output/parameters: none
Function output/returned: updated character as specified
Device input/---: none
Device output/---: none
Dependencies: none
*/
char toLowerCase( char testChar )
   {
    if( testChar >= 'A' && testChar <= 'Z' )
       {
        return testChar - 'A' + 'a';
       }

    return testChar;
   }



