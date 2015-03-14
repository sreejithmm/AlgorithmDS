#include <stdio.h>

void print_pointer_arith(char * str)
{
	printf("Single pointer- character pointer\n");
	
	printf("%s\n",str);
	printf("%p\n",str);
	printf("%p\n",str+1);
	
	return;
}

int main()
{

	char *str="name";
	char *str[10]={"name","namak","horrible"};

	print_pointer_arith(str);
	print_pointer_arith_2(str);



	return 0;
	
}
