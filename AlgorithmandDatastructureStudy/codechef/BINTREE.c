#include <stdio.h>

typedef unsigned long long ULL;

ULL getparent(ULL src)
{
  return (src/2);
}

ULL leftchildof(ULL indx)
{
  return (2*indx );
}

ULL rightchildof(ULL indx)
{
  return (2*indx + 1);
}

ULL getshortestpath(ULL src, ULL dest)
{
  ULL parent ;
  ULL path = 1;
  ULL next;

  parent = getparent (src);
  if(parent == dest)
  {
    return path;
  }
  next = parent;

  while(next != dest)
  {

    // if (leftchildof(parent) < dest)
    // {
    //
    //   parent = parent * 2;
    //
    // }
    // else if(rightchildof(parent) < dest)
    // {
    //   parent = parent * 2 + 1;
    //
    // }
    // else
    // {
    //   parent = getparent(parent);
    //
    // }
     if(leftchildof(next)==dest || rightchildof(next==dest))
     {
       next = dest;
     }
     else if((dest > leftchildof(next) && dest > rightchildof(next))
                || (dest<leftchildof(next) && dest < rightchildof(next)))
      {
        next = getparent(next);
      }
      else if(dest > leftchildof(next) && dest < rightchildof(next))
      {
        
      }
    path++;
  }
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
