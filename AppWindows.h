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
    void onJoinConversationClick();
    std::unique_ptr<ConversationWindow> m_convWindowPtr;
    Gtk::Entry* e_ipAddress, *e_portNumber, *e_key;

};

class ConversationWindow : public Gtk::Window {
public:
    ConversationWindow(const Glib::ustring&, Gtk::Window&, MainWindow&);
    ~ConversationWindow() override = default;

protected:

private:
    Glib::ustring m_windowTitle;
    Gtk::ScrolledWindow* m_chatWindow, *m_inputWindow;
    Gtk::TextView* m_chatTextView, *m_inputTextView;
    Glib::RefPtr<Gtk::TextBuffer> m_refChatBuffer, m_refInputBuffer;

};


#endif //CPPPROJECTS_MAINWINDOW_H
