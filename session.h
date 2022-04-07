#include <boost/asio.hpp>
#include <memory>
#include <iostream>

#pragma once

using boost::asio::ip::tcp;

/** \name               Session
 *  \brief              Session allocated for each client (one session by client). Its goal is to receive data from
 *  client (and send it through an output analog port of the RP card) and to send back to client received data from an
 *  input analog port of the RP card (/!\ this feature is not implemented yet, and some code might be added for that).
 *  More information about it is detailed in the project report.
**/
class Session : public std::enable_shared_from_this<Session>
{
public:

    /*******************************************************
     * \section             Constructor, destructor
     *
    *******************************************************/
    
    /** \brief              Assign constructor
     *  \param[in]          socket Socket object (that will handle data transmissions with the client)            
    **/
    explicit Session(tcp::socket socket);

    /** \brief              Destructor
    **/
    ~Session() = default;

    /*******************************************************
     * \section             Methods and functions
     *
    *******************************************************/
    
    /** \brief              Start the session
    **/
    void start();

private:

    /*******************************************************
     * \section             Private methods and functions
     *
    *******************************************************/
    
    /** \brief              Read data received from the client
    **/
    void read();
    
    /** \brief              Send data to the client
     *  \param[in]          data_ Data to send
     *  \param[in]          dataLen_ Length of the sent data
    **/
    void send(uint8_t* data_, size_t dataLen_);

    /*******************************************************
     * \section             Constants
     *
    *******************************************************/
    
    /// \brief              Size of a packet
    static constexpr const uint16_t DATA_SIZE = 1024;
    
    /*******************************************************
     * \section             Private members
     *
    *******************************************************/
    
    /// \brief              Socket instance
    tcp::socket m_socket;

    /// \brief              Buffer (for queuing received data from the client before being processed by the RP card)
    uint8_t m_data[DATA_SIZE];
};
