

#include <stdio.h>

#include <string.h>

int main()
{
	char str[100005] = { '\0' };
	int nT, i, j = 1, k, len, ex, idx = -1, m = 0,r,s;
	int idxarr[1000] = { 0 };

	scanf("%d", &nT);
	for (i = 0; i < nT; i++) {
		scanf("%s", str);
		len = strlen(str);

		ex = len / 2;
		for (k = 0; k < ex; k++) {

			if (str[k] == str[len - j]) {
				idx = -1;
				j++;
			} else {
				r = isPalindrome(str,k+1,len-j);
				if(r == 1)
				{
					idx = k;
					goto halt;

				}
				else
				{
					idx = len- j;
					goto halt;
				}

/*				
				if (str[k + 1] == str[len - j]) {
					idx = k;
					goto halt;
				} else if (str[k] == str[len - j - 1]) {
					idx = len - j;
					j++;
					k--;
					goto halt;
				} else {
#ifdef DEBUG
					printf("Unexpected\n");
#endif
				}
*/
			}
		}
	      halt:

		idxarr[m] = idx;
		m++;
		memset(str, '\0', 100005);
		j = 1;
	}

	for (i = 0; i < nT; i++) {
		printf("%d\n", idxarr[i]);
	}
}

int isPalindrome(char *s,int start, int end)
{
	int m = (start+end) /2;
	int i,j,k;
	
	for(j = start,k=0; j<m;j++,k++)
	{
		if(s[j] == s[end-k])
		{
			continue;
		}
		else {
			return 0;
		}
	}
	return 1;

}
