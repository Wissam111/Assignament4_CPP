
#include "Duke.hpp"

namespace coup
{

    string Duke::role()
    {
        return "Duke";
    }

    void Duke::block(Player &otherPlayer)
    {
        cout << "hoxfox" << endl;
    }

    void Duke::tax()
    {
        if (_playerName == game.turn())
        {

            if (game.getCurr() == game.numOfPlayers() - 1)
            {
                game.setTurn(0);
            }
            else
            {
                int turn = game.getCurr();
                turn++;
                game.setTurn(turn);
            }

            upateOperation(TAX);
            return;
        }

        throw "Not His Turn";
    }

}