//
// Created by richard on 11.02.19.
//

#ifndef CPPPROJECTS_SERVER_H
#define CPPPROJECTS_SERVER_H

#ifndef STRING_H
#define STRING_H

#include <string>

#endif

#ifndef NETWORK_H
#define NETWORK_H

#include <SFML/Network.hpp>

#endif

#ifndef VERNAM_H
#define VERNAM_H

#include "VernamCoder.h"

#endif

class Server {
public:
    explicit Server(unsigned short, const std::string&);
    bool waitToConnect();
    bool sendMessage(const std::string&);
    std::string receiveMessage();

private:
    unsigned short m_portNumber;
    sf::TcpSocket m_tcpClient;
    sf::TcpListener m_tcpListener;
    const std::string m_key;

};


#endif //CPPPROJECTS_SERVER_H
