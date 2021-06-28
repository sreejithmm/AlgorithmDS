#https://www.codechef.com/?destination=/UADPIP01/problems/SUBINC
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

def subinc():
    pass

def main():
    tests = int(input())
    dp = [0]*10
    while (tests):
        n, k = input().split()
        n = int(n)
        k = int(k)
        logging.warning('start of test:%d',n)
        subinc()
        tests = tests-1
    return 0



if __name__ =="__main__":
    main()