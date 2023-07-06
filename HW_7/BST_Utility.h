#ifndef BST_UTILITY_H
#define BST_UTILITY_H

// header files
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "File_Input_Utility.h"
#include "StandardConstants.h"

// external constants


// data types

typedef struct ContractorStruct
   {
    int licenseNum;
    char businessName[ STD_STR_LEN ];
    char classCode[ MIN_STR_LEN ];
    char classDetail[ STD_STR_LEN ];
    char city[ MIN_STR_LEN ];

    struct ContractorStruct *leftChildPtr;
    struct ContractorStruct *rightChildPtr;
   } ContractorType;

// prototypes

/*
Name: clearTree
Process: recursively deallocates tree data, uses post order traversal algorithm
Function input/parameters: working pointer for recursion (ContractorType *)
Function output/parameters: none
Function output/returned: empty tree (NULL)
Device input/---: none
Device output/---: none
Dependencies: free, clearTree (recursively)
*/
ContractorType *clearTree( ContractorType *wkgPtr );

/*
Name: compareStringSegments
Process: compares two string segments as follows:
         - compares the string segments up to the length of the test segment
         - if test segment segment is alphabetically greater 
                                      than the equal sized right string segment, 
         returns value greater than zero
         - if test segment segment is alphabetically less 
                                                  than the right string segment, 
         returns value less than zero
         - if string segments are equal returns zero
Function input/parameters: two strings to be compared (const char *)
Function output/parameters: none
Function output/returned: result as specified above (int)
Device input/---: none
Device output/---: none
Dependencies: strlen
*/
int compareStringSegments( const char *testSegment, const char *otherStr );

/*
Name: contractorDataToString
Process: sets data from node to formatted string
Function input/parameters: node with data to be set (ContractorType)
Function output/parameters: string array with result (char [])
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: sprintf
*/
void contractorDataToString( char destStr[], ContractorType contractorData );

/*
Name: copyTree
Process: recursively duplicates the provided tree
         using a pre order traversal strategy
Function input/parameters: working pointer for recursion (ContractorType *)
Function output/parameters: none
Function output/returned: pointer to duplicate tree (ContractorType *)
Device input/---: none
Device output/---: none
Dependencies: initializeContractorNodeFromNode, copyTree (recursively)
*/
ContractorType *copyTree( ContractorType *wkgPtr );

/*
Name: displayInOrder
Process: recursively displays tree using in order traversal
Function input/parameters: working pointer for recursion (ContractorType *)
Function output/parameters: none
Function output/returned: none
Device input/---: none
Device output/monitor: displayed as specified
Dependencies: contractorDataToString, printf, displayInOrder (recursively)
*/
void displayInOrder( ContractorType *ctrctrPtr );

/*
Name: displayPostOrder
Process: recursively displays tree using post order traversal,
         dynamically creates and frees string for display
Function input/parameters: working pointer for recursion (ContractorType *)
Function output/parameters: none
Function output/returned: none
Device input/---: none
Device output/monitor: displayed as specified
Dependencies: contractorDataToString, printf, displayPostOrder (recursively)
*/
void displayPostOrder( ContractorType *ctrctrPtr );

/*
Name: displayPreOrder
Process: recursively displays tree using pre order traversal,
         dynamically creates and frees string for display
Function input/parameters: working pointer for recursion (ContractorType *)
Function output/parameters: none
Function output/returned: none
Device input/---: none
Device output/monitor: displayed as specified
Dependencies: contractorDataToString, printf, displayPreOrder (recursively)
*/
void displayPreOrder( ContractorType *ctrctrPtr );

/*
Name: displaySelectionInOrder
Process: recursively displays selected items in tree using in order traversal,
         items are specified by starting segment of business name string,         
         dynamically creates and frees string for display
Function input/parameters: working pointer for recursion (ContractorType *)
Function output/parameters: none
Function output/returned: none
Device input/---: none
Device output/monitor: displayed as specified
Dependencies: compareStringSegments, contractorDataToString, printf,
              displaySelectionInOrder (recursively)
*/
void displaySelectionInOrder( ContractorType *ctrctrPtr, char *nameSegment );

/*
Name: getDataFromFile
Process: uploads data from file with unknown number of data sets,
         has internal Boolean to test for data input success
Function input/parameters: file name (const char *)
Function output/parameters: none
Function output/returned: pointer to BST holding data (ContractorType *)
Device input/---: data from HD
Device output/monitor: if internal Boolean set, displays uploaded values
Dependencies: openInputFile, readStringToDelimiterFromFile, 
              checkForEndOfInputFile, readIntegerFromFile, 
              readCharacterFromFile, insertRawData, printf, closeInputFile
*/
ContractorType *getDataFromFile( const char *fileName );

/*
Name: initializeBST
Process: sets BST root pointer to NULL, root pointer is returned by address
Function input/parameters: address of working pointer (ContractorType **)
Function output/parameters: address of updated working pointer 
                            (ContractorType **)
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: none
*/
void initializeBST( ContractorType **bstPtr );

/*
Name: initializeContractorNodeFromData
Process: captures data from individual data items, 
         dynamically creates new node,
         copies data, and returns pointer to new node         
Function input/parameters: data to be copied (char *, int, double)
Function output/parameters: none
Function output/returned: pointer to new node as specified (ContractorType *)
Device input/---: none
Device output/---: none
Dependencies: malloc, strcpy, keyword sizeof
*/
ContractorType *initializeContractorNodeFromData( int ctrctrLicense, 
                     const char *ctrctrBizName, const char *ctrctrClassCode, 
                        const char *ctrctrClassDetail, const char *ctrctrCity );

