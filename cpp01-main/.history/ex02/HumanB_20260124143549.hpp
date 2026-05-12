#include"Weapon.hpp"
#include<iostream>
#include<string>

class HumanB{
    private:
        Weapon* myWeapon;
        std::string myName;
    public:
        HumanB(std::string name);
        ~HumanB(void);
        std::string getMyName(void);
        void atack(void);

};