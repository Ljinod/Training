###############################################################################
# Problem:
# Find the greatest product of five consecutive digits in the 1000-digit number
#
# Solution:
###############################################################################

a = 10 ** 1001
res = 1
for i in range(1, 6):
    res *= (a-i)

print res
