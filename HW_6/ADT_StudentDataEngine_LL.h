#ifndef STUDENT_DATA_ENGINE_ARRAY_H
#define STUDENT_DATA_ENGINE_ARRAY_H

// header files
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "StandardConstants.h"

// data structures
typedef struct StudentDataLLStruct
   {
    char name[ STD_STR_LEN ];

    char gender;

    int studentId;

    double gpa;

    struct StudentDataLLStruct *nextPtr;
   } StudentNodeType;

typedef struct StudentLinkedListStruct
   {
    StudentNodeType *headPtr;

   } StudentLinkedListType;

// file level constants
typedef enum { BEFORE_LOCATION, AT_LOCATION, AFTER_LOCATION } LocationCodeType;

// Prototypes

/*
Name: clearLinkedList
Process: iteratively deallocates memory for StudentNodeType linked list,
         then deallocates memory for StudentLinkedListType structure
         returns NULL to calling function
Function input/parameters: pointer to student linked list
                                                       (StudentLinkedListType *)
Function output/parameters: none
Function output/returned: NULL
Device input/---: none
Device output/---: none
Dependencies: free
*/
StudentLinkedListType *clearLinkedList( StudentLinkedListType *linkedList );

/*
Name: copyLinkedList
Process: copies nodes from one linked list ADT to another
Function input/parameters: source linked list (StudentLinkedListType *)
Function output/parameters: none
Function output/returned: pointer to destination linked list type
                                                       (StudentLinkedListType *)
Device input/---: none
Device output/---: none
Dependencies: createLLNodeWithNode (suggested 10 lines)
*/
StudentLinkedListType *copyLinkedList( StudentLinkedListType *linkedList );

/*
Name: createLLNodeWithData
Process: creates linked list node, assigns data to it,
         sets next pointer to NULL, returns pointer to the new node
Function input/parameters: student name (const char *),
                           student gender (char),
                           student ID (int),
                           student gpa (double)
Function output/parameters: none
Function output/returned: pointer to newly created node (StudentNodeType *)
Device input/---: none
Device output/---: none
Dependencies: malloc, strcpy
*/
StudentNodeType *createLLNodeWithData( const char *name,
                                       char gender, int studentId, double gpa );

/*
Name: CreateLLNodeWithNode
Process: creates linked list node, assigns node data to it,
         sets next pointer to NULL, returns pointer to the new node
Function input/parameters: linked list node (StudentNodeType *)
Function output/parameters: none
Function output/returned: pointer to newly created node (StudentNodeType *)
Device input/---: none
Device output/---: none
Dependencies: createLLNodeWithData (one line of code)
*/
StudentNodeType *createLLNodeWithNode( StudentNodeType *srcPtr );

/*
Name: deepCopyNode
Process: copies all member values from StudentNodeType source,
         does not assign next pointer
Function input/parameters: source node (const StudentNodeType)
Function output/parameters: pointer to destination value (StudentNodeType *)
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: strcpy
*/
void deepCopyNode( StudentNodeType *dest, const StudentNodeType src );

/*
Name: displayLLData
Process: displays comma-delimited element data in linked list
         if it is not empty,
         otherwise displays "Data not found - Display aborted",
         allows for subtitle to be added to "Display Data - "
Function input/parameters: student linked list head pointer
                                                  (const StudentLinkedListType),
                           subtitle (const char *)
Function output/parameters: none
Function output/returned: none
Device input/---: none
Device output/monitor: data displayed as specified
Dependencies: printf
*/
void displayLLData( const StudentLinkedListType linkedList,
                                                         const char *subTitle );

/*
Name: getLLSize
Process: finds the size (number of items) of the linked list, returns
Function input/parameters: linked list (const StudentLinkedListType)
Function output/parameters: none
Function output/returned: number of nodes (int)
Device input/---: none
Device output/---: none
Dependencies: none
*/
int getLLSize( const StudentLinkedListType linkedList );

