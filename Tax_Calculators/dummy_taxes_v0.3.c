// header files
#include "Console_IO_Utility.h"

// global constants
    //AZ taxes
        // AZ tax Baseline RATE
const double AZ_TAX_BASELINE_RATE = 0.0259;
        // AZ tax Baseline LIMIT
const double AZ_TAX_BASELINE_LIMIT = 27808.5; 
        // AZ tax First bracket RATE
const double AZ_TAX_FIRST_BRACKET_RATE = 0.0334;   
        // AZ tax First bracket LIMIT 
const double AZ_TAX_FIRST_BRACKET_LIMIT = 55615.5;
        // AZ tax Second bracket RATE
const double AZ_TAX_SECOND_BRACKET_RATE = 0.0417; 
        // AZ tax Second bracket LIMIT
const double AZ_TAX_SECOND_BRACKET_LIMIT = 166843.5;
        // AZ tax MAX bracket RATE
const double AZ_TAX_MAX_RATE = 0.045;

    // Federal taxes
        // Minimum FED Tax RATE
const double FED_TAX_BASELINE_RATE = 0.1000;   
        // FED tax Baseline LIMIT
const double FED_TAX_BASELINE_LIMIT = 10275.5; 
        // FED tax First bracket RATE
const double FED_TAX_FIRST_BRACKET_RATE = 0.1200;   
        // FED tax First bracket LIMIT 
const double FED_TAX_FIRST_BRACKET_LIMIT = 41775.5;
        // FED tax Second bracket RATE
const double FED_TAX_SECOND_BRACKET_RATE = 0.2200; 
        // FED tax Second bracket LIMIT
const double FED_TAX_SECOND_BRACKET_LIMIT = 89075.5;
        // FED tax Third bracket RATE
const double FED_TAX_THIRD_BRACKET_RATE = 0.2400;  
        // FED tax Third bracket LIMIT 
const double FED_TAX_THIRD_BRACKET_LIMIT = 170050.5;
        // FED tax Fourth bracket RATE
const double FED_TAX_FOURTH_BRACKET_RATE = 0.3200;   
        // FED tax Fourth bracket LIMIT 
const double FED_TAX_FOURTH_BRACKET_LIMIT = 215950.5;
        // FED tax Fifth bracket RATE
const double FED_TAX_FIFTH_BRACKET_RATE = 0.3500; 
        // FED tax Fifth bracket LIMIT
const double FED_TAX_FIFTH_BRACKET_LIMIT = 539900.5;
        // AZ tax MAX bracket RATE
const double FED_TAX_MAX_RATE = 0.3700;

    // Other Taxes
        // SSN Tax RATE
const double TAX_SSN = 0.0620;
        // MC Tax RATE
const double TAX_MC = 0.0145;
    
    
    // Percent Conversion, ratio
const double PERCENTAGE_CONVERSION = 100;

    // printing related constants
const int TWO_ENDLINES = 2;
    // constants for table
const int TABLE_WIDTH = 46;
const int DATA_NAME_WIDTH = 20;
const int UNIT_WIDTH = 7;
const int VALUE_WIDTH = 15;
const char TOP_LINE[]
                = "==============================================";
const char THICK_LINE_DIVIDER[]
                = "|============================================|";
const char THIN_LINE_DIVIDER[]
                = "|--------------------------------------------|";
const char PIPE_SPACE[] = "| ";
const char SPACE_PIPE[] = " |";

// function prototypes
double calculateFederalTax( double adjustedIncome );
double calculateArizonaTax( double adjustedIncome );
                           
void displayResultsTable( double taxArizona, double taxFederal,
                          double incomeAfterTaxes, double effectiveTax,
                          double taxTotal, double incomeLocked);

