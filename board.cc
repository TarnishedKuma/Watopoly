#include "board.h"
#include <vector>
#include <string>
#include <iostream>
#include "square.h"
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
#include <fstream>
//output working!!


using namespace std;

enum class sqr;

struct Pos {
    int row;
    int col;

    bool operator<(const Pos pos) const {
        return (row + col) < (pos.col + pos.row);
    }

    bool operator==(const Pos pos) const {
        return (row == pos.row && col == pos.col);
    }

};


Board::Board(vector<ActualPlayer*> p, int n): players{p},  numPlayers{n}, gameDone{false}{
        monopoly.push_back(new Monopoly("Arts1"));
        monopoly.push_back(new Monopoly("Arts2"));
        monopoly.push_back(new Monopoly("Eng"));
        monopoly.push_back(new Monopoly("Health"));
        monopoly.push_back(new Monopoly("Env"));
        monopoly.push_back(new Monopoly("Sci1"));
        monopoly.push_back(new Monopoly("Sci2"));
        monopoly.push_back(new Monopoly("Math"));


        squares.push_back(Square::make_square(sqr::OSAP, monopoly));
        squares.push_back(Square::make_square(sqr::AL, monopoly));
        squares.push_back(Square::make_square(sqr::SLC, monopoly));
        squares.push_back(Square::make_square(sqr::ML, monopoly));
        squares.push_back(Square::make_square(sqr::TUI, monopoly));
        squares.push_back(Square::make_square(sqr::MKV, monopoly));
        squares.push_back(Square::make_square(sqr::ECH, monopoly));
        squares.push_back(Square::make_square(sqr::NH, monopoly));
        squares.push_back(Square::make_square(sqr::PAS, monopoly));
        squares.push_back(Square::make_square(sqr::HH, monopoly));
        squares.push_back(Square::make_square(sqr::DCT, monopoly));
        squares.push_back(Square::make_square(sqr::RCH, monopoly));
        squares.push_back(Square::make_square(sqr::PAC, monopoly));
        squares.push_back(Square::make_square(sqr::DWE, monopoly));
        squares.push_back(Square::make_square(sqr::CPH, monopoly));
        squares.push_back(Square::make_square(sqr::UWP, monopoly));
        squares.push_back(Square::make_square(sqr::LHI, monopoly));
        squares.push_back(Square::make_square(sqr::SLC, monopoly));
        squares.push_back(Square::make_square(sqr::BMH, monopoly));
        squares.push_back(Square::make_square(sqr::OPT, monopoly));
        squares.push_back(Square::make_square(sqr::GN, monopoly));
        squares.push_back(Square::make_square(sqr::EV1, monopoly));
        squares.push_back(Square::make_square(sqr::NH, monopoly));
        squares.push_back(Square::make_square(sqr::EV2, monopoly));
        squares.push_back(Square::make_square(sqr::EV3, monopoly));
        squares.push_back(Square::make_square(sqr::V1, monopoly));
        squares.push_back(Square::make_square(sqr::PHYS, monopoly));
        squares.push_back(Square::make_square(sqr::B1, monopoly));
        squares.push_back(Square::make_square(sqr::CIF, monopoly));
        squares.push_back(Square::make_square(sqr::B2, monopoly));
        squares.push_back(Square::make_square(sqr::GTT, monopoly));
        squares.push_back(Square::make_square(sqr::EIT, monopoly));
        squares.push_back(Square::make_square(sqr::ESC, monopoly));
        squares.push_back(Square::make_square(sqr::SLC, monopoly));
        squares.push_back(Square::make_square(sqr::C2, monopoly));
        squares.push_back(Square::make_square(sqr::REV, monopoly));
        squares.push_back(Square::make_square(sqr::NH, monopoly));
        squares.push_back(Square::make_square(sqr::MC, monopoly));
        squares.push_back(Square::make_square(sqr::COOP, monopoly));
        squares.push_back(Square::make_square(sqr::DC, monopoly));
        
        
        for (auto block : monopoly) {
            block->assign_monopoly(squares);
        }
        

        for (int i = 0; i<40; i++){

            staticSquares.push_back(squares[i]);
        }

    for (auto p : players) {
        p->setOSAP();
    }
}

Board::~Board() {
for (auto s : squares) {
    delete s;
}
for (auto m : monopoly) {
    delete m;
}

}

