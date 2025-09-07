#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<random>
#include"./game/game.h"
#include"gameControl.h"
#include<sys/socket.h>
#include"./game/newGame.cpp"







GameBoard::GameBoard() {
    this->CurrentMatchings = std::vector<GamePool>(10);
    

    std::vector<int> Randarray(1000);
    for (int i = 0; i < 1000; i++) {
        Randarray[i] = i + 1;
    }

    initialShuffle(Randarray);

    for (int i = 0; i < 1000; i++) {
        this->gameQueues.push(Randarray[i]);
    }
}




void GameBoard::initialShuffle(std::vector<int>& Randarray) {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(Randarray.begin(), Randarray.end(), g);
}