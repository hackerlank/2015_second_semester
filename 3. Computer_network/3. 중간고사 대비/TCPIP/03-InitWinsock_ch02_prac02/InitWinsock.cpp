//ch02_p02 : InitWinsock 예제를 수정하여 UDP소켓을 생성하시오

#pragma comment (lib, "ws2_32")
#include <WinSock2.h>

//InitWinsock 프로젝트를 열어 다음과 같이 코드를 추가한다. 
void err_quit(char *msg) {
	LPVOID lpMsgBuf;
	FormatMessage (
		FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, 
		NULL, WSAGetLastError(), 
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), 
		(LPTSTR)&lpMsgBuf, 0, NULL);
	MessageBox(NULL, (LPCTSTR)lpMsgBuf, msg, MB_ICONERROR);
	LocalFree(lpMsgBuf);
	exit(1);
}

int main(int argc, char *argv[]) {
	//윈속 초기화
	WSADATA wsa;
	if(WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
		return 1;
	MessageBox(NULL, "윈속 초기화 성공", "알림", MB_OK);

	//UDPsocket()
	SOCKET udp_sock = socket(AF_INET, SOCK_DGRAM, 0);
	if(udp_sock == INVALID_SOCKET)
		err_quit("socket()");
	MessageBox(NULL, "UDP 소켓 성공", "알림", MB_OK);

	////TCPsocket()
	//SOCKET tcp_sock = socket(AF_INET, SOCK_STREAM, 0);
	//if(tcp_sock == INVALID_SOCKET) 
	//	err_quit("socket()");
	//MessageBox(NULL, "TCP 소켓 성공", "알림", MB_OK);

	//closesocket() 
	closesocket(udp_sock);//closesocket(tcp_sock);



	//윈속 종료
	WSACleanup();
	
}