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

        this->setCoins(_coins + 1);
        otherPlayer.setCoins(otherPlayer.coins() - 1);
    }

    void Captain::block(Player &otherPlayer)
    {
        if (otherPlayer.getLastOper() == STEAL)
        {

            return;
        }

        throw "His Last Operation Cant be blocked";
    }

}