// header file
#include "ADT_StudentDataEngine_Array.h"
#include "QueueType.h"
#include "StackType.h"
#include "IteratorType.h"

// local constant(s)
const int INITIAL_CAPACITY = 30;

int main()
   {
    // initialize function/program

       // declare/define variables
       StudentArrayType *arrayData;
       QueueType *queueData;
       StackType *stackData;
       IteratorType *iteratorData;
       StudentDataType tempStudent;
       int index, numItems = 10;

       // initialize data types
       arrayData = initializeArray( INITIAL_CAPACITY );
       queueData = initializeQueue( INITIAL_CAPACITY );
       stackData = initializeStack( INITIAL_CAPACITY );
       iteratorData = initializeIterator( INITIAL_CAPACITY );

       // show title
       printf( "\nData Structure Test Bed\n" );
       printf( "=======================\n" );
       
    // Array testing
    printf( "\nArray Testing\n" );

        // get input - hard coded
        insertArrayRawDataBeforeLocation( arrayData, "Johnson, Robert", 
                                                  'M', 603667, 2.844077875, 0 );
        insertArrayRawDataBeforeLocation( arrayData, "Elliott, Cayley",  
                                                  'F', 135658, 2.978848017, 0 );
        insertArrayRawDataBeforeLocation( arrayData, "Reyes, Connor",  
                                                  'M', 191261, 3.295578577, 0 );
        insertArrayRawDataBeforeLocation( arrayData, "Rodriguez, Susan",  
                                                  'F', 154838, 2.063213296, 0 );
        insertArrayRawDataBeforeLocation( arrayData, "Penn, Frederick",  
                                                  'M', 819367, 2.828974752, 0 );
        insertArrayRawDataBeforeLocation( arrayData, "Deangelis, Shawna", 
                                                  'F', 764050, 2.203316877, 0 );
        insertArrayRawDataBeforeLocation( arrayData, "Shafer, Tristan", 
                                                  'F', 693686, 3.180700609, 0 );
        insertArrayRawDataBeforeLocation( arrayData, "Ruan, Francisco", 
                                                  'M', 587182, 3.726603614, 0 );
        insertArrayRawDataBeforeLocation( arrayData, "Werner, Riley", 
                                                   'F', 444253, 2.34553428, 0 );
        insertArrayRawDataBeforeLocation( arrayData, "Davis, Glen-Andrew", 
                                                  'M', 188133, 3.937722411, 0 );

        // display array data
        displayArrayData( *arrayData, "Original Data" );

    // Queue testing
    printf( "\nQueue Testing\n" );

        // get input from array
        for( index = 0; index < numItems; index++ )
           {
            getElementAtLocation( &tempStudent, *arrayData, index );

            printf( "Enqueueing %s\n", tempStudent.name );

            enqueueAdtData( queueData, tempStudent );
           }
        
        printf( "\n" );
        // dump/display dequeud items
        while( !queueIsEmpty( *queueData ) )
           {
            dequeueAdtData( &tempStudent, queueData );

            printf( "Dequeueing %s\n", tempStudent.name );
           }

    // Stack Testing
    printf( "\nStack Testing\n" );

        // get input from array
        for( index = 0; index < numItems; index++ )
           {
            getElementAtLocation( &tempStudent, *arrayData, index );
    
            printf( "Pushing %s onto stack\n", tempStudent.name );
    
            pushAdtData( stackData, tempStudent );
           }

        printf( "\n" );

        while( !stackIsEmpty( *stackData ) )
           {
            popAdtData( &tempStudent, stackData );

            printf( "Popping %s from stack\n", tempStudent.name );
           }

    // Iterator testing
    printf( "\nIterator Testing\n" );

        // get input from array
        for( index = 0; index < 3; index++ )
           {
            getElementAtLocation( &tempStudent, *arrayData, index );

            printf( "Adding %s to iterator at beginning\n", tempStudent.name );
            
            insertAdtDataAtBeginning( iteratorData, tempStudent );
           }
    
        displayIterator( *iteratorData ); printf( "\n" );

        for( index = 3; index < 6; index++ )
           {
            getElementAtLocation( &tempStudent, *arrayData, index );
    
            printf( "Adding %s to iterator at end\n", tempStudent.name );
            
            appendAdtDataAtEnd( iteratorData, tempStudent );
           }

        displayIterator( *iteratorData ); printf( "\n" );

        printf( "Moving current to end\n" );    
        setCurrentAtEnd( iteratorData ); 

        displayIterator( *iteratorData ); printf( "\n" );

        printf( "Moving current index left four elements\n" );    
        movePrev( iteratorData ); 
        movePrev( iteratorData );
        movePrev( iteratorData );
        movePrev( iteratorData );

        displayIterator( *iteratorData ); printf( "\n" );

        printf( "Moving current index right two elements\n" );    
        moveNext( iteratorData ); 
        moveNext( iteratorData );

        displayIterator( *iteratorData ); printf( "\n" );

        for( index = 6; index < numItems; index++ )
           {
            getElementAtLocation( &tempStudent, *arrayData, index );
    
            printf( "Adding %s to iterator at current\n", tempStudent.name );
            
            insertAdtDataAtCurrent( iteratorData, tempStudent );
           }
    
        displayIterator( *iteratorData ); printf( "\n" );

        // moving to end
        printf( "Moving to end\n" );
        while( moveNext( iteratorData ) );

        displayIterator( *iteratorData ); printf( "\n" );

        printf( "Removing from current\n" );
        removeAdtDataFromCurrent( &tempStudent, iteratorData );

        displayIterator( *iteratorData ); printf( "\n" ); 

        // moving to beginning
        printf( "Moving to beginning\n" );
        while( movePrev( iteratorData ) );

        displayIterator( *iteratorData ); printf( "\n" );

        printf( "Removing from current\n" );
        removeAdtDataFromCurrent( &tempStudent, iteratorData );

        displayIterator( *iteratorData );

    // end program

       // deallocate array types
       arrayData = clearArray( arrayData );
       queueData = clearQueue( queueData );
       stackData = clearStack( stackData );
       iteratorData = clearIterator( iteratorData );
       
       // report end program
          // function: printf
       printf( "\nProgram End\n" );

       // return program success
       return 0;
   }


