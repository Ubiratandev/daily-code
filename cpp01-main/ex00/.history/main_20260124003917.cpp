#include<iostream>
#include<string>
#include"Zombie.hpp"

int main()
{
        Zombie *newHorde;
        int num = 10;
        std::string name = "zumbies";
        newHorde =  zombieHorde(num, name);
        for(int i = 0; i < num; i++)
        {
            newHorde[i].announce();
        }
        delete[] newHorde;
}