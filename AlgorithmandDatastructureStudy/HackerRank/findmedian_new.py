# Enter your code here. Read input from STDIN. Print output to STDOUT
numbers=[]
f=open('input01.txt','r')
N=f.readline().rstrip()
print N
numbersInput=f.readline().rstrip()
for num in numbersInput.split():
    numbers.append(int(num))
#print numbers
numbers.sort()
#print numbers
print numbers[len(numbers)/2]
