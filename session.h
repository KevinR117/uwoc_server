#include <boost/asio.hpp>
#include <memory>
#include <iostream>

#pragma once

using boost::asio::ip::tcp;

class Session : public std::enable_shared_from_this<Session>
{
public:

    explicit Session(tcp::socket socket);

    ~Session() = default;

    void start();

private:

    void read();

    void send(uint8_t* data_, size_t dataLen_);

    static constexpr const uint16_t DATA_SIZE = 1024;

    tcp::socket m_socket;

    uint8_t m_data[DATA_SIZE];
};
