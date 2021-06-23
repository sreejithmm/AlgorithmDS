#https://www.codechef.com/UADPIP01/problems/MXAD
#https://www.codechef.com/UADPIP01/problems/MXAD
import numpy as np
import logging
import math

#encoding works only in python3.9 onwards
#logging.basicConfig(filename='logger.log', encoding='utf-8', level=logging.DEBUG)
logging.basicConfig(filename='logger.log', level=logging.DEBUG)


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
pinf = math.inf
ninf = -math.inf

def log2ddp(dp):
    for row in range(100000):
        for col in range(100000):
            if(dp[row][col] != ninf ):
                logging.warning(dp[row][col])
                logging.warning(" ")
        logging.warning("\n")
    print()

def kfib(n,k,dp):
    if(n<=1 or k<=0):
        return 0
    if(n<=k):
        return 1
    if(dp[n][k] != 0):
        return dp[n][k]
    for j in range(1,k):
        dp[n][k] = dp[n][k] + kfib(n-j,k,dp) 
    log2ddp(dp)
    return dp[n][k]

def main():
    tests = 1
 #   dp = [[ninf]*100000 for i in range(100000)]
    dp = [[ninf]*100000]*100000
    print(tests)
    while (tests):
        n, k = input().split()
        n = int(n)
        k = int(k)
        logging.warning('start of test:%d',n)
        val = kfib(n,k,dp)
        print (val%mod)
        tests = tests-1
        print(tests)
        print(tests)
    return 0


if __name__ =="__main__":
    main()