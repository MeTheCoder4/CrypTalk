//
// Created by richard on 11.02.19.
//

#include "Client.h"

using namespace sf;

Client::Client(const std::string &ipAddress, unsigned short portNumber)
    : m_ipAddress(ipAddress), m_portNumber(portNumber) {
    m_socket.setBlocking(false);
}

bool Client::joinServer() {
    return (m_socket.connect(m_ipAddress, m_portNumber) != Socket::Done);
}


