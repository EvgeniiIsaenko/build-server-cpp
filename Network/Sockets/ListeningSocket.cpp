#include "ListeningSocket.hpp"

// Constructor
Network::ListeningSocket::ListeningSocket(int domain, int service, int protocol, int port, unsigned long interface, int backlog) : BindingSocket(domain, service, protocol, port, interface) {
    this->backlog = backlog;
    start_listening();
    std::cout << "Testing ListeningSocket" << std::endl;
    test_connection(listening);
}

// Listener
void Network::ListeningSocket::start_listening() {
    listening = listen(get_sock(), backlog);
};