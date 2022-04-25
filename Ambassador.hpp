#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include "Game.hpp"
#include "Player.hpp"
using namespace std;

namespace coup
{

    class Ambassador : public Player
    {

    public:
        Ambassador(Game &game, string playerName) : Player(game, playerName) {}
        void block(Player &otherPlayer);
        void transfer(Player &player1, Player &player2);
    };

}