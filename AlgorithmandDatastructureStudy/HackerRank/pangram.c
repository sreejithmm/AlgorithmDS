/*
 *
 * https://www.hackerrank.com/challenges/pangrams
 */

#include <stdio.h>
#include <stdlib.h>


typedef unsigned long long ULL;

char letters[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
int occ[26]={0};

void readLine(char str[])
{
	char ch;
	while((ch=getchar()) != EOF)
	{

		ch = tolower(ch);
		if( ch <= letters[25] && ch>=letters[0])
		{
			occ[ch-'a'] = 1;
		}
		

	}

	return ;
}
int main()
{
	char str[1000] = {'\0'};
	int i;

	readLine(str);
	for(i=0;i<26;i++)
	{
		if(occ[i]==0)
		{
			printf("not pangram\n");
			return 0;
		}
	}
	printf("pangram\n");
	return 0;
	
}
