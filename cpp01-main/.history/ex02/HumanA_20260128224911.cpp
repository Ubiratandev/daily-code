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

std::string HumanA::getMyName(void)
{
    return(this->_myName);
}
void HumanA::atack(void)
{
    std::cout<<"\n"<< this->getMyName()<<" attacks with their "<<this->getMyWeapon().getTypeOfWeapon()<<std::endl;
}
 HumanA::~HumanA(void)
{
    // std::cout<<"desctuctor HumanA called\n";
}