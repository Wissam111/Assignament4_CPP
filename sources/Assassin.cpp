/*
 * AUTHORS: Wissam kabha
 * gitHub: https://github.com/Wissam111
 * Date: 04/2022
 */

#include "Assassin.hpp"
#include "Player.hpp"
namespace coup
{

    void Assassin::coup(Player &otherPlayer)
    {

        int plrT = game.playerTurn(player_index);
        int otherplrT = game.playerTurn(otherPlayer.getPlayerIndex());
        bool b = (plrT == game.getTurn() && !game.isCopued(otherPlayer.getPlayerIndex()));
        if (((coins() < sevenCoins) && (coins() < 3)) || !b)
        {
            throw invalid_argument("Invalid operations!");
        }
        game.setCopued(otherPlayer.getPlayerIndex(), true);
        game.resetTurns();
        if (game.getTurn() < otherplrT)
        {
            game.updateTurns();
        }

        if (coins() >= threeCoins && coins() < sevenCoins)
        {
            setCoins(coins() - threeCoins);
            upateOperation(ASSASSIN);
        }
        else if (coins() >= sevenCoins)
        {
            setCoins(coins() - sevenCoins);
            upateOperation(COUP);
        }

        setLastOperPlayer(otherPlayer);
        game.setNumOfPlayers(game.numOfPlayers() - 1);
        if (game.numOfPlayers() == 1)
        {
            game.setRunning(false);
        }
    }
    string Assassin::role()
    {
        return "Assassin";
    }
}
