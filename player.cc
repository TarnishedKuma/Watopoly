#include "player.h"
#include "board.h"
#include <vector>
#include <iostream>
using namespace std;

int Player::getMoney() {
        return money;
}

void Player::setMoney(int amt) {
        money = amt;
}

vector<Square *> Player::getProperties() {
        return properties;
}

void Player::addProperties(Square *property) {
        properties.push_back(property);
        if (property->acd_building()) {
                property->getMonopolyBlock()->check_monopoly();
        }
        
        
}

void Player::addPropertyWithout(Square *property) {
        properties.push_back(property);
}

void Player::removeProperties(Square *property) {
        int index = 0;
        for (int i = 0; i < properties.size(); i++) {
                if (properties[i]->getName() == property->getName()) {
                        index = i;
                }
        }
        properties.erase(properties.begin() + index);
        if (property->acd_building()) {
                property->getMonopolyBlock()->check_monopoly();
        }
}

void Player::removePropertyWithout(Square *property) {
        int index = 0;
        for (int i = 0; i < properties.size(); i++) {
                if (properties[i]->getName() == property->getName()) {
                        index = i;
                }
        }
        properties.erase(properties.begin() + index);
}

vector<Square *> Player::getMortgaged() {
        return mortgaged;
}

void Player::addMortgaged(Square *r) {
        mortgaged.push_back(r);
}

void Player::removeMortgaged(Square *property){
      int index = 0;
        for (int i = 0; i < mortgaged.size(); i++) {
                if (mortgaged[i]->getName() == property->getName()) {
                        index = i;
                }
        }
        mortgaged.erase(mortgaged.begin() + index);
}

vector<Square *> Player::getResidences() {
        return residences;
}

void Player::addResidence(Square *res) {
        residences.push_back(res);
}

void Player::removeResidence(Square *res){
      int index = 0;
        for (int i = 0; i < residences.size(); i++) {
                if (residences[i]->getName() == res->getName()) {
                        index = i;
                }
        }
        residences.erase(residences.begin() + index);
}

void Player::receive_money(int amount) {
        cout << "You just received " << amount << " of money!" << endl;
        money += amount;
}


//optional
int Player::pay_money(int amount){
        string s;
        cout << "You are required to pay "<<amount <<". You currently have "<<getMoney() <<". Please enter 'Y' to confirm."<<endl;
        while (true){
                cin >> s;
                if (s=="Y"){
                        if (getMoney() < amount){
                                cout << "You do not have enough funds to pay for this. Please mortgage a property or declare bankruptcy"<< endl;
                        }

                        else{
                                cout << "Sucessfully paid." << endl;
                                setMoney(getMoney() - amount);
                                return 1;
                        }
                }

                if (s=="N"){
                        cout << "Declined purchase." << endl;
                        return 0;
                }

                else if (s == "next") {
                        cout <<"Cannot pass turn until you have made a decision."<<endl;
                } 
                else if (s == "trade"){
                         cout <<"Cannot trade at this time."<< amount <<endl;       
                }
                else if (s =="improve"){
                        cout <<"Cannot improve at this time."<< amount <<endl;      
                }
                else if (s == "mortgage"){
                        string s;
                        cin >> s;
                        //mortgageProperty(s);
                }
                else if (s=="unmortgage"){
                        cout <<"Cannot unmortgage at this time."<< amount <<endl;      
                }
                else if (s=="bankrupt"){
                        cout <<"Cannot declare bankruptcy at this time. If you do not have the funds to purchase this property, enter 'N'."<<endl;

                } 
                else if (s == "assets") {
                        cout <<"Displaying all assets"<<endl;
                        cout << "$" << getMoney() << endl;
                        cout << "Properties:" << endl;
                        int numProperties = getProperties().size();
                        for (int i = 0; i< numProperties; i++){
                                cout << getProperties()[i]->getName()<< " "<<endl;
                        }
                        cout << "Mortgaged Properties:" << endl;
                        int numMortgaged = getMortgaged().size();
                        for (int i = 0; i< numMortgaged; i++){
                                cout << getMortgaged()[i]->getName()<< " "<<endl;
                        }
                       
                }
                else if (s=="all"){
                        /*
                        for (int j = 0; j < players; j++) {
                                cout <<"Displaying all assets of "<<allPlayers[j]->getName()<<endl;
                                cout << "$" << allPlayers[j]->getMoney() << endl;
                                cout << "Properties:" << endl;
                                int numProperties = allPlayers[j]->getProperties().size();
                                for (int i = 0; i< numProperties; i++){
                                        cout << allPlayers[j]->getProperties()[i]->getName()<< " "<<endl;
                                }
                                cout << "Mortgaged Properties:" << endl;
                                int numMortgaged = allPlayers[turn]->getMortgaged().size();
                                for (int i = 0; i< numMortgaged; i++){
                                        cout << allPlayers[turn]->getMortgaged()[i]->getName()<< " "<<endl;
                                }
                                cout << endl;
                        }
                        */
                }
                else if (s == "save") {
                        cout <<"Cannot save at this time."<<endl;
                }
                       
                else {
                        cout <<"Invalid command. Please check the spelling of your input."<<endl;
                }
                cin.ignore();
                cin.clear();

        }

        return 0;
}

