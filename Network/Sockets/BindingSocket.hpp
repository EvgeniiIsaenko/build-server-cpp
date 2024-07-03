#ifndef BindingSocket_hpp
#define BindingSocket_hpp

#include <stdio.h>
#include "Socket.hpp"

namespace Network {
    class BindingSocket : public Socket {
    private:
        int binding;
    public:
        // Constructor
        BindingSocket(int domain, int service, int protocol, int port, unsigned long interface);
        // Virtual function
        void connect_to_network(int sock, struct sockaddr_in address);
    }; 
}

#endif /* BindingSocket_hpp */