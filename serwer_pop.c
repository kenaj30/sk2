#include <sys/socket.h> 
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/types.h>
#include <stdlib.h>

int main(){
    int sfd, cfd;
    socklen_t sl;
    char buf[256];
    int p, indeks =155638;
    struct sockaddr_in saddr, caddr;
    memset(&saddr, 0, sizeof(saddr));
    saddr.sin_family = AF_INET;
    saddr.sin_addr.s_addr = INADDR_ANY;
    saddr.sin_port = htons(1234);
    sfd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    bind(sfd, (struct sockaddr*) &saddr, sizeof(saddr));
    listen(sfd, 10);
    while(1) {
        sl = sizeof(caddr);
        cfd = accept(sfd, (struct sockaddr*) &caddr, &sl);
        p =  read(cfd, buf, sizeof(buf));
        p = atoi(buf);
        if (indeks ==p){
            write(cfd, "Jan Czemko!\n", 11);
        }else{
            write(cfd,"Nie ok indeks\n",14);
        }
        
        close(cfd);
    }
}
