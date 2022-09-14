#include<stdio.h>
#include<stdlib.h>
#include<netdb.h>
#include<string.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<sys/types.h>
#include <unistd.h>

#define PORT 8080
#define SA struct sockaddr
#define max sizeof(int)

void func(int confd){
    int a,b,c;
    read(confd,&a,max);
    read(confd,&b,max);
    c=a+b;
    write(confd,&c,max);
}
int main(){
    int sockfd,confd,len;
    struct sockaddr_in server,client;
    bzero(&server,sizeof(server));
    sockfd = socket(AF_INET,SOCK_STREAM,0);
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = htons(INADDR_ANY);
    server.sin_port = htons(PORT);

    bind(sockfd,(SA*)&server,sizeof(server));
    listen(sockfd,5);

    len = sizeof(client);
    confd = accept(sockfd,(SA*)&client,&len);
    // printf("%d",confd);
    func(confd);
    // close(sockfd);
}
