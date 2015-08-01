#include <iostream>


/*
 * Solution: 233168
 */
int main(int argc, char *argv[])
{
   unsigned int res = 0;
   for (unsigned int i = 0; i < 1000; i++)
      if ( (i%3 == 0) || (i%5 == 0) )
         res += i;

   std::cout << res << std::endl;

   return 0;
}
