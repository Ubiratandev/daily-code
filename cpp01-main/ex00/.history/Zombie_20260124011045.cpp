#include<iostream>
#include"Zombie.hpp"

void Zombie::setName(std::string& value)
{
    this->name = value;
}
void Zombie::announce(void)
{
    std::cout<<"Iam a zumbie end my name is "<<name<<"\n";
}
Zombie::Zombie(void)
{
    std::cout<<"consturctor is alive\n";
}
Zombie::~Zombie(void)
{
    std::cout<<"Desctructor called\n";
}