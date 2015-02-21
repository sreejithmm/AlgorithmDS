
#include "stddheaders.h"

int main()
{
	int i,k,j;

	int n,t;
	printf("Enter the number :\n");
	scanf("%d",&n);
	t=n;
	i = 9;

	k=0;
	j=1;


	while(i)
	{
		if(n%i ==0 )
		{
			k= i*j+k;
			j = j*10;
			n = n/i;
		}
		i--;
		 
	}
	printf("The smallest number which produces the number %d as the product of its digits is %d\n",t,k);
}
