#include <stdio.h>


typedef struct _structure{

	int val1;
	char * name;
	int val2;
}packet;


packet * create_packet(int * len)
{
	int len;

	printf("Enter the number of database entries you want to make:");
	scanf("%d",&len);

	for(i=0;i<n;i++)
	{
		
	}
}
int main()
{
	packet *x;
	int length;

	x= create_packet(&length);

	send_packet(x,length);

	return 0;
}