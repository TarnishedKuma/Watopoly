#include "monopoly.h"
#include <string>
#include <iostream>
#include "square.h"
 using namespace std;

Monopoly::Monopoly(std::string name): name{name}, owner{nullptr} {}

Monopoly::~Monopoly() {}

void Monopoly::assign_monopoly(std::vector<Square*> sqr) {
    int i = 0;
    for (auto s : sqr) {
       if (s->get_block() == this)
       squares.push_back(s);
       i++;
    }
}
   
string Monopoly::getName(){
    return name;
}

ActualPlayer* Monopoly::get_owner() {
    return owner;
}

void Monopoly::check_monopoly() {
    bool can_assign = 1;
    ActualPlayer* p = squares[0]->getOwner();

    for (auto s : squares) {
        // cerr << s->getName() << s->getOwner()  << endl;
        if (s->getOwner() != p) {
            can_assign = 0;
            break;
        }
    }
    if (can_assign == 1) {
        owner = p;
    } else {
       owner = nullptr;
    }


}


