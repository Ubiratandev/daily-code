#include<iostream>
#include<string>
#include"HumanB.hpp"

HumanB::HumanB(std::string myName): _myName(myName)
{}
HumanB::~HumanB(void)
{
    std::cout<<"destructor human b called";
}

std::string HumanB::getMyName(void)
{
    return(this->_myName);
}
Weapon* HumanB::getMyWeapon()
{
    return this->_myWeapon;
}
void HumanB::atack()
{
    if (_myWeapon)
        std::cout << _myName << " attacks with their "
                  << std::endl;
    else
        std::cout << _myName << " attacks with their bare hands"
                  << std::endl;
}