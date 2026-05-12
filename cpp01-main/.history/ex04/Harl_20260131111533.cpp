#include<iostream>
#include<string>
#include"Harl.hpp"

void Harl::debug()
{
    std::cout<<"Harl debug function was called"<<std::endl;
}
void Harl::info()
{
    std::cout<<"Harl info function was called"<<std::endl;
}

void Harl::warning()
{
    std::cout<<"Harl warning function was called"<<std::endl;
}
void Harl::error()
{
    std::cout<<"Harl error function was called"<<std::endl;
}
void Harl::Complain(std::string arg)
{
    std::string complainArgs[] = {"debug","info", "warning","error"};
}