#include "Ambassador.hpp"

namespace coup
{

    void Ambassador::transfer(Player &player1, Player &player2)
    {
        if (coins() >= 10 || player1.coins() < 1)
        {
            throw "Invalid operation";
        }

        if (_playerTurn == game.getTurn() && !isCuped())
        {

            updateTurns();

            player1.setCoins(player1.coins() - 1);
            player2.setCoins(player1.coins() + 1);
            upateOperation(FOREIGN_AID);
            return;
        }

        throw "Not His Turn";
    }

    void Ambassador::block(Player &otherPlayer)
    {

        if (otherPlayer.getLastOper() == STEAL)
        {

            int c = Player::_playersMap.at(getLastPlayer()).coins();
            this->setCoins(coins() - 2);
            Player::_playersMap.at(getLastPlayer()).setCoins(c + 2);
            return;
        }

        throw "His Last Operation Cant be blocked";
    }
}
