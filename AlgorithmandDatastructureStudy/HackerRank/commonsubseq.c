/*
 *
 * https://www.hackerrank.com/challenges/dynamic-programming-classics-the-longest-common-subsequence
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int commonIdx=0;

typedef struct _common {
	int length;
	int common[100];
}com_strct;

com_strct* matrix[100][100];

com_strct* find_common_subsequence(int A[],int B[],int n, int m)
{

	
	com_strct* ret=NULL;
	com_strct* local=NULL;



	if(m < 0 || n <0 )
		return NULL;
	if(matrix[n][m] != NULL)
//		return (matrix[n][m]);

#ifdef DEBUG
	printf("input: %d %d\n",n ,m);
#endif	
	if(A[n] == B[m]) {
                if(m > 0 && n > 0) {
			ret = find_common_subsequence(A,B,n-1,m-1);
		}
		local = (com_strct*)malloc(sizeof(com_strct));
		memset(local->common,0,sizeof(int)*100);

		local->length = 0;

		if(ret != NULL) {
#ifdef DEBUG
			printf("ret not null\n");
#endif
			local->length = ret->length + 1;
			memcpy(local->common,ret->common,sizeof(int)*100);

//			free(ret);

		} else {
#ifdef DEBUG
			printf("ret  null\n");
#endif

			local->length = local->length+1;
			commonIdx = 0;
		}
#ifdef DEBUG
		printf("DEBUG::%d %d\n",commonIdx,A[n]);
#endif
		local->common[commonIdx++] = A[n];

		matrix[n][m] = local;
		return local;

	}
	else {

		if(m > 0)
			ret = find_common_subsequence(A,B,n,m-1);
		if(n > 0)
			local = find_common_subsequence(A,B,n-1,m);
		if((ret != NULL)  && (local != NULL)) { 

			if( (ret->length > local->length)) {
#ifdef DEBUG
				printf("ret->legnth > local->length\n");
#endif
				commonIdx = ret->length;
				free(local);
				matrix[n][m] = ret;
				return ret;
			}
			else {
				commonIdx= local->length;
#ifdef DEBUG
				printf("local->length > ret->length\n");
#endif

				matrix[n][m] = local;
				free(ret);
				return local;
			}

	    	}
		else if( local != NULL) {
#ifdef DEBUG
			printf("local is nt  NULL\n");
#endif
			commonIdx= local->length;
				matrix[n][m] = local;
			return local;
		}
		else if( ret != NULL) {
#ifdef DEBUG
			printf("ret not null\n");
#endif

			commonIdx= ret->length;
				matrix[n][m] = ret;
			return ret;
		}


	}
#ifdef DEBUG
	printf("Somethng wrong\n");
#endif

		return NULL;
}

	


int main()
{
	int common[100]={0};
	com_strct* local;

	int n,i, m,t=0,j;
	int A[100]={0};
	int B[100]={0};

	for(i=0;i<100;i++)
		for(j=0;j<100;j++)
			matrix[i][j] = NULL;
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++)
		scanf("%d",&A[i]);
	for(i=0;i<m;i++)
		scanf("%d",&B[i]);

	if(m == 0 || n == 0)
	{
		if(A[0] == B[0])
		{
			printf("%d\n",A[0]);
		}
		
		goto exit;
	}
	local = find_common_subsequence(A,B,n-1,m-1);

	for(i=0; i<local->length; i++) {
		printf("%d ",local->common[i]);
	}
#ifdef DEBUG
	printf("\n");
#endif
exit:
	return 0;
}


