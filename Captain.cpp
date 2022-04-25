#include "Captain.hpp"

namespace coup
{

    string Captain::role()
    {
        return "Captain";
    }

    void Captain::steal(Player &otherPlayer)
    {
        int p1 = game.getPlayerIndex(otherPlayer.getName());

        if (p1 == -1 || otherPlayer.coins() < 1)
        {
            throw "Invalid operation";
        }

        if (_playerName == game.turn())
        {

            if (game.getCurr() == game.numOfPlayers() - 1)
            {
                game.setTurn(0);
            }
            else
            {
                int turn = game.getCurr();
                turn++;
                game.setTurn(turn);
            }

            this->setLastOperPlayer(otherPlayer);
            this->setCoins(_coins + 1);
            otherPlayer.setCoins(otherPlayer.coins() - 1);
            upateOperation(STEAL);
            return;
        }

        throw "Not His Turn";
    }

    void Captain::block(Player &otherPlayer)
    {
        if (otherPlayer.getLastOper() == STEAL)
        {
            int c = otherPlayer.getLastPlayer().coins();
            this->setCoins(coins() - 2);
            otherPlayer.getLastPlayer().setCoins(c + 2);
        }

        throw "His Last Operation Cant be blocked";
    }

}