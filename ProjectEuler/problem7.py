# -*- coding: utf-8 -*-

###############################################################################
# Problem:
# By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see
# that the 6th prime is 13.
# What is the 10 001st prime number?
#
# Solution: 104743
###############################################################################

from math import sqrt


# This function tells if a number is prime or not
def isPrime(nb):
    i = 1
    j = 2*i + 1
    sqrt_nb = int(sqrt(nb))
    while(j <= sqrt_nb):
        if(nb % j == 0):
            return False
        i = i + 1
        j = 2*i + 1
    return True


# And now I count until I find the 10001th prime number
i = 1
j = 1
nb = 3
res = 0
while(i < 10001):
    if isPrime(nb) is True:
        i = i + 1
        res = nb
        j = j + 1
        nb = 2*j+1

print "The solution might be: %d" % res
