#include<iostream>
#include"Zombie.hpp"

void Zombie::setName(std::string& value)
{
    Zombie::name = value;
}
void Zombie::announce(void)
{
    std::cout<<name;
}
Zombie::~Zombie(void)
{
    std::cout<<"Desctructor called";
}