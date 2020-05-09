#include <stdio.h>

void soln1(int);
void soln2(int);

int main()
{

    int num;
    printf("Enter a number \n");
    scanf("%d",&num);

    printf("recursive soln: ");
    soln1(num);

    printf("\nLoop soln: ");
    soln2(num);

    return 0;
}


void soln1(int num)
{

    if(num == 0) {
        return;
    }
    soln1(num >> 1);
    (num &0x01) ?printf("1"):printf("0");
    return;
}
void soln2(int num)
{
  unsigned int bits;
  int i =31;

  for(bits=(0x01<<i);i>=0;bits=(0x01<<(i)))
  {
//      printf("\n%d\n",bits);
      i--;
      (num & bits)?printf("1"):printf("0");
  }
    printf("\n");
    return;

}
