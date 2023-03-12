#include "basebuilding.h"
#include <iostream>
using namespace std;

BaseBuilding::BaseBuilding(string building_name, Monopoly* monopoly_block, int purchase_price,
    int improvement_price, int improvement_level, vector<int> building_tuition): Square(building_name),
    building_name{building_name}, monopoly_block{monopoly_block}, purchase_price{purchase_price},
    improvement_price{improvement_price}, improvement_level{improvement_level}, building_tuition{building_tuition}{
}

BaseBuilding::~BaseBuilding() {
    //delete monopoly_block;
}

int BaseBuilding::event(ActualPlayer &p) {
    if (getOwner() == &p) {
        cout << "You own this property!!" << endl;
        return 1;
    } 
    if (getOwner() == nullptr) {
        cout << "Landed on " << building_name << " . To purchase this building for " << purchase_price<< ", enter 'Y'. Otherwise, enter 'N'." << endl;
        cout << "If you do not have the funds to make the purchase, you may mortgage properties." << endl;
        int d = p.pay_money(purchase_price);

        if (d == 0){
            cout << "Now auctioning "<<getName()<< endl;
            return 0;

        }
        else{
            cout << p.getName() << " now owns "<<getName() << endl;
            p.addProperties(this);
            p.addResidence(this);
            setOwner(&p);
            monopoly_block->check_monopoly();
            return 1;
        }


    } 
    else {
        int fee = 0;
        string t;
        if (improvement_level == 0) {
            if (getMonopolyBlock()->get_owner() == nullptr) {
                fee = building_tuition[0];
            } else {
                cout << "Player " << getOwner()->getName() << " owns the monopoly, paying double rent!!" << endl;
                fee = building_tuition[0] * 2;
            }
            
        } else if (improvement_level == 1) {
            fee = building_tuition[1];
        } else if (improvement_level == 2) {
            fee = building_tuition[2];
        } else if (improvement_level == 3) {
            fee = building_tuition[3];
        } else if (improvement_level == 4) {
            fee = building_tuition[4];
        } else if (improvement_level == 5) {
            fee = building_tuition[5];
        }
        cout << "Landed on " << building_name << ". You must pay " << fee << " to its owner. Please enter 'Y' to pay." << endl;
        p.forcePay(fee, this->getOwner());
        
        return 1;

    }
}

string BaseBuilding::getName() {
    return building_name;
}

Monopoly* BaseBuilding::getMonopolyBlock() {
    return monopoly_block;
}

int BaseBuilding::getPurchasePrice() {
    return purchase_price;
}

int BaseBuilding::getImprovementPrice() {
    return improvement_price;
}

int BaseBuilding::getImprovementLevel() {
    return improvement_level;
}

void BaseBuilding::setImprovementLevel(int level) {
    improvement_level = level;
}

vector<int> BaseBuilding::getBuildingTuition() {
    return building_tuition;
}

Monopoly* BaseBuilding::get_block() {
    return monopoly_block;
}

bool BaseBuilding::acd_building() {
    return true;
}

void BaseBuilding::buy_improvement(ActualPlayer* p) {
    if (getMortgaged()) {
        cout << "The property is mortgaged, you need to unmortgaged it first!" << endl;
        return;
    } else if (monopoly_block->get_owner() != p) {
        cout << "You don't own the monopoly!" << endl;
        return;
    
    } else if (improvement_level == 5) {
        cout << "Max improvement level! Can't further improving!!" << endl;
    
    } else {
        if (p->pay_money(improvement_price)){
            improvement_level++;
            cout << "You just improved " << getName() << "!" << endl;
        } else { cout << "You cancelled improving!" << endl;}
    }
    return;
}


void BaseBuilding::sell_improvement(ActualPlayer* p) {
    if (getOwner() != p) {
        cout << "You can't sell someone else's property!" << endl;
        return;
    } else if (improvement_level == 0) {
        cout << "No improvement to be sold!" << endl;
        return;
    } else {
        p->receive_money( (improvement_price / 2));
        improvement_level--;
        return;
    }
    return;
}

