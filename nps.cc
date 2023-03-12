#include "nps.h"
#include <iostream>
#include <string>
using namespace std;

vector<Square*> Board::staticSquares;


NPS::NPS(std::string name): Square{name} {

}

NPS::~NPS() {}


OSAP::OSAP(std::string name): NPS{name} {
}

int OSAP::event(ActualPlayer &p) {
    cout << "Landed on Collect OSAP. Collected $200." << endl;
    p.setMoney(p.getMoney()+200);
    return 1;
}



Monopoly* OSAP::getMonopolyBlock() {
    return nullptr;
}

int OSAP::getPurchasePrice() {
    return 0;
}

int OSAP::getImprovementPrice() {
    return 0;
}

int OSAP::getImprovementLevel() {
    return 0;
}

void OSAP::setImprovementLevel(int level) {
}

vector<int> OSAP::getBuildingTuition() {
    vector<int> v;
    return v;
}

DCT::DCT(std::string name): NPS{name} { }

int DCT::event(ActualPlayer &p) {
    if (p.getInTims() == true) {
        if (p.getTimTurns() == 3) {

                cout << "You must leave the DC Tims Line. Choose between A) Pay $50, or B) Use a Roll Up the Rim Cup." << endl;
                cout << "If you do not have the funds to make either payment, you may mortgage properties or declare bankruptcy." << endl;
                string option;
                cin >> option;
                while (true){
                    if ((option != "A" && option != "B" && option != "mortgage" && option != "bankrupt")){
                        cout << "Please input 'A', 'B', 'mortgage', or 'bankrupt'." << endl;
                        cin.clear();
                        cin.ignore();
                        cin >> option;
                    }

                    else if (option == "A" && p.getMoney() < 50){
                        cout << "You do not have the required funds for option A. Please input 'B' or 'mortgage' or 'bankrupt'." << endl;
                        cin.clear();
                        cin.ignore();
                        cin >> option;
                    }
                    else if (option == "B" && p.getTimCup() < 1){
                        cout << "You do not have any Roll Up the Rim cups. Please input 'A' or 'mortgage' or 'bankrupt'." << endl;
                        cin.clear();
                        cin.ignore();
                        cin >> option;
                    }
                    else if (option =="mortgage"){
                        string s;
                        cin >> s;
                        p.mortgageProperty(s);
                        cout << "Please input 'A', 'B', 'mortgage', or 'bankrupt'." << endl;
                        cin.clear();
                        cin.ignore();
                        cin >> option;
                    }
                    else{
                        break;
                    }
                    

                }

                if (option == "A"){
                    p.forcePay(50);
                    p.setInTims(false);
                    p.setTimTurns(0);
                }
                else if (option == "B"){
                    if (p.getTimCup() < 1) {
                        cout<< "Not enough Tim card!" << endl;
                    } else {
                        p.setTimCup(p.getTimCup() - 1);
                        p.setInTims(false);
                        p.setTimTurns(0);
                        Square::timCupsActive -= 1;
                    }

                    
                } 
                else if (option == "bankrupt") {
                    cout <<"Declaring bankruptcy for "<< p.getName() <<endl;
                    p.setBankrupt(true);
                }
            
        }
        else if (p.getTimTurns() < 3) {

                cout << "You can choose to leave the DC Tims Line. Choose between A) Pay $50, or B) Use a Roll Up the Rim Cup, or C) Stay in line." << endl;
                cout << "If you do not have the funds to make either payment, you may mortgage properties or declare bankruptcy." << endl;
                string option;
                cin >> option;
                while (true){
                    if ((option != "A" && option != "B" && option != "C" && option != "mortgage" && option != "bankrupt")){
                        cout << "Please input 'A', 'B', 'C', 'mortgage', or 'bankrupt'." << endl;
                        cin.clear();
                        cin.ignore();
                        cin >> option;
                    }

                    else if (option == "A" && p.getMoney() < 50){
                        cout << "You do not have the required funds for option A. Please input 'B' or 'C' or 'mortgage' or 'bankrupt'." << endl;
                        cin.clear();
                        cin.ignore();
                        cin >> option;
                    }
                    else if (option == "B" && p.getTimCup() == 0){
                        cout << "You do not have any Roll Up the Rim cups. Please input 'A' or 'C' or 'mortgage' or 'bankrupt'." << endl;
                        cin.clear();
                        cin.ignore();
                        cin >> option;
                    }
                    else if (option =="mortgage"){
                        string s;
                        cin >> s;
                        p.mortgageProperty(s);
                        cout << "Please input 'A', 'B', 'C', 'mortgage', or 'bankrupt'." << endl;
                        cin.clear();
                        cin.ignore();
                        cin >> option;
                    }
                    else{
                        break;
                    }
                    

                }

                if (option == "A"){
                    cout << "Payment successful. You are out of Tims!" << endl;
                    p.setMoney(p.getMoney() - 50);
                    p.setInTims(false);
                    p.setTimTurns(0);
                }
                else if (option == "B"){
             
                    cout << "Roll Up the Rim Cup used. You are out of Tims!" << endl;
                    p.setTimCup(p.getTimCup() - 1);
                    p.setInTims(false);
                    p.setTimTurns(0);
                    Square::timCupsActive -= 1;
                } 
                else if (option == "C") {
                    cout << "You are still stick in the DC Tims Line. You will have a chance to leave on your next turn." << endl;
                    p.setTimTurns(p.getTimTurns() + 1);
                }
                else if (option == "bankrupt") {
                    cout <<"Declaring bankruptcy for "<< p.getName() <<endl;
                    p.setBankrupt(true);
                }
            

        }
    } else {
        cout << "Passing by DC Tim's Line. Wow! The line's long! How will I get coffee today?" << endl;
    }

    return 1;
}



