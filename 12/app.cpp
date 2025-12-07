#include <iostream>
#include <string>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstring>
#include <ifaddrs.h>
int main() {
    struct ifaddrs *ifaddr, *ifa;
    getifaddrs(&ifaddr);
    std::cout << "Network interfaces:\n";
    for(ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {
        if(ifa->ifa_addr && ifa->ifa_addr->sa_family == AF_INET) {
            char ip[INET_ADDRSTRLEN];
            struct sockaddr_in *addr = (struct sockaddr_in*)ifa->ifa_addr;
            inet_ntop(AF_INET, &addr->sin_addr, ip, sizeof(ip));
            std::cout << ifa->ifa_name << ": " << ip << "\n";
        }
    }
    freeifaddrs(ifaddr);
    return 0;
}
