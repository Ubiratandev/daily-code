#include<iostream>
#include"HumanA.hpp"
#include"Weapon.hpp"
#include<string>

HumanA::HumanA( std::string& myName, Weapon& myWeapon) : _myWeapon(myWeapon) , _myName(myName)
{

}
