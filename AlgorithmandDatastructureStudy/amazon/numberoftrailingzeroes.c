/* number of trailing zeroes in factorial
 *
 */

#include "stddheaders.h"

int main()
{
	int x=0;
	int n;
	printf("Enter the number\n");
	scanf("%d",&n);
	
	while(n)
	{
		x=n/5+x;
		n=(n/5);


	}

	printf("Answer is : %d\n",x);


}
