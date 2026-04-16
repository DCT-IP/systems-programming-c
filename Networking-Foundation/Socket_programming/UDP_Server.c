// udp_server.c
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
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);

    // 1. Create socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    // 2. Configure server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // 3. Bind socket
    bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));

    printf("UDP Server listening on port %d...\n", PORT);

    while (1) {
        // 4. Receive message
        int n = recvfrom(sockfd, buffer, BUFFER_SIZE, 0,
                         (struct sockaddr*)&client_addr, &addr_len);
        buffer[n] = '\0';

        printf("Client: %s\n", buffer);

        // 5. Send response
        char *response = "Message received!";
        sendto(sockfd, response, strlen(response), 0,
               (struct sockaddr*)&client_addr, addr_len);
    }

    close(sockfd);
    return 0;
}