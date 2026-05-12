#include"Weppon.hpp"
#include<iostream>
#include<string>

void Weppon::setTypeOfWeppon(std::string& value)
{
    this->typeOfWeppon = value;
}

std::string& Weppon::getTypeOfWeppon(void)
{
    return(this->typeOfWeppon);
}

Weapon::Weapon(void) : typeOfWeapon("")
{
}
Weppon::Weppon(void)
{
    std::cout<<"destructor called";
}
