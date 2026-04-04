#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <string.h>

int main(){
    int sockfd;

    struct sockaddr_in addr;

    // 1. socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    // allow port reuse
    int opt = 1;
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    // 2. initialize struct
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8080);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);

    // 3. bind
    if (bind(sockfd, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        perror("bind");
        exit(1);
    }

    // 4. listen
    listen(sockfd, 5);
    printf("Server listening on port 8080...\n");

    while(1){
        // 5. accept
        int clientfd = accept(sockfd, NULL, NULL);
        if(clientfd < 0){
            perror("accept");
            continue;
        }

        // 6. recv
        char buffer[2048];
        int bytes = recv(clientfd, buffer, sizeof(buffer) - 1, 0);

        if (bytes <= 0) {
            close(clientfd);
            continue;
        }

        buffer[bytes] = '\0';

        // parse request
        char method[10], path[100];
        sscanf(buffer, "%9s %99s", method, path);

        printf("Method: %s, Path: %s\n", method, path);

        // handle only GET
        if (strcmp(method, "GET") == 0) {

            // route: home
            if (strcmp(path, "/") == 0) {

                FILE *fp = fopen("index.html", "r");

                if (fp == NULL) {
                    char *resp =
                        "HTTP/1.0 500 Internal Server Error\r\n\r\n";
                    send(clientfd, resp, strlen(resp), 0);
                } else {
                    char filebuf[4096];
                    int n = fread(filebuf, 1, sizeof(filebuf), fp);

                    char header[] =
                        "HTTP/1.0 200 OK\r\n"
                        "Content-Type: text/html\r\n"
                        "\r\n";

                    send(clientfd, header, strlen(header), 0);
                    send(clientfd, filebuf, n, 0);

                    fclose(fp);
                }

            } else {
                // 404 route
                char *resp =
                    "HTTP/1.0 404 Not Found\r\n\r\n"
                    "404 Not Found";
                send(clientfd, resp, strlen(resp), 0);
            }

        } else {
            // non-GET
            char *resp =
                "HTTP/1.0 405 Method Not Allowed\r\n\r\n";
            send(clientfd, resp, strlen(resp), 0);
        }

        // 7. close
        close(clientfd);
    }

    return 0;
}