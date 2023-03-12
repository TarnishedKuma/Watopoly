#include <vector>
#include <iostream>
#include <string>
#include "watopolygame.h"

using namespace std;

bool validChar(char x, char symbols[]){
        for (int i = 0; i<8; i++){
                if (symbols[i] == x){
                        symbols[i] = 'x';
                        return true;
                }
        }
        return false;
}

void printOptions(char symbols[]){
        for (int i = 0; i<8; i++){
                if (symbols[i]!='x'){
                        cout << symbols[i] << " ";
                }
        }
        cout << endl;

}

int getIndex(char c, char symbols[]){
        for (int i = 0; i<8; i++){
                if (c==symbols[i]){
                        return i;
                }
        }
        return 0;
}

int main(int argc, char **argv) {
        int playerCount;
        char symbols[8] = {'G', 'B', 'D', 'P', 'S', '$', 'L', 'T'};

        if (argc == 1){
                cout <<"Please enter the number of players playing Watopoly: " <<endl;
                cin >> playerCount;
                while(cin.fail() || playerCount < 6 || playerCount > 8){
                        cout <<"Please enter an integer between 6 and 8  for the number of players playing Watopoly: " <<endl;
                        cin.clear();
                        cin.ignore();
                        cin>>playerCount;
                }
                vector<string>playerNames;
                vector<char>syms;
                string s;
                char c;
                for (int i = 1; i<=playerCount; i++){
                        cout << "Please enter the name for player " << i <<": "<<endl;
                        cin>>s;
                        playerNames.push_back(s);
                        cout << "Please enter the character representing player " << i << ". The possible options are: "<<endl;
                        printOptions(symbols);
                        cin >> c;

                        while (validChar(c,symbols) == false){
                                cout << "Please enter a proper character representing player " << i << " from the possible options: "<<endl;
                                printOptions(symbols);
                                cin >> c;
                        }
                        syms.push_back(c);
                        symbols[getIndex(c, symbols)] = 'x';
                }


                WatopolyGame *w = new WatopolyGame(playerNames, syms, playerCount, 0);
                w->play();
                 delete w;
        } 

        else if (argc == 2) {
                cout <<"Please enter the number of players playing Watopoly: " <<endl;
                cin >> playerCount;
                while(cin.fail() || playerCount < 6 || playerCount > 8){
                        cout <<"Please enter an integer between 6 and 8  for the number of players playing Watopoly: " <<endl;
                        cin.clear();
                        cin.ignore();
                        cin>>playerCount;
                }
                vector<string>playerNames;
                vector<char>syms;
                string s;
                char c;
                for (int i = 1; i<=playerCount; i++){
                        cout << "Please enter the name for player " << i <<": "<<endl;
                        cin>>s;
                        playerNames.push_back(s);
                        cout << "Please enter the character representing player " << i << ". The possible options are: "<<endl;
                        printOptions(symbols);
                        cin >> c;

                        while (validChar(c,symbols) == false){
                                cout << "Please enter a proper character representing player " << i << " from the possible options: "<<endl;
                                printOptions(symbols);
                                cin >> c;
                        }
                        syms.push_back(c);
                        symbols[getIndex(c, symbols)] = 'x';
                }


                WatopolyGame *w = new WatopolyGame(playerNames, syms, playerCount, 1);
                w->play();
                 delete w;
        }

        else if (argc == 3) {
                string s = argv[1];
                
                if (s=="-load"){
                        string file = argv[2];
                        WatopolyGame *w = new WatopolyGame(file, 0);
                        w->play();
                         delete w;
                }
                
        }

        else {
                string s1 = argv[1];
                string file = argv[2];
                string s3 = argv[3];
                if (s1=="-load" && s3 == "-testing"){
                        WatopolyGame *w = new WatopolyGame(file, 1);
                        w->play();
                        delete w;
                }
                else {
                        cout << "Usage: -load <file> -testing" << endl;
                        return 2;
                }
        }

        
        



}

