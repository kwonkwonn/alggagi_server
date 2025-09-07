#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <random>
#include "./game/game.h"
#include "gameControl.h"
#include "./proto/Match.pb.h"



int main() {
    GameBoard gb;
    // 소켓 열기
    GOOGLE_PROTOBUF_VERIFY_VERSION;


int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in address{};
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(9090);

    bind(server_fd, (struct sockaddr*)&address, sizeof(address));
    listen(server_fd, 3);


    return 0;
}
