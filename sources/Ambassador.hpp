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

    class Ambassador : public Player
    {
    public:
        Ambassador(Game &game, string playerName) : Player(game, playerName) {}
        static void block(Player &otherPlayer);
        void transfer(Player &player1, Player &player2);
        string role() override;
    };

}