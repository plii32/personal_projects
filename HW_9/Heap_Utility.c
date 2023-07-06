// header files
#include "Heap_Utility.h"

// constants
const int MIN_HEAP_CAPACITY = 100;
const int NON_VALID_PRIORITY = -1;

// functions
/*
Name: accessPriority
Process: generates unique value between 1 and 100 (MAX_HEAP_CAPACITY),
         generated value is not repeated during one program run
         Priority Codes:
         INITIALIZE_PRIORITY_ENGINE - sets up priority generating system
         GET_PRIORITY - generates a unique value between 1 and 100 
                                                             (MAX_HEAP_CAPACITY)
         CLEAR_PRIORITY_ENGINE - deallocates dynamic memory created
         for the function operation
Function input/parameters: control codes as specified (PriorityCode)
Function output/parameters: none
Function output/returned: value as specified (int)
Device input/---: none
Device output/---: none
Dependencies: rand, malloc w/sizeof, isInArray, free
*/
int accessPriority( PriorityCode code )
 {
   // declare variables
   static int *randNums = NULL;
   int numbers;
   int priorityNum = NON_VALID_PRIORITY;
   static int size = 0;

   // if the code is INITIALIZE
   if(code == INITIALIZE_PRIORITY_ENGINE)
    {
       // create an int array based on capacity
        // function: malloc w/ sizeof
       randNums = (int*)malloc(sizeof(int)*MIN_HEAP_CAPACITY);

       // loop through the array
       for(numbers = 0; numbers < MIN_HEAP_CAPACITY; numbers++)
        {
           // assign non valid values for each element
           randNums[numbers] = priorityNum;
           
        }
      // initialize size 
      size = 0;
    }


   // if the code is GET
   else if(code == GET_PRIORITY)
    {
      // check if array is initialized
      if(randNums == NULL)
       {
        // return the non valid priority
        return NON_VALID_PRIORITY;

       }

     // get random number and store in variable
      // function: rand
     priorityNum = rand() % MIN_HEAP_CAPACITY + 1;

     // check if number is in array
      // function: isInArray
     if(!isInArray(randNums, priorityNum, MIN_HEAP_CAPACITY))
      {
       // put generalized number in array
       randNums[size] = priorityNum;

       // increment the size 
       size++;
      }

    }
   // if the priority code is CLEAR
    else
    {
      // clear the array
       // function: free
       free(randNums);
    
       // set randnums to null
       randNums = NULL;

       // set the size to zero
       size = 0;
    }
  // return the number
   return priorityNum;

 }

/*
Name: addRawDataToHeap
Process: adds data to end of heap, uses bubbleUp to resettle heap,
         allows for display of addition operations,
         returns true if successful and not past limit (MAX_HEAP_CAPACITY),
         false otherwise
Function input/parameters: pointer to heap (HeapType *), 
                           contractor license (int),
                           contractor business name, class code (const char *),
                           contractor class detail, city (const char *),
                           priority (int), display flag (bool)
Function output/parameters: pointer to updated heap (HeapType *)
Function output/returned: value as specified (bool)
Device input/---: none
Device output/---: none
Dependencies: setContractorRawData, bubbleUp
*/
bool addRawDataToHeap( HeapType *heap, 
                               int ctrctrLicense, 
                                   const char *ctrctrBizName,
                                      const char *ctrctrClassCode, 
                                          const char *ctrctrClassDetail,
                                              const char *ctrctrCity,
                                               int priority, bool displayFlag )
 {

   // check if the data doesn't go past limit
   if(heap->size < MIN_HEAP_CAPACITY)
    {

      // add the data
       // function: setContractorRawData
       setContractorRawData(&heap->array[heap->size], ctrctrLicense, 
                                                       ctrctrBizName,
                                                      ctrctrClassCode, 
                                                     ctrctrClassDetail,
                                                             ctrctrCity,
                                                               priority);
      // increment the size 
      heap->size++;

      // move number up 
        // function: bubbleUp 
      bubbleUp(heap, heap->size-1, displayFlag);

      // return true
      return true;
    }
   // return false
   return false;
 }

