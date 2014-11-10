#include <stdio.h>
#include <string.h>

void reverse_print(char*);
char* reverse(char*s);

int main(){

char s[] ="this";
        reverse_print(s);
       printf("%s\n",reverse(s));



}


void reverse_print(char *str){

//    printf("%c",*str);
    if (*str=='\0')
    {
        return;

    }
    reverse_print(str+1);
    printf("%c",*str);
    printf("\n");
    return;

}

char* reverse(char *s){


return ((!*s)?s:strcpy(s,strncat(reverse(s+1),s,1)));


}
