//
// Created by richard on 12.02.19.
//

#include "AppWindows.h"
#include "Server.h"
#include "Client.h"
#include "VernamCoder.h"

using namespace Gtk;
using namespace sf;

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
    e_ipAddress = manage(new Entry);
    e_ipAddress->set_hexpand(true);
    grid->attach(*e_ipAddress, 1, 0, 1, 1);

    e_portNumber = manage(new Entry);
    e_portNumber->set_hexpand(true);
    grid->attach(*e_portNumber, 1, 1, 1, 1);

    e_key = manage(new Entry);
    e_key->set_hexpand(true);
    grid->attach(*e_key, 1, 2, 1, 1);

    // Buttons
    Button* b_newConv = manage(new Button("New conversation"));
    b_newConv->signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::onNewConversationClick));
    b_newConv->set_border_width(10);
    b_newConv->set_hexpand(true);
    grid->attach(*b_newConv, 0, 3, 1, 1);

    Button* b_joinConv = manage(new Button("Join conversation"));
    b_joinConv->signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::onJoinConversationClick));
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

void MainWindow::onJoinConversationClick() {
    m_ipAddress = e_ipAddress->get_text();
    m_portNumber = static_cast<unsigned short>(strtol(e_portNumber->get_text().c_str(), nullptr, 10));
    m_key = e_key->get_text();

    if(m_ipAddress.empty() || m_key.empty()) {
        showErrorMessage("Host IP or key remains empty!");
        return;
    }
    
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
    set_title(m_windowTitle + " | " + mainWindow.getIpAddress());
    set_resizable(false);
    set_position(WIN_POS_CENTER);
    set_transient_for(window);

    Box* windowBox = manage(new Box(ORIENTATION_VERTICAL, 0));
    add(*windowBox);

    Grid* grid = manage(new Grid);
    grid->set_border_width(10);
    grid->set_row_spacing(5);
    windowBox->add(*grid);

    m_chatWindow = manage(new ScrolledWindow);
    m_chatWindow->set_hexpand(true);
    m_chatWindow->set_vexpand(true);
    m_chatWindow->set_policy(POLICY_AUTOMATIC, POLICY_ALWAYS);
    grid->attach(*m_chatWindow, 0, 0, 2, 1);

    m_chatTextView = manage(new TextView);
    m_chatTextView->set_editable(false);
    m_chatWindow->add(*m_chatTextView);

    m_refChatBuffer = TextBuffer::create();
    m_refChatBuffer->set_text("Establishing connection...\n");
    m_chatTextView->set_buffer(m_refChatBuffer);

    m_inputWindow = manage(new ScrolledWindow);
    m_inputWindow->set_hexpand(true);
    m_inputWindow->set_policy(POLICY_NEVER, POLICY_AUTOMATIC);
    grid->attach(*m_inputWindow, 0, 1, 1, 1);

    m_inputTextView = manage(new TextView);
    m_inputWindow->add(*m_inputTextView);

    m_refInputBuffer = TextBuffer::create();
    m_inputTextView->set_buffer(m_refInputBuffer);

    Button* b_send = manage(new Button("Send"));
    b_send->set_border_width(10);
    grid->attach(*b_send, 1, 1, 1, 1);

    show_all_children();
}
