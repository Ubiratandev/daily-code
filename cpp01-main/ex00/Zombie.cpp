#include<iostream>
#include"Zombie.hpp"

void Zombie::setName(std::string& value)
{
    this->name = value;
}
void Zombie::announce(void)
{
    std::cout<<name<<": BraiiiiiiinnnzzzZ..."<<std::endl;
}
Zombie* newZombie(const std::string& name)
{
    Zombie *zombieNew = new Zombie(name);
    return zombieNew;
}
void randomChump( std::string name )
{
    Zombie * chumpZombie = newZombie(name);
    chumpZombie->announce();
    delete chumpZombie;
}
