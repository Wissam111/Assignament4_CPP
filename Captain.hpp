
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

    class Captain : public Player
    {

    public:
        Captain(Game &game, string playerName) : Player(game, playerName) {}
        string role() override
        {
            return "Player" + _playerName;
        };
        void steal(Player &otherPlayer);
        void block(Player &otherPlayer);
        };

}