// header files
#include "ADT_StudentDataEngine_LL.h"

// constants?

// functions

StudentLinkedListType *clearLinkedList( StudentLinkedListType *linkedList )
   {
     // declare variables
        StudentNodeType *temp;

      // set a working pointer to the head pointer
        StudentNodeType *wkgPtr = linkedList->headPtr;

      // loop through the linked list
        while(wkgPtr != NULL)
         {
           // store the next in temp
           temp = wkgPtr->nextPtr;

           // clear the working pointer
             // function: free
           free(wkgPtr);
           
           // set working to next pointer
           wkgPtr = temp;
         }
      // clear the head pointer
        // function: free
        free(linkedList);

      // return null
        return NULL;
   }

StudentLinkedListType *copyLinkedList( StudentLinkedListType *linkedList )
   {
     // declare variables
     StudentNodeType *wkgPt;
     StudentNodeType *nodeCreated;

     // create dest linked list
       // function: malloc
     StudentLinkedListType *destList = (StudentLinkedListType*)malloc
                                              (sizeof(StudentLinkedListType));

     // initialize dest list
     destList->headPtr = NULL;

     // create a working pointer for src linked list
     wkgPt = linkedList->headPtr;

     // loop through the src linked list
     while(wkgPt != NULL)
      {
         // create a new node for dest
          // function: createLLNodeWithNode
          nodeCreated = createLLNodeWithNode(wkgPt);

         // assign new node to dest head
          nodeCreated->nextPtr = destList->headPtr;

         // assign dest head to the new node
          destList->headPtr = nodeCreated;

         // move through the original linked list
          wkgPt = wkgPt->nextPtr;
      }
      // return the new list
      return destList;
   }

StudentNodeType *createLLNodeWithData( const char *name,
                                       char gender, int studentId, double gpa )
   {
     // declare variables
       StudentNodeType *newNode;

     // create space for node
       // function: malloc
       newNode = (StudentNodeType*)malloc(sizeof(StudentNodeType));

     // assign data to node
      // assign name
         // strcpy
       strcpy(newNode->name, name);

      // assign gender
       newNode->gender = gender;

      // assign student id
       newNode->studentId = studentId;

      // assign gpa
       newNode->gpa = gpa;

      // assign null
       newNode->nextPtr = NULL;

      // return the new node
       return newNode;
   }

StudentNodeType *createLLNodeWithNode( StudentNodeType *srcPtr )
   {
     // return createLLNodeWithData function
     return createLLNodeWithData(srcPtr->name, srcPtr->gender, 
                                               srcPtr->studentId, srcPtr->gpa);
   }

void deepCopyNode( StudentNodeType *dest, const StudentNodeType src )
   {
      // copy the name
       // function strcpy
       strcpy(dest->name, src.name);
      // copy the gender
       dest->gender = src.gender;
      // copy the studentId
       dest->studentId = src.studentId;
      // copy the gpa
       dest->gpa = src.gpa;
   }

void displayLLData( const StudentLinkedListType linkedList,
                                                         const char *subTitle )
    {
       // declare variables
       int index = 0;
       StudentNodeType *newTemp;

       // store head pointer in temp
       newTemp = linkedList.headPtr;

       // if there's still more nodes
       if(newTemp != NULL)
         {
            // print title
              // function: printf
            printf("\nDisplay Data - %s\n", subTitle);

            // while temp is not null
            while(newTemp != NULL)
             {
               // print out the data
                 // function: printf
               printf("[ %d ]: %s, %c, %d, %0.5f\n", index, newTemp->name, \
                   newTemp->gender, newTemp->studentId, newTemp->gpa);

               // increment index
               index++;

               // go to the next node
               newTemp = newTemp->nextPtr;
             }

         }
         // otherwise
         else
          {
            // print error message
              // function: printf
             printf("Data not Found - Display aborted\n");
          }
    }

