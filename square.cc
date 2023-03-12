
#include <string>
#include <iostream>
#include "square.h"
#include "basebuilding.h"
#include "gym_res.h"
#include "nps.h"
#include "slc_needles.h"

class Player;

int Square::timCupsActive = 0;

Square::Square(std::string name): name{name}, owner{nullptr} {}

Square* Square::make_square(sqr sqr_name, std::vector<Monopoly*> monopoly_list) {

    switch (sqr_name)
    {
    //field of acdbuildings: name, block,  purchase_cost,  imp_cost, imp_level,  tuitions
    case sqr::AL:
        return new BaseBuilding("AL", monopoly_list[0], 40, 50, 0, std::vector<int>{2, 10, 30, 90, 160, 250});
    case sqr::ML:
        return new BaseBuilding("ML", monopoly_list[0], 60, 50, 0, std::vector<int>{4, 20, 60, 180, 320, 450});
    case sqr::ECH:
        return new BaseBuilding("ECH", monopoly_list[1], 100, 50, 0, std::vector<int>{6, 30, 90, 270, 400, 550});
        
    case sqr::PAS:
        return new BaseBuilding("PAS", monopoly_list[1], 100, 50, 0, std::vector<int>{6, 30, 90, 270, 400, 550});
        
    case sqr::HH:
        return new BaseBuilding("HH", monopoly_list[1], 120, 50, 0, std::vector<int>{8, 40, 100, 300, 450, 600});
        
    case sqr::RCH:
        return new BaseBuilding("RCH", monopoly_list[2], 140, 100, 0, std::vector<int>{10, 50, 150, 450, 625, 750});
        
    case sqr::DWE:
        return new BaseBuilding("DWE", monopoly_list[2], 140, 100, 0, std::vector<int>{10, 50, 150, 450, 625, 750});
    case sqr::CPH:
        return new BaseBuilding("CPH", monopoly_list[2], 160, 100, 0, std::vector<int>{12, 60, 180, 500, 700, 900});
    case sqr::LHI:
        return new BaseBuilding("LHI", monopoly_list[3], 180, 100, 0, std::vector<int>{14, 70, 200, 550, 750, 950});
    case sqr::BMH:
        return new BaseBuilding("BMH", monopoly_list[3], 180, 100, 0, std::vector<int>{14, 70, 200, 550, 750, 950});
    case sqr::OPT:
        return new BaseBuilding("OPT", monopoly_list[3], 200, 100, 0, std::vector<int>{16, 80, 220, 600, 800, 1000});
    case sqr::EV1:
        return new BaseBuilding("EV1", monopoly_list[4], 220, 150, 0, std::vector<int>{18, 90, 250, 700, 875, 1050});
    case sqr::EV2:
        return new BaseBuilding("EV2", monopoly_list[4], 220, 150, 0, std::vector<int>{18, 90, 250, 700, 875, 1050});
    case sqr::EV3:
        return new BaseBuilding("EV3", monopoly_list[4], 240, 150, 0, std::vector<int>{20, 100, 300, 750, 925, 1100});
    case sqr::PHYS:
        return new BaseBuilding("PHYS", monopoly_list[5], 260, 150, 0, std::vector<int>{22, 110, 330, 800, 975, 1150});
    case sqr::B1:
        return new BaseBuilding("B1", monopoly_list[5], 260, 150, 0, std::vector<int>{22, 110, 330, 800, 975, 1150});
    case sqr::B2:
        return new BaseBuilding("B2", monopoly_list[5], 280, 150, 0, std::vector<int>{24, 120, 360, 850, 1025, 1200});
    case sqr::EIT:
        return new BaseBuilding("EIT", monopoly_list[6], 300, 200, 0, std::vector<int>{26, 130, 390, 900, 1100, 1275});
    case sqr::ESC:
        return new BaseBuilding("ESC", monopoly_list[6], 300, 200, 0, std::vector<int>{26, 130, 390, 900, 1100, 1275});
    case sqr::C2:
        return new BaseBuilding("C2", monopoly_list[6], 320, 200, 0, std::vector<int>{28, 150, 450, 1000, 1200, 1400});
    case sqr::MC:
        return new BaseBuilding("MC", monopoly_list[7], 350, 200, 0, std::vector<int>{35, 175, 500, 1100, 1300, 1500});
    case sqr::DC:
        return new BaseBuilding("DC", monopoly_list[7], 400, 200, 0, std::vector<int>{50, 200, 600, 1400, 1700, 2000});
    case sqr::MKV:
        return new Res{"MKV"};
    case sqr::UWP:
        return new Res{"UWP"};
    case sqr::V1:
        return new Res{"V1"};
    case sqr::REV:
        return new Res{"REV"};
    case sqr::PAC:
        return new Gym{"PAC"};
    case sqr::CIF:
        return new Gym{"CIF"};
    case sqr::OSAP:
        return new OSAP{"Collect OSAP"};
    case sqr::DCT:
        return new DCT{"DC Tims Line"};
    case sqr::GTT:
        return new GTT{"Go to Tims"};
    case sqr::GN:
        return new GN{"Goose Nesting"};
    case sqr::TUI:
        return new TUI{"Tuition"};
    case sqr::COOP:
        return new COOP{"Coop Fee"};
    case sqr::SLC:
        return new SLC{};
    case sqr::NH:
        return new NH{};
    }
}

Square::~Square() {

}

ActualPlayer* Square::getOwner() {
    return owner;
}

void Square::setOwner(ActualPlayer *p){
    owner = p;
}

Monopoly* Square::get_block() {
    return nullptr;
}

bool Square::acd_building() {
    return false;
}

std::string Square::getName() {
    return name;
}

bool Square::getMortgaged() {
    return mortgaged;
}

void Square::setMortgaged(bool m) {
    mortgaged = m;
}


void Square::buy_improvement(ActualPlayer* p) {
    
}


void Square::sell_improvement(ActualPlayer* p) {
    
}
