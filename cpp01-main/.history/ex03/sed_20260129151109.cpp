#include"sed.hpp"

std::string Sed::getFileName()
{
    return this->_fileName;
}
std::string Sed::getS1()
{
    return this->_s1;
}

std::string Sed::getS2()
{
    return this->_s2;
}

Sed::Sed(std::string fileName, std::string s1, std::string s2)
{
    this->_fileName = fileName;
    this->_s1 = s1;
    this-> _s2 = s2;
}