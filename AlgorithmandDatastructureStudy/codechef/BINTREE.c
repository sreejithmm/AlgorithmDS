#include <stdio.h>

typedef unsinged long long ULL;


void getmaxmin(ULL a, ULL b, ULL *max, ULL *min)
{
  if (a > b)
  {
    *max = a;
    *min = b;
  }
  else
  {
    *max = b;
    *max = a;
  }
  return ;

}
int main()
{
  ULL n,i,j;
  ULL max,min;
  ULL spath;

  scanf("%llu",&n);

  while(n)
  {
    scanf("%llu %llu",&i,&j);
    getmaxmin(i,j,&max,&min);
    spath = getshortestpath(max,min);
    
    n--
  }


}
