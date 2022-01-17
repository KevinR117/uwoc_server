#include <boost/asio.hpp>

#include "session.h"

#pragma once

using boost::asio::ip::tcp;

class Server
{
public:

    Server(boost::asio::io_service& ioContext_, uint16_t port_);

    ~Server() = default;

private:

    void accept();

    tcp::acceptor m_acceptor;

    tcp::socket m_socket;
};
