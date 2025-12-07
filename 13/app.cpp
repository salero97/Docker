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
    address.sin_port = htons(8888);
    bind(server_fd, (struct sockaddr*)&address, sizeof(address));
    listen(server_fd, 3);
    std::cout << "MACVLAN demo on port 8888\n";
    while(true) {
        int client_socket = accept(server_fd, nullptr, nullptr);
        char hostname[256];
        gethostname(hostname, sizeof(hostname));
        char ip[INET_ADDRSTRLEN];
        struct sockaddr_in client_addr;
        socklen_t len = sizeof(client_addr);
        getpeername(client_socket, (struct sockaddr*)&client_addr, &len);
        inet_ntop(AF_INET, &client_addr.sin_addr, ip, sizeof(ip));
        std::string response = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<h1>MACVLAN Container</h1><p>Hostname: " + std::string(hostname) + "</p><p>Client IP: " + std::string(ip) + "</p>";
        send(client_socket, response.c_str(), response.length(), 0);
        close(client_socket);
    }
    return 0;
}
