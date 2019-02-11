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

class Client {
public:
    Client(const std::string&, unsigned short);
    bool joinServer();

private:
    sf::TcpSocket m_socket;
    std::string m_ipAddress;
    unsigned short m_portNumber;

};


#endif //CPPPROJECTS_CLIENT_H
