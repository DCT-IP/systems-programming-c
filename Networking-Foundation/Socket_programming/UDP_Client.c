// udp_client.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int sockfd;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in server_addr;

    // 1. Create socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    // 2. Configure server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    // 3. Send message
    char *msg = "Hello from client!";
    sendto(sockfd, msg, strlen(msg), 0,
           (struct sockaddr*)&server_addr, sizeof(server_addr));

    // 4. Receive response
    socklen_t len = sizeof(server_addr);
    int n = recvfrom(sockfd, buffer, BUFFER_SIZE, 0,
                     (struct sockaddr*)&server_addr, &len);
    buffer[n] = '\0';

    printf("Server: %s\n", buffer);

    close(sockfd);
    return 0;
}