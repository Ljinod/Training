###############################################################################
# Problem:
# 2520 is the smallest number that can be divided by each of the numbers from 1
# to 10 without any remainder.
# What is the smallest positive number that is evenly divisible by all of the
# numbers from 1 to 20?
#
# Solution: 232792560
###############################################################################


# Calculation of the Greatest Common Factor
def gcf(a, b):
    sup = max(a, b)
    inf = min(a, b)
    tmp = sup % inf
    while(tmp != 0):
        sup = inf
        inf = tmp
        tmp = sup % inf

    return inf


# Calculation of the Least Common Multiple
def lcm(a, b):
    return (a * b) / gcf(a, b)


# Explanation: the smallest positive number that is evenly divisible by all the
# numbers from 1 to 20 is, simply, the LCM of all those numbers
res = 0
for i in range(1, 20):
    if res == 0:
        res = lcm(i, i+1)
    else:
        res = lcm(res, i)

print "The solution might be: %d" % res
