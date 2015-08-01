# -*- coding: utf-8 -*-

###############################################################################
# Problem:
# The sum of the squares of the first ten natural numbers is,
# 12 ** 2 + 22 ** 2 + ... + 102 ** 2 = 385
#
# The square of the sum of the first ten natural numbers is,
# (1 + 2 + ... + 10) ** 2 = 552 ** 2 = 3025
#
# Hence the difference between the sum of the squares of the first ten natural
# numbers and the square of the sum is 3025 − 385 = 2640.
#
# Find the difference between the sum of the squares of the first one hundred
# natural numbers and the square of the sum.
#
#
# Solution: 25164150
###############################################################################

sumSquare = 0
squareSum = 0

for i in range(1, 101):
    sumSquare += (i ** 2)
    squareSum += i

print "The result is: %d" % ((squareSum ** 2) - sumSquare)
