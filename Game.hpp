#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
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
        ASSASSIN,
        TAX,
        STEAL
    };

    class Game
    {
    private:
        vector<string> _players;
        int _currPlayer = 0;
        string _winner;
        bool _isRunning = false;

    public:
        Game() { _isRunning = true; }
        ~Game(){};
        int numOfPlayers();

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