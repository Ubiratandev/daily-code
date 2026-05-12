#include"Weapon.hpp"
#include<iostream>
#include<string>

void Weapon::setTypeOfWeapon(std::string& value)
{
    this->_typeOfWeapon = value;
}

std::string& Weapon::getTypeOfWeapon(void)
{
    return(this->_typeOfWeapon);
}

Weapon::Weapon(std::string typeOfWeapon) : _typeOfWeapon(typeOfWeapon)
{
}
Weapon::~Weapon(void)
{
    std::cout<<"destructor weapon called"<<std::endl;
}
