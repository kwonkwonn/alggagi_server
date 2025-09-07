#pragma once
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<random>

#ifdef _WIN32 // Or WIN32, _MSC_VER, etc.
#include <winsock2.h> // Or winsock.h
#pragma comment(lib, "ws2_32.lib") // Link with Winsock library
#else
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h> // For close()
#endif

class Player{
    int PlayerID;

};

typedef enum turn{
    Red=1,
    Blue=2
} turn;

class Game{
    int playerRed;
    int playerBlue;
    turn turn;
    int gameNum;
};

class GamePool
{
    public: 
    GamePool();
    int GameManager();
    private:
    int sock;
    std::vector<std::unique_ptr<Game>> Games;
};