Board::Board(vector<ActualPlayer*> p, int n, vector<Square*> fileSquares, vector<Monopoly*> monopoly_list) : players{p}, numPlayers{n}, gameDone{false}{
    monopoly = monopoly_list;

    squares.push_back(Square::make_square(sqr::OSAP, monopoly));
    squares.push_back(fileSquares[0]);
    squares.push_back(Square::make_square(sqr::SLC, monopoly));
    squares.push_back(fileSquares[1]);
    squares.push_back(Square::make_square(sqr::TUI, monopoly));
    squares.push_back(fileSquares[2]);
    squares.push_back(fileSquares[3]);
    squares.push_back(Square::make_square(sqr::NH, monopoly));
    squares.push_back(fileSquares[4]);
    squares.push_back(fileSquares[5]);
    squares.push_back(Square::make_square(sqr::DCT, monopoly));
    squares.push_back(fileSquares[6]);
    squares.push_back(fileSquares[7]);
    squares.push_back(fileSquares[8]);
    squares.push_back(fileSquares[9]);
    squares.push_back(fileSquares[10]);
    squares.push_back(fileSquares[11]);
    squares.push_back(Square::make_square(sqr::SLC, monopoly));
    squares.push_back(fileSquares[12]);
    squares.push_back(fileSquares[13]);
    squares.push_back(Square::make_square(sqr::GN, monopoly));
    squares.push_back(fileSquares[14]);
    squares.push_back(Square::make_square(sqr::NH, monopoly));
    squares.push_back(fileSquares[15]);
    squares.push_back(fileSquares[16]);
    squares.push_back(fileSquares[17]);
    squares.push_back(fileSquares[18]);
    squares.push_back(fileSquares[19]);
    squares.push_back(fileSquares[20]);
    squares.push_back(fileSquares[21]);
    squares.push_back(Square::make_square(sqr::GTT, monopoly));
    squares.push_back(fileSquares[22]);
    squares.push_back(fileSquares[23]);
    squares.push_back(Square::make_square(sqr::SLC, monopoly));
    squares.push_back(fileSquares[24]);
    squares.push_back(fileSquares[25]);
    squares.push_back(Square::make_square(sqr::NH, monopoly));
    squares.push_back(fileSquares[26]);
    squares.push_back(Square::make_square(sqr::COOP, monopoly));
    squares.push_back(fileSquares[27]);
    
   

     for (auto block : monopoly) {
        
            block->assign_monopoly(squares);
            
    }


    for (int i = 0; i<40; i++){
            staticSquares.push_back(squares[i]);
    }
    
}

bool Board::getGameDone(){
    return gameDone;
}

void Board::playerRoll(ActualPlayer &p, int roll1, int roll2){
            p.setRoll1(roll1);
            p.setRoll2(roll2);
            cout <<"Rolled " << roll1 <<" and "<<roll2<<"!"<<endl;
            movePlayer(p, roll1+roll2);
            p.setNumDoubles(0);
}

void Board::playerRoll(ActualPlayer &p){
        vector<int> v = { 1, 2, 3, 4, 5, 6,};
        vector<int> c = { 1, 2, 3, 4, 5, 6,};
        // use a time-based seed for the default seed value
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();


        default_random_engine rng{seed};


        //std::shuffle( v.begin(), v.end(), std::default_random_engine(seed) );
        while (true){
            shuffle( v.begin(), v.end(), rng );
            shuffle( c.begin(), c.end(), rng );
            int roll1 = v[0];
            int roll2 = c[0];
            if (p.getNumDoubles() == 3) {
                cout <<"Rolled 3 doubles in a row! Sending you to the DC Tims Line."<<endl;
                int steps = 10 - p.getPosition();
                movePlayer(p , steps);
                p.setNumDoubles(0);
            }

            else if (roll1 == roll2) {
                cout <<"Rerolling (rolled doubles!)..."<<endl;
                p.setNumDoubles(p.getNumDoubles() + 1);
                continue;
            } else {
                playerRoll(p, roll1, roll2);
                break;
            }


        }
}

void Board::timRoll(ActualPlayer &p){
        vector<int> v = { 1, 2, 3, 4, 5, 6,};
        vector<int> c = { 1, 2, 3, 4, 5, 6,};
        // use a time-based seed for the default seed value
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();


        default_random_engine rng{seed};


        //std::shuffle( v.begin(), v.end(), std::default_random_engine(seed) );

            shuffle( v.begin(), v.end(), rng );
            shuffle( c.begin(), c.end(), rng );
            int roll1 = v[0];
            int roll2 = c[0];
            timRoll(p, roll1, roll2);


        
}


