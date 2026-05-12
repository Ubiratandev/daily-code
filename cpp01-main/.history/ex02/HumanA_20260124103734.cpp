#include<iostream>
#include"HumanA.hpp"
#include"Weapon.hpp"
#include<string>

HumanA::HumanA(Weapon& myWeapon, std::string& myName) : _myWeapon(myWeapon) , _myName(myName)
{

}
