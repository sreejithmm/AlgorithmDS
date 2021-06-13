#https://www.codechef.com/UADPIP01/problems/FIBONUM
import numpy as np
import logging

dp=[None]*1000
dp[0]= 0
dp[1] = 1

def main():
    tests = int(input())
    logging.basicConfig(filename='logger.log', encoding='utf-8', level=logging.DEBUG)
    while (tests):
        n = int(input())
        logging.warning('start of test:%d',n)
        val = fib(n)
        tests = tests-1
        print(val)
    

        

def fib(n):    
    
    logging.debug('fib entry = %d',n)  # will print a message to the console
    total = 0
    if ( n==1):
        return 1
    if (n==0):
        return 0
    if(dp[n] is not None):
        return dp[n]
    if( n-2 >= 0):
            total =  (fib(n-1)+fib(n-2))

    dp[n] = total
    return total

if __name__ == "__main__":
    main()
    


