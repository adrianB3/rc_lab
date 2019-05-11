#include<sys/socket.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<netinet/in.h>
#include<string.h>
#include<arpa/inet.h>

#define PORT 8080

int main(int argc, char *argv[]){

    int server_fd, new_socket; // sock id initialization
    long valread;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    char * message = "Hello from server";

    if((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0){
        perror("Init socket");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );

    memset(address.sin_zero, '\n', sizeof address.sin_zero);

    if(bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0){
        perror("Init listen");
        exit(EXIT_FAILURE);
    }

    while(1){
        printf("\n+++++++ Waiting for new connection ++++++++\n\n");
        if((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0){
            perror("Init accept");
            exit(EXIT_FAILURE);
        }

        char buffer[30000] = {0};
        valread = read(new_socket, buffer, 30000);
        printf("%s\n", buffer);
        write(new_socket, message, strlen(message));
        printf("------------------Hello message sent-------------------\n");
        close(new_socket);
    }

    return 0;
}