void Board::timRoll(ActualPlayer &p, int r1, int r2){

            if (r1 == r2) {
                cout << "You are out of Tims!!!!" << endl;
                p.setInTims(false);
                p.setTimTurns(0);
                
            } else {
                cout << "You are stuck in Tim's! Can't roll this term!" << endl;
                movePlayer(p, 0);
                
            }


        
}

void Board::movePlayer(ActualPlayer &p, int roll){
   
        int currentIndex = p.getPosition();
        
        p.setCurSquare(squares[(currentIndex + roll) % 40]);
        p.setPosition((currentIndex + roll) % 40);

         
        print_board();

        int status = squares[currentIndex+roll]->event(p);

        int currentTurn = 0;

        for (int i = 0; i<numPlayers; i++){
            if (players[i]==&p){
                currentTurn = i;
            }
        }

        if (status==0){
            auctionProperty(currentTurn ,squares[currentIndex + roll]);
        }

        print_board();


}

Player* Board::checkBankruptcy() {
    for (int i = 0; i < numPlayers; i++) {
        if (players[i]->getBankrupt() == true) {
            declareBankruptcy(*(players[i]));
            return players[i];
        }
    }
    return nullptr;
}

void Board::auctionProperty(int playerIndex, Square *s){
   
   int currentIndex = playerIndex + 1;
    int playersAsked = 0;
    while(true){
        if (playersAsked == numPlayers - 1){
            cout << "All players have rejected buying " << s->getName() << ". This property is now given to the bank." << endl;
            s->setOwner(nullptr);
            return;
        }

        if (currentIndex == numPlayers){
            currentIndex = 0;
        }

        cout << players[currentIndex]->getName() << " now has the opportunity to purchase "<< s->getName()<< ". Please enter 'Y' to purchase, or 'N' to decline" << endl;
        int d = players[currentIndex]->pay_money(s->getPurchasePrice());

        if (d == 0){
            currentIndex++;
            playersAsked++;
        }
        else{
            cout << players[currentIndex]->getName() << " has now purchased " << s->getName() << "!" << endl;
            return;
        }

        
    }
    
}

