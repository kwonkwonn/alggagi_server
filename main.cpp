#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <random>
#include "./game/game.h"
#include "gameControl.h"

struct NewMatchRequest // 랜덤 입장
{
    
};

struct NewMatchInfo // 코드 입장 : 서버 -> 클라이언트
{
    int gameCode;
};

struct NewMatchResponse // 코드 입장 : 클라이언트 -> 서버
{
    int gameCode;

};

#define PORT 9090
#define SERVER_IP "203.229.49.110"

int main() {
    GameBoard gb;
    
    // socket programming
    SOCKET sock;
    SOCKADDR_IN serverAddr;

    if (WSAStartup(MAKEWORD(2, 2), new WSADATA()) != 0) { // 스타트업 구조체를 통하여 main 내부에 winsock을 초기화
        std::cerr << "WSAStartup failed!" << std::endl;
        exit(EXIT_FAILURE);
    }

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) { // 소켓 생성
        std::cerr << "Socket creation failed!" << std::endl;
        exit(EXIT_FAILURE);
    }

    serverAddr.sin_family = AF_INET; // IPv4
    serverAddr.sin_port = htons(PORT); // 포트 번호
    serverAddr.sin_addr.s_addr = inet_addr(SERVER_IP); // 서버 IP 주소

    if (connect(sock, (SOCKADDR*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) { // 서버에 연결
        std::cerr << "Connection failed!" << std::endl;
        exit(EXIT_FAILURE);
    }

    if (bind(sock, (SOCKADDR*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) { // 소켓에 주소 할당
        std::cerr << "Bind failed!" << std::endl;
        exit(EXIT_FAILURE);
    }

    if (listen(sock, SOMAXCONN) == SOCKET_ERROR) { // 연결 요청 대기
        std::cerr << "Listen failed!" << std::endl;
        exit(EXIT_FAILURE);
    }

    while (true)
    {
        SOCKET clientSock;
        SOCKADDR_IN clientAddr;
        int clientAddrSize = sizeof(clientAddr);

        if ((clientSock = accept(sock, (SOCKADDR*)&clientAddr, &clientAddrSize)) == INVALID_SOCKET) { // 클라이언트 연결 수락
            std::cerr << "Accept failed!" << std::endl;
            continue; // 에러 발생 시 다음 클라이언트 연결 대기
        }

        std::cout << "Client connected: " << inet_ntoa(clientAddr.sin_addr) << std::endl;

        // 여기서 클라이언트와의 통신 처리
        // 예: recv(clientSock, buffer, sizeof(buffer), 0);
        // 예: send(clientSock, buffer, sizeof(buffer), 0);

        closesocket(clientSock); // 클라이언트 소켓 닫기
    }

    WSACleanup(); // 윈속 종료

    return 0;
}
