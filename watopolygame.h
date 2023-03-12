#ifndef WATOPOLYGAME_H
#define WATOPOLYGAME_H


#include <string>
#include <vector>
#include "board.h"
#include "player.h"
#include "basebuilding.h"
#include "gym_res.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;


class WatopolyGame{
        vector <ActualPlayer*> allPlayers;
        vector<string>playerNames;
        vector<char> symbols;
        int players;
        Board *b;
        bool debug;
        public:
                WatopolyGame(vector<string> s, vector<char> c, int n, bool debug);
                void play();
                void roll(int p, vector<ActualPlayer*> allPlayers);
                WatopolyGame(string s, bool debug);


};



#endif  