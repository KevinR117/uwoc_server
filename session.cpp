#include "session.h"

Session::Session(tcp::socket socket)
    : m_socket(std::move(socket))
{
}

void Session::start()
{
    read();
}

void Session::read()
{
    auto self(shared_from_this());
    m_socket.async_read_some(boost::asio::buffer(m_data, DATA_SIZE), [this, self](const boost::system::error_code& err_, size_t dataLen_) {
        if (!err_)
        {
            // Send data through the analog port here
	    this->send(m_data, dataLen_);
            read();
        }
    });
}

void Session::send(uint8_t* data_, size_t dataLen_)
{
    boost::asio::async_write(m_socket, boost::asio::buffer(data_, dataLen_), [this](const boost::system::error_code& err_, size_t bytesTransfered_) {
	if (err_)
	{
	    std::cout << "Can't send data" << std::endl;
	}
    });
}
