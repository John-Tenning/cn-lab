#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#define SA struct sockaddr

int main()
{
    int sockfd;
    struct sockaddr_in serv,cli;
    int n1,n2,ans=0,zz;

    sockfd=socket(AF_INET,SOCK_DGRAM,0);

    serv.sin_family=AF_INET;
    serv.sin_addr.s_addr= htonl(INADDR_ANY);
    serv.sin_port=htons(8080);

    bind(sockfd,(SA*)&serv,sizeof(serv));
    
    int len=sizeof(cli);
    recvfrom(sockfd,&n1,sizeof(n1),0,(SA*)&cli,&len);
    printf("From Client : Number 1 : %d\n",n1);
    recvfrom(sockfd,&n2,sizeof(n2),0,(SA*)&cli,&len);
    printf("From Client : Number 2 : %d\n",n2);

    ans=n1+n2;
    sendto(sockfd,&ans,sizeof(ans),0,(SA*)&cli,len);
    
    close(sockfd);
    return 0;

}