/*
Name: bubbleUp
Process: recursively implements heap bubble up operation with optional display 
         of operations,
         necessary swaps use only two lines of code, 
         no interim/temporary value used
Function input/parameters: pointer to heap (HeapType *), current index (int),
                           display flag (bool)
Function output/parameters: pointer to updated heap (HeapType *)
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: setContractorStructData, printf, bubbleUp (recursively)
*/
void bubbleUp( HeapType *heap, int currentIndex, bool displayFlag )
 {
    
    // declare variables
    int parentIndex;
    ContractorType child;
    ContractorType newParent;

    // check for current index greater than 0
    if(currentIndex > 0)
     { 
      // calculate parent's index
      parentIndex = (currentIndex - 1) / 2;

      // set up the child temp
       // function: setContractorStructData
      setContractorStructData(&child, heap->array[currentIndex]);
    
      // set up the parent temp
       // function: setContractorStructData
      setContractorStructData(&newParent, heap->array[parentIndex]);

      // check if current child's value is less than parent value
      if(heap->array[currentIndex].priority < 
                                             heap->array[parentIndex].priority)
       {
        // store the child at the current index
         // function: setContractorStructData
         setContractorStructData(&heap->array[currentIndex], child);

        // store the parent at the parent index
         // function: setContractorStructData
         setContractorStructData(&heap->array[parentIndex], newParent);

        // the flag is true
        if(displayFlag)
         {
           // print out statement
            // function: printf
           printf("  - Bubble up swap:\n");

           // print out child
            // function: printf
           printf("    - moving up child: %s (%d)\n", 
                                        heap->array[currentIndex].businessName, 
                                           heap->array[currentIndex].priority);

           // print out parent
            // function: printf
           printf("    - moving down parent: %s (%d)\n", 
                                         heap->array[parentIndex].businessName, 
                                            heap->array[parentIndex].priority);
         }

         // call the function recursively with the parent's index
          // function: bubbleUp
         bubbleUp(heap, parentIndex, displayFlag);
       }
         
     }
    
 }

/*
Name: clearHeap
Process: deallocates dynamic data used for heap contents
Function input/parameters: pointer to heap (HeapType *)
Function output/parameters: none
Function output/returned: NULL
Device input/---: none
Device output/---: none
Dependencies: free
*/
HeapType *clearHeap( HeapType *heap )
 {
   // check if heap is empty already
   if(heap != NULL)
    {
     // clear the array
      // function: free
      free(heap->array);

     // clear the size  
      heap->size = 0;

     // clear the heap
      // function: free
      free(heap);
    }
   // return null 
   return NULL;
 }

/*
Name: getDataFromFile
Process: uploads data from file with unknown number of data sets,
         has internal Boolean for upload verification,
         returns true if data found and uploaded, false otherwise
Function input/parameters: file name (const char *), display flag (bool)
Function output/parameters: pointer to heap (HeapType *)
Function output/returned: result of file operation (bool)
Device input/hard drive: data from HD
Device output/monitor: if internal Boolean set, displays uploaded values
Dependencies: openInputFile, readStringToDelimiterFromFile, 
              checkForEndOfInputFile, readIntegerFromFile, 
              readCharacterFromFile, initializeContractorNodeFromData, 
              accessPriority, addRawDataToHeap, printf, closeInputFile
*/
bool getDataFromFile( HeapType *heap, const char *fileName, bool displayFlag )
 {
   // declare variables
     
      int licenseNum;
      char businessName[STD_STR_LEN];
      char classCode[MIN_STR_LEN];
      char classDetail[STD_STR_LEN];
      char city[MIN_STR_LEN];
      int priority;
      char headerCode[MIN_STR_LEN];
      int index = 0;

      // open and check if file is accessible
        // function: openInputFile
      if(openInputFile(fileName))
       {
         // if the display flag is true 
         if(displayFlag)
          {
            // print the loading statement
             // function: printf
             printf("\n Begin Loading Data From File . . . \n");
          }

         // check if the file has been opened
          // function: accessPriority
         accessPriority(INITIALIZE_PRIORITY_ENGINE);

         // prime loop by reading the headers first
          // function: readStringToLineEndFromFile
         readStringToLineEndFromFile(headerCode);

         // start with the first number
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
 
             // get the randomized value
              // function: accessPriority
              priority = accessPriority(GET_PRIORITY);

              // add the data
                // function: addRawDataToHeap
              addRawDataToHeap(heap, licenseNum, businessName, classCode,
                                     classDetail, city, priority, displayFlag);

              // if flag is true
              if(displayFlag)
               {
                // print out license number
                 // function: printf
                printf("\n%d) License Number: %d, ", index, licenseNum);

                // print out business name
                 // function: printf
                printf("Business Name: %s, ", businessName);

                // print out class code
                 // function: printf
                printf("Class Code: %s, ", classCode);

                // print out class detail
                 // function: printf
                printf("Class Detail: %s, ", classDetail);

                // print out priority
                 // function: printf
                printf("City: %s, Priority: %d\n", city, priority);
               }
              
              // print next number
               // function: readIntegerFromFile
	            licenseNum = readIntegerFromFile();
               
              // increment the index 
              index++;
           }
         // close file
          // function: closeInputFile
         closeInputFile();

         // set the priority to clear
          // function: accessPriority
         accessPriority(CLEAR_PRIORITY_ENGINE);  
  
         // if the flag is true
         if(displayFlag)
            {
              // print the ending statement
               // function: printf
               printf("\t\t\t\t\t\t    . . . End Loading Data From File\n\n");
            }

         // return true
         return true;
       }
       // return false
        return false;
 }

