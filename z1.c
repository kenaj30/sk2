#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/types.h>
#include <stdlib.h>


int main(int argc, char **argv){
    int sfd, rc;
    char buf[256];
    struct sockaddr_in saddr;
    struct hostent* addrent;

    addrent = gethostbyname(argv[1]);
    sfd = socket(PF_INET, SOCK_STREAM, 0);
    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(atoi(argv[2]));
    memcpy(&saddr.sin_addr.s_addr, addrent -> h_addr, addrent -> h_length);
    connect(sfd, (struct sockaddr*) &saddr, sizeof(saddr));
    rc = read(sfd, buf, sizeof(buf));
    write(1, buf, rc);
    close(sfd);

    return EXIT_SUCCESS;
}
