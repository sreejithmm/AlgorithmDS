#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include <arpa/inet.h>

#define BACKLOG 10


char    *method,   *uri;     



int main()
{

    int serverSocket = socket(
        AF_INET,      
        SOCK_STREAM, 
        0             
    );

    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8001);
    serverAddress.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    int ret ;

    ret =  bind(
        serverSocket,                         
        (struct sockaddr *) &serverAddress,  
        sizeof(serverAddress)                 
    );

    if(ret < 0) {

        perror("Bind error:");
        return -1;

    }

    int lis_ret = listen(serverSocket, BACKLOG);
    if (lis_ret < 0) {
        printf("Error: The server is not listening.\n");
        return 1;
    }

    printf("\n\nServer listening on http://127.0.0.1:8001\n");

    int clientSocket;

    while(1) {
        clientSocket = accept(serverSocket, NULL, NULL);
	
        unsigned long read_bytes;    
	    char buffer[30000] = {'\0'};
        char *temp ;
        read_bytes = read( clientSocket , buffer, 30000);
       
        printf("\nReceived -------\n");
        printf("%s\n",buffer );


        
        temp = buffer;

        method = strtok(buffer,  " \t\r\n");
        uri    = strtok(NULL, " \t");

        if (strcmp("/",uri)==0&&strcmp("GET",method)==0) {
                printf("Inside GET\n");
                char resp_data_get[8000]= "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 11\n\nHey Client!";

                send(clientSocket, resp_data_get, sizeof(resp_data_get), 0);


        } else if (strcmp("/",uri)==0&&strcmp("POST",method)==0) {
                printf("Inside POST\n");
                char resp_data_post [8000] = {'\0'};
                char payload[1000] = {'\0'};

                for (int i= 0; i < read_bytes; i++) {
                    if (strncmp(temp++, "\r\n\r\n", 4) == 0) break;
                }
                temp += 3;
                int payloadlen = strlen(temp)+19;
                sprintf(resp_data_post,"HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: %d\n\nYour message was : %s",payloadlen,temp);
                send(clientSocket, resp_data_post, sizeof(resp_data_post), 0);
        } else {
                printf(" Not GET or POST\n");

        }
 
        close(clientSocket);
    }
    return 0;
}

