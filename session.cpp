#include "session.h"

/// \brief              Assign constructor
Session::Session(tcp::socket socket)
    : m_socket(std::move(socket))
{
}

/// \brief              Start the session (and start waiting for client data then)
void Session::start()
{
    // Wait for client data
    read();
}

/// \brief              Wait for client data
void Session::read()
{
    auto self(shared_from_this());
    // When data is received, the callback is called
    m_socket.async_read_some(boost::asio::buffer(m_data, DATA_SIZE), [this, self](const boost::system::error_code& err_, size_t dataLen_) {
        if (!err_)
        {
            // this->send(m_data, dataLen_);  // Uncomment if echo mode is needed

            // Send data through the analog port of the RP card here, some code might be added for that

            // Then wait for new data from the client
            read();
        }
    });
}

/// \brief              Send data to the client
void Session::send(uint8_t* data_, size_t dataLen_)
{
    // When packets are well sent or an error occurs, the callback is called
    boost::asio::async_write(m_socket, boost::asio::buffer(data_, dataLen_), [this](const boost::system::error_code& err_, size_t bytesTransfered_) {
        if (err_)
        {
            std::cout << "Can't send data" << std::endl;
        }
    });
}
