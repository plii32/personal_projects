 //=============================================================================
 // Base64 Encoding Starter Framework
 // 2011.02.16 by Abe Pralle
 //
 // Reads a string of text and prints a resulting string of text where every
 // 3 original characters have been transformed into 4 result characters
 // consisting of the first three characters reversed followed by a hypen.
 //
 // Example output:
 // Enter text: ABCDEFGHIJKLMNOPQRSTUVWXYZ
 // You typed in "ABCDEFGHIJKLMNOPQRSTUVWXYZ" (26 characters)
 // Encoded value: CBA-FED-IHG-LKJ-ONM-RQP-UTS-XWV-
 //=============================================================================
 #include <stdio.h>
 #include <string.h>
 using namespace std;

 void encode( char* src, char* dest );

 int main()
 {
   // Declare arrays to store original and encoded strings.
   char st[80];
   char encoded[120];

   // Read in original string.
   cout << "Enter text: ";
   cin.getline( st, 80 );

   // Print back out along with the # of characters.
   int len = strlen(st);
   cout << "You typed in \"" << st << "\" (" << len << " characters)" << endl;

   // Round length down to a multiple of 3.
   len -= (len % 3);

   // Encode the string - every 3 characters of original becomes
   // 4 characters of result.
   int dest_index = 0;
   for (int i=0; i<len; i+=3)
   {
     encode( st+i, encoded+dest_index );
     dest_index += 4;
   }

   // Null terminate destination string.
   encoded[dest_index] = 0;

   // Print encoded value.
   cout << "Encoded value: ";
   cout << encoded << endl;

   return 0;
 }
 
 void encode( char* src, char* dest )
 {
   unsigned char Binout0, Binout1, Binout2, Binout3;
   unsigned char ch0 = src[0];
   unsigned char ch1 = src[1];
   unsigned char ch2 = src[2];

   dest[0] = ch2;
   dest[1] = ch1;
   dest[2] = ch0;
   dest[3] = '-';
 
 // general cases
  // create general case if statement
   if ( ch0 && ch1 && ch2 != '\0')
     { 
       Binout0 = ch0 >> 2;
       Binout1 = ch0 << 6;
       Binout1 = Binout1 >> 2;
       Binout1 = Binout1 + (ch1 << 4);
       Binout2 = ch0 << 4;
       Binout2 = Binout2 >> 2;
       Binout2 = Binout2 + (ch1 << 6);
       Binout3 = ch2 << 2;
       Binout3 = Binout3 >> 2;

       dest[0] = Binout0;
       dest[1] = Binout1;
       dest[2] = Binout2;
       dest[3] = Binout3; 

     } 
    else if (( ch2 = '\0')) 
        {
          
             Binout0 = ch0 >> 2;
             Binout1 = ch0 << 6;
             Binout1 = Binout1 >> 2;
             Binout1 = Binout1 + (ch1 << 4);
             Binout2 = ch0 << 4;
             Binout2 = Binout2 >> 2;
             Binout2 = Binout2 + (ch1 << 6);
             Binout3 = "=";

             dest[0] = Binout0;
             dest[1] = Binout1;
             dest[2] = Binout2;
             dest[3] = Binout3;    
       
        }
       else ((ch1 && ch2 == '\0')) 
        {
             Binout0 = ch0 >> 2;
             Binout1 = ch0 << 6;
             Binout1 = Binout1 >> 2;
             Binout1 = Binout1 + (ch1 << 4);
             Binout2 = "=";
             Binout3 = "=";

             dest[0] = Binout0;
             dest[1] = Binout1;
             dest[2] = Binout2;
             dest[3] = Binout3;
 
         }
     }