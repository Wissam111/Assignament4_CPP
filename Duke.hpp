/*
 * AUTHORS: Wissam kabha
 * gitHub: https://github.com/Wissam111
 * Date: 04/2022
 */

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

    class Duke : public Player
    {

    public:
        Duke(Game &game, string playerName) : Player(game, playerName) {}

        string role() override;
        void block(Player &otherPlayer);
        void tax();
    };

}