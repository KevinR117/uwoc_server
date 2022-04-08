#include <iostream>

#include "server.h"

/** \brief              Main entry point of a server
 *  \param[in]          argc Args count
 *  \param[out]         argv Arguments array
 *  \return             integer
**/
int main(int argc, char* argv[])
{
    try
    {
        // Test for the presence of the port of the server
        if (argc != 2)
        {
            std::cerr << "Usage: async_tcp_echo_server <port>\n";
            return 1;
        }

        // Creation of a server instance
        boost::asio::io_service ioContext;
        Server s(ioContext, std::atoi(argv[1]));

        // Run the server
        ioContext.run();
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}
