
#include "Duke.hpp"

namespace coup
{

    string Duke::role()
    {
        return "Duke";
    }

    void Duke::block(Player &otherPlayer)
    {

        if (otherPlayer.getLastOper() == FOREIGN_AID)
        {

            int c = otherPlayer.coins();
            otherPlayer.setCoins(c - 2);
            return;
        }

        throw "His Last Operation Cant be blocked";
    }

    void Duke::tax()
    {

        if (coins() >= 10)
        {
            throw "Operation Should be Coup!";
        }
        if (_playerTurn == game.getTurn() || !isCuped())
        {
            _coins += 3;
            updateTurns();
            upateOperation(TAX);
            return;
        }

        throw "Not His Turn";
    }
}