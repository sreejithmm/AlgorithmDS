#include <stdio.h>
#include <math.h>

typedef unsigned long long ULL;


ULL get_level(ULL src)
{
  ULL level ;
  level = (ULL)(log(src)/log(2));
}

ULL getshortestpath(ULL src, ULL dest)
{
  ULL parent ;
  ULL path = 1;
  ULL next;
  ULL lca,left_level,right_level,lca_level;

  lca = getLCA(src,dest);

  left_level = get_level(src);
  right_level = get_level(dest);

  lca_level = get_level(lca);

  path = left_level+right_level-(2*lca_level);

  return path;
}

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
    printf("%llu",spath);
    n--;
  }


}