/*
Name: getNodeAtLocation
Process: checks for index in bounds,
         sets found data to returned variable, returns true,
         otherwise if not in bounds, sets data to empty/default values,
         returns false
Function input/parameters: pointer to linked list (StudentLinkedListType *),
                           pseudo list location to access (int)
Function output/parameters: accessed item,
                            or empty node if not found (StudentNodeType *)
Function output/returned: Boolean result of successful removal (bool)
Device input/---: none
Device output/---: none
Dependencies: deepCopyNode, setEmptyNodeData
*/
bool getNodeAtLocation( StudentNodeType *accessedElement,
                    const StudentLinkedListType linkedList, int accessedIndex );

/*
Name: initializeLinkedList
Process: initializes linked list type, sets head pointer member to NULL
Function input/parameters: none
Function output/parameters: none
Function output/returned: linked list (StudentLinkedListType *)
Device input/---: none
Device output/---: none
Dependencies: malloc
*/
StudentLinkedListType *initializeLinkedList();

/*
Name: insertLLAdtDataAfterLocation
Process: verifies location within bounds,
         inserts given node into the linked list
         AFTER a specified zero-based location, returns true
         if location not within bounds, returns false
Function input/parameters: pointer to linked list (StudentLinkedListType *),
                           student ADT (const StudentNodeType),
                           pseudo list location (int)
Function output/parameters: updated pointer to linked list
                                                       (StudentLinkedListType *)
Function output/returned: success of operation (bool)
Device input/---: none
Device output/---: none
Dependencies: insertLLRawDataEngine - one line of code
*/
bool insertLLAdtDataAfterLocation( StudentLinkedListType *linkedList,
                             const StudentNodeType student, int listLocation );

/*
Name: insertLLAdtDataBeforeLocation
Process: verifies location within bounds,
         inserts given node into the linked list
         PRIOR TO a specified zero-based location, returns true,
         if location not within bounds, returns false
Function input/parameters: pointer to linked list (StudentLinkedListType *),
                           student ADT (const StudentNodeType),
                           pseudo list location (int)
Function output/parameters: updated pointer to linked list
                                                      (StudentLinkedListType *),
                           pseudo list location (int)
Function output/returned: success of operation (bool)
Device input/---: none
Device output/---: none
Dependencies: insertLLRawDataEngine (one line of code)
*/
bool insertLLAdtDataBeforeLocation( StudentLinkedListType *linkedList,
                             const StudentNodeType student, int listLocation );

/*
Name: insertLLRawDataEngine
Process: verifies location within bounds,
         inserts individual data values to the StudentLinkedListType ADT
         switchably before, at, or after, returns true
         if location not within bounds, returns false
         for insertion at, overwrites value at that location, returns true
         if location not within bounds, returns false,
         Note: Used as engine for other set and insert operations
Function input/parameters: pointer to linked list (StudentLinkedListType *),
                           student name (const char *),
                           student gender (char),
                           student ID (int),
                           student gpa (double),
                           pseudo list location (int),
                           location code (LocationCodeType)
Function output/parameters: updated pointer to linked list
                                                       (StudentLinkedListType *)
Function output/returned: success of operation (bool)
Device input/---: none
Device output/---: none
Dependencies: createLLNodeWithData, strcpy
*/
bool insertLLRawDataEngine( StudentLinkedListType *linkedList,
             const char *name, char gender, int studentId,
                       double gpa, int listLocation, LocationCodeType locCode );

/*
Name: insertLLRawDataAfterLocation
Process: verifies location within bounds,
         inserts individual data values to the StudentLinkedListType ADT
         AFTER a specified zero-based pseudo location, returns true
         if location not within bounds, returns false
Function input/parameters: pointer to linked list (StudentLinkedListType *),
                           student name (const char *),
                           student gender (char),
                           student ID (int),
                           student gpa (double),
                           pseudo list location (int)
Function output/parameters: updated pointer to linked list
                                                       (StudentLinkedListType *)
Function output/returned: success of operation (bool)
Device input/---: none
Device output/---: none
Dependencies: insertLLRawDataEngine (one line of code)
*/
bool insertLLRawDataAfterLocation( StudentLinkedListType *linkedList,
             const char *name, char gender, int studentId,
                                                 double gpa, int listLocation );

