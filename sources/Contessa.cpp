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

        int otherplrT = game.playerTurn(otherPlayer.getLastPlayer().getPlayerIndex());
        if (otherPlayer.getLastOper() == ASSASSIN)
        {

            game.setCopued(otherPlayer.getLastPlayer().getPlayerIndex(), false);
            game.setNumOfPlayers(game.numOfPlayers() + 1);
            game.resetTurns();
            if (game.getTurn() > otherplrT)
            {
                game.updateTurns();
            }

            return;
        }

        throw invalid_argument("Invalid operations!");
    }

}