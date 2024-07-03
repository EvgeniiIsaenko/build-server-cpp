#include "BindingSocket.hpp"

// Constructor
Network::BindingSocket::BindingSocket(int domain, int service, int protocol, int port, unsigned long interface) : Socket(domain, service, protocol, port, interface) {
    connect_to_network(get_sock(), get_address());
    std::cout << "Testing BindingSocket " << std::endl; 
    test_connection(binding);
};

// Definition of connect_to network
void Network::BindingSocket::connect_to_network(int sock, struct sockaddr_in address) {
    binding = bind(sock, (struct sockaddr *)&address, sizeof(address));
}