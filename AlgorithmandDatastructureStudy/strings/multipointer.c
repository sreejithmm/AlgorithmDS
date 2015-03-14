#include <stdio.h>

void print_pointer_arith(char * str)
{
	printf("Single pointer- character pointer\n");
	
	printf("%s\n",str);
	printf("%p\n",str);
	printf("%p\n",str+1);
	
	return;
}


void print_pointer_arith_2(char **str2)
{
#if 0
	printf("array of pointers\n");
	printf("%s\n",str2);
	printf("%p\n",str2);
	printf("%p\n",str2+1);

	return;
#endif
}

int main()
{

	char *str="name";
	
	char (*str2)[10]="myan";//"fdma","horrible","Mikeeerer",NULL,NULL,NULL,NULL,NULL,NULL};
	char arr[10]="hello";

	print_pointer_arith(str);
	//print_pointer_arith_2(str2);

	printf("%s\n",*str2);
	printf("%p\n",(str2));
	printf("%p\n",str2+1);
	printf("%s\n",*(str2+1));
	printf("%s\n",*(str2+2));
	printf("%s\n",*(str2+3));

	return 0;
	
}