// main program
int main()
    {
    // TODO: Write program as specified    
    // show title
        // function: printString, printEndline(s)
    printEndline();
    printString( "Dummy tax calculator V0.3" );
    printEndline();
    printString( TOP_LINE );
    printEndlines( TWO_ENDLINES );
    
    // initialize variables/functions
    double totalIncome, contributionToIRA, adjustedIncome;
    double taxFederal, taxArizona;
    double taxSSN, taxMC, taxTotal;
    double incomeAfterTaxes;
    double effectiveTax, incomeLocked;
    
    // get user input
       // section title
           // function: printString, printEndline
    printString( "Provide your Tax information below." );
    printEndline();
    
        // total income $
            // function: promptForDouble
    totalIncome = promptForDouble("Total income $: ");
    
        // IRA contributions $
            // function: promptForDouble
    contributionToIRA = promptForDouble("Your IRA contributions $: ");
    
    // conduct computations
        // adjust income by IRA contributions, $
    adjustedIncome = totalIncome - contributionToIRA;

        // calculate federal tax, $
    taxFederal = calculateFederalTax(adjustedIncome);
    
        // calculate AZ tax, $
    taxArizona = calculateArizonaTax(adjustedIncome);
    
        // calculate SSN tax, $
    taxSSN = adjustedIncome * TAX_SSN;
    
        // calculate MC tax, $
    taxMC =  adjustedIncome * TAX_MC;
    
        // calculate Total tax to be payed, $
    taxTotal = taxFederal + taxArizona + taxSSN + taxMC; 
    
        // calculate Income after Tax, $
    incomeAfterTaxes = totalIncome - taxTotal;
    
        // calculate effective tax rate, %
    effectiveTax = taxTotal / totalIncome;
    
        // calculate % of income locked in IRA, %
    incomeLocked = (contributionToIRA / totalIncome) * PERCENTAGE_CONVERSION;
    
    // display results
    displayResultsTable( taxArizona, taxFederal,
                         incomeAfterTaxes, effectiveTax,
                         taxTotal, incomeLocked);
   
    // end program / return program success
    return 0;
    }

// supporting functions
    // TODO


/*
Name: calculateArizonaTax
Process: calculates total marginal Arizona tax based on adjusted income
Function Input/Parameters: adjustedIncome
Function Output/Parameters: none
Function Output/Returned: total arizona tax
Device Input/Keyboard: none
Device Output/Monitor: none
Dependencies: none
*/

double calculateArizonaTax( double adjustedIncome ){
   
   // initialize variables
   double baseBracket, firstBracket, secondBracket, restOfIncome;
   
   // take adjusted income and decide what bracket it's in
   // subtract adjusted income and subtract bracket limit from it
   // take bracket limit and multiply by bracket rate
   // take difference and multiply by bracket rate
   // add all products together
  
     // use if-else statements
       // determine if user is in upper most bracket
     
     if (adjustedIncome > AZ_TAX_SECOND_BRACKET_LIMIT)
       { 
         double totalAzTax;

     // determine amount of tax dollars in each bracket
       // baseline bracket

         baseBracket = AZ_TAX_BASELINE_LIMIT * AZ_TAX_BASELINE_RATE;

       // first bracket

         firstBracket = (AZ_TAX_FIRST_BRACKET_LIMIT - AZ_TAX_BASELINE_LIMIT);
         firstBracket = firstBracket * AZ_TAX_FIRST_BRACKET_RATE;

       // second bracket
         
         secondBracket = (AZ_TAX_SECOND_BRACKET_LIMIT 
                         - AZ_TAX_FIRST_BRACKET_LIMIT);
         secondBracket = secondBracket * AZ_TAX_SECOND_BRACKET_RATE;

       // using the limit of the next bracket, find remaining money
       // find the rest of tax dollars with remaining money by
       // multiplying by rate
         
         restOfIncome = adjustedIncome - AZ_TAX_SECOND_BRACKET_LIMIT; 
         restOfIncome = restOfIncome * AZ_TAX_MAX_RATE;        

       // find total tax dollars by adding all the brackets up 
         
         totalAzTax = baseBracket + firstBracket + 
                      secondBracket + restOfIncome;
         
         return totalAzTax; 
       }
     else
       { 
         // if income is below baseline limit, just multiply it by rate

         if (adjustedIncome < AZ_TAX_BASELINE_LIMIT)
           {
              baseBracket = adjustedIncome * AZ_TAX_BASELINE_RATE;
              return baseBracket;
           }
        
         else if (adjustedIncome < AZ_TAX_FIRST_BRACKET_LIMIT)
           {
             double totalAzTax;

             // baseline bracket is found by multiplying the limit by rate

               baseBracket = AZ_TAX_BASELINE_LIMIT * AZ_TAX_BASELINE_RATE;
  
             // first bracket is found by finding remaining money
             // and multiplying by rate

               firstBracket = adjustedIncome - AZ_TAX_BASELINE_LIMIT;
               firstBracket = firstBracket * AZ_TAX_FIRST_BRACKET_RATE;

             // find total tax dollars by adding the brackets together

               totalAzTax = baseBracket + firstBracket;
               return totalAzTax; 
               
           }
         else if (adjustedIncome < AZ_TAX_SECOND_BRACKET_LIMIT)
           {  
              double totalAzTax;

              // for the first two brackets just find total tax dollars
              // for the last bracket, find remaining money and add all tax
              // dollars together

             // baseline bracket

              baseBracket = AZ_TAX_BASELINE_LIMIT * AZ_TAX_BASELINE_RATE;
             
             // first bracket

              firstBracket = (AZ_TAX_FIRST_BRACKET_LIMIT - AZ_TAX_BASELINE_LIMIT);
              firstBracket = firstBracket * AZ_TAX_FIRST_BRACKET_RATE;

             // second bracket 

              secondBracket = adjustedIncome - AZ_TAX_FIRST_BRACKET_LIMIT;
              secondBracket = secondBracket * AZ_TAX_SECOND_BRACKET_RATE;

            // add all tax dollars together
              totalAzTax = baseBracket + firstBracket + secondBracket; 
              return totalAzTax; 
 
           }
          
       }
    return 1; 
 }

