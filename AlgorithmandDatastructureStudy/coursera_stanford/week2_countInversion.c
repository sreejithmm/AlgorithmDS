#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long uint64_t;
FILE * output;

uint64_t count_inversions(uint64_t arr[],uint64_t temp[],uint64_t startidx, uint64_t half,uint64_t endidx) {

    uint64_t inv = 0;

    int i , j, k =0;
    i=0;
    j=0;
    fprintf(output,"%s(): startidx = %llu endindex = %llu, middle = %llu\n",__FUNCTION__,startidx,endidx,half);
    fprintf(output,"%s() Left subarray\n",__FUNCTION__);

    for(i=startidx;i<=half-1;i++) {
        
        fprintf(output,"%llu ",arr[i]);

    }
    fprintf(output,"\n%s() Right subarray\n",__FUNCTION__);

    for(i=half;i<=endidx;i++) {
        
        fprintf(output,"%llu ",arr[i]);

    }

    i= startidx;
    k = startidx;
    j = half;
    while(i <= half-1 && j<=endidx){
        fprintf(output,"\ni = %d j = %d arr[i] = %llu arr[j] = %llu k = %d\n",i,j,arr[i],arr[j],k);
        if(arr[i] <= arr[j]){
            temp[k] = arr[i];
            i++;
            k++;
        }else {
            fprintf(output,"Counting Inversion \n");
            temp[k] = arr[j];
            j++;
            k++;
            inv+=(half-i);
         }
    }
    while(i<=half-1 ){
        temp[k] = arr[i];
        k++;
        i++;
    }
copy:
    while(j<=endidx ){
        temp[k] = arr[j];
        k++;
        j++;
    }

    for (i = startidx; i <= endidx; i++)  {
                arr[i] = temp[i]; 
    }

    fprintf(output,"%s(): Inversion =%llu\n",__FUNCTION__,inv);
    return inv;

}

uint64_t inversion(uint64_t arr[],uint64_t temp[] ,uint64_t startidx,  uint64_t endidx, int dir) {
    uint64_t half;
    uint64_t inv_count = 0;
    half = startidx+((endidx-startidx)/2);
    fprintf(output,"startidx = %llu endidx = %llu half=%llu direction=%d\n",startidx,endidx,half,dir);
    if (endidx > startidx) {

        inv_count += inversion(arr,temp,startidx,half,0);
        inv_count += inversion (arr,temp,half+1,endidx,1);

        inv_count +=count_inversions(arr,temp,startidx,half+1,endidx);

        fprintf(output,"count of inversion: %d\n",inv_count);
    }
    return inv_count;
}


int main(){
    FILE * fd;
    int i = 0;
    uint64_t num_array[100000];
    uint64_t count = 0;
    uint64_t temp_array[100000];

    output = fopen("out.txt","w");
    fd = fopen("test.txt","r");
    for(i=0;i<100000;i++){
        fscanf(fd,"%llu\n",&num_array[i]);
//        fprintf(output,"%llu ",num_array[i]);    
    }
    fprintf(output,"\n");
    fclose(fd);

    fd = fopen("original.txt","w");
    for(i=0;i<100000;i++){
        fprintf(fd,"%llu\n",num_array[i]);
        printf("%llu\n",num_array[i]);
    }


    fclose(fd);
    count = inversion(num_array,temp_array,0,99999,2);

    printf("Inversions = %llu\n",count);
    fclose(output);
    fd = fopen("sorted.txt","w");
     for(i=0;i<100000;i++){
        fprintf(fd,"%llu\n",temp_array[i]);
    }

    return 0;
}
