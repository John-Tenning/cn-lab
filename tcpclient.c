#include<stdlib.h>
#include<netdb.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<stdio.h>
#include <unistd.h>

#define port 8080
#define max sizeof(int)
#define SA struct sockaddr

void func(int sockfd){
    int a,b,c;
    scanf("%d",&a);
    scanf("%d",&b);
    write(sockfd,&a,max);
    write(sockfd,&b,max);
    read(sockfd,&c,max);
    printf("%d + %d = %d\n",a,b,c);
}
int main(){
    int sockfd,confd,len;
    struct sockaddr_in server,client;
    sockfd = socket(AF_INET,SOCK_STREAM,0);
    bzero(&server,sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_port = htons(port);

    connect(sockfd,(SA*)&server,sizeof(server));
    func(sockfd);
}
