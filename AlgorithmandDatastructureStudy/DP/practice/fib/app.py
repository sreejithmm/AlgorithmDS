#https://www.codechef.com/UADPIP01/problems/FIBONUM
import numpy as np
def main():
    tests = int(input())
    dp=[None]*1000
    dp[0]= 0
    dp[1] = 1
    print(tests)
    while (tests):
        n = int(input())
        print(n)
        val = fib(n)
        tests = tests-1
    print(val)

        

def fib(n):    if ( n==1):
        return 1
    if (n==0):
        return 0
    
    if( n-2 >= 0):
            total =  (fib(n-1)+fib(n-2))

    return total

if __name__ == "__main__":
    main()
    


