
// SUBJECT:
// The prime factors of 13195 are 5, 7, 13 and 29.
// What is the largest prime factor of the number 600851475143 ?

// Solution: 6857

#include <iostream>
#include <cmath>
#include <vector>

const bool is_prime(const unsigned int);

int main(int argc, char **argv)
{
   static unsigned long bignumber = 600851475143;

   unsigned int sqrt_nb = sqrt(bignumber), res=0;
   std::vector<unsigned int> prime_list;
   
   for (unsigned int i=2; i<sqrt_nb; i++)
      if ( is_prime(i) )
         prime_list.push_back(i);

   for (std::vector<unsigned int>::iterator j = prime_list.begin();
        j != prime_list.end(); j++)
   {
      if ( (bignumber % *j) == 0 )
         res = *j;
   }

   std::cout << "\n" << res << std::endl;

   return 0;
}


const bool is_prime(const unsigned int n)
{
   unsigned int limit = sqrt(n);
   unsigned int i=1, j=2;
   
   while (j < limit)
   {
      if ( (n % j) == 0 )
         return false;

      i++;
      j = 2*i + 1;
   }

   return true;
}
