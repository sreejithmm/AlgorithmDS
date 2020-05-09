def calculate_balance(wd,balance):
    if(wd > balance-0.5):
        print '%.2f'%balance
    elif(wd%5 !=0):
        print '%.2f'%balance
    else:
        balance = balance - wd - 0.5
        print '%.2f'%balance
    return

string = raw_input()

x,y = string.split()
x=int(x)

y=float(y)
calculate_balance(x,y)
