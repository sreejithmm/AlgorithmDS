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

mod=1000000007

dp=[None]*1000
dp[0]= 0
dp[1] = 1

def mxad(numbers,n,i):
    if(i<0):
        return 0
    else:
        if(dp[i] is not None):
            return dp[i]
        for j in range(1,i):
            dp[i] = max(dp[i],numbers[i] + mxad(numers,n,i-j))
    
    return dp[i]

def main():
    tests = input()
    tests = int(tests)
    logging.basicConfig(filename='logger.log', encoding='utf-8', level=logging.DEBUG)
    while (tests):
        n = input()
        n = int(n)
        logging.warning('start of test:%d - number of integers:',n)
        numbers = list(map(int, input().split()))
        logl(numbers)
        sum = mxad(numbers,n,n-1)
        tests= tests-1

    return 0
if __name__ =="__main__":
    main()