/*
Name: heapIsEmpty
Process: returns true if heap is empty, false othwerwise
Function input/parameters: heap (const HeapType)
Function output/parameters: none
Function output/returned: result as specified (bool)
Device input/---: none
Device output/---: none
Dependencies: none
*/
bool heapIsEmpty( const HeapType heap )
 {
   // return size
   return heap.size == 0;
 }

/*
Name: initializeHeap
Process: allocates memory for heap, and for heap contents
Function input/parameters: none
Function output/parameters: none
Function output/returned: pointer to updated heap (HeapType *)
Device input/---: none
Device output/---: none
Dependencies: malloc w/sizeof
*/
HeapType *initializeHeap()
 {
   // declare variables
     HeapType *newHeap;

   // create space for the heap
    // function: malloc w/sizeof
     newHeap = (HeapType*)malloc(sizeof(HeapType));

   // initialize heap contents
   
     // initialize the array
      // function: malloc w/ sizeof
     newHeap->array = (ContractorType*)malloc(sizeof(ContractorType)
                                                           *MIN_HEAP_CAPACITY);

     // initialize the size 
     newHeap->size = 0;

     // return the heap
     return newHeap;
 }

/*
Name: isInArray
Process: utility function that reports if a specified value 
         has been found in a given array
Function input/parameters: pointer to integer array (int *), value (int),
                           size of array (int)
Function output/parameters: none
Function output/returned: result as specified (bool)
Device input/---: none
Device output/---: none
Dependencies: none
*/
bool isInArray( int *array, int value, int arraySize )
 {
   // declare variables
   int element;

   // loop through the array
   for(element = 0; element < arraySize; element++)
    {
       // if the value matches any of the elements
      if(array[element] == value)
       {
        // return true 
        return true;
       }
    }
    // otherwise return false
    return false;
 }

/*
Name: removeFromHeap
Process: removes value from heap, resets top of heap,
         then resettles heap,
         allows optional display of operations
Function input/parameters: pointer to heap (HeapType *), display flag (bool)
Function output/parameters: pointer to returned value (Contractor *),
                            pointer to updated heap (HeapType *)
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: setContractorStructData, printf, trickleDown
*/
void removeFromHeap( ContractorType *returned, 
                                             HeapType *heap, bool displayFlag )
 {
  //:3
  
    // check if the heap exists

    if(heap->size > 0)
     {
       // if it does, set the root to the returned value
        // function: setContractorStructData 
       setContractorStructData(returned, heap->array[0]);

       // if flag is true
       if(displayFlag)
        {
         // print out message
          // function: printf
          printf("\nRemoving business: %s\n", heap->array[0].businessName);
        }

       // decrease the size 
       heap->size = heap->size - 1;
     
       // set the last node to be the new root
        // function: setContractorStructData
       setContractorStructData(&heap->array[0], heap->array[heap->size]);

       // using trickle down method to push new root to the top
        // function: trickleDown
       trickleDown(heap, 0, displayFlag);

     }
     
 }

