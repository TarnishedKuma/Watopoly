#include "gym_res.h"
#include <string>
#include <iostream>
using namespace std;


//vector<Square*> Board::staticSquares;

Gym::Gym(string name): Square{name} {
}

Gym::~Gym() {}

int Gym::event(ActualPlayer &p) {
    if (this->getOwner() == &p) {
        cout <<  "You already own this building." << endl;
        return 1;
    } 
    if (getOwner() == nullptr) {
        cout << "Landed on " << getName() << " . To purchase this property for $150, enter 'Y'. Otherwise, enter 'N'." << endl;
        cout << "If you do not have the funds to make the purchase, you may mortgage properties or declare bankruptcy." << endl;
        int d = p.pay_money(150);
        if (d == 0){
            cout << "Now auctioning "<<getName()<< endl;
            return 0;

        }
        else{
            cout << p.getName() << " now owns "<<getName() << endl;
            p.addPropertyWithout(this);
            p.addResidence(this);
            setOwner(&p);
            return 1;

        }

    } else {
        int fee = 0;
        string t;
        if (Board::staticSquares[12]->getOwner() == Board::staticSquares[28]->getOwner()) {
            fee = (p.getRoll1() + p.getRoll2()) * 10;
        } else {
            fee = (p.getRoll1() + p.getRoll2()) * 4;
        }
        cout << "Landed on " << getName() << ". You must pay " << fee << " to its owner. Please enter 'Y' to pay." << endl;
        p.forcePay(fee, this->getOwner());
        return 1;
    }
    
}


Monopoly* Gym::getMonopolyBlock() {
    return nullptr;
}

int Gym::getPurchasePrice() {
    return 150;
}

int Gym::getImprovementPrice() {
    return 0;
}

int Gym::getImprovementLevel() {
    return 0;
}

void Gym::setImprovementLevel(int level) {
}

vector<int> Gym::getBuildingTuition() {
    vector<int> v;
    return v;
}


Res::Res(string name): Square{name} {}

Res::~Res() {}

int Res::event(ActualPlayer &p) {

    if (this->getOwner() == &p){
        cout << "You already own this building."<<endl;
        return 1;
    }

        
    if (getOwner() == nullptr) {
        cout << "Landed on " << getName() << " . To purchase this property, enter 'Y'. Otherwise, enter 'N'." << endl;
        cout << "If you do not have the funds to make the purchase, you may mortgage properties or declare bankruptcy." << endl;
       int q = p.pay_money(200);

       if (q == 0){
            cout << "Now auctioning "<<getName()<< endl;
            return 0;

        }
        else{
            cout << p.getName() << " now owns "<<getName() << endl;
            p.addPropertyWithout(this);
            p.addResidence(this);
            setOwner(&p);
            return 1;
        }

    } else {
        int fee = 0;
        string t;
        if ((p.getResidences()).size() == 1) {
            fee = 25;
        } else if ((p.getResidences()).size() == 2) {
            fee = 50;
        } else if ((p.getResidences()).size() == 3) {
            fee = 100;
        } else if ((p.getResidences()).size() == 4) {
            fee = 200;
        }
        cout << "Landed on " << getName() << ". You must pay " << fee << " to its owner. Please enter 'Y' to pay." << endl;
        p.forcePay(fee, this->getOwner());
        return 1;

    }
}


Monopoly* Res::getMonopolyBlock() {
    return nullptr;
}

int Res::getPurchasePrice() {
    return 200;
}

int Res::getImprovementPrice() {
    return 0;
}

int Res::getImprovementLevel() {
    return 0;
}

void Res::setImprovementLevel(int level) {
}

vector<int> Res::getBuildingTuition() {
    vector<int> v;
    return v;
}

