#include "slc_needles.h"
#include "board.h"
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include "player.h"
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;

SLC::SLC(): Square{"SLC"} {}

SLC::~SLC() {}

int SLC::event(ActualPlayer &p) {
    // use a time-based seed for the default seed value
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    default_random_engine rng{seed};
   
    vector <int> timsVec;
    for (int i = 1; i<=100; i++){
        timsVec.push_back(i);
    }
    shuffle( timsVec.begin(), timsVec.end(), rng);
    int timsRoll = timsVec[0];

    if (timsRoll == 1 && Square::timCupsActive < 4){
        p.setTimCup(p.getTimCup() + 1);
        Square::timCupsActive++;
        cout << "You have received a Roll Up the Rim Cup. The Cup can be used to get out of the DC Tims Line." << endl;
    } else {
        vector<int> v = { 1, 2, 3, 4, 5, 6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24};
        // use a time-based seed for the default seed value
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        default_random_engine rng{seed};
        shuffle( v.begin(), v.end(), rng );
        int roll = v[0];
        roll = 23;
        if (roll >= 1 && roll <= 3) {
            cout << "You have been moved back 3 tiles. Boohoo!"<<endl;
            p.setPosition(p.getPosition() - 3);
            p.setCurSquare(Board::staticSquares[p.getPosition()]);
            cout << "You are now on " << p.getCurSquare()->getName() << "." << endl;
            p.getCurSquare()->event(p);
        }
        else if (roll >=4 && roll <= 7) {
            cout << "You have been moved back 2 tiles. Boohoo!"<<endl;
            p.setPosition(p.getPosition() - 2);
            p.setCurSquare(Board::staticSquares[p.getPosition()]);
            cout << "You are now on " << p.getCurSquare()->getName() << "." << endl;
            p.getCurSquare()->event(p);
        } 
        else if (roll >=8 && roll <= 11) {
            cout << "You have been moved back 1 tile. Boohoo!"<<endl;
            p.setPosition(p.getPosition() - 1);
            p.setCurSquare(Board::staticSquares[p.getPosition()]);
            cout << "You are now on " << p.getCurSquare()->getName() << "." << endl;
            p.getCurSquare()->event(p);
        }
        else if (roll >=12 && roll <= 14) {
            cout << "You have been moved forward 1 tile."<<endl;
            p.setPosition(p.getPosition() + 1);
            p.setCurSquare(Board::staticSquares[p.getPosition()]);
            cout << "You are now on " << p.getCurSquare()->getName() << "." << endl;
            p.getCurSquare()->event(p);
        }
        else if (roll >=15 && roll <= 18) {
            cout << "You have been moved forward 2 tiles."<<endl;
            p.setPosition(p.getPosition() + 2);
            p.setCurSquare(Board::staticSquares[p.getPosition()]);
            cout << "You are now on " << p.getCurSquare()->getName() << "." << endl;
            p.getCurSquare()->event(p);
        }
        else if (roll >=19 && roll <= 22) {
            cout << "You have been moved forward 3 tiles."<<endl;
            p.setPosition(p.getPosition() + 3);
            p.setCurSquare(Board::staticSquares[p.getPosition()]);
            cout << "You are now on " << p.getCurSquare()->getName() << "." << endl;
            p.getCurSquare()->event(p);
        }
        else if (roll == 23) {
            cout << "Uh oh! You have been moved to the DC Tims Line. Boohoo!"<<endl;
            p.setPosition(10);
            p.setCurSquare(Board::staticSquares[10]);
            Board::staticSquares[30]->event(p);
        }
        else if (roll == 24) {
            cout << "Congrats! You have been moved to the Collect OSAP tile! Money!"<<endl;
            p.setPosition(0);
            p.setCurSquare(Board::staticSquares[0]);
            p.getCurSquare()->event(p);
        }
    }
    return 1;
}


Monopoly* SLC::getMonopolyBlock() {
    return nullptr;
}

int SLC::getPurchasePrice() {
    return 0;
}

int SLC::getImprovementPrice() {
    return 0;
}

int SLC::getImprovementLevel() {
    return 0;
}

void SLC::setImprovementLevel(int level) {
}

vector<int> SLC::getBuildingTuition() {
    vector<int> v;
    return v;
}



NH::NH(): Square{"NEEDLES HALL"} {}

NH::~NH() {}

int NH::event(ActualPlayer &p) {
     // use a time-based seed for the default seed value
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    default_random_engine rng{seed};
   
    vector <int> timsVec;
    for (int i = 1; i<=100; i++){
        timsVec.push_back(i);
    }
    shuffle( timsVec.begin(), timsVec.end(), rng);
    int timsRoll = timsVec[0];

    if (timsRoll == 1 && Square::timCupsActive < 4){
        p.setTimCup(p.getTimCup() + 1);
        Square::timCupsActive++;
        cout << "You have received a Roll Up the Rim Cup. The Cup can be used to get out of the DC Tims Line." << endl;
    }
    else{
        vector<int> v = { 1, 2, 3, 4, 5, 6,7,8,9,10,11,12,13,14,15,16,17,18};
        shuffle( v.begin(), v.end(), rng );

   
        int roll = v[0];
        string t;
        if (roll == 1) {
            cout << "You have landed on Needle's Hall. You now owe $200. Please enter 'Y' to pay."<<endl;
            p.forcePay(200);
        }
        else if (roll >=2 && roll <= 3) {
            cout << "You have landed on Needle's Hall. You now owe $100. Please enter 'Y' to pay."<<endl;
            p.forcePay(100);
        } 
        else if (roll >=4 && roll <= 6) {
            cout << "You have landed on Needle's Hall. You now owe $50. Please enter 'Y' to pay."<<endl;
            p.forcePay(50);
        }
        else if (roll >=7 && roll <= 12) {
            cout << "You have gained $25. Yay!"<<endl;
            p.setMoney(p.getMoney() + 25);
        }
        else if (roll >=13 && roll <= 15) {
            cout << "You have gained $50. Yay!"<<endl;
            p.setMoney(p.getMoney() + 50);
        }
        else if (roll >=16 && roll <= 17) {
            cout << "You have received $100. Yay!"<<endl;
        p.setMoney(p.getMoney() + 100);
        }
        else if (roll == 18) {
            cout << "You have received $200. Yay!"<<endl;
        p.setMoney(p.getMoney() + 200);
        }

    }
    return 1;
    
}



Monopoly* NH::getMonopolyBlock() {
    return nullptr;
}

int NH::getPurchasePrice() {
    return 0;
}

int NH::getImprovementPrice() {
    return 0;
}

int NH::getImprovementLevel() {
    return 0;
}

void NH::setImprovementLevel(int level) {
}

vector<int> NH::getBuildingTuition() {
    vector<int> v;
    return v;
}