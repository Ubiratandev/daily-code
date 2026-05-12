#include<iostream>
#include<string>
#include"Weapon.hpp"

class HumanA{
    private:
        std::string myWeapon;
        std::string myName;
    public:
        HumanA(Weapon& myWeapon, std::string& myName);
        std::string getMyWeapon();
        void setMyWeapon(std::string typeWeapon);
        void atack(void);
};