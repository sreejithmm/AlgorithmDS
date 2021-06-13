#https://www.codechef.com/UADPIP01/problems/FIBONUM
import numpy as np
import logging

logging.basicConfig(filename='logger.log', encoding='utf-8', level=logging.DEBUG)

dp=[None]*1000
dp[0]= 0
dp[1] = 1

def main():
    tests = input()
    tests = int(tests)
    logging.basicConfig(filename='logger.log', encoding='utf-8', level=logging.DEBUG)
    while (tests):
 #       n = int(input())
        n = input()
        n = int(n)
        logging.warning('start of test:%d',n)
        val = fib(n)
        tests = tests-1
        print(val)
    return 0

        

def fib(n):    
    
    logging.debug('fib entry = %d',n)  # will print a message to the console
    total = 0
    if ( n==1):
        return 1
    if (n==0):
        return 0
    if(dp[n] is not None):
        logging.debug('dp is not none-%d',dp[n])
        return dp[n]
    if( n-2 >= 0):
            total =  (fib(n-1)+fib(n-2))
    logging.fatal('dp[%d]=%d',n,total)
    dp[n] = total
    return total

if __name__ == "__main__":
    main()
    