void Board::declareBankruptcy(ActualPlayer &p) {
    ActualPlayer *owed = p.getCurSquare()->getOwner();
    if (owed == nullptr){
        for (int j = 0; j < 40; j++) {
            for (int i = 0; i < p.getProperties().size(); i++) {
                if (staticSquares[j]->getName() == p.getProperties()[i]->getName()) {
                    staticSquares[j]->setOwner(nullptr);
                }
            }
        }
        for (int j = 0; j < 40; j++) {
            for (int i = 0; i < p.getMortgaged().size(); i++) {
                if (staticSquares[j]->getName() == p.getMortgaged()[i]->getName()) {
                    staticSquares[j]->setOwner(nullptr);
                }
            }
        }
    }
    else{
        owed->setMoney(owed->getMoney() + p.getMoney());
        for (int i = 0; i < p.getProperties().size(); i++) {
            owed->addProperties(p.getProperties()[i]);
        }
        
        for (int i = 0; i < p.getMortgaged().size(); i++) {
            owed->addMortgaged(p.getMortgaged()[i]);
            int fee = 0.1 * p.getMortgaged()[i]->getPurchasePrice();
            cout << owed->getName() << " has received the mortgaged property " << p.getMortgaged()[i]->getName() << ". You must pay 10% of the purchase price." << endl;
            cout << "Enter 'Y' to pay, or enter 'mortgage' or 'bankrupt' if you do not have the funds to make the payment." << endl;
            string option;
            cin >> option;
            while (true){
                if ((option != "Y" && option != "mortgage" && option != "bankrupt")){
                    cout << "Please input 'Y', 'mortgage', or 'bankrupt'." << endl;
                    cin.clear();
                    cin.ignore();
                    cin >> option;
                }
                else if (option == "Y" && owed->getMoney() < fee){
                    cout << "You do not have the required funds to pay the fee. Please input 'mortgage' or 'bankrupt'." << endl;
                    cin.clear();
                    cin.ignore();
                    cin >> option;
                }
                else if (option =="mortgage"){
                    string s;
                    cin >> s;
                    owed->mortgageProperty(s);
                    cout << "Please input 'Y', 'mortgage', or 'bankrupt'." << endl;
                    cin.clear();
                    cin.ignore();
                    cin >> option;
                }
                else {
                    break;
                }
            }

            if (option == "Y"){
                owed->setMoney(owed->getMoney() - fee);
                cout << owed->getName() << " has successfully received the mortgaged property " << p.getMortgaged()[i]->getName() << "." << endl;
                int principal = 0.5 * p.getMortgaged()[i]->getPurchasePrice();
                cout << "Choose to A) Unmortgage the property by paying the principal, $" << principal << ", or B) Keep the property unmortgaged, which means you will need to pay an additional 10% if you unmortgage later on." << endl;
                string choice;
                cin >> choice;
                while (true) {
                    if (option != "A" && option != "B"){
                        cout << "Please input 'A' or 'B'." << endl;
                        cin.clear();
                        cin.ignore();
                        cin >> choice;
                    }
                    else if (option == "A" && owed->getMoney() < principal) {
                        cout << "You do not have the required funds to unmortgage the property. Please input 'B'." << endl;
                        cin.clear();
                        cin.ignore();
                        cin >> choice;
                    } else {
                        break;
                    }
                }
                if (option == "A") {
                    int price = 0.1 * p.getMortgaged()[i]->getPurchasePrice();
                    int index = 0;
                    for (int k = 0; k < 40; k++) {
                            if (Board::staticSquares[k]->getName() == p.getMortgaged()[i]->getName()) {
                                    index = k;
                            }
                    }
                    if (owed->getMoney() < price) {
                            cout << "You do not have enough funds to unmortgage this property." << endl;
                    }
                    else {  
                        cout <<"Now unmortgaging "<< p.getMortgaged()[i]->getName() <<". Paying $"<<price<<endl;
                        owed->setMoney(owed->getMoney() - price);
                        owed->addProperties(Board::staticSquares[index]);
                        if (Board::staticSquares[index]->getName() == "REV" || Board::staticSquares[index]->getName() == "MKV" || Board::staticSquares[index]->getName() == "V1" || Board::staticSquares[index]->getName() == "UWP") {
                                    owed->addResidence(Board::staticSquares[index]);
                            }
                            owed->removeMortgaged(Board::staticSquares[index]);
                        Board::staticSquares[index]->setOwner(owed);        
                    }
                } else if (option == "B") {
                    cout << "The property "<< p.getMortgaged()[i]->getName() << "is still mortgaged." << endl;
                }
            }
            else if (option == "bankrupt") {
                cout <<"Declaring bankruptcy for "<< owed->getName() <<endl;
                owed->setBankrupt(true);
            }
        }
        
    }
      
      p.setMoney(0);
      for (int i = 0; i < p.getProperties().size(); i++) {
        if (p.getProperties()[i]->acd_building() == true) {
            p.removeProperties(p.getProperties()[i]);
        } else {
            p.removePropertyWithout(p.getProperties()[i]);
        }
      }
        for (int i = 0; i < p.getMortgaged().size(); i++) {
            p.removeMortgaged(p.getMortgaged()[i]);
        }
        for (int i = 0; i < p.getResidences().size(); i++) {
            p.removeResidence(p.getResidences()[i]);
        }
        
}


void Board::draw_square(vector<vector <char>> & canvas, int row, int col, int height, int width, Square* sqr) {
    //frame
    for (int i = row; i < row + height; i++) {
        for (int j = col; j < col + width; j ++) {
            if (j == col || j == col + width - 1) {
                canvas[i][j] = '|';
            } else if (i == row || i == row + height - 1) {
                canvas[i][j] = '-';
            } 
        }
    }

    
    
    int first_col = col + 1;
    //int second_col = first_col + 1;
    int last_col = col + width - 2;
    if (sqr->acd_building()) {
        // line 3 = '-'
        int line3 = row + 2;
        int shift = 2;
        for (int j = first_col + shift; j < last_col - shift; j++) {
            canvas[line3][j] = '*';
        }

        // line 4 = building name
        int line_for_building_name = row + 3;
        std::string sqr_name = sqr->getName();
        int j = 0;
        for (auto c : sqr_name) {
            canvas[line_for_building_name][first_col + shift + j] = c;
            j++;
        }
        int level = sqr->getImprovementLevel() + 1;
        for (int k = 0; k < level; k++) {
            if (k == 0) continue;
            canvas[line_for_building_name][first_col + shift + j + 1] = 'I';
            j++;
        }
    } else { 
        //line 2 = building name
        int line2 = row + 1;
        std::string sqr_name = sqr->getName();
        int j = 0;
        
        for (auto c : sqr_name) {
            canvas[line2][first_col + j] = c;
            j++;
        }
    }

    
    
    
}

