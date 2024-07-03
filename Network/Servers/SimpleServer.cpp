#include "SimpleServer.hpp"

// Constructor
Network::SimpleServer::SimpleServer(int domain, int service, int protocol, int port, unsigned long interface, int backlog) {
    // This is the socket for which memory was reserved
    socket = new ListeningSocket(domain, service, protocol, port, interface, backlog);
}

Network::ListeningSocket * Network::SimpleServer::get_socket() {
    return socket;
}