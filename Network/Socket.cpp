#include "Socket.hpp"

Network::Socket::Socket(int domain, int service, int protocol, int port, unsigned long interface) {
	// Defining address structure
	address.sin_family = domain;
	address.sin_port = htons(port);
	address.sin_addr.s_addr = htonl(interface);

	// Establishing connection
	// Establishing socket
	int sock = socket(domain, service, protocol);
	test_connection(sock);

	//Establishing connection itself
	connection = connect_to_network(sock, address);
	test_connection(connection);
}

// Test the connection TODO: maybe change this
void Network::Socket::test_connection(int to_test) {
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

int Network::Socket::get_connection() {
	return connection;
}
