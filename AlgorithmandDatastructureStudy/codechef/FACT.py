def find_facts(num):
	x = 5
	facts =0
	while((num/x) != 0):
		facts = facts+ num/x
		x = x*5
	return facts

nt=int(raw_input())
while (nt):
	no = int(raw_input())
	facts = find_facts(no)
	print no
	nt = nt-1