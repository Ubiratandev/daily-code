#ifndef _HUMANB_HPP
#define _HUMANB_HPP
    #include"Weapon.hpp"
    #include<iostream>
    #include<string>

    class HumanB{
     private:
         Weapon* _myWeapon;
         std::string _myName;
     public:
         HumanB(std::string myName);
         ~HumanB(void);
         std::string getMyName(void);
         void setMyWeapon(Weapon newWeapon);
         Weapon* getMyWeapon();
         void atack(void);

    };
#endif