void Board::draw_square(vector<vector <char>> & canvas, int row, int col, int height, int width, Square* sqr, vector<char> piece) {
    draw_square(canvas, row, col, height, width, sqr);
    int j = 0;
    for (auto c : piece) {

        canvas[row + height - 2][col + 1 + j] = c;
        j++;
    }
    
}

void Board::draw_logo(vector<vector <char>> & canvas, int row, int col) {
    vector<string> vs;
    vs.push_back("                                .-'''-.                               .-'''-.                         ");
    vs.push_back("                               '   _    \\                            '   _    \\  .---.                ");
    vs.push_back("                             /   /` '.   \\_________   _...._       /   /` '.   \\ |   |                ");
    vs.push_back("       _     _              .   |     \\  '\\        |.'      '-.   .   |     \\  ' |   |.-.          .\\ ");
    vs.push_back(" /\\    \\\\   //           .| |   '      |  '\\        .'```'.    '. |   '      |  '|   | \\ \\        / / ");
    vs.push_back(" `\\\\  //\\ //  __      .' |_ \\    \\     / /  \\      |       \\     \\    \\      / / |   |  \\ \\      / /  ");
    vs.push_back("   \\`//  \\'/.:--.'.  .'     |`.   ` ..' /    |     |        |    | `.   ` ..' /  |   |   \\ \\    / /   ");
    vs.push_back("    \\|   |// /   \\ |'--.  .-'   '-...-'`     |      \\      /    .     '-...-'`   |   |    \\ \\  / /    ");
    vs.push_back("           *  __ | |   |  |                  |     |\\`'-.-'   .'                 |   |     \\ `  /     ");
    vs.push_back("            .'.''| |   |  |                  |     | '-....-'`                   |   |      \\  /      ");
    vs.push_back("           / /   | |_  |  '.'               .'     '.                            '---'      / /       ");
    vs.push_back("           \\ \\._,\\ '/  |   /              '-----------'                                 |`-' /        ");
    vs.push_back("            `--'  `-   `'-'                                                              '..'         ");


    for (auto s : vs) {
        int col_shift = 0;
        for (auto c : s) {
            canvas[row][col + col_shift] = c;
            col_shift++;
        }
        row++;
    }
        
    return;
}

void Board::print_board() {
    int height = 7;
    int width = 15;
    vector<vector<char>> canvas( 11 * height, vector<char>( 11 * width, ' '));

    //define the map here
    std::map<Pos, int> map_canvas;
    //top line
    for (int j = 0; j < 11; j++) {
        map_canvas[Pos{0, j * width}] = 20 + j;
    } 
    // left

    for (int i = 10; i > 0; i--) {
        map_canvas[Pos{i * height, 0}] = 20 - i;
    } 
    // right
    for (int i = 1; i < 10; i++) {
        map_canvas[Pos{i * height, 10 * width}] = 30 + i;
    } 
    // bottom
    for (int j = 0; j < 11; j++) {
        map_canvas[Pos{10 * height, j * width}] = 10 - j;
    }

    
    for (int i = 0; i < 11 * height; i = i + height) {
        for (int j = 0; j < 11 * width; j = j + width) {

            if((i != 0 && i != height * 10) && (j !=0 && j != width * 10)) continue;
            // check table for which square to draw
            int index = map_canvas[Pos{i,j}];

            

            vector<char> player_piece;
            // find if any player is at this index, and put their symbol in player_piece
            for (int k = 0; k < players.size(); k++) {
                if (players[k]->getPosition() == index) {
                    
                    player_piece.push_back(players[k]->getCharacter());
                }
            }


            // call appropriate draw_square
            if (player_piece.empty()) {
                draw_square(canvas, i, j, height, width, squares[index]);
            } else {

                draw_square(canvas, i, j, height, width, squares[index], player_piece);         
            }
        
        draw_square(canvas, i, j, height, width, squares[index]);
        }
    }
    draw_logo(canvas, height + 1, width + 1);

    for (int i = 0; i < 11 * height; i++) {
        for (int j = 0; j < 11 * width; j++) {
            cout << canvas[i][j];
        }
        cout << endl;
    }
}



