#include<iostream>
#include"HumanA.hpp"
#include"Weapon.hpp"
#include<string>

// HumanA::HumanA( std::string& myName, Weapon& myWeapon) : _myWeapon(myWeapon) , _myName(myName)
// {

// }
HumanA::HumanA(std::string myName, Weapon& myWeapon)
    : _myName(myName), _myWeapon(myWeapon)
{
}
Weapon& HumanA::getMyWeapon()
{

    return this->_myWeapon;
}


