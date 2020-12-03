'''
In this programming assignment you will implement one or more of the integer multiplication algorithms described in lecture.

To get the most out of this assignment, your program should restrict itself to multiplying only pairs of single-digit numbers. You can implement the grade-school algorithm if you want, but to get the most out of the assignment you'll want to implement recursive integer multiplication and/or Karatsuba's algorithm.

So: what's the product of the following two 64-digit numbers?

3141592653589793238462643383279502884197169399375105820974944592

2718281828459045235360287471352662497757247093699959574966967627
'''

num1 = 3141592653589793238462643383279502884197169399375105820974944592
num2 = 2718281828459045235360287471352662497757247093699959574966967627

print(num1*num2)
import math as m
def add (num1, num2 ):
    pass

def multiply(num1,num2)->int:
    str1  = len(str(num1))
    str2 = len(str(num2))
    if(str1 == 0 or str2 == 0):
        return 0
    if(str1 == 1 or str2 == 1):
        return(num1*num2)
    val1 = m.pow(10,(str1/2))
    val2 = m.pow(10,(str2/2))
    prod = multiply(val1,val2)
    





#val = multiply(2,3)

print(val)