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

int main() {
    GameBoard gb;
    // 소켓 열기

    return 0;
}
