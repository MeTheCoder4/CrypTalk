#include <iostream>
#include <string>
#include "VernamCoder.h"
#include "Server.h"
#include "Client.h"

using namespace std;

int main() {
    string key;
    unsigned short portNumber = 0;

    cout << "************" << endl;
    cout << "* CrypTalk *" << endl;
    cout << "************" << endl;
    cout << "1) Join conversation." << endl;
    cout << "2) Host new conversation." << endl;

    int option = 0;
    cin >> option;
    cout << option << endl;
    do {
        switch(option) {
            case 1:
                {
                    cout << "Enter port number" << endl;
                    cin >> portNumber;
                    cout << "Enter ip address: " << endl;
                    string ipAddress;
                    cin >> ipAddress;
                    Client client(ipAddress, portNumber);

                    if(!client.joinServer()) {
                        cout << "Error while connecting!" << endl;
                        return 1;
                    }

                    cout << "Connected!" << endl;
                }
                break;
            case 2:
                {
                    cout << "Enter port number:" << endl;
                    cin >> portNumber;
                    Server server(portNumber);
                    cout << "Waiting for connections..." << endl;

                    if(!server.waitToConnect()) {
                        cout << "Error while connecting!";
                        return 1;
                    }

                    cout << "Connected!" << endl;
                }
                break;
            default:
                cout << "Invalid input." << endl;
                cin >> option;
        }
    } while(option < 1 || option > 2);

    return 0;
}