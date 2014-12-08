/*
 * * Author :Sreejith M M
 * */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


void
calculateMaxSum (int arr[], int num, long long *contSum,
		 long long *nonContSum)
{
  int i;
  long long tCont = 0, tnonCont = 0;
  long long max = tCont;

  for (i = 0; i < num; i++)
    {
      tCont = tCont + arr[i];
      if (tCont > max || max == 0)
	{
	  max = tCont;

	}
      if (tCont <= 0)
	{
	  tCont = 0;
	}

      if (arr[i] > 0)
	{
	  tnonCont = tnonCont + arr[i];
	}

    }
  *contSum = max;
  if (max < 0)
    {
      *nonContSum = max;
    }
  else
    {

      *nonContSum = tnonCont;
    }


}

int
main ()
{

  int nT;
  int num;
  int i, j, k, m = 1;
  int arr[100000] = { 0 };
  long long contSum, nonContSum;

  scanf ("%d", &nT);
  while (nT)
    {
      scanf ("%d", &num);
      for (i = 0; i < num; i++)
	{
	  scanf ("%d", &arr[i]);
	}

      calculateMaxSum (arr, num, &contSum, &nonContSum);
      printf ("%lld %lld\n", contSum, nonContSum);
      for (i = 0; i < num; i++)
	{
	  arr[i] = 0;

	}
      nT--;
    }
  return 0;

}
