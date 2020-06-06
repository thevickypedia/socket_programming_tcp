# Socket Programming
Simple TCP connection between server and client

This is a simple tcp connection establishment between server and client using socket programming in C

Suitable for Linux command line

Steps:
* Place the server and client files in different folders
* Run gcc server.c -o server to create executable server file
* Run gcc client.c -o client to create executable client file
* Initiate server using ./server <port_nummber>
* Initiate client using ./client <server_ip> <port_number>

Connection established!

Note: Both ./server and ./client can run without arguments in case of [localhost](https://stackoverflow.com/questions/7382602/what-is-the-difference-between-127-0-0-1-and-localhost) (127.0.0.1) and the port number is also hard coded.