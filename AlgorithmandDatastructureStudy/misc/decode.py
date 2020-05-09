import sys
def print_chars(string,val):
    for i in range(len(string)):
        if(string[i] != " "):
            base =ord(string[i])%97
            diff = base - val
            if (diff < 0):
                num = 122+diff+1
            else:
                num = diff+97
            sys.stdout.write(chr(num))
        else:
            sys.stdout.write(string[i])
    print ""

string="Dhfufydk fudjdff kfiffjdj djdud uxucj cjxd uckcjdu sudu xhssyz hzu xjcjd duxjcud uxudj xhxuxhx ducj hash u uxhxd jccjuc"


print "Original string:",string
print ""
for val in range (1,27):
    print_chars(string.lower(),val)
