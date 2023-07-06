// header files
#include "BST_Utility.h"
#include "StandardConstants.h"

// functions

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
ContractorType *clearTree( ContractorType *wkgPtr )
   {
     // if the node is null
     if(wkgPtr != NULL)
       {
         // recursively delete the left child
           // function: clearTree
         clearTree(wkgPtr->leftChildPtr);

        // recursively delete the right child
          // function: clearTree
         clearTree(wkgPtr->rightChildPtr);

         // clear the working pointer
           // function: free
         free(wkgPtr);
       }
       
       // return empty tree
       return wkgPtr;
   }

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
int compareStringSegments( const char *testSegment, const char *otherStr )
   {
     // declare variables 
     int result = 0; 
     int comp;

     // while there are still letters
       // function: strlen
     for(comp = 0; comp < strlen(testSegment); comp++)
      {
           // count the difference
           result = testSegment[comp] - otherStr[comp];

           // if the strings are not the same length
           if(result != 0)
            {
              // return the result
              return result;
            }   
      }
      // return the difference 
      return result;
   }

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
void contractorDataToString( char destStr[], ContractorType contractorData )
   {
      // print result 
        // function: sprintf
        sprintf(destStr, "Name: %s, Num: %d, Code: %s, Detail: %s, City: %s\n", 
                  contractorData.businessName, contractorData.licenseNum, 
                         contractorData.classCode, contractorData.classDetail, 
                                                          contractorData.city);
   }

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
ContractorType *copyTree( ContractorType *wkgPtr )
   {
     // declare variables 
     ContractorType *newNode;

     // while the node is not null 
     if(wkgPtr != NULL)
      {
        // create a new node 
         // function: initializeContractorNodeFromNode
        newNode = initializeContractorNodeFromNode(*wkgPtr);

        // copy left child
         // function: copyTree
        newNode->leftChildPtr = copyTree(wkgPtr->leftChildPtr);

       // copy right child
        // function: copyTree 
        newNode->rightChildPtr = copyTree(wkgPtr->rightChildPtr);
       
       // return working pointer
        return newNode;
      }
      // return null
      return NULL;
     
   }

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
void displayInOrder( ContractorType *ctrctrPtr )
   {
      // declare vahriables 
      char destStr[HUGE_STR_LEN];
      
      // loop through the nodes
      if(ctrctrPtr != NULL)
       {
         // display the left child 
          // function: displayInOrder
         displayInOrder(ctrctrPtr->leftChildPtr);
    
         // store the data in the destStr
          // function: contractorDataToString
         contractorDataToString(destStr, *ctrctrPtr);

         // display the root
          // function: printf
         printf("%s\n", destStr);

         // display the right child
          // function: displayInOrder
         displayInOrder(ctrctrPtr->rightChildPtr);
       }
   }

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
void displayPostOrder( ContractorType *ctrctrPtr )
   {
     // declare variables 
     char destStr[HUGE_STR_LEN];

     // while the working pointer is not null
     if(ctrctrPtr != NULL)
      {
        // display the left node 
         // function: displayPostOrder
        displayPostOrder(ctrctrPtr->leftChildPtr);

       // display the right node 
        // function: displayPostOrder
        displayPostOrder(ctrctrPtr->rightChildPtr);

       // store the data in the destStr
        // function: contractorDataToString
        contractorDataToString(destStr, *ctrctrPtr);

       // display the root
        // function: printf
        printf("%s\n", destStr);
      }

   }

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
void displayPreOrder( ContractorType *ctrctrPtr )
   {
     // declare variables 
     char destStr[HUGE_STR_LEN];

     // if the working pointer isn't null
     if(ctrctrPtr != NULL)
      {
        // store the data in destStr
         // function: contractorDataToString
        contractorDataToString(destStr, *ctrctrPtr);

        // display the root
         // function: printf
        printf("%s\n", destStr);

        // display the left child 
         // function: displayPreOrder
        displayPreOrder(ctrctrPtr->leftChildPtr);

        // display the right the child 
         // function: displayPreOrder
        displayPreOrder(ctrctrPtr->rightChildPtr);
      }
     
   }

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
void displaySelectionInOrder( ContractorType *ctrctrPtr, char *nameSegment )
   {
     // declare variables 
      char destStr[HUGE_STR_LEN];
      
      // if the working pointer isn't null
      if(ctrctrPtr != NULL)
       {
         // display the left child 
          // function: displayInOrder
         displaySelectionInOrder(ctrctrPtr->leftChildPtr, nameSegment);

         // if the nameSegment is found
           // function: compareStringSegments
         if(compareStringSegments(nameSegment, ctrctrPtr->businessName) == 0)
          {
             // store the root in destStr
              // function: contractorDataToString
             contractorDataToString(destStr, *ctrctrPtr);

             // display the root
               // function: printf
             printf("%s\n", destStr);

          }

         // display the right child
          // function: displayInOrder
         displaySelectionInOrder(ctrctrPtr->rightChildPtr, nameSegment);
       }
   }

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
              readCharacterFromFile, initializeContractorNodeFromData,
              insertRawData, printf, closeInputFile
