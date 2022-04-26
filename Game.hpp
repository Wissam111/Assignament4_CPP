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
        int _numOfPlayers = 0;
        string _winner;

    public:
        Game(){};
        ~Game(){};
        int numOfPlayers();
        void setNumOfPlayers(int num);
        vector<string> &players();
        void setWinner(string winner);
        void setTurn(int currPlayerIndex);
        int getTurn();
        string turn();
        string winner();
    };

}