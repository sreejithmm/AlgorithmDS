#include <stdio.h>

int editmatr[500][500]={0};

int min(int a,int b,int c)
{
	if(a <b && a<c )
		return a;
	if(b <a && b < c)
		return b;
	else
		return c;
}
int computeMinEdits(char *src, char* dest, int lensrc, int lendest)
{

    if(editmatr[lensrc][lendest] != 0)
	    return editmatr[lensrc][lendest] ;
    if(lensrc<0 && lendest < 0)
	    return INT_MAX;
    if(lensrc<0)
	    return lendest;
    if(lendest<0)
	    return lensrc;

     editmatr[lensrc][lendest] = min(computeMinEdits(src,dest,lensrc-1,lendest-1)+(src[lensrc]==dest[lendest]),
		     	computeMinEdits(src,dest,lensrc,lendest-1)+1,
		     	computeMinEdits(src,dest,lensrc-1,lendest)+1);

     return editmatr[lensrc][lendest];

	

}

int main()
{

	char src[500]={'\0'};
	char dst[500]={'\0'};

	int edits;
	printf("Enter source string\n");
	scanf("%s",src);

	printf("Enter destination string\n");
	scanf("%s",dst);

	edits = computeMinEdits(src,dest,strlen(src),strlen(dest));
	printf("Min edits = %d\n",edits);

}
