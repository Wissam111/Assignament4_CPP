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
#include "Player.hpp"
using namespace std;
namespace coup
{

    class Contessa : public Player
    {

    public:
        Contessa(Game &game, string playerName) : Player(game, playerName) {}
        string role() override;
        void block(Player &otherPlayer); // can block assiassin
    };

}