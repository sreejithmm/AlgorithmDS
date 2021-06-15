#https://www.codechef.com/UADPIP01/problems/MXAD
import numpy as np
import logging

logging.basicConfig(filename='logger.log', encoding='utf-8', level=logging.DEBUG)
import sys
import math
import bisect
from sys import stdin,stdout
from math import gcd,floor,sqrt,log
from collections import defaultdict as dd
from bisect import bisect_left as bl,bisect_right as br

sys.setrecursionlimit(100000000)

inp    =lambda: int(input())
# strng  =lambda: input().strip()
# jn     =lambda x,l: x.join(map(str,l))
# strl   =lambda: list(input().strip())
# mul    =lambda: map(int,input().strip().split())
# mulf   =lambda: map(float,input().strip().split())
# seq    =lambda: list(map(int,input().strip().split()))

# ceil   =lambda x: int(x) if(x==int(x)) else int(x)+1
# ceildiv=lambda x,d: x//d if(x%d==0) else x//d+1

# flush  =lambda: stdout.flush()
# stdstr =lambda: stdin.readline()
# stdint =lambda: int(stdin.readline())
# stdpr  =lambda x: stdout.write(str(x))
logl   = lambda l: logging.info(str(l))
logw   = lambda l: logging.warning(str(l))

mod=1000000007

def mxad(numbers,n,i,dp):
    if(i<0):
        logw("i is less than 0")
        return 0
    else:
        logging.warning('enter else')
        logl(numbers)
        logw('i='+str(i))
        
        if(dp[i] != -1):
            return dp[i]
        else:
            total = max(dp[i],numbers[i]+ mxad(numbers,n,i-2,dp),mxad(numbers,n,i-1,dp))
            logging.warning('dp[%d] is %d',i,dp[i])
    logging.info("total = %d i is %d",total,i)
    dp[i] = total
    return dp[i]

def main():
    tests = input()
    tests = int(tests)
    dp=[-1]*1000
    logging.basicConfig(filename='logger.log', encoding='utf-8', level=logging.DEBUG)
    while (tests):
        n = input()
        n = int(n)
        logging.warning('start of test:%d - number of integers:',n)
        numbers = list(map(int, input().split()))
        logl(numbers)
        sum = mxad(numbers,n,n-1,dp)
        print(sum)
        dp=[-1]*1000
        logl(dp)
        tests= tests-1

    return 0
if __name__ =="__main__":
    main()


