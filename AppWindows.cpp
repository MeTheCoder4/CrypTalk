//
// Created by richard on 12.02.19.
//

#include "AppWindows.h"

using namespace Gtk;

MainWindow::MainWindow(const Glib::ustring& windowTitle)
    : m_windowTitle(windowTitle) {
    set_default_size(300, 170);
    set_title(m_windowTitle);
    set_resizable(false);
    set_position(WIN_POS_CENTER);

    Box* windowBox = manage(new Box(ORIENTATION_VERTICAL, 0));
    add(*windowBox);

    Grid* grid = manage(new Grid);
    grid->set_border_width(10);
    grid->set_row_spacing(5);
    windowBox->add(*grid);

    // Labels
    Label* l_ipAddress = manage(new Label);
    l_ipAddress->set_markup("<b>Host IP address: </b>");
    l_ipAddress->set_alignment(0, 0);
    grid->attach(*l_ipAddress, 0, 0, 1, 1);

    Label* l_portNumber = manage(new Label);
    l_portNumber->set_markup("<b>Port number: </b>");
    l_portNumber->set_alignment(0, 0);
    grid->attach(*l_portNumber, 0, 1, 1, 1);

    Label* l_key = manage(new Label);
    l_key->set_markup("<b>Key: </b>");
    l_key->set_alignment(0, 0);
    grid->attach(*l_key, 0, 2, 1, 1);

    //Entries
    Entry* e_ipAddress = manage(new Entry);
    e_ipAddress->set_hexpand(true);
    grid->attach(*e_ipAddress, 1, 0, 1, 1);

    Entry* e_portNumber = manage(new Entry);
    e_portNumber->set_hexpand(true);
    grid->attach(*e_portNumber, 1, 1, 1, 1);

    Entry* e_key = manage(new Entry);
    e_key->set_hexpand(true);
    grid->attach(*e_key, 1, 2, 1, 1);

    // Buttons
    Button* b_newConv = manage(new Button("New conversation"));
    b_newConv->signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::onNewConversationClick));
    b_newConv->set_border_width(10);
    b_newConv->set_hexpand(true);
    grid->attach(*b_newConv, 0, 3, 1, 1);

    Button* b_joinConv = manage(new Button("Join conversation"));
    b_joinConv->set_border_width(10);
    b_joinConv->set_hexpand(true);
    grid->attach(*b_joinConv, 1, 3, 1, 1);

    show_all_children();
}

void MainWindow::showErrorMessage(const Glib::ustring &message) {
    MessageDialog messageDialog(message, false, MESSAGE_ERROR, BUTTONS_OK, true);
    messageDialog.set_title("Error!");
    messageDialog.set_transient_for(*this);
    messageDialog.run();
}

void MainWindow::showInfoMessage(const Glib::ustring &message) {
    MessageDialog messageDialog(message, false, MESSAGE_INFO, BUTTONS_OK, true);
    messageDialog.set_title("Info");
    messageDialog.set_transient_for(*this);
    messageDialog.run();
}

void MainWindow::onNewConversationClick() {
    m_convWindowPtr = std::make_unique<ConversationWindow>(m_windowTitle, *this, *this);
    m_convWindowPtr->show();
}

Glib::ustring MainWindow::getKey() {
    return m_key;
}

unsigned short MainWindow::getPortNumber() {
    return m_portNumber;
}

Glib::ustring MainWindow::getIpAddress() {
    return m_ipAddress;
}

ConversationWindow::ConversationWindow(const Glib::ustring& windowTitle, Window& window, MainWindow& mainWindow)
        : m_windowTitle(windowTitle) {
    set_default_size(600, 400);
    set_title(m_windowTitle);
    set_resizable(false);
    set_position(WIN_POS_CENTER);
    set_transient_for(window);

    Box* windowBox = manage(new Box(ORIENTATION_VERTICAL, 0));
    add(*windowBox);

    Grid* grid = manage(new Grid);
    grid->set_border_width(10);
    grid->set_row_spacing(5);
    windowBox->add(*grid);
}
