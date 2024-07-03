#include "Socket.hpp"

Network::Socket::Socket(int domain, int service, int protocol, int port, unsigned long interface) {
	// Defining address structure
	address.sin_family = domain;
	address.sin_port = htons(port);
	address.sin_addr.s_addr = htonl(interface);

	// Establishing connection
	// Establishing socket
	int sock = socket(domain, service, protocol);
	int reuse = 1;
	setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, (const char*)&reuse, sizeof(reuse));
	setsockopt(sock, SOL_SOCKET, SO_REUSEPORT, (const char*)&reuse, sizeof(reuse));
	std::cout << "Testing Socket" << std::endl;
	test_connection(sock);
}

// Test the connection TODO: maybe change this
void Network::Socket::test_connection(int to_test) {
	std::cout << "in test connection " << to_test << std::endl;
	if (to_test < 0) {
		perror("Connection failed");
		exit(EXIT_FAILURE);
	}
}

// Getters
struct sockaddr_in Network::Socket::get_address() {
	return address;
}

int Network::Socket::get_sock() {
	return sock;
}