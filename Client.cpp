//
// Created by richard on 11.02.19.
//

#include "Client.h"

using namespace sf;
using namespace std;

Client::Client(const std::string &ipAddress, unsigned short portNumber, const std::string& key)
    : m_ipAddress(ipAddress), m_portNumber(portNumber), m_key(key) {
    m_socket.setBlocking(false);
}

bool Client::joinServer() {
    return (m_socket.connect(m_ipAddress, m_portNumber) != Socket::Done);
}

bool Client::sendMessage(const std::string &message) {
    Packet packet;
    string encodedMessage = VernamCoder::apply(message, m_key);

    if(packet << encodedMessage) {
        if(m_socket.send(packet) != Socket::Done)
            return false;
    }
    else
        return false;

    return true;
}

std::string Client::receiveMessage() {
    Packet packet;
    string message;

    if (m_socket.receive(packet) != Socket::Done)
        return string("Network failure.");

    if (packet >> message)
        return VernamCoder::apply(message, m_key);
    else
        return string("Packet failure.");
}


