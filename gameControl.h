#include <vector>
#include <queue>
#include "./game/game.h"

class GameBoard {
public:
    GameBoard();
    std::vector<GamePool> CurrentMatchings;
    std::queue<int> gameQueues;
    void initialShuffle(std::vector<int>& Randarray);
};