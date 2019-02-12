//#include <iostream>
//#include <string>
//#include "Server.h"
//#include "Client.h"
#include "AppWindows.h"

//using namespace std;
using namespace Gtk;

int main(int argc, char** argv) {
    auto app = Application::create(argc, argv, "com.gtkmm.cryptalk.base");
    MainWindow mainWindow("CrypTalk");
    return app->run(mainWindow);

//    string key, message;
//    unsigned short portNumber = 0;
//
//    cout << "************" << endl;
//    cout << "* CrypTalk *" << endl;
//    cout << "************" << endl;
//    cout << "1) Join conversation." << endl;
//    cout << "2) Host new conversation." << endl;
//
//    int option = 0;
//    cin >> option;
//    do {
//        switch(option) {
//            case 1:
//                {
//                    cout << "Enter port number:" << endl;
//                    cin >> portNumber;
//                    cout << "Enter ip address: " << endl;
//                    string ipAddress;
//                    cin >> ipAddress;
//                    cout << "Enter the key: " << endl;
//                    cin >> key;
//                    Client client(ipAddress, portNumber, key);
//
//                    if(!client.joinServer()) {
//                        cout << "Error while connecting!" << endl;
//                        return 1;
//                    }
//
//                    cout << "Connected!" << endl;
//
//                    while(message != "end_connection()") {
//                        cout << "Write message: ";
//                        getline(cin, message);
//                        client.sendMessage(message);
//                    }
//                }
//                break;
//            case 2:
//                {
//                    cout << "Enter port number:" << endl;
//                    cin >> portNumber;
//                    cout << "Enter the key: " << endl;
//                    cin >> key;
//                    Server server(portNumber, key);
//                    cout << "Waiting for connections..." << endl;
//
//                    if(!server.waitToConnect()) {
//                        cout << "Error while connecting!";
//                        return 1;
//                    }
//
//                    cout << "Connected!" << endl;
//
//                    while(message != "end_connection()") {
//                        message = server.receiveMessage();
//                        cout << "Message received: " << message << endl;
//                    }
//                }
//                break;
//            default:
//                cout << "Invalid input." << endl;
//                cin >> option;
//        }
//    } while(option < 1 || option > 2);

//    return 0;
}