#include<iostream>
#include<string>
#include"HumanB.hpp"

HumanB::HumanB(std::string myName): _myName(myName)
{}
HumanB::~HumanB(void)
{
    std::cout<<"destructor human b called";
}

void HumanB::atack()
{
    
}