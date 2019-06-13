#include <iostream>
#include <pthread.h>
#include <string>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstring>
#include "RequestHandler.h"
#include "ResponseHandler.h"

class server {
private:
    int port = 8080;
    int serverSocket;
    int clientSocket;
    struct sockaddr_in serverAddr, clientAddr;
    socklen_t addr_size;

public:
    server(){
        // create socket
        this->serverSocket = socket(AF_INET, SOCK_STREAM, 0);
        if(this->serverSocket < 0){
            perror("Error creating server socket");
        }

        bzero((char *) &serverAddr, sizeof(serverAddr));
        this->serverAddr.sin_family = AF_INET; // Address family is Internet
        this->serverAddr.sin_port = htons(this->port); // host to network short address(16bit)
        this->serverAddr.sin_addr.s_addr = INADDR_ANY; // any client address accepted

        if(bind(serverSocket, (struct sockaddr *) &this->serverAddr, sizeof(this->serverAddr)) < 0){
            perror("Error binding");
        }
    }

    void start(){
        listen(this->serverSocket, 5);
        std::cout << "Waiting for connections." << std::endl;
        while(this->clientSocket = accept(this->serverSocket, 0, 0)){
            pthread_t client_thread;

            pthread_create(&client_thread, 0, this->client_handler, (void*)this->clientSocket);
        }
    }

    static void * client_handler(void * param){

        pthread_detach(pthread_self());

        char buf[2048];
        int count;

        struct sockaddr_in client_addr;
        char clientIP[16];
        unsigned int clientPort;

        pthread_t id = pthread_self();

        int clientSocket = static_cast<int>(reinterpret_cast<std::intptr_t>(param));
        printf("Created thread: %d\n", int(id));
        printf("Connected with sock id: %d\n", clientSocket);

//        bzero(&client_addr, sizeof(client_addr));
//
//        getsockname(clientSocket, (struct sockaddr *) &client_addr, reinterpret_cast<socklen_t *>(sizeof(client_addr)));
//        inet_ntop(AF_INET, &client_addr.sin_addr, clientIP, sizeof(clientIP));
//        clientPort = ntohs(client_addr.sin_port);
//
//        printf("Client ip address: %s\n", clientIP);
//        printf("Client port : %u\n", clientPort);

        while( count = read(clientSocket, buf, 2047) > 0 ) {

            RequestHandler reqh;
            ResponseHandler resh;

            Request req = reqh.parseRequest(std::string(buf));
            std::string res = resh.getResponse(req);

            write(clientSocket, res.c_str(), sizeof(char)*res.size());

            close(clientSocket);
        }
    }
};

int main(int argc, char *argv[]) {

    server srv;
    srv.start();
    

    return 0;
}