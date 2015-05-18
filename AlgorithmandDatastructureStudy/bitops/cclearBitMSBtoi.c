#include <stdio.h>

void clearbit(int num, int i)
{
	int mask = (1<<i)-1;
	int val;

	printf("%d %d\n",1<<i,mask);

	val = num & mask;
	printf("%d is final",val);

}
int main()
{
	
	clearbit(10,2);
}
