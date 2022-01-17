#include "server.h"

Server::Server(boost::asio::io_service& ioContext_, uint16_t port_)
    : m_acceptor(ioContext_, tcp::endpoint(tcp::v4(), port_)), m_socket(ioContext_)
{
    this->accept();
}

void Server::accept()
{
    m_acceptor.async_accept(m_socket, [this](const boost::system::error_code& err_) {
        if (!err_)
        {
            std::make_shared<Session>(std::move(m_socket))->start();
        }

        this->accept();
    });
}
