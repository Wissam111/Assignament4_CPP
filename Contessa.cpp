#include "Contessa.hpp"

namespace coup
{

    string Contessa::role()
    {
        return "Contessa";
    }

    void Contessa::block(Player &otherPlayer)
    {
        if (otherPlayer.getLastOper() == ASSASSIN)
        {
            string cn = otherPlayer.getLastPlayer().getName();
            game.players().push_back(cn);
            this->setCoins(coins() + 3);
            return;
        }

        cout << "hoxfox" << endl;

        throw "His Last Operation Cant be blocked";
    }

}