# Server UWOC

## Usage

This server application is supposed to be running on the RedPitaya Card.

It contains a server that is waiting for distant machines (clients) to send data
(like video data for example).

It also waits for data from the input analog port of the RedPitaya Card so it
can send it back to the clients that are connected to the server.

## Build and execute

To compile this project, you need to change directory to build directory by cd build

Then remove the directory content when you are compiling it for the first time with typing rm -rf *
Be carefull to be in the build directory before doing this

Type cmake ..

Finally type make -j2

An executable file will be created, so you can execute it typing ./uwoc_server
