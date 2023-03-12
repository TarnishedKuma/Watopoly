#ifndef NPS_H
#define NPS_H
#include "square.h"

#include "board.h"

#include "player.h"
#include <string>
using namespace std;



class NPS : public Square{
    
 public:
    NPS(std::string name);

    ~NPS();

    virtual int event(ActualPlayer &p) = 0;


    virtual Monopoly* getMonopolyBlock() = 0;
    virtual int getPurchasePrice() = 0;
    virtual int getImprovementPrice() = 0;
    virtual int getImprovementLevel() = 0;
    virtual void setImprovementLevel(int level) = 0;
    virtual vector<int> getBuildingTuition() = 0;

};

class OSAP : public NPS {
 public:
    OSAP(std::string name);
    int event(ActualPlayer &p) override;

    Monopoly* getMonopolyBlock() override;
    int getPurchasePrice() override;
    int getImprovementPrice() override;
    int getImprovementLevel() override;
    void setImprovementLevel(int level) override;
    vector<int> getBuildingTuition() override;
};

class DCT : public NPS {
 public:
    DCT(std::string name);
    int event(ActualPlayer &p) override;

    Monopoly* getMonopolyBlock() override;
    int getPurchasePrice() override;
    int getImprovementPrice() override;
    int getImprovementLevel() override;
    void setImprovementLevel(int level) override;
    vector<int> getBuildingTuition() override;
};

class GTT : public NPS {
 public:
    GTT(std::string name);
    int event(ActualPlayer &p) override;

    Monopoly* getMonopolyBlock() override;
    int getPurchasePrice() override;
    int getImprovementPrice() override;
    int getImprovementLevel() override;
    void setImprovementLevel(int level) override;
    vector<int> getBuildingTuition() override;
};

class GN : public NPS {
 public:
    GN(std::string name);
    int event(ActualPlayer &p) override;


    Monopoly* getMonopolyBlock() override;
    int getPurchasePrice() override;
    int getImprovementPrice() override;
    int getImprovementLevel() override;
    void setImprovementLevel(int level) override;
    vector<int> getBuildingTuition() override;
};

class TUI : public NPS {
 public:
    TUI(std::string name);
    int event(ActualPlayer &p) override;

    Monopoly* getMonopolyBlock() override;
    int getPurchasePrice() override;
    int getImprovementPrice() override;
    int getImprovementLevel() override;
    void setImprovementLevel(int level) override;
    vector<int> getBuildingTuition() override;
};

class COOP : public NPS {
 public:
    COOP(std::string name);
    int event(ActualPlayer &p) override;


    Monopoly* getMonopolyBlock() override;
    int getPurchasePrice() override;
    int getImprovementPrice() override;
    int getImprovementLevel() override;
    void setImprovementLevel(int level) override;
    vector<int> getBuildingTuition() override;
};


#endif