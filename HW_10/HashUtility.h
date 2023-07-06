#ifndef HASH_UTILITY_H
#define HASH_UTILITY_H

// header files
#include "SimpleBST_Utility.h"
#include <string.h>

// Data Types
typedef struct HashTableStruct
   {
    CityDataType **table;

    int capacity;    
   } HashTableType;

// prototypes

/*
Name: addHashItem
Process: adds new item to hash table
Function input/parameters: pointer to hash table (HashTableType *), 
                           city name (const char *), city population (int)
Function output/parameters: updated pointer to hash table (HashTableType *)
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: generateHashIndex, initializeCityNodeFromData, insert
*/
void addHashItem( HashTableType *hashData, char *cityName, int cityPop );

/*
Name: clearHashTable
Process: clears contents of hash table, and then hash table itself
Function input/parameters: pointer to hash table (HashTableType *)
Function output/parameters: none
Function output/returned: NULL
Device input/---: none
Device output/---: none
Dependencies: clearTree, free
*/
HashTableType *clearHashTable( HashTableType *hashData );

/*
Name: copyHashTable
Process: creates new hash table and makes duplicate
Function input/parameters: pointer to source hash table (HashTableType *)
Function output/parameters: none
Function output/returned: pointer to new hash table (HashTableType *)
Device input/---: none
Device output/---: none
Dependencies: initializeHashTable, copyTree
*/
HashTableType *copyHashTable( HashTableType *source );

/*
Name: findMean
Process: finds the mean of a set of integers
Function input/parameters: integer array (int *), size (int)
Function output/parameters: none
Function output/returned: mean of values (double)
Device input/---: none
Device output/---: none
Dependencies: none
*/
double findMean( int *array, int size );

/*
Name: findMedian
Process: finds the median of a set of integers,
         assumes all input arrays will have an odd number of values
Function input/parameters: integer array (int *), size (int)
Function output/parameters: none
Function output/returned: median of values (int)
Device input/---: none
Device output/---: none
Dependencies: none
*/
int findMedian( int *array, int size );

/*
Name: generateHashIndex
Process: finds hashed index for given data item,
         sums integer values of city name characters,
         if city name length is less than MINIMUM_HASH_CHARACTERS,
         repeats going over the city letters as needed to meet this minimum
Function input/parameters: hash table (const HashTableType),
                           city name (const char *)
Function output/parameters: none
Function output/returned: generated hash index (int)
Device input/---: none
Device output/---: none
Dependencies: strlen
*/
int generateHashIndex( const HashTableType hashData, const char *cityName );

/*
Name: getHashDataFromFile
Process: uploads data from city file with unknown number of data sets,
         provides Boolean parameter to display data input success
Function input/parameters: file name (char *), capacity (int),
                           verbose flag (bool)
Function output/parameters: none
Function output/returned: pointer to newly created hash table 
                            (HashTableType *)
Device input/file: data from HD
Device output/---: none
Dependencies: openInputFile, initializeHashTable, readStringToDelimiterFromFile, 
              readStringToLineEndFromFile, checkForEndOfInputFile, 
              readCharacterFromFile, readIntegerFromFile, 
              addHashItem, printf, closeInputFile
*/
HashTableType *getHashDataFromFile( const char *fileName, 
                                                   int capacity, bool verbose );

/*
Name: initializeHashTable
Process: dynamically creates new hash table with internal components
Function input/parameters: capacity (int)
Function output/parameters: none
Function output/returned: pointer to newly created hash table 
                            (HashTableType *)
Device input/file: data from HD
Device output/---: none
Dependencies: malloc w/sizeof, initializeBST
*/
HashTableType *initializeHashTable( int capacity );

/*
Name: removeHashItem
Process: acquires hashed item, returns
Function input/parameters: pointer to hash table (HashTableType *),
                           city name (const char *)
Function output/parameters: none
Function output/returned: pointer to removed item (CityDataType *), or NULL
Device input/---: none
Device output/---: none
Dependencies: generateHashIndex, removeItem
*/
CityDataType *removeHashItem( HashTableType *hashData, const char *cityName );

/*
Name: searchHashTable
Process: searches for value in table, returns pointer if found
Function input/parameters: hash table (const HashTableType),
                           city name (const char *)
Function output/parameters: none
Function output/returned: pointer to found item (CityDataType *), or NULL
Device input/---: none
Device output/---: none
Dependencies: generateHashIndex, search
*/
CityDataType *searchHashTable( const HashTableType hashData, 
                                                         const char *cityName );

/*
Name: showHashTableStatus
Process: displays item counts from each BST element in the hash table,
         displays highest and lowest number of items in an element,
         displays range between highest and lowest,
         displays the mean and median,
         and displays the total number of nodes found,
         all in a formatted structure
Function input/parameters: hashTable (const HashTableType)
Function output/parameters: none
Function output/returned: none
Device input/---: none
Device output/monitor: hash data status displayed as specified
Dependencies: malloc w/sizeof, countTreeNodes, printf, 
              findMean, findMedian, free
*/
void showHashTableStatus( const HashTableType hashData );

#endif  //  HASH_UTILITY_H