/*
Name: insertLLRawDataBeforeLocation
Process: verifies location within bounds,
         inserts individual data values to the StudentLinkedListType ADT
         PRIOR TO a specified zero-based pseudo location, returns true
         if location not within bounds, returns false
Function input/parameters: pointer to linked list (StudentLinkedListType *)
                           student name (const char *),
                           student gender (char),
                           student ID (int),
                           student gpa (double),
                           pseudo list location (int)
Function output/parameters: updated pointer to linked list
                                                       (StudentLinkedListType *)
Function output/returned: success of operation (bool)
Device input/---: none
Device output/---: none
Dependencies: insertLLRawDataEngine (one line of code)
*/
bool insertLLRawDataBeforeLocation( StudentLinkedListType *linkedList,
                 const char *name, char gender, int studentId,
                                                 double gpa, int listLocation );

/*
Name: linkedListIsEmpty
Process: returns true if list is empty, false otherwise
Function input/parameters: linked list (const StudentLinkedListType)
Function output/parameters: none
Function output/returned: Boolean result of test as specified (bool)
Device input/---: none
Device output/---: none
Dependencies: none
*/
bool linkedListIsEmpty( const StudentLinkedListType linkedList );

/*
Name: removeLLDataAtLocation
Process: checks for index in bounds,
         sets found data to returned variable,
         removes data from linked list, returns true,
         otherwise if not in bounds, sets data to empty/default values,
         returns false
Function input/parameters: pointer to linked list (StudentLinkedListType *),
                           pseudo list location to remove (int)
Function output/parameters: updated pointer to linked list
                                                      (StudentLinkedListType *),
                            removed item, or empty node if not found
                                                          (StudentNodeType *),
Function output/returned: Boolean result of successful removal (bool)
Device input/---: none
Device output/---: none
Dependencies: deepCopyNode, free, setEmptyNodeData
*/
bool removeLLDataAtLocation( StudentNodeType *removedElement,
                           StudentLinkedListType *linkedList, int removeIndex );

/*
Name: setEmptyNodeData
Process: sets student data type members to empty or default values,
         sets next pointer to NULL
Function input/parameters: student data value (StudentNodeType *)
Function output/parameters: updated student data value (StudentNodeType *)
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: none
*/
void setEmptyNodeData( StudentNodeType *element );

/*
Name: setLLAdtDataAtLocation
Process: verifies location within bounds,
         overwrites node data at specified node, returns true
         if location not within bounds, returns false
Function input/parameters: pointer to linked list (StudentLinkedListType *),
                           student ADT (const StudentNodeType),
                           pseudo list location (int)
Function output/parameters: updated pointer to linked list
                                                       (StudentLinkedListType *)
Function output/returned: success of operation (bool)
Device input/---: none
Device output/---: none
Dependencies: insertLLRawDataEngine (one line of code)
*/
bool setLLAdtDataAtLocation( StudentLinkedListType *linkedList,
                             const StudentNodeType student, int listLocation );

/*
Name: setLLRawDataAtLocation
Process: verifies location within bounds,
         overwrites individual data at specified node, returns true
         if location not within bounds, returns false
Function input/parameters: pointer to linked list (StudentLinkedListType *),
                           student ADT (const StudentNodeType),
                           pseudo list location (int)
Function output/parameters: updated pointer to linked list
                                                       (StudentLinkedListType *)
Function output/returned: success of operation (bool)
Device input/---: none
Device output/---: none
Dependencies: insertLLRawDataEngine (one line of code)
*/

bool setLLRawDataAtLocation( StudentLinkedListType *linkedList,
                             const char *name, char gender, int studentId,
                                                 double gpa, int listLocation );

#endif   // STUDENT_DATA_ENGINE_ARRAY_H
