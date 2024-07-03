#ifndef SimpleServer_hpp
#define SimpleServer_hpp

#include <stdio.h>
#include "../serverlib-network.hpp" // includes all socket types

namespace Network {
    class SimpleServer {
    private:
        ListeningSocket * socket; // hold off the socket defining by reserving memory. Defined by the server when needed
        // Utility functions for the server to work. Makes the server to define them once initialized
        virtual void accepter() = 0;
        virtual void handler() = 0;
        virtual void responder() = 0;
    public:
        SimpleServer(int domain, int service, int protocol, int port, unsigned long interface, int backlog);
        // Launch function is also defined by the constructor
        virtual void launch() = 0;
        ListeningSocket * get_socket();
    };
}

#endif