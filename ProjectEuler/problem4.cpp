/*******************************************************************************
 * Problem:
 * A palindromic number reads the same both ways. The largest palindrome made 
 * from the product of two 2-digit numbers is 9009 = 91 × 99.
 * Find the largest palindrome made from the product of two 3-digit numbers.
 *
 * Solution: 906609
 ******************************************************************************/


#include <vector>
#include <iostream>


bool isAPalindrome(long);



////////////////////////////////////////////////////////////////////////////////
/// Main
////////////////////////////////////////////////////////////////////////////////
int main( int argc, char *argv[] )
{
   std::vector<long> palindromes;
   long nb;

   for( int i=999; i>=100; i-- )
      for( int j=999; j>=100; j-- )
      {
         nb = i*j;
         if( isAPalindrome(nb) )
            palindromes.push_back(nb);
      }

   for( std::vector<long>::iterator it = palindromes.begin();
        it != palindromes.end(); it++ )
           if( *it > nb )
              nb = *it;

   std::cout << "The solution is: " << nb << std::endl;

}


////////////////////////////////////////////////////////////////////////////////
/// Is the number a palindrome?
////////////////////////////////////////////////////////////////////////////////

bool isAPalindrome(long nb)
{
   long tmp;
   int i, j;
   std::vector<int> digits;


   tmp = nb;
   while( tmp > 0 )
   {
      digits.push_back( tmp % 10 );
      tmp /= 10;
   }

   i = 0;
   j = digits.size()-1;

   while( j > i )
   {
      if( digits[i] != digits[j] )
         return false;

      i++; j--;
   }

   return true;
}
