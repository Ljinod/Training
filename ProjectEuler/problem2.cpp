#include <iostream>


// Solution: 4613732
int main(int argc, char *argv[])
{
   unsigned int fib = 0;
   // as I coded it, the even number < 2 > was missing...!
   unsigned long int res = 2;

   unsigned int a = 3;
   unsigned int b = 2;

   while (fib < 4000000)
   {
      fib = a + b;
      b   = a;
      a   = fib;

      if ((fib % 2) == 0)
         res += fib;
   }

   std::cout << res << std::endl;

   return 0;
}
