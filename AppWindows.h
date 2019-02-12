//
// Created by richard on 12.02.19.
//

#ifndef CPPPROJECTS_MAINWINDOW_H
#define CPPPROJECTS_MAINWINDOW_H

#ifndef GTKMM_H
#define GTKMM_H

#include <gtkmm.h>

#endif

#ifndef MEMORY_H
#define MEMORY_H

#include <memory>

#endif

class ConversationWindow;

class MainWindow : public Gtk::Window {
public:
    explicit MainWindow(const Glib::ustring&);
    MainWindow() = default;
    ~MainWindow() override = default;
    Glib::ustring getIpAddress();
    unsigned short getPortNumber();
    Glib::ustring getKey();

protected:
    void showErrorMessage(const Glib::ustring&);
    void showInfoMessage(const Glib::ustring&);
    Glib::ustring m_windowTitle;
    Glib::ustring m_ipAddress;
    unsigned short m_portNumber;
    Glib::ustring m_key;

private:
    void onNewConversationClick();
    std::unique_ptr<ConversationWindow> m_convWindowPtr;

};

class ConversationWindow : public Gtk::Window {
public:
    ConversationWindow(const Glib::ustring&, Gtk::Window&, MainWindow&);
    ~ConversationWindow() override = default;

protected:

private:
    Glib::ustring m_windowTitle;

};


#endif //CPPPROJECTS_MAINWINDOW_H