ActualPlayer::ActualPlayer(string name, char symbol): name{name}, symbol{symbol}, numDouble{0}{
        roll1 = 0;
        roll2 = 0;
        money = 1500;
        position = 0;
        timCup = 0;
        inTims = false;
        timTurns = 0;
        bankrupt = false;
        numResOwned = 0;
}

ActualPlayer::~ActualPlayer() {}

void ActualPlayer::setName(string piece) {
        name = piece;
}

string ActualPlayer::getName() {
        return name;
}

void ActualPlayer::setCharacter(char c) {
        symbol = c;
}

char ActualPlayer::getCharacter() {
        return symbol;
}

Square* ActualPlayer::getCurSquare() {
        return curSquare;
}

void ActualPlayer::setCurSquare(Square *pos) {
            
        curSquare = pos;
}

int ActualPlayer::getPosition() {
        return position;
}

void ActualPlayer::setPosition(int index) {
        position = (index + 40) % 40;
}

int ActualPlayer::getTimCup() {
        return timCup;
}

void ActualPlayer::setTimCup(int num) {
        timCup = num;
}

bool ActualPlayer::getInTims() {
        return inTims;
}

void ActualPlayer::setInTims(bool inLine) {
        inTims = inLine;
}

int ActualPlayer::getTimTurns() {
        return timTurns;
}

void ActualPlayer::setTimTurns(int num) {
        timTurns = num;
}

bool ActualPlayer::getBankrupt() {
        return bankrupt;
}

void ActualPlayer::setBankrupt(bool declared) {
        bankrupt = declared;
}

int ActualPlayer::getNumResOwned() {
        return numResOwned;
}

void ActualPlayer::setNumResOwned(int num) {
        numResOwned = num;
}

int ActualPlayer::getNumDoubles() {
        return numDouble;
}
void ActualPlayer::setNumDoubles(int i) {
        numDouble = i;
}

int ActualPlayer::calcTotalWorth() {
        int total = money;
        for (int i = 0; i < properties.size(); i++) {
                if (properties[i]->getName() == "PAC" || properties[i]->getName() == "CIF") {
                        total += 150;
                } else if (properties[i]->getName() == "MKV" || properties[i]->getName() == "REV" 
                || properties[i]->getName() == "UWP" || properties[i]->getName() == "V1") {
                        total += 200;
                } else {
                        total += properties[i]->getPurchasePrice();
                        total += (properties[i]->getImprovementLevel() * properties[i]->getImprovementPrice());
                }
        } 
        return total;
}

int ActualPlayer::calcMortgageWorth() {
        int total = money;
        for (int i = 0; i < properties.size(); i++) {
                if (properties[i]->getName() == "PAC" || properties[i]->getName() == "CIF") {
                        total += (150 / 2);
                } else if (properties[i]->getName() == "MKV" || properties[i]->getName() == "REV" 
                || properties[i]->getName() == "UWP" || properties[i]->getName() == "V1") {
                        total += (200 / 2);
                } else {
                        total += (properties[i]->getImprovementLevel() * properties[i]->getImprovementPrice());
                        total += (properties[i]->getPurchasePrice() / 2);
                }
        } 
        return total;
}

void ActualPlayer::mortgageProperty(string s) {
        for (int i = 0; i < properties.size(); i++) {
                if (s == properties[i]->getName()) {
                        if (properties[i]->getImprovementLevel() > 0) {
                                cout << "Mortgage unsuccessful. You must sell all improvements before you can mortgage a property." << endl;
                                return;
                        } else {
                                 setMoney(getMoney() + (properties[i]->getPurchasePrice() / 2));
                                 removePropertyWithout(properties[i]);
                                 if (s == "REV" || s == "MKV" || s == "V1" || s == "UWP") {
                                        removeResidence(residences[i]);
                                 }
                                 addMortgaged(properties[i]);
                                 properties[i]->setMortgaged(true);
                                 cout << s << " was successfully mortgaged." << endl;
                                 return;
                        }
                   
                }
            }
}

