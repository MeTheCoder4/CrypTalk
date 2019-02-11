//
// Created by richard on 11.02.19.
//

#include <iostream>
#include "Server.h"

using namespace sf;
using namespace std;

Server::Server(unsigned short portNumber)
    : m_portNumber(portNumber) {
}

bool Server::waitToConnect() {
    if(m_tcpListener.listen(m_portNumber) != Socket::Done)
        return false;

    return !(m_tcpListener.accept(m_tcpClient) != Socket::Done);
}


