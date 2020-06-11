#pragma once

#define _CRT_SECURE_NO_WARNINGS
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define WIN32_LEAD_AND_MEAN


#include <winsock2.h>
#include <windows.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctime>

// Link with Ws2_32.lib, Mswsock.lib and Advapi32.lib
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "Advapi32.lib")

#define DEFAULT_BUFFER_LENGTH	512
#define PORT_NUMBER				10000
#define IP_ADDR					"server IP address"

int initSocket();
int sendData(char buffer[]);
int closeSocket();