#include<iostream>
#include<string>
#include"Zombie.hpp"

int main()
{
    std::string name = "bob";
    
    Zombie* z1 = newZombie(name);
    z1->announce();
    delete z1; 

 
    randomChump("Alice");

    return 0;
}