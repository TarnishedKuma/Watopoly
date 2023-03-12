#include "watopolygame.h"
#include <vector>
#include <string>
#include <algorithm>
#include "player.h"
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <map>

using namespace std;


WatopolyGame::WatopolyGame(vector<string> s, vector<char> c, int n, bool debug): playerNames{s}, symbols{c}, players{n}, b{nullptr}, debug{debug} {  
        for (int i = 0; i<players; i++){
                ActualPlayer *p = new ActualPlayer(playerNames[i], symbols[i]);
                allPlayers.push_back(p);
        }
                       
}


//read in :
WatopolyGame::WatopolyGame(string filename, bool debug): b{nullptr}, debug{debug} {
         
        //vector <ActualPlayer*> allPlayers;
        ifstream file;
        file.open (filename);
        string line;
        if (file.is_open()) {
                getline(file, line);
                char playerNumberFromFile;
                istringstream iss(line);
                iss >> playerNumberFromFile;
                int q = playerNumberFromFile - 48;
                players = q; //players var set
                
                for (int i = 0; i < q; i++) {
                        getline(file, line);
                        //cout << line << endl;
                        istringstream pp(line);
                        string name;
                        char sym;
                        int cups;
                        int money;
                        int pos;
                        int inTims;
                        int turns;

                        pp >> name;
                        
                        pp>>sym;
                        
                        pp>>cups;

                        pp>>money;

                        pp>>pos;
                        if (pos == 10) {
                                pp >> inTims;
                                pp >> turns;
                        }
                        ActualPlayer *p = new ActualPlayer(name, sym);
                        p->setTimCup(cups);
                        p->setMoney(money);
                        p->setPosition(pos);
                        if (p->getPosition() == 10) {
                                p->setInTims(true);
                                p->setTimTurns(turns);
                        }
                        allPlayers.push_back(p);
                        
                }
                
                vector<Square*> fileSquares;     
                vector<Monopoly*> monopoly_list;
                monopoly_list.push_back(new Monopoly("Arts1"));
                monopoly_list.push_back(new Monopoly("Arts2"));
                monopoly_list.push_back(new Monopoly("Eng"));
                monopoly_list.push_back(new Monopoly("Health"));
                monopoly_list.push_back(new Monopoly("Env"));
                monopoly_list.push_back(new Monopoly("Sci1"));
                monopoly_list.push_back(new Monopoly("Sci2"));
                monopoly_list.push_back(new Monopoly("Math"));
          
                for (int i = 0; i<28; i++){
                        
                         
                        getline(file, line);
                        istringstream qq(line);
                        string building_name="";
                        string ownerString;
                        ActualPlayer *pe;
                        int improvement;

                        qq>>building_name;
                        qq>>ownerString;

                        for (int i = 0; i<players;i++){
                                if (allPlayers[i]->getName() == ownerString){
                                        pe = allPlayers[i];
                                }
                        }

                        qq >> improvement;
                        Square *s;
                        
                        
                        //field of acdbuildings: name, block,  purchase_cost,  imp_cost, imp_level,  tuitions
                        // cerr << i <<endl;
                        // cerr << building_name << endl;
                        if (building_name == "AL"){
                                s = new BaseBuilding("AL", monopoly_list[0], 40, 50, 0, std::vector<int>{2, 10, 30, 90, 160, 250});
                                s->setOwner(pe);
                                s->setImprovementLevel(improvement);
                                
                                fileSquares.push_back(s);
                        }

                        else if (building_name == "ML"){
                                s = new BaseBuilding("ML", monopoly_list[0], 60, 50, 0, std::vector<int>{4, 20, 60, 180, 320, 450});
                                s->setOwner(pe);
                                s->setImprovementLevel(improvement);
                                fileSquares.push_back(s);
                        }
                        else if (building_name == "ECH"){
                                s = new BaseBuilding("ECH", monopoly_list[1], 100, 50, 0, std::vector<int>{6, 30, 90, 270, 400, 550});
                                s->setOwner(pe);
                                s->setImprovementLevel(improvement);
                                fileSquares.push_back(s);
                        }
                        else if (building_name == "PAS"){
                                s = new BaseBuilding("PAS", monopoly_list[1], 100, 50, 0, std::vector<int>{6, 30, 90, 270, 400, 550});
                                s->setOwner(pe);
                                s->setImprovementLevel(improvement);
                                fileSquares.push_back(s);
                        }
                      else if (building_name == "HH"){
                                s = new BaseBuilding("HH", monopoly_list[1], 120, 50, 0, std::vector<int>{8, 40, 100, 300, 450, 600});
                                s->setOwner(pe);
                                s->setImprovementLevel(improvement);
                                fileSquares.push_back(s);
                      }
                        else if (building_name == "RCH"){
                                s = new BaseBuilding("RCH", monopoly_list[2], 140, 100, 0, std::vector<int>{10, 50, 150, 450, 625, 750});
                                s->setOwner(pe);
                                s->setImprovementLevel(improvement);
                                fileSquares.push_back(s);       
                        }
                        else if (building_name == "DWE"){
                                s = new BaseBuilding("DWE", monopoly_list[2], 140, 100, 0, std::vector<int>{10, 50, 150, 450, 625, 750});
                                s->setOwner(pe);
                                s->setImprovementLevel(improvement);
                                fileSquares.push_back(s);
                        }
                        else if (building_name == "CPH"){
                                s = new BaseBuilding("CPH", monopoly_list[2], 160, 100, 0, std::vector<int>{12, 60, 180, 500, 700, 900});
                                s->setOwner(pe);
                                s->setImprovementLevel(improvement);
                                fileSquares.push_back(s);
                        }
                        else if (building_name == "LHI"){
                                s = new BaseBuilding("LHI", monopoly_list[3], 180, 100, 0, std::vector<int>{14, 70, 200, 550, 750, 950});
                                s->setOwner(pe);
                                s->setImprovementLevel(improvement);
                                fileSquares.push_back(s);
                        }
                        else if (building_name == "BMH"){
                                s = new BaseBuilding("BMH", monopoly_list[3], 180, 100, 0, std::vector<int>{14, 70, 200, 550, 750, 950});
                                s->setOwner(pe);
                                s->setImprovementLevel(improvement);
                                fileSquares.push_back(s);
                        }
                        else if (building_name == "OPT"){
                                s = new BaseBuilding("OPT", monopoly_list[3], 200, 100, 0, std::vector<int>{16, 80, 220, 600, 800, 1000});
                                s->setOwner(pe);
                                s->setImprovementLevel(improvement);
                                fileSquares.push_back(s);
                        }
                        else if (building_name == "EV1"){
                                s = new BaseBuilding("EV1", monopoly_list[4], 220, 150, 0, std::vector<int>{18, 90, 250, 700, 875, 1050});
                                s->setOwner(pe);
                                s->setImprovementLevel(improvement);
                                fileSquares.push_back(s);
                        }
                        else if (building_name == "EV2"){
                                s = new BaseBuilding("EV2", monopoly_list[4], 220, 150, 0, std::vector<int>{18, 90, 250, 700, 875, 1050});
                                s->setOwner(pe);
                                s->setImprovementLevel(improvement);
                                fileSquares.push_back(s);
                        }
                                
                        else if (building_name == "EV3"){
                                s = new BaseBuilding("EV3", monopoly_list[4], 240, 150, 0, std::vector<int>{20, 100, 300, 750, 925, 1100});
                                s->setOwner(pe);
                                s->setImprovementLevel(improvement);
                                fileSquares.push_back(s);
                        }
                        else if (building_name == "PHYS"){
                                s = new BaseBuilding("PHYS", monopoly_list[5], 260, 150, 0, std::vector<int>{22, 110, 330, 800, 975, 1150});
                                s->setOwner(pe);
                                s->setImprovementLevel(improvement);
                                fileSquares.push_back(s);
                        }
                        else if (building_name == "B1"){
                                s = new BaseBuilding("B1", monopoly_list[5], 260, 150, 0, std::vector<int>{22, 110, 330, 800, 975, 1150});
                                s->setOwner(pe);
                                s->setImprovementLevel(improvement);
                                fileSquares.push_back(s);
                        }
                        else if (building_name == "B2") {
                                s = new BaseBuilding("B2", monopoly_list[5], 280, 150, 0, std::vector<int>{24, 120, 360, 850, 1025, 1200});
                                s->setOwner(pe);
                                s->setImprovementLevel(improvement);
                                fileSquares.push_back(s);
                        }
                        else if (building_name == "EIT") {
                                s = new BaseBuilding("EIT", monopoly_list[6], 300, 200, 0, std::vector<int>{26, 130, 390, 900, 1100, 1275});
                                s->setOwner(pe);
                                s->setImprovementLevel(improvement);
                                fileSquares.push_back(s);
                        }
                        else if (building_name == "ESC") {
                                s = new BaseBuilding("ESC", monopoly_list[6], 300, 200, 0, std::vector<int>{26, 130, 390, 900, 1100, 1275});
                                s->setOwner(pe);
                                s->setImprovementLevel(improvement);
                                fileSquares.push_back(s);
                        }
                        else if (building_name == "C2") {
                                s = new BaseBuilding("C2", monopoly_list[6], 320, 200, 0, std::vector<int>{28, 150, 450, 1000, 1200, 1400});
                                s->setOwner(pe);
                                s->setImprovementLevel(improvement);
                                fileSquares.push_back(s);
                        }
                        else if (building_name == "MC") {
                               
                                s = new BaseBuilding("MC", monopoly_list[7], 350, 200, 0, std::vector<int>{35, 175, 500, 1100, 1300, 1500});
                               
                                s->setOwner(pe);
                                
                                s->setImprovementLevel(improvement);
                             
                                fileSquares.push_back(s);
                                     
                        }
                        else if (building_name == "DC") {
                                s = new BaseBuilding("DC", monopoly_list[7], 400, 200, 0, std::vector<int>{50, 200, 600, 1400, 1700, 2000});
                                s->setOwner(pe);
                                s->setImprovementLevel(improvement);
                                fileSquares.push_back(s);
                        }
                        else if (building_name == "MKV") {
                                s = new Res{"MKV"};
                                s->setOwner(pe);
                                fileSquares.push_back(s);
                        }
                        else if (building_name == "UWP") {
                               s = new Res{"UWP"};
                                s->setOwner(pe);
                                fileSquares.push_back(s);
                        }
                        else if (building_name == "V1") {
                                s = new Res{"V1"};
                                s->setOwner(pe);
                                fileSquares.push_back(s);
                        }
                        else if (building_name == "REV") {
                                s = new Res{"REV"};
                                s->setOwner(pe);
                                fileSquares.push_back(s);
                        }
                        else if (building_name == "PAC") {
                                s = new Gym{"PAC"};
                                s->setOwner(pe);
                                fileSquares.push_back(s);
                        }
                        else if (building_name == "CIF") {
                                s = new Gym{"CIF"};
                                s->setOwner(pe);
                                fileSquares.push_back(s);
                        }


                        if (ownerString != "BANK") {
                                pe->addPropertyWithout(s);
                                if (building_name == "REV" || building_name == "UWP" || building_name == "MKV" || building_name == "V1") {
                                        pe->addResidence(s);
                                }
                        }
                               
                               
                          
                        
                }
                
             
                Board *b = new Board(allPlayers, players, fileSquares, monopoly_list);
               
                /*
                int turn = 0;
                while (!cin.eof()){
                if (turn == players){
                        turn = 0;
                }

                cout << "It is now "<< allPlayers[turn]->getName()<<"'s turn."<<endl;
                string command;
                //cin >> command;
                
                
        }*/
                
        } 
        else {
                cout << "Unable to open file" << endl;
        }
        
}

