#ifndef BST_UTILITY_H
#define BST_UTILITY_H

// header files
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "StandardConstants.h"
#include "File_Input_Utility.h"

// external constants


// data types

typedef struct CityDataStruct
   {
    char name[ MIN_STR_LEN ];
    int population;

    struct CityDataStruct *leftChildPtr;
    struct CityDataStruct *rightChildPtr;
   } CityDataType;

// prototypes

/*
Name: clearTree
Process: recursively deallocates tree nodes using a post order traversal
Function input/parameters: working pointer for recursion (StudentDataType *)
Function output/parameters: none
Function output/returned: empty tree (NULL)
Device input/file: none
Device output/monitor: none
Dependencies: free, clearTree (recursively)
*/
CityDataType *clearTree( CityDataType *wkgPtr );

/*
Name: compareStrings
Process: compares two strings as follows:
         - if left string is greater than the right string, 
         returns value greater than zero
         - if left string is less than the right string, 
         returns value less than zero
         - if strings are equal but one is longer, longer one is greater
         - otherwise, returns zero
Function input/parameters: two strings to be compared (const char *)
Function output/parameters: none
Function output/returned: result as specified above (int)
Device input/file: none
Device output/monitor: none
Dependencies: strlen
*/
int compareStrings( const char *leftStr, const char *rightStr );

/*
Name: copyTree
Process: recursively duplicates the provided tree
         using a pre order traversal strategy
Function input/parameters: working pointer for recursion (CityDataType *)
Function output/parameters: none
Function output/returned: pointer to duplicate tree (CityDataType *)
Device input/---: none
Device output/---: none
Dependencies: initializeCityNodeFromNode, copyTree (recursively)
*/
CityDataType *copyTree( CityDataType *wkgPtr );

/*
Name: countTreeNodes
Process: finds the number of nodes in a given BST
Function input/parameters: working pointer for recursion (CityDataType *)
Function output/parameters: none
Function output/returned: number of nodes found (int)
Device input/---: none
Device output/---: none
Dependencies: countTreeNodeHelper
*/
int countTreeNodes( CityDataType *rootPtr );

/*
Name: countTreeNodeHelper
Process: recursively finds the number of nodes in a given BST
Function input/parameters: working pointer for recursion (CityDataType *)
Function output/parameters: pointer to number of nodes (int *)
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: countTreeNodeHelper (recursively)
*/
void countTreeNodeHelper( CityDataType *cdtPtr, int *counter );

/*
Name: displayData
Process: displays data sorted by city name
Function input/parameters: root pointer (CityDataType *)
Function output/parameters: none
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: displayInOrder
*/
void displayData( CityDataType *rootPtr );

/*
Name: displayInOrder
Process: recursively displays tree with numbered values 
         using in order traversal,
         dynamically creates and frees string for display
Function input/parameters: working pointer for recursion (CityDataType *),
                           pointer to count (int *)
Function output/parameters: none
Function output/returned: none
Device input/file: none
Device output/monitor: none
Dependencies: cityDataToString, malloc, sizeof, printf, free, 
              displayInOrder (recursively)
*/
void displayInOrder( CityDataType *cdtPtr, int *count );

/*
Name: findMax
Process: finds the maximum of two integer values
Function input/parameters: two integer values (int)
Function output/parameters: none
Function output/returned: larger of the two numbers (int)
Device input/---: none
Device output/---: none
Dependencies: none
*/
int findMax( int oneVal, int otherVal );

/*
Name: findOptimalTreeHeight
Process: finds the optimal height of a given BST
Function input/parameters: pointer to root (CityDataType *)
Function output/parameters: none
Function output/returned: optimal tree height (int)
Device input/---: none
Device output/---: none
Dependencies: countTreeNodes
*/
int findOptimalTreeHeight( CityDataType *cdtPtr );

/*
Name: findActualTreeHeight
Process: recursively finds the actual height of a given BST
Function input/parameters: pointer to root (CityDataType *)
Function output/parameters: none
Function output/returned: actual tree height (int)
Device input/---: none
Device output/---: none
Dependencies: findActualTreeHeight (recursively), findMax
*/
int findActualTreeHeight( CityDataType *cdtPtr );

/*
Name: getBstDataFromFile
Process: uploads data from file with unknown number of data sets,
         allows for Boolean flag to show upload
Function input/parameters: file name (char *), verbose flag (bool)
Function output/parameters: none
Function output/returned: pointer to newly created BST
Device input/file: data from HD
Device output/monitor: none
Dependencies: openInputFile, readStringToLineEndFromFile, initializeBST
              checkForEndOfInputFile, readIntegerFromFile, 
              readCharacterFromFile, readStringToDelimiterFromFile,
              readStringToLineEndFromFile,  initializeCityNodeFromData, 
              insert, printf, closeInputFile
*/
CityDataType *getBstDataFromFile( const char *fileName, bool verbose );

