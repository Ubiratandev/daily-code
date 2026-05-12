#include<iostream>
#include<string>
#include"Zombie.hpp"
Zombie* zombieHorde(int num, std::string name)
{
    Zombie *horde = new Zombie[num];
    for(int i = 0; i < num; i++)
    {
        horde[i].setName(name);
        i++;
    }
    return(horde);
}
int main()
{
        Zombie *newHorde;
        int num = 10;
        std::string name = "zumbies";
        newHorde =  zombieHorde(num, name);
        for(int i = 0; i < num; i++)
        {
            newHorde[i].announce();
            i++;
        }
        delete newHorde;
}