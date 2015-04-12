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

	char*  str3[2][3] = {	{"seeping","danger","hsorsdsbo"},
				{"maru","dolphinnger","tort"},
		            };


#if 0					
	print_pointer_arith(str);
	//print_pointer_arith_2(str2);

	printf("%s\n",*str2);
	printf("%p\n",(str2));
	printf("%p\n",str2+1);
	printf("%s\n",*(str2+1));
	printf("%s\n",*(str2+2));
	printf("%s\n",*(str2+3));
#endif
	printf("%s\n",**str3); //prints seeping
	printf("%p\n",(str3)); //prints str3 values

	printf("%p\n",(*str3)); //prints str3 values
	printf("%p\n",(**str3));

	printf("%p\n",str3+1); // skips the first array of strings and goes to address of mary
	printf("%p\n",*(str3+1)); // same as above
	printf("%s\n",**(str3+1)); //prints maru
	

	return 0;
	
}