/*
Name: initializeBST
Process: sets BST root pointer to NULL, root pointer is returned by address
Function input/parameters: address of working pointer (CityDataType **)
Function output/parameters: address of updated working pointer 
                            (CityDataType **)
Function output/returned: none
Device input/file: none
Device output/monitor: none
Dependencies: none
*/
void initializeBST( CityDataType **bstPtr );

/*
Name: initializeCityNodeFromData
Process: captures data from individual data items, 
         dynamically creates new node,
         copies data, and returns pointer to new node         
Function input/parameters: data to be copied (char *, int, double)
Function output/parameters: none
Function output/returned: pointer to new node as specified (CityDataType *)
Device input/file: none
Device output/monitor: none
Dependencies: malloc, sizeof, strcpy
*/
CityDataType *initializeCityNodeFromData( const char *name, int population );

/*
Name: initializeCityNodeFromNode
Process: captures data from source node pointer, dynamically creates new node,
         copies data, and returns pointer to new node         
Function input/parameters: node to be copied (CityDataType)
Function output/parameters: none
Function output/returned: pointer to new node as specified (CityDataType *)
Device input/file: none
Device output/monitor: none
Dependencies: initializeCityNodeFromData
*/
CityDataType *initializeCityNodeFromNode( const CityDataType source );

/*
Name: insert
Process: recursively searches for available location in BST,
         creates new node and returns it to the calling function,
         if node is already in tree, data is overwritten
Function input/parameters: working pointer for recursion (CityDataType *),
                           node to be inserted (const CityDataType)
Function output/parameters: none
Function output/returned: pointer to new node and subtrees 
                          as specified (CityDataType *)
Device input/file: none
Device output/monitor: none
Dependencies: compareStrings, setCityNodeData, initializeCityNodeFromNode,
              insert (recursively)
*/
CityDataType *insert( CityDataType *wkgPtr, const CityDataType inData );

/*
Name: isEmpty
Process: tests root node for NULL, returns result
Function input/parameters: pointer to root node (CityDataType *)
Function output/parameters: none
Function output/returned: result of test as specified (bool)
Device input/file: none
Device output/monitor: none
Dependencies: none
*/
bool isEmpty( CityDataType *sdtPtr);

/*
Name: removeFromMax
Process: recursively searches for max node,
         when found, node is unlinked from tree and returned
Function input/parameters: pointer to parent and child nodes (CityDataType *)
Function output/parameters: none
Function output/returned: pointer to removed node (CityDataType *)
Device input/file: none
Device output/monitor: none
Dependencies: none
*/
CityDataType *removeFromMax( CityDataType *parentPtr,
                                                       CityDataType *childPtr );

/*
Name: removeItem
Process: searches for item, if found, creates new node from search pointer,
         then removes item from tree using helper function,
         otherwise returns NULL
Function input/parameters: address of pointer to root node (CityDataType *),
                           node to be removed with at least city name key
Function output/parameters: address of updated root node pointer 
                            (CityDataType **)
Function output/returned: pointer to dynamically created duplicate 
                          of removed item (CityDataType *)
Device input/file: none
Device output/monitor: none
Dependencies: search, initializeCityNodeFromNode, removeItemHelper
*/
CityDataType *removeItem( CityDataType **rootPtr, const char *cityName );

/*
Name: removeItemHelper
Process: recursively searches for item, removes node,
         returns dynamic memory of removed node to OS,
         returns updated link to parent (at each recursive level),
         only one return at end of function
Function input/parameters: pointer to working node (CityDataType *),
                           node to be removed with at least city name key
                           (const CityDataType)
Function output/parameters: none
Function output/returned: link to recursive parent
Device input/file: none
Device output/monitor: none
Dependencies: compareStrings, setCityNodeData, removeFromMax, free,
              removeItemHelper (recursively)
*/
CityDataType *removeItemHelper( CityDataType *wkgPtr, const char *cityName );

/*
Name: search
Process: recursively searches for item, if found, returns pointer to node,
         otherwise, returns NULL
Function input/parameters: pointer to working node (CityDataType *),
                           node to be found with city name key
                           (const char *)
Function output/parameters: none
Function output/returned: link to found node, or NULL, as specified
Device input/file: none
Device output/monitor: none
Dependencies: compareStrings, search (recursively)
*/
CityDataType *search( CityDataType *wkgPtr, const char *cityName );

/*
Name: setCityNodeData
Process: copies data from source node to destination pointer
Function input/parameters: node to be copied (CityDataType)
Function output/parameters: destination pointer (CityDataType *)
Function output/returned: none
Device input/file: none
Device output/monitor: none
Dependencies: strcpy
*/
void setCityNodeData( CityDataType *destPtr, const CityDataType source );

/*
Name: cityDataToString
Process: sets data from node to formatted string
Function input/parameters: node with data to be set (CityDataType)
Function output/parameters: string array with result (char [])
Function output/returned: none
Device input/file: none
Device output/monitor: none
Dependencies: sprintf
*/
void cityDataToString( char str[], CityDataType cityData );

#endif   // BST_UTILITY_H