Monopoly* DCT::getMonopolyBlock() {
    return nullptr;
}

int DCT::getPurchasePrice() {
    return 0;
}

int DCT::getImprovementPrice() {
    return 0;
}

int DCT::getImprovementLevel() {
    return 0;
}

void DCT::setImprovementLevel(int level) {
}

vector<int> DCT::getBuildingTuition() {
    vector<int> v;
    return v;
}

GTT::GTT(std::string name) : NPS{name} {}

int GTT::event(ActualPlayer &p) {
    cout << "Uh oh! You are being sent to the DC Tims Line (jail)!" << endl;
    cout << "You will be stuck in line until you a) roll doubles, b) pay $50, or c) use a Roll Up the Rim Cup." << endl;
    cout << "On your third turn of being in the line, if you do not roll doubles, you MUST leave the line, either by paying $50 or using the Cup." << endl;
    p.setCurSquare(Board::staticSquares[10]);
    p.setInTims(true);
    p.setPosition(10);
    p.setTimTurns(1);
    return 1;
}


Monopoly* GTT::getMonopolyBlock() {
    return nullptr;
}

int GTT::getPurchasePrice() {
    return 0;
}

int GTT::getImprovementPrice() {
    return 0;
}

int GTT::getImprovementLevel() {
    return 0;
}

void GTT::setImprovementLevel(int level) {
}

vector<int> GTT::getBuildingTuition() {
    vector<int> v;
    return v;
}

GN::GN(std::string name) : NPS{name} {}

int GN::event(ActualPlayer &p) {
    cout << "You are attacked by a flock of nesting geese!" << endl;
    return 1;
}



Monopoly* GN::getMonopolyBlock() {
    return nullptr;
}

int GN::getPurchasePrice() {
    return 0;
}

int GN::getImprovementPrice() {
    return 0;
}

int GN::getImprovementLevel() {
    return 0;
}

void GN::setImprovementLevel(int level) {
}

vector<int> GN::getBuildingTuition() {
    vector<int> v;
    return v;
}

TUI::TUI(std::string name) : NPS{name} {}

int TUI::event(ActualPlayer &p) {
    cout << "Landed on Tuition. Choose between A) pay $300, or B) pay 10% of your total worth." << endl;
    cout << "If you do not have the funds to make either payment, you may mortgage properties or declare bankruptcy." << endl;
    string option;
    cin >> option;
    while (true){
        if ((option != "A" && option != "B" && option != "mortgage" && option != "bankrupt")){
            cout << "Please input 'A', 'B', 'mortgage', or 'bankrupt'." << endl;
              cin.clear();
              cin.ignore();
              cin >> option;
        }

        else if (option == "A" && p.getMoney() < 300){
            cout << "You do not have the required funds for option A. Please input 'B' or 'mortgage' or 'bankrupt'." << endl;
            cin.clear();
            cin.ignore();
            cin >> option;
        }
        else if (option == "B" && p.getMoney() < p.calcTotalWorth() * 0.1){
            cout << "You do not have the required funds for option B. Please input 'A' or 'mortgage' or 'bankrupt'." << endl;
            cin.clear();
            cin.ignore();
            cin >> option;
        }
        else if (option =="mortgage"){
            string s;
            cin >> s;
            p.mortgageProperty(s);
            cout << "Please input 'A', 'B', 'mortgage', or 'bankrupt'." << endl;
            cin.clear();
            cin.ignore();
            cin >> option;
        }
        else{
            break;
        }
        

    }

    if (option == "A"){
        p.setMoney(p.getMoney() - 300);
    }
    else if (option == "B"){
        p.setMoney(p.getMoney() - (p.calcTotalWorth() * 0.1));
    } 
    else if (option == "bankrupt") {
        cout <<"Declaring bankruptcy for "<< p.getName() <<endl;
        p.setBankrupt(true);
    }

    return 1;
}
    

Monopoly* TUI::getMonopolyBlock() {
    return nullptr;
}

int TUI::getPurchasePrice() {
    return 0;
}

int TUI::getImprovementPrice() {
    return 0;
}

int TUI::getImprovementLevel() {
    return 0;
}

void TUI::setImprovementLevel(int level) {
}

vector<int> TUI::getBuildingTuition() {
    vector<int> v;
    return v;
}

COOP::COOP(std::string name) : NPS{name} {}

int COOP::event(ActualPlayer &p) {
    cout << "Landed on COOP Fee. Please enter 'Y' to make the payment." << endl;
    cout << "If you do not have the funds to make the payment, you may mortgage properties or declare bankruptcy." << endl;
    p.forcePay(150);
    return 1;
}

Monopoly* COOP::getMonopolyBlock() {
    return nullptr;
}

int COOP::getPurchasePrice() {
    return 0;
}

int COOP::getImprovementPrice() {
    return 0;
}

int COOP::getImprovementLevel() {
    return 0;
}

void COOP::setImprovementLevel(int level) {
}

vector<int> COOP::getBuildingTuition() {
    vector<int> v;
    return v;
}