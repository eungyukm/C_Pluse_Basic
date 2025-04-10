// Basic_24.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <WinSock2.h>
#include <iostream>
#pragma comment(lib, "ws2_32.lib")
using namespace std;

// iocp 전에 꼭 알아야 할 3가지 핵심!

int main()
{
    // 1. Winsock 초기화
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    // 2. 비동기 소켓 생성
    SOCKET sock = WSASocket(AF_INET, SOCK_STREAM, 0, NULL,
        0, WSA_FLAG_OVERLAPPED);

    // 3. OverLapped 구조체 + 비동기 수신 준비
    char buffer[1024];
    WSAOVERLAPPED overlapped = {};
    WSABUF wasBuf = { sizeof(buffer), buffer };
    DWORD flags = 0;
    WSARecv(sock, &wasBuf, 1, NULL, &flags, &overlapped,
        NULL);

    cout << "기초 세팅 완료!" << endl;

    closesocket(sock);
    WSACleanup();
    return 0;
}