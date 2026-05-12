#include"Weapon.hpp"
#include<iostream>
#include<string>

class HumanB{
    private:
        Weapon* _myWeapon;
        std::string _myName;
    public:
        HumanB(std::string _myName);
        ~HumanB(void);
        std::string getMyName(void);
        void atack(void);

};