*/
ContractorType *getDataFromFile( const char *fileName )
   {
      // declare variables
      ContractorType *dataHolder = NULL;
      bool notDone = false;
      char readHeader[MAX_STR_LEN];
      int licenseNum;
      char businessName[STD_STR_LEN];
      char classCode[MIN_STR_LEN];
      char classDetail[STD_STR_LEN];
      char city[MIN_STR_LEN];

      // open and check if file is accessible
        // function: openInputFile
      if(openInputFile(fileName))
       {
        
         // prime loop by reading the headers first
           // function: readStringToLineEndFromFile
         readStringToLineEndFromFile(readHeader);

         // read the license number
           // function: readIntegerFromFile
         licenseNum = readIntegerFromFile();

         // loop through the file
          // function: checkForEndOfInputFile
         while(!checkForEndOfInputFile())
           {
             // read the comma
              // function: readCharacterFromFile
             readCharacterFromFile();

             // read business name
              // function: readStringToDelimiterFromFile
              readStringToDelimiterFromFile(COMMA, businessName);

             // read business class
               // function: readStringToDelimiterFromFile
              readStringToDelimiterFromFile(COMMA, classCode);

             // read class details
               // function: readStringToDelimiterFromFile
               readStringToDelimiterFromFile(COMMA, classDetail);

             // read city
               // function: readStringToLineEndFromFile
               readStringToLineEndFromFile(city);

             // insert node into tree
               // function: insertRawData
                dataHolder = insertRawData(dataHolder, licenseNum, businessName,
                                                 classCode, classDetail, city);

             // flag is true
             notDone = true;

             // debug
               if(notDone)
                {
                  // print the data
                   // function: printf
                   printf("Name: %s, Num: %d, Code: %s, Detail: %s, City: %s\n",
                      businessName, licenseNum, classCode, classDetail, city);
                }
               
              // read the license number
               // function: readIntegerFromFile
              licenseNum = readIntegerFromFile();
           }
           // close file
             // function: closeInputFile
           closeInputFile();
       }
      // return pointer holding data
       return dataHolder;
    
   }

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
void initializeBST( ContractorType **bstPtr )
   {
      // set bstPtr to null
      *bstPtr = NULL;

   }

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
                        const char *ctrctrClassDetail, const char *ctrctrCity )
   {
     // declare variables
     ContractorType *newNode;

     // create space for a new node 
       // function: malloc, sizeof
     newNode = (ContractorType*)malloc(sizeof(ContractorType));

     // initialize license numbers 
     newNode->licenseNum = ctrctrLicense;

     // initialize business name
       // function: strcpy
      strcpy(newNode->businessName, ctrctrBizName);

     // initialize class code
      strcpy(newNode->classCode, ctrctrClassCode);

     // initialize class detail
      strcpy(newNode->classDetail, ctrctrClassDetail);

     // initialize city
      strcpy(newNode->city, ctrctrCity);

     // set the left child to null
       newNode->leftChildPtr = NULL;

     // set the right child to null 
       newNode->rightChildPtr = NULL;

     // return new pointer 
       return newNode;
   }

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
ContractorType *initializeContractorNodeFromNode( const ContractorType source )
   {
      // return initializeContractorNodeFromData
      return initializeContractorNodeFromData(source.licenseNum, 
                                               source.businessName, 
                                                   source.classCode,
                                                      source.classCode, 
                                                          source.city);
   }

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
                                              const ContractorType ctrctrNode )
   {
     // return the insertRawData
     return insertRawData(wkgPtr, ctrctrNode.licenseNum,
                                     ctrctrNode.businessName,
                                        ctrctrNode.classCode,
                                               ctrctrNode.classDetail,
                                                       ctrctrNode.city);
   }

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
                                                       const char *ctrctrCity )
   {
     // if the working pointer isn't null
     if(wkgPtr != NULL)
      {
         // if the name is found 
          // function: compareStringSegment
         if(compareStringSegments(wkgPtr->businessName, ctrctrBizName) == 0)
          {
            // overwrite the data
             // function: setContractorRawData
             setContractorRawData(wkgPtr, ctrctrLicense, ctrctrBizName,
                                  ctrctrClassCode, ctrctrClassDetail, ctrctrCity);
          }
        // if the left > right
         // function: compareStringSegments 
         if(compareStringSegments(wkgPtr->businessName, ctrctrBizName) < 0)
          {
            // insert at the right child 
             // function: insertRawData
            wkgPtr->rightChildPtr = insertRawData(wkgPtr->rightChildPtr,
                                     ctrctrLicense, ctrctrBizName,
                                       ctrctrClassCode,ctrctrClassDetail,
                                                               ctrctrCity);
          }
          // if the left < right
            // function: compareStringSegments 
         if(compareStringSegments(wkgPtr->businessName, ctrctrBizName) > 0)
          {
            // insert at the left data
              // function: insertRawData
             wkgPtr->leftChildPtr = insertRawData(wkgPtr->leftChildPtr,
                                     ctrctrLicense, ctrctrBizName,
                                       ctrctrClassCode,ctrctrClassDetail,
                                                              ctrctrCity);
          }
       }
      else
       {
          // otherwise create a new node 
           // function: initializeContractorNodeFromData
          return initializeContractorNodeFromData(ctrctrLicense, ctrctrBizName,
                             ctrctrClassCode,ctrctrClassDetail, ctrctrCity); 

       }
       
       // return the working pointer
       return wkgPtr;
     
      }
   

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
bool isEmpty( ContractorType *ctrctrPtr )
   {
      // return the empty node
      return ctrctrPtr == NULL;
   }

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
                                                     ContractorType *childPtr )
  {
    // check if the right child exists
    if(childPtr->rightChildPtr != NULL)
     {
          // remove the max
            // function: removeFromMax
            removeFromMax(parentPtr, childPtr->rightChildPtr); 
     }
     // re-link the tree
    parentPtr->rightChildPtr = childPtr->leftChildPtr;

    // return the child pointer
    return childPtr;
  }
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
                                                         const char *toRemove )
  {
    // declare variables
    ContractorType *searcher;

       // look for the item
        // function: search
       searcher = search(rootPtr, toRemove);
       
       // check if the search is null
       if(searcher != NULL)
        {
          // if found, create new node
           // function: setContractorNodeData
           setContractorNodeData(resultPtr, *searcher);
         
          // then remove item
           // function: removeItemHelper
           rootPtr = removeItemHelper(rootPtr, toRemove);

          // return new node 
           return rootPtr;
        }
      // return null 
     return NULL;
  }

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
                                                         const char *toRemove )
  {
    // declare variables 
    ContractorType *removedMax;

     // check if value is less than current
      // function: compareStringSegments
     if(compareStringSegments(toRemove, wkgPtr->businessName) < 0)
      {
        // assign left child to recursion to the left
         // function: removeItemHelper
       wkgPtr->leftChildPtr = removeItemHelper(wkgPtr->leftChildPtr,toRemove);

      }

     // check if value is greater than current
       // function: compareStringSegments
     else if(compareStringSegments(toRemove, wkgPtr->businessName) > 0)
      {        
        // assign right child to recursion to the right
         // function: removeItemHelper
        wkgPtr->rightChildPtr = 
                            removeItemHelper(wkgPtr->rightChildPtr, toRemove);
      }


// - result: we found it!


   // check for left node NULL/not there
   else if(wkgPtr->leftChildPtr == NULL)
    {
      // assign pointer to right node
      wkgPtr = wkgPtr->rightChildPtr;

    }

   // check for right node NULL/not there
   else if(wkgPtr->rightChildPtr == NULL)
    {
      // assign pointer to left node
      wkgPtr = wkgPtr->leftChildPtr;

    }


// result: handled easy stuff


    // check for left child has right child
    else if(wkgPtr->leftChildPtr->rightChildPtr != NULL)
     {
      
      // call removeFromMax to that left child
      removedMax = removeFromMax(wkgPtr, wkgPtr->leftChildPtr);

      // replace the data in the removed node with what was in the max
       // function: setContractorNodeData
      setContractorNodeData(wkgPtr, *removedMax);

      // then must deallocate node
       // function: free
       free(removedMax);
     }

// - assume left child has no right child
    else
     {
       // - replace the data in the removed node with the left child data
        // function: setContractorNodeData
       setContractorNodeData(wkgPtr,  *wkgPtr->leftChildPtr);

       // put left child in temp
       removedMax = wkgPtr->leftChildPtr;

       // - link around the left child
       wkgPtr->leftChildPtr = wkgPtr->leftChildPtr->leftChildPtr;
       
       // - don't forget to deallocate
         // function: free
       free(removedMax);
     }
   
   // return the working pointer
   return wkgPtr;

  }

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
ContractorType *search( ContractorType *wkgPtr, const char *toFind )
  {
    // if the node is not null 
    if(wkgPtr != NULL)
     {
    
       // if item is found 
        // function: compareStringSegments
       if(compareStringSegments(toFind, wkgPtr->businessName) == 0)
        {
          // return working pointer
          return wkgPtr;
        }
     
       // if item is not found 
        // function: compareStringSegments
       else if(compareStringSegments(toFind, wkgPtr->businessName) > 0)
        {
          // search the right child 
           // function: search 
         return search(wkgPtr->rightChildPtr, toFind);

        }
        else
         {
           // otherwise search the left child 
            // function: search 
             search(wkgPtr->leftChildPtr, toFind);
         }
       
     }
     // return null
     return NULL;

  }

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
                                                       const char *ctrctrCity )
  {
     // set the license number
       destPtr->licenseNum = ctrctrLicense;

     // set the business name 
       // function: strcpy
       strcpy(destPtr->businessName, ctrctrBizName);

     // set the class code 
       // function: strcpy
       strcpy(destPtr->classCode, ctrctrClassCode);

     // set the class detail
       // function: strcpy
       strcpy(destPtr->classDetail, ctrctrClassDetail);

     // set the city 
       // function: strcpy
       strcpy(destPtr->city, ctrctrCity);
  }

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
                                                  const ContractorType source )
  {
    // call setContractorRawData
    setContractorRawData(destPtr, source.licenseNum, source.businessName, 
                           source.classCode, source.classDetail, source.city);
  }
