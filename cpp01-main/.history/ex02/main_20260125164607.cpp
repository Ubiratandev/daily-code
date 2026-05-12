#include<iostream>
#include<string>
#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main(void)
{
   std::string typeWeapon = "faca";
   Weapon  newWeapon(typeWeapon);
   HumanA  newHumanA("bob" , newWeapon); 
   newHumanA.atack()
}