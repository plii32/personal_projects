// header files
#include "Console_IO_Utility.h"

// global constants
const double ABSOLUTE_BASE = 0.0000001;
const double BOOSTING_VALUE = 5.55;
const double DRYWALL_PRICE = 3.00;
const double PLYWOOD_PRICE = 3.125;    // per square foot
const double ROOFING_PRICE = 3.535525;  // per square foot
const double SIDE_WALL_RATIO = 0.67;
const double SQUARE_ROOT_PRECISION = 0.000001;
const double TWO_BY_FOUR_PRICE = 7.50;  // per board

const int HOUSE_HEIGHT = 10;
const int NUM_2x4_PER_FOOT = 6;
const int TRIMMING_VALUE = 10;
const int TWO_ENDLINES = 2;

// constants for table
const int DESCRIPTION_WIDTH = 16;
const int TABLE_WIDTH = 39;
const int UNIT_WIDTH = 9;
const int VALUE_WIDTH = 10;

const char THICK_LINE = '=';
const char THIN_LINE = '-';

// prototypes
double findAbsolute( int value );
double findSquareRoot( double value );
void printDividedLine( char thickness );
void printHeavyDividedLine();
void printLightDividedLine();
void printTopLine();

// main program
int main()
   {
    // TODO: Write program as specified
       //initialize variables
           double desFoot, firstPart, sideWall; 
           double sideArea, frontArea, plywoodArea; 
           double secondPart,sumLengSide,sumrownSide;
           double floorArea,totalRoofing,plywoodCosts;
           double twofourCost, drywallArea,totalEstim;

       // title

           printString( "House Cost Estimator" );
           printEndline();
           printString( "====================" );
           printEndlines(2);

       // prompt for input
           desFoot
                  =promptForInteger("Enter the desired floor square footage: ");

       // front and back wall length AKA WIDTH
           firstPart = (desFoot * 3)/2;
           secondPart = findSquareRoot((firstPart));
           int wallLength;
           wallLength = secondPart + BOOSTING_VALUE;
           wallLength = wallLength/TRIMMING_VALUE;
           
           wallLength = wallLength * TRIMMING_VALUE;
           
       // side wall length AKA DEPTH
           sideWall  = wallLength * SIDE_WALL_RATIO;
           int rowndSide;
           rowndSide = sideWall + BOOSTING_VALUE;
           rowndSide = rowndSide/TRIMMING_VALUE;
           rowndSide = rowndSide * TRIMMING_VALUE;
           
       // floor area calculations
           floorArea = wallLength * rowndSide;
 
       // roofing cost calculations
           
           totalRoofing = floorArea * ROOFING_PRICE;
 

       // plywood cost calculations
           sideArea = (rowndSide * HOUSE_HEIGHT) * 2;
           frontArea = (wallLength * HOUSE_HEIGHT) * 2; 
           plywoodArea = frontArea + sideArea + desFoot;
           plywoodCosts = plywoodArea * PLYWOOD_PRICE;
            
       // 2 x 4 cost
           sumLengSide = wallLength * TWO_BY_FOUR_PRICE;
           sumrownSide = rowndSide * TWO_BY_FOUR_PRICE;
           twofourCost = (sumLengSide + sumrownSide)+75+(plywoodArea*0.75);
             
       // drywall cost
           
           drywallArea = frontArea + sideArea;
           drywallArea =  drywallArea * 3;

       // total estimate
           
           totalEstim = totalRoofing + plywoodCosts + twofourCost + drywallArea;

       // print first pipe
       // function: printCharacter
          printCharacters( TABLE_WIDTH, THIN_LINE );
          printEndline();
          ;printCharacter( PIPE );
          printStringJustified("Description", DESCRIPTION_WIDTH, "CENTER");
          ;printCharacter( PIPE );
          printStringJustified("Value", VALUE_WIDTH, "CENTER")
          ;printCharacter( PIPE );
          printStringJustified("Unit", UNIT_WIDTH, "CENTER");
          ;printCharacter( PIPE );
          printEndline();
          ;printCharacter( PIPE );
          printCharacters( DESCRIPTION_WIDTH, THICK_LINE );
          ;printCharacter( PIPE );
          printCharacters( VALUE_WIDTH, THICK_LINE );
          ;printCharacter( PIPE );
          printCharacters( UNIT_WIDTH, THICK_LINE );
          ;printCharacter( PIPE );
          printEndline();

       // print second pipe
          ;printCharacter( PIPE );
          printStringJustified("Desired Area", DESCRIPTION_WIDTH, "LEFT");
          ;printCharacter( PIPE );
          printIntegerJustified(desFoot, VALUE_WIDTH, "RIGHT");
          ;printCharacter( PIPE );
          printStringJustified("sq feet", UNIT_WIDTH, "LEFT");
          printCharacter( PIPE );
          printEndline();
          printCharacter( PIPE );
          printCharacters( DESCRIPTION_WIDTH, THIN_LINE );
          printCharacter( PIPE );
          printCharacters( VALUE_WIDTH, THIN_LINE );
          printCharacter( PIPE );
          printCharacters( UNIT_WIDTH, THIN_LINE );
          printCharacter( PIPE );
          printEndline();
    
       // print third pipe
          printCharacter( PIPE );
          printStringJustified("Actual Area", DESCRIPTION_WIDTH, "LEFT");
          printCharacter( PIPE );
          printIntegerJustified(desFoot, VALUE_WIDTH, "RIGHT");
          printCharacter( PIPE );
          printStringJustified("sq feet", UNIT_WIDTH, "LEFT");
          printCharacter( PIPE ); 
          printEndline();
          printCharacter( PIPE );
          printCharacters( DESCRIPTION_WIDTH, THIN_LINE );
          printCharacter( PIPE );
          printCharacters( VALUE_WIDTH, THIN_LINE );
          printCharacter( PIPE );
          printCharacters( UNIT_WIDTH, THIN_LINE );
          printCharacter( PIPE );
          printEndline();

       // print fourth pipe
          printCharacter( PIPE );
          printStringJustified("House Width", DESCRIPTION_WIDTH, "LEFT");
          printCharacter( PIPE );
          printIntegerJustified(wallLength, VALUE_WIDTH, "RIGHT");
          printCharacter( PIPE );
          printStringJustified("feet", UNIT_WIDTH, "LEFT");
          printCharacter( PIPE );
          printEndline();
          printCharacter( PIPE );
          printCharacters( DESCRIPTION_WIDTH, THIN_LINE );
          printCharacter( PIPE );
          printCharacters( VALUE_WIDTH, THIN_LINE );
          printCharacter( PIPE );
          printCharacters( UNIT_WIDTH, THIN_LINE );
          printCharacter( PIPE );
          printEndline();

       // print fifth pipe
          printCharacter( PIPE );
          printStringJustified("House Depth", DESCRIPTION_WIDTH, "LEFT");
          printCharacter( PIPE );
          printIntegerJustified(rowndSide,VALUE_WIDTH, "RIGHT");
          printCharacter( PIPE );
          printStringJustified("feet", UNIT_WIDTH, "LEFT");
          printCharacter( PIPE );
          printEndline();
          printCharacter( PIPE );
          printCharacters( DESCRIPTION_WIDTH, THIN_LINE );
          printCharacter( PIPE );
          printCharacters( VALUE_WIDTH, THIN_LINE );
          printCharacter( PIPE );
          printCharacters( UNIT_WIDTH, THIN_LINE );
          printCharacter( PIPE );
          printEndline();
    
       // print sixth pipe
          printCharacter( PIPE );
          printStringJustified("Roofing Cost", DESCRIPTION_WIDTH, "LEFT");
          printCharacter( PIPE );
          printDoubleJustified(totalRoofing, 2, VALUE_WIDTH, "RIGHT");
          printCharacter( PIPE );
          printStringJustified("dollars", UNIT_WIDTH, "CENTER");
          printCharacter( PIPE );
          printEndline();
          printCharacter( PIPE );
          printCharacters( DESCRIPTION_WIDTH, THIN_LINE );
          printCharacter( PIPE );
          printCharacters( VALUE_WIDTH, THIN_LINE );
          printCharacter( PIPE );
          printCharacters( UNIT_WIDTH, THIN_LINE );
          printCharacter( PIPE );
          printEndline();

       // print seventh pipe
          printCharacter( PIPE );
          printStringJustified("Plywood Cost", DESCRIPTION_WIDTH, "LEFT");
          printCharacter( PIPE );
          printDoubleJustified(plywoodCosts, 2, VALUE_WIDTH, "RIGHT");
          printCharacter( PIPE );
          printStringJustified("dollars", UNIT_WIDTH, "CENTER");
          printCharacter( PIPE );
          printEndline();
          printCharacter( PIPE );
          printCharacters( DESCRIPTION_WIDTH, THIN_LINE );
          printCharacter( PIPE );
          printCharacters( VALUE_WIDTH, THIN_LINE );
          printCharacter( PIPE );
          printCharacters( UNIT_WIDTH, THIN_LINE );
          printCharacter( PIPE );
          printEndline();
  
       // print eighth pipe
          printCharacter( PIPE );
          printStringJustified("2 x 4 Cost", DESCRIPTION_WIDTH, "LEFT");
          printCharacter( PIPE );
          printDoubleJustified(twofourCost, 2, VALUE_WIDTH, "RIGHT");
          printCharacter( PIPE );
          printStringJustified("dollars", UNIT_WIDTH, "CENTER");
          printCharacter( PIPE );
          printEndline();
          printCharacter( PIPE );
          printCharacters( DESCRIPTION_WIDTH, THIN_LINE );
          printCharacter( PIPE );
          printCharacters( VALUE_WIDTH, THIN_LINE );
          printCharacter( PIPE );
          printCharacters( UNIT_WIDTH, THIN_LINE );
          printCharacter( PIPE ); 
          printEndline();  

       // print ninth pipe
          printCharacter( PIPE );
          printStringJustified("Drywall Cost", DESCRIPTION_WIDTH, "LEFT");
          printCharacter( PIPE );
          printDoubleJustified(drywallArea, 2, VALUE_WIDTH, "RIGHT");
          printCharacter( PIPE ); 
          printStringJustified("dollars", UNIT_WIDTH, "CENTER");
          printCharacter( PIPE );
          printEndline();
          printCharacter( PIPE );
          printCharacters( DESCRIPTION_WIDTH, THIN_LINE );
          printCharacter( PIPE );
          printCharacters( VALUE_WIDTH, THIN_LINE );
          printCharacter( PIPE );
          printCharacters( UNIT_WIDTH, THIN_LINE );
          printCharacter( PIPE );
          printEndline();
    
       // print tenth pipe
          printCharacter( PIPE );
          printStringJustified("Total Estimate", DESCRIPTION_WIDTH, "CENTER");
          printCharacter( PIPE );
          printDoubleJustified(totalEstim, 2, VALUE_WIDTH, "RIGHT");
          printCharacter( PIPE );
          printStringJustified("dollars", UNIT_WIDTH, "CENTER");
          printCharacter( PIPE );
          printEndline();
          printCharacter( PIPE );
          printCharacters( DESCRIPTION_WIDTH, THIN_LINE );
          printCharacter( PIPE );
          printCharacters( VALUE_WIDTH, THIN_LINE );
          printCharacter( PIPE );
          printCharacters( UNIT_WIDTH, THIN_LINE );
          printCharacter( PIPE );
          printEndlines(2);
  
           

       // return program success
           printf("End Program");
           return 0;
   }


