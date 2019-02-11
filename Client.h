//
// Created by richard on 11.02.19.
//

#ifndef CPPPROJECTS_CLIENT_H
#define CPPPROJECTS_CLIENT_H

#ifndef NETWORK_H
#define NETWORK_H

#include <SFML/Network.hpp>

#endif

#ifndef STRING_H
#define STRING_H

#include <string>

#endif

#ifndef VERNAM_H
#define VERNAM_H

#include "VernamCoder.h"

#endif

class Client {
public:
    Client(const std::string&, unsigned short, const std::string&);
    bool joinServer();
    bool sendMessage(const std::string&);
    std::string receiveMessage();

private:
    sf::TcpSocket m_socket;
    std::string m_ipAddress;
    unsigned short m_portNumber;
    const std::string m_key;

};


#endif //CPPPROJECTS_CLIENT_H
