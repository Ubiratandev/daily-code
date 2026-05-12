#include<iostream>
#include<string>
#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main(void)
{
   std::string typeWeapon = "faca";
   Weapon  newWeapon(typeWeapon);
   HumanA  newHumanA("Fabio Akita" , newWeapon);
   HumanB newHumanB ("luca montano"); 
   newHumanA.atack();
   newHumanB.atack();
   Weapon newHumanBWeapon(typeWeapon);
   newHumanB.setMyWeapon(newHumanBWeapon);
   newHumanB.atack();
}