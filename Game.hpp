#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
namespace coup
{

    enum OPERATION
    {
        INCOME,
        FOREIGN_AID,
        COUP,
        ROLE,
        BLOCK,
        TRANSFER,
        TAX,
        STEAL
    };

    class Game
    {
    private:
        vector<string> _players;
        // vector<Player> _playersObj;
        int _currPlayer = 0;
        string _winner;

    public:
        Game() {}
        ~Game(){};
        int numOfPlayers();
        bool _isRunning = false;
        vector<string> &players();
        void setWinner(string winner);
        void setTurn(int currPlayerIndex);
        int getCurr();
        void eraseAt(int index);

        string turn();
        string winner();
        int getPlayerIndex(string playerName);
    };

}