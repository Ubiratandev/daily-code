#include<iostream>
#include<string>
#include"Weapon.hpp"

class HumanA{
    private:
        Weapon _myWeapon;
        std::string _myName;
    public:
        //HumanA(Weapon& myWeapon, std::string& myName);
        HumanA(std::string _myName, Weapon& _myWeapon);
        Weapon& getMyWeapon();
        void atack(void);
};