int getLLSize( const StudentLinkedListType linkedList )
   {
     // declare variables
       int nodeCount = 0;
       StudentNodeType *wkgPtr;

      // assign working pointer to the list's head pointer
       wkgPtr = linkedList.headPtr;

     // while headPtr is not null
       while(wkgPtr != NULL)
        {
          // increment counter
           nodeCount++;
           
          // point to nextPtr
           wkgPtr = wkgPtr->nextPtr;
        }
      // return counter
       return nodeCount;
   }

bool getNodeAtLocation( StudentNodeType *accessedElement,
                    const StudentLinkedListType linkedList, int accessedIndex )
   {
      // declare variables
      int count = 0;
      StudentNodeType *workingPt;

      // initialize working pointer to head pointer
      workingPt = linkedList.headPtr;

      // loop through the list
      while(workingPt != NULL)
       {
         // test if index is the same as count
         if(count == accessedIndex)
          {
            // copy working pointer into accessedElement
             // function: deepCopyNode
            deepCopyNode(accessedElement, *workingPt);

          // return true
            return true;
          }
        // increment count
          count++;

        // set working pointer to next
          workingPt = workingPt->nextPtr;
       }

      // set accessedElement to zero
        // function: setEmptyNodeData
      setEmptyNodeData(accessedElement);

      // return false
      return false;
   }

StudentLinkedListType *initializeLinkedList()
   {
      // declare variable
      StudentLinkedListType *tempList;

      // create space for temp
       // function: malloc
      tempList = (StudentLinkedListType*)malloc(sizeof(StudentLinkedListType));

      // set head to null
      tempList->headPtr = NULL;

      // return the list
      return tempList;
   }

bool insertLLAdtDataAfterLocation( StudentLinkedListType *linkedList,
                             const StudentNodeType student, int listLocation )
   {
     // return insertLLRawDataEngine at AFTER_LOCATION
     return insertLLRawDataEngine(linkedList, student.name, student.gender,
                                          student.studentId, student.gpa,
                                                listLocation, AFTER_LOCATION);
   }

bool insertLLAdtDataBeforeLocation( StudentLinkedListType *linkedList,
                             const StudentNodeType student, int listLocation )
   {
     // return insertLLRawDataEngine at BEFORE_LOCATION
     return insertLLRawDataEngine(linkedList, student.name, student.gender,
                                         student.studentId, student.gpa,
                                               listLocation, BEFORE_LOCATION);
   }

bool insertLLRawDataEngine( StudentLinkedListType *linkedList,
             const char *name, char gender, int studentId,
                       double gpa, int listLocation, LocationCodeType locCode )
   {
      // declare variables
      int nodeCount = 0;
      StudentNodeType *nodeCreated;
      StudentNodeType *wkgPt;
      StudentNodeType *tempPtr;

      // initialize variables
      tempPtr = linkedList->headPtr;
      nodeCreated = createLLNodeWithData(name, gender, studentId, gpa);
      wkgPt = linkedList->headPtr;

         // check if list is empty and if location is zero or if locCode is 0
         if(listLocation == 0 && (wkgPt == NULL || locCode == BEFORE_LOCATION))
           {
             // assign the new next pointer to head pointer of linked list
             nodeCreated->nextPtr = linkedList->headPtr;

             // create the new node
             linkedList->headPtr = nodeCreated;

             // return true
             return true;
           }
        // if the locCode is 0 and listLocation is positive
        if(locCode == BEFORE_LOCATION && listLocation > 0)
         {
            // decrease listLocation
            listLocation--;
         }
        // loop through list
         while(tempPtr != NULL && nodeCount < listLocation)
           {
               // go to the next node
               tempPtr = tempPtr->nextPtr;

               // increment count
               nodeCount++;
           }
        // if the node is not null
         if(tempPtr != NULL)
          {
            // if locCode is 1
            if(locCode == AT_LOCATION)
             {
               // replace the data
                // assign the name
                 // function: strcpy
                strcpy(tempPtr->name, name);

                 // assign gender
                tempPtr->gender = gender;

                 // assign the student id
                tempPtr->studentId = studentId;

                 // assign the gpa
                tempPtr->gpa = gpa;
             }
            else
             {
               // create node at specific index
               // assign new next pointer to the temp next pointer
                 nodeCreated->nextPtr = tempPtr->nextPtr;

               // assign the temp next pointer to the new node
                 tempPtr->nextPtr = nodeCreated;
             }
            // return true
            return true;
         }
        // otherwise return false
       return false;
   }

