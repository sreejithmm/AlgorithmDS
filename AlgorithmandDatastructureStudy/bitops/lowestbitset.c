#include <stdio.h>
#include <stdlib.h>

void printInBinary(int num)
{
  int i = 31;
  int x;

  for(x=(1<<i);i>=0;x=(i<<i))
  {
    (num & x)?printf("1"):printf("0");
    i--;
  }
  return;
}

int main(){


    int num,lb;
    printf("Enter a number\n");
    scanf("%d",&num);
    lb = (num) & -(num);
    printf("Lowest bit set:%d\n",lb);
    printf("Lowest bit set:%d\n",-num);
    printInBinary(-(num));
    return 0;
}
