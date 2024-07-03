#include "TestServer.hpp"

Network::TestServer::TestServer() : SimpleServer(AF_INET, SOCK_STREAM, 0, 80, INADDR_ANY, 10) {
    launch();
}

// Accepts the connection
void Network::TestServer::accepter() {
    struct sockaddr_in address = get_socket()->get_address();
    int addrlen = sizeof(address);
    new_socket = accept(get_socket()->get_sock(), (struct sockaddr *)&address, (socklen_t *)&addrlen);
    read(new_socket, buffer, 3000); // should store the request in the buffer
}

// Handles the connection
void Network::TestServer::handler() {
    std::cout << buffer << std::endl;
}

// Responds to the connection
void Network::TestServer::responder() {
    char *hello_msg = "Hello from server";
    write(new_socket, hello_msg, sizeof(hello_msg) - 1); // Could not figure out a workaround, predefined function requires const void *__buf as well as size_t __n, although they are deprecated (gcc will give a warning, ignore it)
    close(new_socket);
}

void Network::TestServer::launch() {
    while(true) {
        std::cout << "IDLE" << std::endl;
        accepter();
        handler();
        responder();
        std::cout << "COMPLETED" << std::endl;
    }
}