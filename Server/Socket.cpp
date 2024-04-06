#include <iostream>
#include <cstring>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
class Socket{
private:
    int server_fd;
    sockaddr_in address;
    int addrlen = sizeof(address);
public:
    Socket(int port){
        // Create a socket
        server_fd = socket(AF_INET, SOCK_STREAM, 0);

        if (server_fd == -1) {
            std::cerr << "Socket creation failed\n";
        }

        // Server address structure
        address.sin_family = AF_INET;
        address.sin_addr.s_addr = INADDR_ANY; // Listen on all interfaces
        address.sin_port = htons(port); // Port 8080

        // Bind the socket to the given IP and port
        if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
            std::cerr << "Bind failed\n";
        }

        // Start listening for connections
        if (listen(server_fd, 3) < 0) {
            std::cerr << "Listen failed\n";
        }
        std::cout << "Server listening on port "<< port<<"\n";
    }
    void getData(){
        // Accept incoming connections
        int new_socket;
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
            std::cerr << "Accept failed\n";
        }

        // Read data from the client
        char buffer[1024] = {0};
        int valread = read(new_socket, buffer, 1024);
        std::cout << "Received: " << buffer << std::endl;

        // Send response to the client
        const char *hello = "pierdol sie filip!\n";
        send(new_socket, hello, strlen(hello), 0);
        std::cout << "Response sent\n";

        // Close the connection
        close(new_socket);
    }
    void closeSocket(){
        // Close the server socket
        close(server_fd);
    }

};