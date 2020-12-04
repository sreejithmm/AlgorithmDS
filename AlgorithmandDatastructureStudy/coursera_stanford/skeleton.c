#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long uint64_t;
FILE * output;

//#define TEST 1


int main(){
    FILE * fd;
    int i = 0;
#ifndef TEST
    uint64_t num_array[10,000];
#else
    uint64_t num_array[10,000];
#endif
    uint64_t comparisons = 0;

    output = fopen("out.txt","w");
#ifndef TEST
    fd = fopen("QuickSort.txt","r");
#else
    fd = fopen("test.txt","r");
#endif

    for(i=0;i<10000;i++){
        fscanf(fd,"%llu\n",&num_array[i]);
    }
    fprintf(output,"\n");
    /* close input file */
    fclose(fd);

    comparisons = quicksort(num_array,10000);

    printf("Total comparisons = %llu\n",comparisons);
    
    /*close debug file */
    fclose(output);


    return 0;
}
