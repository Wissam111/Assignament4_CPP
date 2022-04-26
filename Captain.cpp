#include "Captain.hpp"

namespace coup
{

    void Captain::steal(Player &otherPlayer)
    {

        if (otherPlayer.coins() < 2 || coins() >= 10)
        {
            throw "Invalid operation";
        }

        if (_playerTurn == game.getTurn() && !isCuped())
        {

            updateTurns();
            this->setLastOperPlayer(otherPlayer.getPlayerIndex());
            this->setCoins(_coins + 2);
            otherPlayer.setCoins(otherPlayer.coins() - 2);

            upateOperation(STEAL);
            return;
        }

        throw "Not His Turn";
    }

    void Captain::block(Player &otherPlayer)
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

    string Captain::role()
    {
        return "Captain";
    }
}