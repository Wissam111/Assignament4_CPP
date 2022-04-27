
/*
 * AUTHORS: Wissam kabha
 * gitHub: https://github.com/Wissam111
 * Date: 04/2022
 */

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

        throw invalid_argument("Invalid operations!");
    }

    void Duke::tax()
    {
        int plrT = game.playerTurn(player_index);
        bool b = (plrT == game.getTurn() && !game.isCopued(player_index));
        if (coins() >= tenCoins || !b)
        {
            throw invalid_argument("Invalid operations!");
        }

        _coins += threeCoins;
        game.updateTurns();
        upateOperation(TAX);
    }
}