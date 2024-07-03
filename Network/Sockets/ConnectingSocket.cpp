#include "ConnectingSocket.hpp"

// Constructor
Network::ConnectingSocket::ConnectingSocket(int domain, int service, int protocol, int port, unsigned long interface) : Socket(domain, service, protocol, port, interface) {
    connect_to_network(get_sock(), get_address());
    std::cout << "Testing ConnectingSocket" << std::endl; 
    test_connection(connecting);
};

// Definition of connect_to_network
void Network::ConnectingSocket::connect_to_network(int sock, struct sockaddr_in address) {
    connecting = connect(sock, (struct sockaddr *)&address, sizeof(address));
}