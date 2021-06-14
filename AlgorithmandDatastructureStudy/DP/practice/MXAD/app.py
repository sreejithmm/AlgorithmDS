#https://www.codechef.com/UADPIP01/problems/MXAD
import numpy as np
import logging

logging.basicConfig(filename='logger.log', encoding='utf-8', level=logging.DEBUG)

dp=[None]*1000
dp[0]= 0
dp[1] = 1

def mxad(n):
    pass

def main():
    tests = input()
    tests = int(tests)
    logging.basicConfig(filename='logger.log', encoding='utf-8', level=logging.DEBUG)
    while (tests):
        n = input()
        n = int(n)
        logging.warning('start of test:%d',n)
        val = fib(n)
        tests = tests-1
        print(val)
    return 0
if __name__ =="__main__":
    main()


