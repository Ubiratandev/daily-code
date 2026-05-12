#include<iostream>
#include<string>
#include"Weapon.hpp"

class HumanA{
    private:
        Weapon _myWeapon;
        std::string _myName;
    public:
        HumanA(std::string _myName, Weapon& _myWeapon);
        ~HumanA(void);
        Weapon& getMyWeapon();
        std::string getMyName(void);
        void atack(void);
};