#include"Weapon.hpp"
#include<iostream>
#include<string>

void Weapon::setTypeOfWeapon(std::string& value)
{
    this->typeOfWeapon = value;
}

std::string& Weapon::getTypeOfWeapon(void)
{
    return(this->typeOfWeapon);
}

Weapon::Weapon(void) : typeOfWeapon("")
{
}
Weapon::Weapon(void)
{
    std::cout<<"destructor called";
}
