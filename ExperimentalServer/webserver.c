#include <stdio.h>      // For standard I/O functions
#include <stdlib.h>     // For exit() and memory functions
#include <string.h>     // For string operations (strlen, memset)
#include <unistd.h>     // For close() function
#include <arpa/inet.h>  // For socket programming (AF_INET, htons, etc.)

int main() {
    int server_file_descriptor;
    int client_id;
    struct sockaddr_in address;
    socklen_t address_length = sizeof(address);
    char request_buffer[1024];

    // WE  CREATE OUR SOCKET
    server_file_descriptor = socket(AF_INET, SOCK_STREAM, 0);

    if (server_file_descriptor == 0) {
        perror("Socket was not created");
        exit(EXIT_FAILURE);
    }
}
