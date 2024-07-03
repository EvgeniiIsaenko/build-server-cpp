#ifndef ListeningSocket_hpp
#define ListeningSocket_hpp

#include <stdio.h>
#include "BindingSocket.hpp"

namespace Network {
    class ListeningSocket : public BindingSocket {
    private:
        int backlog; // as in backlog of people
        int listening;
    public:
        ListeningSocket(int domain, int service, int protocol, int port, unsigned long interface, int backlog);
        void start_listening();
    };
}


#endif /* ListeningSocket_hpp */