#include "Captain.hpp"

namespace coup
{

    void Captain::steal(Player &otherPlayer)
    {

        if (otherPlayer.coins() < 2 || coins() >= 10)
        {
            throw "Invalid operation";
        }

<<<<<<< HEAD
        if (_playerTurn == game.getTurn() && !isCuped())
        {

            updateTurns();
            this->setLastOperPlayer(otherPlayer.getPlayerIndex());
            this->setCoins(_coins + 2);
            otherPlayer.setCoins(otherPlayer.coins() - 2);
=======
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
>>>>>>> 0fd0e2e82c5791fc1620158877323faf2dd72de3
            upateOperation(STEAL);
            return;
        }

        throw "Not His Turn";
    }

    void Captain::block(Player &otherPlayer)
    {
        if (otherPlayer.getLastOper() == STEAL)
        {
<<<<<<< HEAD

            int c = Player::_playersMap.at(getLastPlayer()).coins();
            this->setCoins(coins() - 2);
            Player::_playersMap.at(getLastPlayer()).setCoins(c + 2);
            return;
=======
            int c = otherPlayer.getLastPlayer().coins();
            this->setCoins(coins() - 2);
            otherPlayer.getLastPlayer().setCoins(c + 2);
>>>>>>> 0fd0e2e82c5791fc1620158877323faf2dd72de3
        }

        throw "His Last Operation Cant be blocked";
    }

    string Captain::role()
    {
        return "Captain";
    }
}