/*
 *
 * https://www.hackerrank.com/challenges/gem-stones
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int nR,i,k,cnt=0;
	char str[100]={'\0'};
	int len;
	int arr[26]={0};
	int dup[26]={0};
	scanf("%d",&nR);

	for(i = 0; i < nR-1; i++){
		scanf("%s",str);
#ifdef DEBUG
		printf("read:%s\n", str);
#endif
		len = strlen(str);
		for(k = 0; k < len; k++){
			if (dup[str[k] - 'a'] == 0){
				arr[str[k]-'a'] += 1;
				dup[str[k]-'a'] =1;
			}
		}
		memset(str,'\0',100);
		memset(dup,0,sizeof(int)*26);

	}
	scanf("%s",str);
	for(k = 0; k < strlen(str); k++){
		if(arr[str[k]-'a'] == nR-1 && dup[str[k]-'a'] == 0){
			cnt++;
			dup[str[k] - 'a'] = 1;
		}
	}
	printf("%d\n",cnt);
	return 0;

}
