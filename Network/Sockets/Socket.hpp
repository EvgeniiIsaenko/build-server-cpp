// Header file for the socket

#ifndef Socket_hpp
#define Socket_hpp

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>

// namespace socket
namespace Network {
	class Socket {
	private:
		struct sockaddr_in address;
		int sock;
		int connection;
	public:
		// constructor
		Socket(int domain, int service, int protocol, int port, unsigned long interface);
		// Connects to the network
		virtual int connect_to_network(int sock, struct sockaddr_in address) = 0;
		// Test the network connectino
		void test_connection(int);
		// Incapsulation
		// Getters
		struct sockaddr_in get_address();
		int get_sock();
		int get_connection();
		// Setters
		void set_connection(int);
	};
}


#endif /* Socket_hpp */