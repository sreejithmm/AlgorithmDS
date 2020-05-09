#include <stdio.h>

int main()
{
	int nT,i,j,k,n,t,cnt=0,cancel=1;
	int arr[10]={0};

	scanf("%d",&nT);
	for(i=0;i<nT;i++)
	{
		scanf("%d",&n);
		scanf("%d",&k);
		for(j=0;j<n;j++)
		{
			scanf("%d",&t);
			if(t<=0)
				cnt++;
			if(cnt >= k){
				cancel = 0;
				break;
			}
		}
		if (cancel == 0)
		{
			arr[i] = 1;

		}
		cancel=1;
		cnt=0;
	}
	for(i=0;i<nT;i++)
	{
		if(arr[i] == 1)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}
