#https://www.hackerrank.com/challenges/kaprekar-numbers
import sys
exists =0
num1=int(raw_input())
num2 = int(raw_input())

def sum_digits(n):
   r = 0
   while n:
       r, n = r + n % 10, n / 10
   return r

if(num1 > num2):
    print "INVALID RANGE"
else:
    for i in range(num1,num2+1):
        sqr= i*i
        if (sqr == 1):
            print 1,
        else:
            j = str(sqr)
            len2 = len(str(j))
            firsth,secondh = j[:int((len2/2))] , j[int((len2/2)):]
            if firsth=="":
                firsth='0'
            if secondh=="":
                secondh='0'
            sumd = int(firsth) + int(secondh)
            if(sumd == i):
                print i,
                exists = 1

    if (exists == 0):
        print "INVALID RANGE"
