#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include <string>
#include "board.h"
#include "square.h"
using namespace std;

class Player {
        protected:
                int money;
                
                vector<Square *> properties;
                vector<Square *> residences;
                vector<Square *> mortgaged;
        public:
                int getMoney();
                void setMoney(int amt);
                vector<Square *> getProperties();
                void addProperties(Square *property);
                void removeProperties(Square *property);
                vector<Square *> getResidences();
                void addResidence(Square *res);
                void removeResidence(Square *property);
                vector<Square *> getMortgaged();
                void addMortgaged(Square *property);
                void removeMortgaged(Square *property);
                void receive_money(int amount);
                //if payment is successful return 1; else return 0
                int pay_money(int amount);
                void addPropertyWithout(Square *property);
                void removePropertyWithout(Square *property);
};





class ActualPlayer: public Player {
        string name;
        char symbol;
        Square *curSquare;
        int position;
        int timCup;
        bool inTims;
        int timTurns;
        bool bankrupt;
        int numResOwned;
        int roll1;
        int roll2;
        int numDouble;

        public:
                 ActualPlayer(string name, char symbol);
                ~ActualPlayer();
                void setName(string piece);
                string getName();
                void setCharacter(char c);
                char getCharacter();
                Square *getCurSquare();
                void setCurSquare(Square *pos);
                int getPosition();
                void setPosition(int index);
                int getTimCup();
                void setTimCup(int num);
                bool getInTims();
                void setInTims(bool inLine);
                int getTimTurns();
                void setTimTurns(int num);
                bool getBankrupt();
                void setBankrupt(bool declared);
                int getNumResOwned();
                void setNumResOwned(int num);
                int calcTotalWorth();
                int calcMortgageWorth();
                void mortgageProperty(string s);
                int getRoll1();
                void setRoll1(int r);
                int getRoll2();
                void setRoll2(int r);
                int getNumDoubles();
                void setNumDoubles(int i);
                void unmortgageProperty(string s);
                void setOSAP();

                //i/o functions:
                void forcePay(int amount, ActualPlayer *p  = nullptr);
                int optionalPay(int amount);

};





class Bank: public Player {
        public:
                void OSAP(Bank *b, Player *p);
};

#endif
