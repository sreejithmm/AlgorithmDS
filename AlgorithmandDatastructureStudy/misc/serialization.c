#include <stdio.h>


typedef struct _structure{

	int age;
	char * name;
	int compartment;
}packet;


packet * create_packet(int * len)
{
	int len;
	packet* pArray;
	char name[21]={'\0'};
	int age, compartment;

	printf("Enter the number of database entries you want to make:");
	scanf("%d",&len);
	pArray = (packet*)malloc(sizeof(packet)*len);

	for(i=0;i<len;i++)
	{
			printf("%d->Enter age,compartment,name in the order\n",i+1);
			scanf("%d%d%s",&age,&compartment,name);
			pArray[i].age = age;
			pArray[i].compartment = compartment;
			pArray[i].name = (char*)malloc(sizeof(char)*(strlen(name)+1));
			strcpy(pArray[0].name,name);

	}



	return pArray;
}

void send_packet(packet* pArray, int length)
{
	
}
int main()
{
	packet *x;
	int length;

	x= create_packet(&length);

	send_packet(x,length);

	return 0;
}