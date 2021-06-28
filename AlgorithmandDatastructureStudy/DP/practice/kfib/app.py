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
logi   = lambda l: logging.warning(l)
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

def kfib(n,k,x,dp):
    logging.warning("enter kfib for  n=%d k = %d , x= %d",n,k,x)
    '''
    if(n<x or x<0):
        logw("inside first if")
        return dp[n]
    '''
    logging.warning("index = %d",n)
    if(dp[n] != 0):
        logw("inside dp is non zero")
        return dp[n]
    if(n<=k):
        logw("inside second if")
        dp[n] = 1
        return 1
    for j in range(1,k+1):
         logging.warning("execute for j:%d n=%d k = %d",j,n,k)
 #        dp[n] = dp[n-1]+kfib(n-j,k,x,dp) 
         dp[n] = dp[n]+kfib(n-j,k,x,dp) 
    logging.warning("dp[%d] = %d",n,dp[n])
    return dp[n]

def main():
    tests = 1
 #   dp = [[ninf]*100000 for i in range(100000)]
 #   dp = [[0]*10]*10
    dp = [0]*10
    while (tests):
        n, k = input().split()
        n = int(n)
        k = int(k)
        x = n-k
        for j in range(0,k):
            dp[j] = 1
        print(dp)

        logging.warning('start of test:%d',n)
        val = kfib(n,k,x,dp)
        print (val%mod)
        tests = tests-1
        print(dp)
    return 0



if __name__ =="__main__":
    main()