/*
Name: calculateFederalTax
Process: calculates total marginal federal tax based on adjusted income
Function Input/Parameters: adjustedIncome
Function Output/Parameters: none
Function Output/Returned: total federal tax
Device Input/Keyboard: none
Device Output/Monitor: none
Dependencies: none
*/

double calculateFederalTax( double adjustedIncome ){
 
   // take adjusted income and decide what bracket it's in
   // subtract adjusted income and subtract bracket limit from it
   // take bracket limit and multiply by bracket rate
   // take difference and multiply by bracket rate
   // add all products together
 
      // initialize variables

      double fedBaseline, fedBracketOne, fedBracketTwo, fedBracketThree;
      double fedBracketFour, fedBracketFive, totalFedTax, restOfFedIncome;

      // find the amount of tax dollars beyond fifth bracket

      if (adjustedIncome > FED_TAX_FIFTH_BRACKET_LIMIT)
        {
         // determine amount of fed tax dollars in each bracket

          // fed baseline

          fedBaseline = FED_TAX_BASELINE_LIMIT * FED_TAX_BASELINE_RATE;
           
          // fed bracket one
                    
          fedBracketOne = FED_TAX_FIRST_BRACKET_LIMIT - FED_TAX_BASELINE_LIMIT;
          fedBracketOne = fedBracketOne * FED_TAX_FIRST_BRACKET_RATE;
         
          // fed bracket two
          
          fedBracketTwo = FED_TAX_SECOND_BRACKET_LIMIT 
                          - FED_TAX_FIRST_BRACKET_LIMIT;
          fedBracketTwo = fedBracketTwo * FED_TAX_SECOND_BRACKET_RATE;

          // fed bracket three
          
          fedBracketThree = FED_TAX_THIRD_BRACKET_LIMIT
                            - FED_TAX_SECOND_BRACKET_LIMIT;
          fedBracketThree = fedBracketThree * FED_TAX_THIRD_BRACKET_RATE;
  
          // fed bracket four
               
          fedBracketFour = FED_TAX_FOURTH_BRACKET_LIMIT 
                           - FED_TAX_THIRD_BRACKET_LIMIT;
          fedBracketFour = fedBracketFour * FED_TAX_FOURTH_BRACKET_RATE;

          // fed bracket five
          
          fedBracketFive = FED_TAX_FIFTH_BRACKET_LIMIT 
                           - FED_TAX_FOURTH_BRACKET_LIMIT; 
          fedBracketFive = fedBracketFive * FED_TAX_FIFTH_BRACKET_RATE;
          
          // using the limit of the next bracket, find remaining money
          // find the rest of tax dollars with remaining money by
          // multiplying by rate

          restOfFedIncome = adjustedIncome - FED_TAX_FIFTH_BRACKET_LIMIT;
          restOfFedIncome = restOfFedIncome * FED_TAX_MAX_RATE;
          
          totalFedTax = fedBaseline + fedBracketOne + fedBracketTwo + 
                        fedBracketThree + fedBracketFour + fedBracketFive 
                        + restOfFedIncome;

  
        }
      
        if (adjustedIncome < FED_TAX_BASELINE_LIMIT)
             {
                // if income is below baseline limit, just multiply it by rate

                fedBaseline = adjustedIncome * FED_TAX_BASELINE_RATE;
                totalFedTax = fedBaseline; 
                return totalFedTax;
             }
 
           else
             {
                if (adjustedIncome < FED_TAX_FIRST_BRACKET_LIMIT)
                  {
                    // determine the tax dollars in baseline bracket

                    fedBaseline = FED_TAX_BASELINE_LIMIT * FED_TAX_BASELINE_RATE;
                     
                    // using limit of first bracket, find remaining money
                    // add all the tax dollars together

                    fedBracketOne = adjustedIncome - FED_TAX_BASELINE_LIMIT;
                    fedBracketOne = fedBracketOne * FED_TAX_FIRST_BRACKET_RATE;
                    totalFedTax = fedBaseline + fedBracketOne;
                     
                  }
                else if (adjustedIncome < FED_TAX_SECOND_BRACKET_LIMIT)
                  {
                     // determine tax dollars in the baseline and first bracket

                     fedBaseline = FED_TAX_BASELINE_LIMIT * FED_TAX_BASELINE_RATE;
                     fedBracketOne = FED_TAX_FIRST_BRACKET_LIMIT - FED_TAX_BASELINE_LIMIT;
                     fedBracketOne = fedBracketOne * FED_TAX_FIRST_BRACKET_RATE;
                     
                     // using limit of first bracket, find remaining money
                     // add all the tax dollars together 

                     fedBracketTwo = adjustedIncome - FED_TAX_FIRST_BRACKET_LIMIT;
                     fedBracketTwo = fedBracketTwo * FED_TAX_SECOND_BRACKET_RATE;
                     totalFedTax = fedBaseline + fedBracketOne + fedBracketTwo; 
                     return totalFedTax;
                  }
                else if (adjustedIncome < FED_TAX_THIRD_BRACKET_LIMIT)
                  {
                     // determine tax dollars for baseline, bracket one and two

                     fedBaseline = FED_TAX_BASELINE_LIMIT * FED_TAX_BASELINE_RATE;
                     fedBracketOne = FED_TAX_FIRST_BRACKET_LIMIT - FED_TAX_BASELINE_LIMIT;
                     fedBracketOne = fedBracketOne * FED_TAX_FIRST_BRACKET_RATE;
                     fedBracketTwo = FED_TAX_SECOND_BRACKET_LIMIT - FED_TAX_FIRST_BRACKET_LIMIT;
                     fedBracketTwo = fedBracketTwo * FED_TAX_SECOND_BRACKET_RATE;
 
                     // using limit of first bracket, find remaining money
                     // add all the tax dollars together

                     fedBracketThree = adjustedIncome - FED_TAX_SECOND_BRACKET_LIMIT;
                     fedBracketThree = fedBracketThree * FED_TAX_THIRD_BRACKET_RATE;
                     totalFedTax = fedBaseline + fedBracketOne + fedBracketTwo + fedBracketThree;
                     return totalFedTax; 

                  } 
                else if (adjustedIncome < FED_TAX_FOURTH_BRACKET_LIMIT)
                  {
                     // determine tax dollars for baseline, bracket one, 
                     // two, and three 

                     fedBaseline = FED_TAX_BASELINE_LIMIT * FED_TAX_BASELINE_RATE;
                     fedBracketOne = FED_TAX_FIRST_BRACKET_LIMIT - FED_TAX_BASELINE_LIMIT;
                     fedBracketOne = fedBracketOne * FED_TAX_FIRST_BRACKET_RATE;
                     fedBracketTwo = FED_TAX_SECOND_BRACKET_LIMIT - FED_TAX_FIRST_BRACKET_LIMIT;
                     fedBracketTwo = fedBracketTwo * FED_TAX_SECOND_BRACKET_RATE;
                     fedBracketThree = FED_TAX_FOURTH_BRACKET_LIMIT - FED_TAX_THIRD_BRACKET_LIMIT;
                     fedBracketThree = fedBracketThree * FED_TAX_FOURTH_BRACKET_RATE;
             
                     // using limit of first bracket, find remaining money
                     // add all the tax dollars together

                     fedBracketFour = adjustedIncome - FED_TAX_THIRD_BRACKET_LIMIT;
                     fedBracketFour = fedBracketFour *  FED_TAX_FOURTH_BRACKET_RATE;
                     totalFedTax = fedBaseline + fedBracketOne + fedBracketTwo + fedBracketThree + fedBracketFour;
                     return totalFedTax;
                  }
                else if (adjustedIncome < FED_TAX_FIFTH_BRACKET_LIMIT)
                  {
                     // determine tax dollars for baseline, bracket one, two,
                     // three, and four

                     fedBaseline = FED_TAX_BASELINE_LIMIT * FED_TAX_BASELINE_RATE;
                     fedBracketOne = FED_TAX_FIRST_BRACKET_LIMIT - FED_TAX_BASELINE_LIMIT;
                     fedBracketOne = fedBracketOne * FED_TAX_FIRST_BRACKET_RATE;
                     fedBracketTwo = FED_TAX_SECOND_BRACKET_LIMIT - FED_TAX_FIRST_BRACKET_LIMIT;
                     fedBracketTwo = fedBracketTwo * FED_TAX_SECOND_BRACKET_RATE;
                     fedBracketThree = FED_TAX_FOURTH_BRACKET_LIMIT - FED_TAX_THIRD_BRACKET_LIMIT;
                     fedBracketThree = fedBracketThree * FED_TAX_FOURTH_BRACKET_RATE;
                     fedBracketFour = FED_TAX_FOURTH_BRACKET_LIMIT - FED_TAX_THIRD_BRACKET_LIMIT;
                     fedBracketFour = fedBracketFour *  FED_TAX_FOURTH_BRACKET_RATE;
 
                     // using limit of first bracket, find remaining money
                     // add all the tax dollars together

                     fedBracketFive = adjustedIncome - FED_TAX_FOURTH_BRACKET_LIMIT;
                     fedBracketFive = fedBracketFive *  FED_TAX_FIFTH_BRACKET_RATE;
                     totalFedTax = fedBaseline + fedBracketOne + fedBracketTwo 
                                   + fedBracketThree + fedBracketFour 
                                   + fedBracketFive;

                     return totalFedTax;
                  }
             }
       
          return totalFedTax;
    }
    
