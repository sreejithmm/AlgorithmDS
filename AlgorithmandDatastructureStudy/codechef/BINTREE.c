#include <stdio.h>
#include <math.h>

typedef unsigned long long ULL;


ULL get_level(ULL src)
{
  ULL level ;
  level = (ULL)(log(src)/log(2));
  return level;

}

ULL getLCA(ULL src, ULL dest)
{

  while(src != dest)
  {
    if(src > dest)
      src = src>>1;
    else
      dest =  dest>>1;
  }

  return (src);
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
  path = left_level - lca_level;
  path = path + right_level - lca_level;
//  path = left_level+right_level-(2*lca_level);

  return path;
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
    spath = getshortestpath(i,j);
    printf("%llu\n",spath);
    n--;
  }


}
