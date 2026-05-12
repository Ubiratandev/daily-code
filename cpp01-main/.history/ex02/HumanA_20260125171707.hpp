#ifndef HUMANA_HPP
#define HUMANA_HPP
#include<iostream>
#include<string>
#include"Weapon.hpp"

class HumanA{
    private:
        std::string _myName;
        Weapon _myWeapon;
    public:
        HumanA(std::string _myName, Weapon& _myWeapon);
        ~HumanA(void);
        Weapon& getMyWeapon();
        std::string getMyName(void);
        void atack(void);
};
#endif