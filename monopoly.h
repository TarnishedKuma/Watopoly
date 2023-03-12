#ifndef MONOPOLY
#define MONOPOLY
#include <string>
#include <vector>

class Square;

//enum class monopoly_block {ARTS1, ARTS2, ENG, HEALTH, ENV, SCI1, SCI2, MATH};

class ActualPlayer;

class Monopoly {
private:
    std::string name;
    std::vector<Square*> squares;
    ActualPlayer* owner;
    
public:
    Monopoly(std::string);
    ~Monopoly();
    void assign_monopoly(std::vector<Square*>);
    
    std::string getName();
    ActualPlayer* get_owner();
    void check_monopoly();
};






#endif
