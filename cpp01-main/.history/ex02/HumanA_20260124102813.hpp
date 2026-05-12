#include<iostream>
#include<string>
#include"Weapon.hpp"

class HumanA{
    private:
        std::string myWeapon;
        std::string myName;
    public:
        HumanA(Weapon& weapon, std::string& name);
        std::string getMyWeapon();
        void setMyWeapon(std::string typeWeapon);
        void atack(void);
};