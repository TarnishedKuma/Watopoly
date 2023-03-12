#ifndef SQUARE_H
#define SQUARE_H


#include <string>
#include <vector>
#include "monopoly.h"
using namespace std;


class Player;
class ActualPlayer;
enum class sqr {AL, ML, ECH, PAS, HH, RCH, DWE, CPH, LHI, BMH, OPT, EV1, EV2, EV3, PHYS,
    B1, B2, EIT, ESC, C2, MC, DC, MKV, UWP, V1, REV, PAC, CIF, OSAP, DCT, GTT, GN, TUI, COOP, SLC, NH};

class Square {
    std::string name;
    ActualPlayer* owner;
    bool mortgaged;

public:
    static int timCupsActive;
    virtual int event(ActualPlayer &p) = 0;
    Square(string);
    static Square* make_square(sqr sqr_name, vector<Monopoly*> monopoly_list);
    void setOwner(ActualPlayer *p);
    ~Square();
    virtual string getName();
    ActualPlayer* getOwner();
    virtual Monopoly* getMonopolyBlock() = 0;
    virtual int getPurchasePrice() = 0;
    virtual int getImprovementPrice() = 0;
    virtual int getImprovementLevel() = 0;
    virtual void setImprovementLevel(int level) = 0;
    virtual vector<int> getBuildingTuition() = 0;
    bool getMortgaged();
    void setMortgaged(bool m);


    virtual void buy_improvement(ActualPlayer*);
    virtual void sell_improvement(ActualPlayer*);


    virtual bool acd_building();


    //return nullptr in default, but in case of acd_building return their block
    virtual Monopoly* get_block();
};




#endif
