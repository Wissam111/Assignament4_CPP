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
            Player::_playersMap.at(otherPlayer.getLastPlayer()).setCuped(false);
            updateGameList();
            game.setNumOfPlayers(game.numOfPlayers() + 1);
            return;
        }

        throw "His Last Operation Cant be blocked";
    }

}