import sys

n,T = map(int,raw_input().split(" "))
array=map(int,raw_input().split(" "))
smallest = 1

while(T):
    start,end = map(int,raw_input().split(" "))
    smallest=array[start]
    for i in range(start,end+1):
        if(array[i]<smallest):
            smallest=array[i]
    print smallest
    T = T-1