/*
Name: setContractorRawData
Process: copies data from raw data to destination pointer
Function input/parameters: license number (int), 
                           business name & class code (const char *),
                           class detail & city (const char *),
                           priority (int)
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
                                                        const char *ctrctrCity, 
                                                                 int priority )
 {
     // set the license number
       destPtr->licenseNum = ctrctrLicense;

     // set the priority
       destPtr->priority = priority;

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
Name: setContractorStructData
Process: copies data from source node to destination pointer
Function input/parameters: node to be copied (const ContractorType)
Function output/parameters: destination pointer (ContractorType *)
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: setContractorRawData
*/
void setContractorStructData( ContractorType *destPtr, 
                                                  const ContractorType source )
 {
   // put old data in the destination
    // function: setContractorRawData
    setContractorRawData(destPtr, source.licenseNum, source.businessName, 
                                       source.classCode, source.classDetail, 
                                                 source.city, source.priority);
 }

/*
Name: trickleDown
Process: recursively implements heap trickle down operation 
         with optional display of operations,
         necessary swaps use only two lines of code, 
         no interim/temporary value used
Function input/parameters: pointer to heap (HeapType *), current index (int),
                           display flag (bool)
Function output/parameters: pointer to updated heap (HeapType *)
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: setContractorStructData, printf, trickleDown (recursively)
Author Note: used four "if" and/or "else if" statements, 
             used five inequality tests,
             not including display flag tests,
             this is not required but it should be considered
*/
void trickleDown( HeapType *heap, int currentIndex, bool displayFlag )
 {
   // declare variables
   int smallestChild, leftChild, rightChild;
   ContractorType newChild;

   // initialize the new child 
    // function: setContractorStructData
   setContractorStructData(&newChild, heap->array[currentIndex]);

   // find the children's indices from the current one
    // set up the left child index
   leftChild = (currentIndex * 2) + 1;

    // set up the right child index
   rightChild = (currentIndex * 2) + 2;

   // check for both child indices less than the array size
   if(leftChild < heap->size && rightChild < heap->size)
    {
      // check for either of the children to be smaller than the parent
      if(heap->array[leftChild].priority < heap->array[currentIndex].priority
                                || heap->array[rightChild].priority < 
                                            heap->array[currentIndex].priority)
       {
         // swap the parent with the smallest of the two children
        if(heap->array[leftChild].priority > heap->array[rightChild].priority)
          {
            // assign the right child to the smallest child variable
            smallestChild = rightChild;

            // if the flag is true
            if(displayFlag)
             {
              // print trickle statement
               // function: printf
               printf("   - Trickle down swap:\n");

              // print parent 
               // function: printf
               printf("     - moving down parent: %s (%d)\n",
                                        heap->array[currentIndex].businessName, 
                                           heap->array[currentIndex].priority);

              // print the right child
               // function: printf
               printf("     - moving up right child: %s (%d)\n", 
                                       heap->array[smallestChild].businessName, 
                                          heap->array[smallestChild].priority);
             }
             
          }
          else
          {
            // assign left child to smallest
            smallestChild = leftChild;

            // if the display flag is true
            if(displayFlag)
             {
              // print trickle statement
               // function: printf
               printf("   - Trickle down swap:\n");

               // print parent 
                // function: printf
               printf("     - moving down parent: %s (%d)\n", 
                                        heap->array[currentIndex].businessName,
                                           heap->array[currentIndex].priority);

               // print the left child
                // function: printf
               printf("     - moving up left child: %s (%d)\n", 
                                       heap->array[smallestChild].businessName, 
                                          heap->array[smallestChild].priority);
             }
             
          }

         // store smallest child into current  
          // function: setContractorStructData
         setContractorStructData(&heap->array[currentIndex], 
                                                   heap->array[smallestChild]);

         // store the new child into smallest child
          // function: setContractorStructData
         setContractorStructData(&heap->array[smallestChild], newChild);

         // call the function recursively with that child's index
          // function: trickleDown
         trickleDown(heap, smallestChild, displayFlag);
       }
    }    
 }
