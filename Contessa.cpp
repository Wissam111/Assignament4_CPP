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
<<<<<<< HEAD
            Player::_playersMap.at(otherPlayer.getLastPlayer()).setCuped(false);
            updateGameList();
            game.setNumOfPlayers(game.numOfPlayers() + 1);
            return;
        }

=======
            string cn = otherPlayer.getLastPlayer().getName();
            game.players().push_back(cn);
            this->setCoins(coins() + 3);
            return;
        }

        cout << "hoxfox" << endl;

>>>>>>> 0fd0e2e82c5791fc1620158877323faf2dd72de3
        throw "His Last Operation Cant be blocked";
    }

}