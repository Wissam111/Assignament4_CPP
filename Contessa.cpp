/*
 * AUTHORS: Wissam kabha
 * gitHub: https://github.com/Wissam111
 * Date: 04/2022
 */

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
            game.setCopued(otherPlayer.getLastPlayer().getPlayerIndex(), false);
            game.setNumOfPlayers(game.numOfPlayers() + 1);
            return;
        }

        throw invalid_argument("Invalid operations!");
    }

}