bool insertLLRawDataAfterLocation( StudentLinkedListType *linkedList,
             const char *name, char gender, int studentId,
                                                 double gpa, int listLocation )
   {
     // return insertLLRawDataEngine at AFTER_LOCATION
       return insertLLRawDataEngine(linkedList, name, gender, studentId, gpa,
                                                 listLocation, AFTER_LOCATION);
   }

bool insertLLRawDataBeforeLocation( StudentLinkedListType *linkedList,
                 const char *name, char gender, int studentId,
                                                 double gpa, int listLocation )
   {
    // return insertLLRawDataEngine at BEFORE_LOCATION
      return insertLLRawDataEngine(linkedList, name, gender,studentId, gpa,
                                                listLocation, BEFORE_LOCATION);
   }

bool linkedListIsEmpty( const StudentLinkedListType linkedList )
    {
       // if head pointer is null
        if(linkedList.headPtr == NULL)
         {
            // return true
            return true;
         }
       // return false
       return false;
    }

bool removeLLDataAtLocation( StudentNodeType *removedElement,
                           StudentLinkedListType *linkedList, int removeIndex )
   {
      // declare and initialize variables
     int newIndex = 0;
     StudentNodeType *wkgPt;
     StudentNodeType *nodeCreated;

     // assign working pointer to the head pointer 
     wkgPt = linkedList->headPtr;

       // if the remove index is at zero
       if(removeIndex == 0)
        {
          // reset the working pointer
          wkgPt = linkedList->headPtr;

          // copy the node into removedElement
            // function: deepCopyNode
          deepCopyNode(removedElement, *wkgPt);

          // assign linked list head pointer to the working next pointer
          linkedList->headPtr = wkgPt->nextPtr;

          // clear the working pointer
           // function: free
          free(wkgPt);

          // return true
          return true;
        }
     // if index in bounds
     if(removeIndex >= 0 && linkedList->headPtr != NULL)
      {
        // reset the temp
        wkgPt = linkedList->headPtr;

        // loop through the linked list
        while(newIndex < removeIndex - 1 && wkgPt != NULL)
          {
              // store the next in the temp
              wkgPt = wkgPt->nextPtr;

              // increment the index
              newIndex++;
          }
          // assign the new node to working next pointer
          nodeCreated = wkgPt->nextPtr;

          // store new node in the removedElement
            // function: deepCopyNode
          deepCopyNode(removedElement, *nodeCreated);

          // assign working next pointer to new next pointer
          wkgPt->nextPtr = nodeCreated->nextPtr;

          // clear the new node
            // function: free
          free(nodeCreated);

        // return true
         return true;
      }
      // set removedElement to 0
        // function: setEmptyElementData
      setEmptyNodeData(removedElement);

      // return false
      return false;
   }

void setEmptyNodeData( StudentNodeType *element )
   {
      // set the name to null
     *element->name[0] = NULL_CHAR;

     // set gender to X
     element->gender = 'X';

     // set studentId to 0
     element->studentId = 0;

     // set gpa to 0
     element->gpa = 0.0;
   }

bool setLLAdtDataAtLocation( StudentLinkedListType *linkedList,
                             const StudentNodeType student, int listLocation )
   {
     // return the insertLLRawDataEngine at AFTER_LOCATION
      return insertLLRawDataEngine(linkedList, student.name, student.gender,
                  student.studentId, student.gpa, listLocation, AT_LOCATION);
   }

bool setLLRawDataAtLocation( StudentLinkedListType *linkedList,
                             const char *name, char gender, int studentId,
                                                 double gpa, int listLocation )
   {
     // return insertLLRawDataEngine with locCode at 1
     return insertLLRawDataEngine(linkedList, name, gender, studentId, gpa,
                                                   listLocation, AT_LOCATION);
   }
