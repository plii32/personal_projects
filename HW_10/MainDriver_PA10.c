// header files
#include "File_Input_Utility.h"
#include "SimpleBST_Utility.h"
#include "HashUtility.h"

// constant definitions
   // none

// main function
int main( int argc, char *argv[] )
   {
    CityDataType *rootPtr;
    HashTableType *hashTablePtr, *cpdHashTablePtr;
    char fileName[] = "AZ_Cities.csv";
    int numTreeNodes, actualTreeHeight, optimalTreeHeight;
    int hashSize = 19;  // actually capacity
    bool uploadDisplayFlag;

////////////////////////////////////////////////////////////////////////////////
// BST Analysis

    printf( "\nBinary Search Tree Analysis\n" );
    printf( "===========================\n" );

    uploadDisplayFlag = true;
    rootPtr = getBstDataFromFile( fileName, uploadDisplayFlag );

    numTreeNodes = countTreeNodes( rootPtr );
    printf( "\nnumber of nodes in tree: %d, ", numTreeNodes );

    optimalTreeHeight = findOptimalTreeHeight( rootPtr );
    printf( "Optimal tree height: %d, ", optimalTreeHeight );

    actualTreeHeight = findActualTreeHeight( rootPtr );
    printf( "Actual tree height: %d\n", actualTreeHeight );

    // clear BST
       // function: clearTree
    rootPtr = clearTree( rootPtr );

////////////////////////////////////////////////////////////////////////////////
// Hash Table Analysis

    printf( "\nHash Table Analysis\n" );
    printf( "===================\n" );

    uploadDisplayFlag = true;
    hashTablePtr = getHashDataFromFile( fileName, hashSize, uploadDisplayFlag );

    printf( "\nORIGINAL HASH TABLE\n" );
    showHashTableStatus( *hashTablePtr );

/// copy hash table

    cpdHashTablePtr = copyHashTable( hashTablePtr );

    printf( "\nCOPIED HASH TABLE\n" );
    showHashTableStatus( *cpdHashTablePtr );

       // clear hash table
          // function: clearHashTable
       hashTablePtr = clearHashTable( hashTablePtr );
       hashTablePtr = clearHashTable( cpdHashTablePtr );

       // show program end
          // function: printf
       printf( "\nEnd Program\n" );

       // return success
       return 0;
   }

