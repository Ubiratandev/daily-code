
#include<iostream>
#include<string>
#include"Zombie.hpp"
Zombie* zombieHorde(int num, std::string name)
{
    Zombie *horde = new Zombie[num];
    for(int i = 0; i < num; i++)
    {
        horde[i].setName(name);
    }
    return(horde);
}