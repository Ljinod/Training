###############################################################################
# Problem:
# A pythagorean triplet is a set of three integers, a < b < c, for which,
#        a ** 2 + b ** 2 = c ** 2
#
# For example, 3 ** 2 + 4 ** 2 = 25 = 5 ** 2.
# There is exactly one Pythagorean triplet for which a + b + c = 1000.
# Find the product a * b * c.
#
# Solution: 31875000 = 200 * 375 * 425
###############################################################################

from math import sqrt


# First step: getting all the squared numbers inferior to 1000. Since
# 1000 < 32 ** 2 this is equivalent to:
squared_numbers = [n ** 2 for n in range(500)]


# Second step: gathering all the triplets that match the condition
# a ** 2 + b ** 2 = c ** 2
triplets = []
for i in range(500):
    for j in range(500):
        k = squared_numbers[i] + squared_numbers[j]
        if k in squared_numbers:
            triplets.append([squared_numbers[i], squared_numbers[j], k])


# Third step: cheking which triplet has the sum of its components that equals
# 1000
for row in triplets:
    a = int(sqrt(row[0]))
    b = int(sqrt(row[1]))
    c = int(sqrt(row[2]))
    if a + b + c == 1000:
        res = a * b * c
        print "Solution might be:"
        print "\ta   = %d" % a
        print "\tb   = %d" % b
        print "\tc   = %d" % c
        print "\tabc = %d" % res
