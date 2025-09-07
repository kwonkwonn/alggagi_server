#pragma once
#include<iostream>
#include<sys/socket.h>

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








