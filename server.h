#include <boost/asio.hpp>

#include "session.h"

#pragma once

using boost::asio::ip::tcp;

/** \name               Server
 *  \brief              Class that permits to handle several clients
**/
class Server
{
public:

    /*******************************************************
     * \section             Constructor, destructor
     *
    *******************************************************/

    /** \brief              Assign constructor
     *  \param[in]          ioContext_ Mandatory for creating a server
     *  \param[in]          port_ Server port on which clients will connect
    **/
    Server(boost::asio::io_service& ioContext_, uint16_t port_);

    /** \brief              Default destructor
    **/
    ~Server() = default;

private:

    /*******************************************************
     * \section             Private functions and methods
     *
    *******************************************************/
    
    /** \brief              Accept for new clients (will create a Session for each client)
    **/
    void accept();

    /*******************************************************
     * \section             Private members
     *
    *******************************************************/
    
    /// \brief              Acceptor for new clients
    tcp::acceptor m_acceptor;

    /// \brief              Socket on which clients will connect (Data will be sent and receive thanks to this)
    tcp::socket m_socket;
};
