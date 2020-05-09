#include <stdio.h>

int array[10]={1,2,3,4,5,5,6,7,8,9};
int finddup();

int main() {


    printf("Duplicate element is : %d\n",finddup());


    return 0;

}


int finddup() {
  
  int idx=0;
  int sum = 0;
  int apsum=0;
  while(idx<10) {
      sum+=array[idx];
      idx++;
  }
  apsum= 45;
  return (sum-apsum); 
}
