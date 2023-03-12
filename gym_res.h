#ifndef GYM_RES_H
#define GYM_RES_H
#include <string>
#include "square.h"
#include "player.h"
#include "board.h"
using namespace std;

class Gym : public Square {

public:
    Gym(string name);
    ~Gym();
    int event(ActualPlayer &p) override;

    Monopoly* getMonopolyBlock() override;
    int getPurchasePrice() override;
    int getImprovementPrice() override;
    int getImprovementLevel() override;
    void setImprovementLevel(int level) override;
    vector<int> getBuildingTuition() override;
};

class Res : public Square {
public:
    Res(string name);
    ~Res();
    int event(ActualPlayer &p) override;

    Monopoly* getMonopolyBlock() override;
    int getPurchasePrice() override;
    int getImprovementPrice() override;
    int getImprovementLevel() override;
    void setImprovementLevel(int level) override;
    vector<int> getBuildingTuition() override;
};



#endif