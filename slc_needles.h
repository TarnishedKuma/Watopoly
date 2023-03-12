#ifndef SLC_NEEDLES_H
#define SLC_NEEDLES_H
#include <string>
#include "square.h"
#include "player.h"
#include "board.h"
using namespace std;

class SLC : public Square {
public:
   
    SLC();
    ~SLC();
    int event(ActualPlayer &p) override;


    Monopoly* getMonopolyBlock() override;
    int getPurchasePrice() override;
    int getImprovementPrice() override;
    int getImprovementLevel() override;
    void setImprovementLevel(int level) override;
    vector<int> getBuildingTuition() override;
};

class NH : public Square {
public:
    NH();
    ~NH();
    int event(ActualPlayer &p) override;

    Monopoly* getMonopolyBlock() override;
    int getPurchasePrice() override;
    int getImprovementPrice() override;
    int getImprovementLevel() override;
    void setImprovementLevel(int level) override;
    vector<int> getBuildingTuition() override;
};



#endif