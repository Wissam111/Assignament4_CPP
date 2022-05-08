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
using namespace std;
namespace coup
{

    class Player
    {
    protected:
        Game &game;
        string _playerName;
        int _coins = 0;
        OPERATION lastoper;
        int player_index;
        Player *lastOperPlayer;

    public:
        Player(Game &game, string playerName) : game(game), _playerName(playerName)
        {
            player_index = game.numOfPlayers();
            game.setPlayerName(player_index, _playerName);
            game.setPlayerTurn(player_index, player_index);
            game.setNumOfPlayers(game.numOfPlayers() + 1);

            if (game.Running() || game.numOfPlayers() > 6)
            {
                throw invalid_argument("Invalid operations!");
            }
        };

        /*operations*/
        int coins() const;
        void income();
        void foreign_aid();
        virtual void coup(Player &otherPlayer);
        virtual string role() { return ""; }

        /*healper Functions */
        void setCoins(int coins);
        void upateOperation(OPERATION oper);
        OPERATION getLastOper();
        int getPlayerIndex() const;
        void setLastOperPlayer(Player &otherPlayer);
        Player &getLastPlayer();

        const int tenCoins = 10;
        const int sevenCoins = 7;
        const int threeCoins = 3;
    };
}