void WatopolyGame::roll(int p, vector<ActualPlayer*> allPlayers){
         
        b->playerRoll(*allPlayers[p]);
}



void WatopolyGame::play(){

        int turn = 0;
        b = new Board(allPlayers, players);
        int winner = -1;
        int numAlive= 0;
        while (!cin.eof()){
                if (turn == players){
                        turn = 0;
                }

                cout << "It is now "<< allPlayers[turn]->getName()<<"'s turn."<<endl;
                string command;
                //cin >> command;
                bool has_roll = 0;
                while (cin >> command && allPlayers[turn]->getBankrupt()==false) {
                        if (cin.fail()){
                                cin.ignore();
                                cin.clear();
                                cin >> command;
                        }
                        else if (command == "roll") {
                                if  (allPlayers[turn]->getInTims()) {
                                        if (debug) {
                                                int d1;
                                                int d2;
                                                cin >> d1 >> d2;
                                                b->timRoll(*allPlayers[turn], d1, d2);
                                                has_roll = 1;
                                                
                                        }
                                        else if (!has_roll) {
                                              b->timRoll(*allPlayers[turn]);
                                              has_roll = 1;
                                        } else {
                                                cout << "Already rolled!" <<endl;
                                        }

                                      

                                        
                                }
                                else if (debug) {
                                        int d1;
                                        int d2;
                                        cin >> d1 >> d2;
                                        if(!cin.fail()) {
                                                 b->playerRoll(*allPlayers[turn], d1, d2);
                                                 has_roll = 1;
                                        } else {
                                                cin.clear();
                                                cout << "Must read in 2 ints!" << endl;
                                                continue;
                                        }
                                }
                                else if (has_roll) {
                                        cout << "Already rolled!" << endl;
                                } else {
                                        cout <<"Rolling the dice!"<<endl;
                                        roll(turn, allPlayers);
                                        has_roll = 1;
                                }

                                continue;
                                
                        } 
                        else if (command == "next") {
                                if (!has_roll) {
                                        cout << "You havn't rolled yet!!" << endl;
                                        continue;
                                } else {
                                        has_roll = 0;
                                        cout <<"Giving turn to the next player..."<<endl;
                                        turn++;
                                        break;
                                }

                        } 
                        else if (command == "trade"){
                                string name;
                                string give;
                                int giveNum = 0;
                                string receive;
                                int receiveNum = 0; 
                                cin >> name;
                                cin >> give;
                                cin >> receive;
                                Square *receiveP;
                                Square *giveP;
                                if ((give[0] >= 48 && give[0] <= 57) && (receive[0] >= 48 && receive[0] <= 57)) {
                                        cout << "Trade request rejected. You cannot trade money for money." << endl;
                                        continue;
                                }
                                if (give[0] >= 48 && give[0] <= 57) {
                                        stringstream ss;
                                        ss << give;
                                        ss >> giveNum;
                                } else {
                                        for (int i = 0; i < 40; i++) {
                                                if (give == Board::staticSquares[i]->getName()) {
                                                        giveP = Board::staticSquares[i];
                                                        Monopoly *block = Board::staticSquares[i]->getMonopolyBlock();
                                                        if (block->get_owner() == nullptr) {
                                                                cout << "Trade request rejected. You do not own all properties in the monopoly." << endl;
                                                                continue;
                                                        } else {
                                                                for (int j = 0; j < 40; j++) {
                                                                        if (Board::staticSquares[j]->getMonopolyBlock() == block) {
                                                                                if (Board::staticSquares[j]->getImprovementLevel() != 0) {
                                                                                        cout << "Trade request rejected. You cannot trade " << give << ". All properties in its monopoly cannot have improvements." << endl;
                                                                                        continue;
                                                                                }
                                                                        }
                                                                }
                                                        }
                                                }
                                        }
                                }
                                if (receive[0] >= 48 && receive[0] <= 57) {
                                        stringstream ss;
                                        ss << receive;
                                        ss >> receiveNum;
                                } else {
                                        for (int i = 0; i < 40; i++) {
                                                if (receive == Board::staticSquares[i]->getName()) {
                                                        receiveP = Board::staticSquares[i];
                                                        Monopoly *block = Board::staticSquares[i]->getMonopolyBlock();
                                                        if (block->get_owner() == nullptr) {
                                                                cout << "Trade request rejected. " << name << " does not own all properties in the monopoly." << endl;
                                                                continue;
                                                        } else {
                                                                for (int j = 0; j < 40; j++) {
                                                                        if (Board::staticSquares[j]->getMonopolyBlock() == block) {
                                                                                if (Board::staticSquares[j]->getImprovementLevel() != 0) {
                                                                                        cout << "Trade request rejected. You cannot trade for " << receive << ". All properties in its monopoly cannot have improvements." << endl;
                                                                                        continue;
                                                                                }
                                                                        }
                                                                }
                                                        }
                                                }
                                        }
                                }
                                cout << allPlayers[turn]->getName() << " has requested a trade with " << name << "." << endl;
                                cout << name << " must enter 'accept' or 'reject' for this trade." << endl;
                                string choice;
                                cin >> choice;
                                if (choice == "accept") {
                                        cout << "Your trade has been accepted." << endl;
                                        ActualPlayer *giver = allPlayers[turn];
                                        ActualPlayer *receiver;
                                        for (int i = 0; i < players; i++) {
                                                if (allPlayers[i]->getName() == name) {
                                                       receiver = allPlayers[i]; 
                                                }
                                        }
                                        if (giveNum != 0 && receiveNum == 0) {
                                                giver->setMoney(giver->getMoney() - giveNum);
                                                receiver->setMoney(receiver->getMoney() + giveNum);
                                                giver->addProperties(receiveP);
                                                receiver->removeProperties(receiveP);
                                                
                                                if (receive == "REV" || receive == "UWP" || receive == "V1" || receive == "MKV") {
                                                        giver->addResidence(receiveP);
                                                        receiver->removeResidence(receiveP);
                                                }
                                        } else if (giveNum == 0 && receiveNum != 0) {
                                                receiver->setMoney(receiver->getMoney() - receiveNum);
                                                giver->setMoney(giver->getMoney() + receiveNum);
                                                receiver->addProperties(giveP);
                                                receiver->removeProperties(giveP);
                                                
                                                if (give == "REV" || give == "UWP" || give == "V1" || give == "MKV") {
                                                        receiver->addResidence(giveP);
                                                        giver->removeResidence(giveP);
                                                }
                                        } else if (giveNum == 0 && receiveNum == 0) {
                                                giver->removeProperties(giveP);
                                                receiver->addProperties(giveP);
                                                receiver->removeProperties(receiveP);
                                                giver->addProperties(receiveP);
                                                if (give == "REV" || give == "UWP" || give == "V1" || give == "MKV") {
                                                        receiver->addResidence(giveP);
                                                        giver->removeResidence(giveP);
                                                }
                                                if (receive == "REV" || receive == "UWP" || receive == "V1" || receive == "MKV") {
                                                        giver->addResidence(receiveP);
                                                        receiver->removeResidence(receiveP);
                                                }
                                        }

                                } else if (choice == "reject") {
                                        cout << "Your trade has been rejected." << endl;
                                        continue;
                                }
                                
                                continue;
                                
                        }
                        else if (command =="improve"){
                                string be_improved;
                                string action;
                                cin >> be_improved >> action;
                                bool valid_be_improved = 0;
                                bool valid_action = 0;
                                int i = 0;
                                for (auto p : b->staticSquares) {
                                        if (p->getName() == be_improved && p->acd_building()) {
                                                valid_be_improved = 1;
                                                break;
                                        }
                                        i++;
                                }

                                if (action == "buy" || action == "sell") {
                                        valid_action = 1;
                                }
                                if (!valid_action || !valid_be_improved) {
                                        cout << "Please enter improve <improvable property> buy/sell !" << endl;
                                }

                                if (action == "buy") {
                                        b->staticSquares[i]->buy_improvement(allPlayers[turn]);
                                        
                                } else {
                                        b->staticSquares[i]->sell_improvement(allPlayers[turn]);
                                }

                                continue;
                        }
                        else if (command == "mortgage"){
                                string s;
                                cin >> s;
                                allPlayers[turn]->mortgageProperty(s);
                                continue;
                        }
                        else if (command=="unmortgage"){
                                string s;
                                cin >> s;
                                allPlayers[turn]->unmortgageProperty(s);
                                continue;
                        }
                        else if (command=="bankrupt"){
                                cout << "You cannot declare bankruptcy at this time." << endl;
                               continue;
                        } 
                        else if (command == "assets") {
                                cout <<"Displaying all assets of "<<allPlayers[turn]->getName()<<endl;
                                cout << "$" << allPlayers[turn]->getMoney() << endl;
                                cout << "Properties:" << endl;
                                int numProperties = allPlayers[turn]->getProperties().size();
                                for (int i = 0; i< numProperties; i++){
                                        cout << allPlayers[turn]->getProperties()[i]->getName()<< " "<<endl;
                                }
                                cout << "Mortgaged Properties:" << endl;
                                int numMortgaged = allPlayers[turn]->getMortgaged().size();
                                for (int i = 0; i< numMortgaged; i++){
                                        cout << allPlayers[turn]->getMortgaged()[i]->getName()<< " "<<endl;
                                }
                                continue;
                        }
                        else if (command=="all"){
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
                                
                               continue;
                        }
                        /*
                        else if (debug) {
                                if (command == "buyproperty") {
                                        int p;
                                        cin >> p;
                                }
                        }
                        */
                        else if (command == "save") {
                                string filename;
                                cin >> filename;
                                ofstream file;
                                file.open (filename + ".txt");
                                file << players << endl;
                                for (int i = 0; i<players; i++){
                                        if (allPlayers[i]->getPosition() == 10) {
                                                if (allPlayers[i]->getInTims() == false) {
                                                        file << allPlayers[i]->getName()<<" ";
                                                        file << allPlayers[i]->getCharacter()<<" ";
                                                        file << allPlayers[i]->getTimCup()<<" ";
                                                        file << allPlayers[i]->getMoney() << " ";
                                                        file << allPlayers[i]->getPosition() << " 0 ";
                                                } else {
                                                        file << allPlayers[i]->getName()<<" ";
                                                        file << allPlayers[i]->getCharacter()<<" ";
                                                        file << allPlayers[i]->getTimCup()<<" ";
                                                        file << allPlayers[i]->getMoney() << " ";
                                                        file << allPlayers[i]->getPosition() << " 1 ";
                                                        file << allPlayers[i]->getTimTurns() << " ";
                                                        file << endl;
                                                }
                                        } else {
                                                file << allPlayers[i]->getName()<<" ";
                                                file << allPlayers[i]->getCharacter()<<" ";
                                                file << allPlayers[i]->getTimCup()<<" ";
                                                file << allPlayers[i]->getMoney() << " ";
                                                file << allPlayers[i]->getPosition() << " ";
                                                file << endl;
                                        }
                                }

                                for (int i = 0; i<40; i++){
                                        if (Board::staticSquares[i]->acd_building() == true || Board::staticSquares[i]->getName() == "REV" || Board::staticSquares[i]->getName() == "UWP" || Board::staticSquares[i]->getName() == "V1" || Board::staticSquares[i]->getName() == "MKV" || Board::staticSquares[i]->getName() == "PAC" || Board::staticSquares[i]->getName() == "CIF") {
                                                file << Board::staticSquares[i]->getName() << " ";
                                                if (Board::staticSquares[i]->getOwner() == nullptr) {
                                                        file << "BANK ";
                                                }
                                                else {
                                                        file << Board::staticSquares[i]->getOwner()->getName() << " ";
                                                }
                                                if (Board::staticSquares[i]->acd_building() == false) {
                                                        file << "0 ";
                                                }
                                                else{
                                                        file << Board::staticSquares[i]->getImprovementLevel() << " ";
                                                }
                                                file << endl;
                                        }
                                        
                                        

                                        
                                        
                                }



                                
                                file.close();


                               continue;
                        }


                        else if (cin.eof()){
                                break;
                        }
                        else {
                                cout <<"Invalid command. Please check the spelling of your input."<<endl;
                                continue;
                        }
                        cin.ignore();
                        
                       

                } 
                
                b->checkBankruptcy();
                //delete p;
                 winner = -1;
                 numAlive= 0;
                 for (int i = 0; i<players; i++){
                        if (allPlayers[i]->getBankrupt()==false){
                                numAlive++;
                                winner = i;
                        }
                 }

                 if (numAlive == 1 && winner > 0){
                        break;
                 }

                 
                 
                 turn++;

        }
        
        cout << "Game Over! All players except for "<< allPlayers[winner]->getName() << " has declared bankruptcy."<<endl;
        cout << "Congrats to " << allPlayers[winner]->getName() << ", you have won Watopoly! Thanks for playing!" << endl;

        //destruct:

        for (int i = 0; i<players; i++){
                delete allPlayers[i];
        }
        delete b;


}

