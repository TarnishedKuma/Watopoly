#ifndef BASEBUILDING_H
#define BASEBUILDING_H
#include "square.h"
#include "player.h"
#include "monopoly.h"
using namespace std;

class BaseBuilding: public Square {
private:
    string building_name;
    Monopoly* monopoly_block;
    int purchase_price;
    int improvement_price;
    int improvement_level;
    std::vector<int> building_tuition;

public:
    BaseBuilding(string building_name, Monopoly* monopoly_block, int purchase_price, int improvement_price, int improvement_level, std::vector<int> building_tuition);

    ~BaseBuilding();

    int event(ActualPlayer &p) override;

    string getName() override;
    Monopoly* getMonopolyBlock() override;
    int getPurchasePrice() override;
    int getImprovementPrice() override;
    int getImprovementLevel() override;
    void setImprovementLevel(int level) override;
    vector<int> getBuildingTuition() override;

    Monopoly* get_block() override;
    virtual bool acd_building() override;

    void buy_improvement(ActualPlayer*) override;
    void sell_improvement(ActualPlayer*) override;

};






#endif