/*
Name: displayResultsTable
Process: displays (prints) table for tax calculator V0.3  
Function Input/Parameters: income after tax, effective tax rate, 
                           total tax to be payed, and locked income.
Function Output/Parameters: none
Function Output/Returned: none
Device Input/Keyboard: none
Device Output/Monitor: table as showed in example for PA05
Dependencies: printEndline, printString, printCharacter, printStringJustified,
              printDoubleJustified 
*/

void displayResultsTable( double taxArizona, double taxFederal,
                          double incomeAfterTaxes, double effectiveTax,
                          double taxTotal, double incomeLocked){
   
  // print top line 
  printEndline();
  printString( TOP_LINE );
  printEndline();

  // display title 
  printString( PIPE_SPACE );
  printStringJustified("DUMMY TAX CALCULATIONS", TABLE_WIDTH-3, "CENTER");
  printString( PIPE_SPACE );
  printEndline();
 
  // print divider line
  printString(THICK_LINE_DIVIDER);
  printEndline();

  // display description line
  printString( PIPE_SPACE );
  printStringJustified("Data Name", DATA_NAME_WIDTH-1, "LEFT");
  printCharacter( PIPE );
  printStringJustified("Units", UNIT_WIDTH, "CENTER");
  printCharacter( PIPE );
  printStringJustified("Value", VALUE_WIDTH-1, "CENTER");
  printString( SPACE_PIPE ); 
  printEndline();

  // print divider line
  printString(THICK_LINE_DIVIDER);
  printEndline();

  // display AZ tax 
  printString( PIPE_SPACE );
  printStringJustified("AZ Tax", DATA_NAME_WIDTH-1, "LEFT");
  printCharacter( PIPE );
  printStringJustified("$", UNIT_WIDTH, "CENTER");
  printCharacter( PIPE );
  printDoubleJustified(taxArizona, PRECISION, VALUE_WIDTH-1, "RIGHT"); 
  printString( SPACE_PIPE );
  printEndline();

  // print thin line divider
  printString( THIN_LINE_DIVIDER );
  printEndline();

  // display fed tax 
  printString( PIPE_SPACE );
  printStringJustified("Fed Tax", DATA_NAME_WIDTH-1, "LEFT");
  printCharacter( PIPE );
  printStringJustified("$", UNIT_WIDTH, "CENTER");
  printCharacter( PIPE );
  printDoubleJustified(taxFederal, PRECISION, VALUE_WIDTH-1, "RIGHT");
  printString( SPACE_PIPE );
  printEndline();

  // print thin line divider
  printString( THIN_LINE_DIVIDER );
  printEndline();

  // display effective tax rate
  printString( PIPE_SPACE );
  printStringJustified("Effective Tax Rate", DATA_NAME_WIDTH-1, "LEFT");
  printCharacter( PIPE );
  printStringJustified("%", UNIT_WIDTH, "CENTER");
  printCharacter( PIPE );
  printDoubleJustified(effectiveTax * PERCENTAGE_CONVERSION, 
                                      PRECISION, VALUE_WIDTH-1, "RIGHT");
  printString( SPACE_PIPE ); 
  printEndline();

  // print thin line divider
  printString( THIN_LINE_DIVIDER );
  printEndline();

  // display tax to be paid
  printString( PIPE_SPACE );
  printStringJustified("Tax To Be Payed", DATA_NAME_WIDTH-1, "LEFT");
  printCharacter( PIPE );
  printStringJustified("$", UNIT_WIDTH, "CENTER");
  printCharacter( PIPE );
  printDoubleJustified(taxTotal, PRECISION, VALUE_WIDTH-1, "RIGHT");
  printString( SPACE_PIPE );
  printEndline();
 
  // print thin divider line
  printString( THIN_LINE_DIVIDER );
  printEndline();

  // display income after taxes
  printString( PIPE_SPACE );
  printStringJustified("Income After Tax", DATA_NAME_WIDTH-1, "LEFT");
  printCharacter( PIPE );
  printStringJustified("$", UNIT_WIDTH, "CENTER");
  printCharacter( PIPE );
  printDoubleJustified(incomeAfterTaxes, PRECISION, VALUE_WIDTH-1, "RIGHT");
  printString( SPACE_PIPE ); 
  printEndline();
  
  // print thin line divider
  printString( THIN_LINE_DIVIDER );
  printEndline();
 
  // print locked in IRA
  printString( PIPE_SPACE );
  printStringJustified("Locked in IRA", DATA_NAME_WIDTH-1, "LEFT");
  printCharacter( PIPE );
  printStringJustified("%", UNIT_WIDTH, "CENTER");
  printCharacter( PIPE );
  printDoubleJustified(incomeLocked,PRECISION, VALUE_WIDTH-1, "RIGHT");
  printString( SPACE_PIPE );
  printEndline();

  // print last line
  printString( THICK_LINE_DIVIDER );
  printEndline();

}

  
   
  
  
  

