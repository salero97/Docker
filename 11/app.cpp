#include <iostream>
#include <string>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstring>
int main() {
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);
    bind(server_fd, (struct sockaddr*)&address, sizeof(address));
    listen(server_fd, 3);
    std::cout << "Server started on port 8080\n";
    while(true) {
        int client_socket = accept(server_fd, nullptr, nullptr);
        char hostname[256];
        gethostname(hostname, sizeof(hostname));
        std::string response = "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\n\r\nHello from Bridge Network!\nContainer: " + std::string(hostname) + "\n";
        send(client_socket, response.c_str(), response.length(), 0);
        close(client_socket);
    }
    return 0;
}
