###############################################################################
# Problem:
# Find the sum of all the primes numbers below 2 millions.
#
# Solution: 142913828922
###############################################################################

from math import sqrt


def isPrime(nb):
    sqrt_nb = int(sqrt(nb))

   # if the number is even then it is not prime...
   if nb % 2 == 0:
       return False

   # check if one of the odd numbers divides it
   for i in range(3, sqrt_nb+1, 2):
       if nb % i == 0:
           return False

   # if the function arrived at that point then the number is prime
   return True



res = 2

for i in range(3, 2*10**6, 2):
    if isPrime(i) == True:
        res += i

print "The solution might be: %d" % res
