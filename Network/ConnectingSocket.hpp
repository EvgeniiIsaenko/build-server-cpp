#ifndef ConnectingSocket_hpp
#define ConnectingSocket_hpp

#include<stdio.h>
#include "Socket.hpp"

namespace Network {
    class ConnectingSocket : public Socket {
    public:
        // Constructor
        ConnectingSocket(int domain, int service, int protocol, int port, unsigned long interface);
        // Virtual function
        int connect_to_network(int sock, struct sockaddr_in address);
    };
}

#endif /* ConnectingSocket_hpp */