int ActualPlayer::getRoll1() {
        return roll1;
}

void ActualPlayer::setRoll1(int r) {
        roll1 = r;
}

int ActualPlayer::getRoll2() {
        return roll2;
}

void ActualPlayer::setRoll2(int r) {
        roll2 = r;
}

void ActualPlayer::unmortgageProperty(string s) {
        int price = 0;
        int index = 0;
        for (int i = 0; i < 40; i++) {
                if (Board::staticSquares[i]->getName() == s) {
                        price = (Board::staticSquares[i]->getPurchasePrice() * 0.6);
                        index = i;
                }
        }
        if (getMoney() < price) {
                cout << "You do not have enough funds to unmortgage this property." << endl;
        }
        else {  
               cout <<"Now unmortgaging "<<s<<". Paying $"<<price<<endl;
               setMoney(getMoney() - price);
               addProperties(Board::staticSquares[index]);
               if (s == "REV" || s == "MKV" || s == "V1" || s == "UWP") {
                        addResidence(Board::staticSquares[index]);
                }
                removeMortgaged(Board::staticSquares[index]);
                Board::staticSquares[index]->setMortgaged(false);
        }       
}

void ActualPlayer::setOSAP() {
        curSquare = Board::staticSquares[0];
}


void ActualPlayer::forcePay(int amount, ActualPlayer *p){
        string s;
        while (true){
                cin >> s;
                if (s=="Y"){
                        if (getMoney() < amount){
                                cout << "You do not have enough funds to pay for this. Please mortgage a property or declare bankruptcy"<< endl;
                        }

                        else{
                                cout << "Sucessfully paid." << endl;
                                setMoney(getMoney() - amount);
                                if (p!=nullptr){
                                        p->receive_money(amount);
                                }
                                return;
                        }
                }

                else if (s == "next") {
                        cout <<"Cannot pass turn until you have paid $"<< amount <<endl;
                } 
                else if (s == "trade"){
                         cout <<"Cannot trade at this time." <<endl;       
                }
                else if (s =="improve"){
                        cout <<"Cannot improve at this time." <<endl;      
                }
                else if (s == "mortgage"){
                        string s;
                        cin >> s;
                        //mortgageProperty(s);
                }
                else if (s=="unmortgage"){
                        cout <<"Cannot unmortgage at this time." <<endl;      
                }
                else if (s=="bankrupt"){
                        cout <<"Declaring bankruptcy for "<< getName() <<endl;
                        //call static func
                        return;

                } 
                else if (s == "assets") {
                        cout <<"Displaying all assets of "<<getName()<<endl;
                        cout << "$" << getMoney() << endl;
                        cout << "Properties:" << endl;
                        int numProperties = getProperties().size();
                        for (int i = 0; i< numProperties; i++){
                                cout << getProperties()[i]->getName()<< " "<<endl;
                        }
                        cout << "Mortgaged Properties:" << endl;
                        int numMortgaged = getMortgaged().size();
                        for (int i = 0; i< numMortgaged; i++){
                                cout << getMortgaged()[i]->getName()<< " "<<endl;
                        }
                       
                }
                else if (s=="all"){
                        cout <<"Cannot print all at this time."<<endl;
                        /*
                        for (int j = 0; j < players; j++) {
                                cout <<"Displaying all assets of "<<allPlayers[j]->getName()<<endl;
                                cout << "$" << allPlayers[j]->getMoney() << endl;
                                cout << "Properties:" << endl;
                                int numProperties = allPlayers[j]->getProperties().size();
                                for (int i = 0; i< numProperties; i++){
                                        cout << allPlayers[j]->getProperties()[i]->getName()<< " "<<endl;
                                }
                                cout << "Mortgaged Properties:" << endl;
                                int numMortgaged = allPlayers[turn]->getMortgaged().size();
                                for (int i = 0; i< numMortgaged; i++){
                                        cout << allPlayers[turn]->getMortgaged()[i]->getName()<< " "<<endl;
                                }
                                cout << endl;
                        }
                        */
                }
                else if (s == "save") {
                        cout <<"Cannot save at this time."<<endl;
                }
                       
                else {
                        cout <<"Invalid command. Please check the spelling of your input."<<endl;
                }
                cin.ignore();
                cin.clear();

        }
}






void Bank::OSAP(Bank *b, Player *p) {
        b->setMoney(getMoney() - 200);
        p->setMoney(getMoney() + 200);
}

