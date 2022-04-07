#include "server.h"

/// \brief              Constructor (which directly wait for connections thanks to accept() function call)
Server::Server(boost::asio::io_service& ioContext_, uint16_t port_)
    : m_acceptor(ioContext_, tcp::endpoint(tcp::v4(), port_)), m_socket(ioContext_)
{
    this->accept();
}

/// \brief              Wait for new connection. If a client connect, a session is created for him and started)
void Server::accept()
{
    m_acceptor.async_accept(m_socket, [this](const boost::system::error_code& err_) {
        if (!err_)
        {
            // Crate a session and start it directly
            std::make_shared<Session>(std::move(m_socket))->start();
        }

        this->accept();
    });
}