// supporting functions

double findAbsolute( int value )
   {
    // test for value less than negative precision
    if( value < -ABSOLUTE_BASE )
       {
        // return negated value
        return -value;
       }

    // otherwise, assume positive value, return unchanged
    return value;
   } 

double findSquareRoot( double value )
   {
    // initialize function/variables
    double testSquare, mid, high = value, low = 0;

    // set initial mid value
    mid = ( high + low ) / 2.0;

    // set initial test square value
    testSquare = mid * mid;

    // loop while difference between test square and value
    //   is greater than desired precision
       // function: findAbsolute
    while( findAbsolute( testSquare - value ) > SQUARE_ROOT_PRECISION )
       {
        // test for calculated value too high
        if( testSquare > value )
           {
            // change low to the mid value
            high = mid;
           }

        // otherwise, assume value was too low
        else
           {
            low = mid;
           }

        // calculate new mid
        mid = ( high + low ) / 2.0;

        // calculate new test square
        testSquare = mid * mid;
       }

    // return estimated square root
    return mid;
   }

void printDividedLine( char thickness )
   {
   // print description line
       // function: printCharacters
    printCharacters( DESCRIPTION_WIDTH, thickness );

    // print divider pipe
       // function: printCharacter
    printCharacter( PIPE );

    // print description line
       // function: printCharacter
    printCharacters( VALUE_WIDTH, thickness );

    // print divider pipe
       // function: printCharacter
    printCharacter( PIPE );

    // print description line
       // function: printCharacter
    printCharacters( UNIT_WIDTH, thickness );

    // print last pipe
       // function: printCharacter
    printCharacter( PIPE );
   }

void printHeavyDividedLine()
   {
    // call print divided line with heavy character
       // function: printDividedLine
    printDividedLine( THICK_LINE );
   }

void printLightDividedLine()
   {
    // call print divided line with heavy character
       // function: printDividedLine
    printDividedLine( THIN_LINE );
   }

void printTopLine()
   {
    // print top line
       // function: printCharacter
    printCharacters( TABLE_WIDTH, THIN_LINE );
   }



    