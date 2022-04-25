#include "Assassin.hpp"
#include "Player.hpp"
namespace coup
{

    void Assassin::coup(Player &otherPlayer)
    {
        int p = game.getPlayerIndex(otherPlayer.getName());
        if (p == -1 || coins() < 3)
        {
            throw "Invalid operations";
        }

        game.eraseAt(p);
        setCoins(coins() - 3);
        this->setLastOperPlayer(otherPlayer);
        upateOperation(ASSASSIN);
    }
    string Assassin::role()
    {
        return "Assassin";
    }

}