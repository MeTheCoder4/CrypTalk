//
// Created by richard on 11.02.19.
//

#include <iostream>
#include "Server.h"

using namespace sf;
using namespace std;

Server::Server(unsigned short portNumber, const std::string& key)
    : m_portNumber(portNumber), m_key(key) {
}

bool Server::waitToConnect() {
    if(m_tcpListener.listen(m_portNumber) != Socket::Done)
        return false;

    return !(m_tcpListener.accept(m_tcpClient) != Socket::Done);
}

bool Server::sendMessage(const std::string &message) {
    Packet packet;
    string encodedMessage = VernamCoder::apply(message, m_key);

    if(packet << encodedMessage) {
        if(m_tcpClient.send(packet) != Socket::Done)
            return false;
    }
    else
        return false;

    return true;
}

std::string Server::receiveMessage() {
    Packet packet;
    string message;

    if (m_tcpClient.receive(packet) != Socket::Done)
        return string("Network failure.");

    if (packet >> message)
        return VernamCoder::apply(message, m_key);
    else
        return string("Packet failure.");
}

