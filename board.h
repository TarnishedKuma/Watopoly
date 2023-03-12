#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include <iostream>
#include <string>
#include "player.h"
#include "square.h"
#include "monopoly.h"
using namespace std;

class ActualPlayer;

class Board{
     
        vector<ActualPlayer*> players;
        vector<Square*> squares;
        vector<Monopoly*> monopoly;

        int numPlayers;
        bool gameDone;
        // draw Square in on a canvas at (row,col) with Square's width & height given. can only be called in print_board()
        void draw_square(vector<vector <char>> & canvas, int row, int col, int height, int width, Square* sqr);
        void draw_square(vector<vector <char>> & canvas, int row, int col, int height, int width, Square* sqr, vector<char> piece);
        // draw watopoly's logo on the canvas at (row,col), can only be called in print_board();
        void draw_logo(vector<vector <char>> & canvas, int row, int col);

        public:
                //printing out the board by initiation a canvas on stack and draw components on it.
                //create a vector of player index. when drawing square that has player on it, call the overloaded one with player symbols.
                void print_board();
                bool getGameDone();
                static vector<Square*> staticSquares;
                Board(vector<ActualPlayer*> p, int n);
                ~Board();
                Board(vector<ActualPlayer*> p, int n, vector<Square*> fileSquares, vector<Monopoly*> monopolyList);
                void playerRoll(ActualPlayer &p);
                void playerRoll(ActualPlayer &p, int roll1, int roll2);
                void movePlayer(ActualPlayer &p, int roll);
                //void printBoard();
                Player* checkBankruptcy();
                void declareBankruptcy(ActualPlayer &p);
                void auctionProperty(int playerIndex, Square *s);
                void timRoll(ActualPlayer &p);
                void timRoll(ActualPlayer &p, int r1, int r2);
};

#endif 