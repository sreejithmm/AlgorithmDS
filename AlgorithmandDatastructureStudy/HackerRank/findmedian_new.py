# Enter your code here. Read input from STDIN. Print output to STDOUT
N=raw_input()
N=int(N)
numbers=[]
numbersInput=raw_input()
for num in numbersInput.split():
    numbers.append(int(num))
numbers.sort()
print numbers[len(numbers)/2]
