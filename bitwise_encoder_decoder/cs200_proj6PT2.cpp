#include <iostream>
 #include <string.h>
 using namespace std;

 void decode( char* src, char* dest );
 char indexing(char Rand);

 int main()
 {
   // Declare arrays to store original and encoded strings.
   char st[120];
   char decoded[80];

   // Read in original string.
   cout << "Enter text: ";
   cin.getline( st, 120 );

   // Print back out along with the # of characters.
   int len = strlen(st);
   cout << "You typed in \"" << st << "\" (" << len << " characters)" << endl;

   // Round length down to a multiple of 3.
   len -= (len % 4);

   // Encode the string - every 3 characters of original becomes
   // 4 characters of result.
   int dest_index = 0;
   for (int i=0; i<len; i+=4)
   {
     decode( st+i, decoded+dest_index );
     dest_index += 3;
   }

   // Null terminate destination string.
   decoded[dest_index] = 0;

   // Print encoded value.
   cout << "Decoded value: ";
   cout << decoded << endl;

   return 0;
 }

char Binout0, Binout1, Binout2;
void decode(char* src, char* dest)
     {
       
        char ch0 = src[0];
        char ch1 = src[1];
        char ch2 = src[2];
        char ch3 = src[3];
        
    if (ch2 == '=')
         {
            ch0 = indexing(ch0);
            ch1 = indexing(ch1);

            Binout0 = ch0 << 2;
            Binout0 = Binout0 + (ch1 >> 4);

            Binout1 = '\0';
            Binout2 = '\0'; 

       
            dest[0] = Binout0;
            dest[1] = Binout1;
            dest[2] = Binout2;

         }
        else if (ch3 == '=')
         {
            ch0 = indexing(ch0);
            ch1 = indexing(ch1);
            ch2 = indexing(ch2);
            
            

            Binout0 = ch0 << 2;
            Binout0 = Binout0 + (ch1 >> 4);
            Binout1 = ch1 << 4;
            Binout1 = Binout1 + (ch2 >> 2);

            Binout2 = '\0'; 

           
            dest[0] = Binout0;
            dest[1] = Binout1;
            dest[2] = Binout2; 
                
         }
        else
         {
            ch0 = indexing(ch0);
            ch1 = indexing(ch1);
            ch2 = indexing(ch2);
            ch3 = indexing(ch3);

            
    
            Binout0 = ch0 << 2;
            Binout0 = Binout0 + (ch1 >> 4);
            Binout1 = ch1 << 4;
            Binout1 = Binout1 + (ch2 >> 2);
            Binout2 = ch2 << 6; 
            Binout2 = Binout2 + ch3;

            dest[0] = Binout0;
            dest[1] = Binout1;
            dest[2] = Binout2;
            
         }

        



     }

char indexing(char Rand)
   {
     char BC64[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
     unsigned char counting;
     for (counting = 0; Rand != BC64[counting]; counting++)
           {
                 

           }
         return counting;
   }