/*
Name: initializeContractorNodeFromNode
Process: captures data from source node pointer, dynamically creates new node,
         copies data, and returns pointer to new node         
Function input/parameters: node to be copied (ContractorType)
Function output/parameters: none
Function output/returned: pointer to new node as specified (ContractorType *)
Device input/---: none
Device output/---: none
Dependencies: initializeContractorNodeFromData
*/
ContractorType *initializeContractorNodeFromNode( const ContractorType source );

/*
Name: insertNodeData
Process: recursively searches for available node in BST by name,
         creates new node and returns it to the calling function,
         if node is already in tree, data is overwritten,
         uses "look up" strategy
Function input/parameters: working pointer for recursion (ContractorType *),
                           license number (int), 
                           business name & class code (const char *),
                           class detail & city (const char *)
Function output/parameters: none
Function output/returned: pointer to new node as specified (ContractorType *)
Device input/---: none
Device output/---: none
Dependencies: insertRawData
*/
ContractorType *insertNodeData( ContractorType *wkgPtr, 
                                              const ContractorType ctrctrNode );

/*
Name: insertRawData
Process: recursively searches for available node in BST by name,
         creates new node and returns it to the calling function,
         if node is already in tree, data is overwritten,
         uses "look up" strategy
Function input/parameters: working pointer for recursion (ContractorType *),
                           license number (int), 
                           business name & class code (const char *),
                           class detail & city (const char *)
Function output/parameters: none
Function output/returned: pointer to new node as specified (ContractorType *)
Device input/---: none
Device output/---: none
Dependencies: compareStringSegments, setContractorRawData, 
              initializeContractorNodeFromData, insertRawData (recursively)
*/
ContractorType *insertRawData( ContractorType *wkgPtr, 
                                 int ctrctrLicense, 
                                     const char *ctrctrBizName,
                                        const char *ctrctrClassCode, 
                                               const char *ctrctrClassDetail,
                                                       const char *ctrctrCity );

/*
Name: isEmpty
Process: tests root node for NULL, returns result
Function input/parameters: pointer to root node (ContractorType *)
Function output/parameters: none
Function output/returned: result of test as specified (bool)
Device input/---: none
Device output/---: none
Dependencies: none
*/
bool isEmpty( ContractorType *ctrctrPtr );

/*
Name: removeFromMax
Process: recursively searches for max node,
         when found, node is unlinked from tree,
         and returned
Function input/parameters: pointer to parent and child nodes (ContractorType *)
Function output/parameters: none
Function output/returned: pointer to removed node (ContractorType *)
Device input/---: none
Device output/---: none
Dependencies: removeFromMax (recursively)
*/
ContractorType *removeFromMax( ContractorType *parentPtr,
                                                     ContractorType *childPtr );

/*
Name: removeItem
Process: searches for item, if found, creates new node from search pointer,
         then removes item from tree using helper function,
         otherwise returns NULL
Function input/parameters: pointer to root node (ContractorType *),
                           name segment to be removed (const char *) 
Function output/parameters: pointer to removed data (ContractorType *)
Function output/returned: root/link to recursive pointer (ContractorType *)
Device input/---: none
Device output/---: none
Dependencies: search, setContractorNodeData, removeItemHelper
*/
ContractorType *removeItem( ContractorType *resultPtr, ContractorType *rootPtr, 
                                                         const char *toRemove );

/*
Name: removeItemHelper
Process: recursively searches for item, removes node,
         returns dynamic memory of removed node to OS,
         returns updated link to parent (at each recursive level),
         only one return at end of function
Function input/parameters: pointer to working node (ContractorType *),
                           name segment to be removed (const char *) 
Function output/parameters: none
Function output/returned: root/link to recursive parent
Device input/---: none
Device output/---: none
Dependencies: setContractorNodeData, free, removeItemHelper (recursively),
               compareStringSegments, removeFromMax
*/
ContractorType *removeItemHelper( ContractorType *wkgPtr, 
                                                         const char *toRemove );

/*
Name: search
Process: recursively searches for item, if found, returns pointer to node,
         otherwise, returns NULL
Function input/parameters: pointer to working node (ContractorType *),
                           name segment to be removed (const char *)
Function output/parameters: none
Function output/returned: pointer to found node, or NULL, as specified
Device input/---: none
Device output/---: none
Dependencies: compareStringSegments, search (recursively)
*/
ContractorType *search( ContractorType *wkgPtr, const char *toFind );

/*
Name: setContractorRawData
Process: copies data from raw data to destination pointer,
         does not copy or set node child pointers
Function input/parameters: license number (int), 
                           business name & class code (const char *),
                           class detail & city (const char *)
Function output/parameters: destination pointer (ContractorType *)
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: strcpy
*/
void setContractorRawData( ContractorType *destPtr, 
                                 int ctrctrLicense, 
                                     const char *ctrctrBizName,
                                        const char *ctrctrClassCode, 
                                               const char *ctrctrClassDetail,
                                                       const char *ctrctrCity );

/*
Name: setContractorNodeData
Process: copies data from source node to destination pointer,
         does not copy or set node child pointers
Function input/parameters: node to be copied (ContractorType)
Function output/parameters: destination pointer (ContractorType *)
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: setContractorRawData
*/
void setContractorNodeData( ContractorType *destPtr, 
                                                  const ContractorType source );

#endif   // BST_UTILITY_H

