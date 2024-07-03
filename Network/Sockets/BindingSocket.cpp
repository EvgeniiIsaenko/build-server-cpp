#include "BindingSocket.hpp"

// Constructor
Network::BindingSocket::BindingSocket(int domain, int service, int protocol, int port, unsigned long interface) : Socket(domain, service, protocol, port, interface) {
    set_connection(connect_to_network(get_sock(), get_address()));
    test_connection(get_connection());
};

// Definition of connect_to network
int Network::BindingSocket::connect_to_network(int sock, struct sockaddr_in address) {
    return bind(sock, (struct sockaddr *)&address, sizeof(address));
}