#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <strings.h>
#define DEBUG 

int main()
{

	int nT,nL,nS;
	int i,j=0,k;
	int *LadderArr;
	int *SnakeArr;
	int board[100]={1};
	scanf("%d",&nT);
	
	while(nT)
	{
		scanf("%d,%d",&nL,&nS);
		LadderArr=(int*)calloc(2*nL,sizeof(int));
		SnakeArr=(int*)calloc(nS,sizeof(int));
		for(i=0;i<nL;i++)
		{
			scanf("%d,%d",&LadderArr[j++],&LadderArr[j++]);
		}
		j=0;
		for(i=0;i<nS;i++)
		{
			scanf("%d,%d",&SnakeArr[j],&k);
			board[SnakeArr[j]]=0;
			j++;
		}

#ifdef DEBUG
		for(i=0;i<2*nL;i++)
		{
			printf("LadderArr:%d->%d\n",i,LadderArr[i]);
		}
		for(i=0;i<nS;i++)
		{
			printf("SnakeArr:%d->%d\n",i,SnakeArr[i]);
		}
#endif	

		calculateMoves(LadderArr,SnakeArr,board,nL,nS);
		nT--;
	}

	return 0;


}


void calculateMoves(int LadderArr[],int SnakeArr,int board,int nL, int nS)
{
	


}
