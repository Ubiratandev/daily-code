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
    std::cout<<"my constructor are called here\n";
}
Sed::~Sed(void)
{
    std::cout<<"Sed desctructor called \n";
}

 void Sed::replaceWord(void)
        {
            std::string line;
            std::ifstream infile(_fileName.c_str());
            size_t pos;
            std::string after;
            std::string before;
            std::ofstream outfile(_fileName+".replace");
            if(_s1.empty())
                return;
            while(std::getline(infile, line))
            {
                pos = line.find(_s1);
                if(pos == std::string::npos)
                {
                    outfile <<line<<std::endl;
                }
                else
                {
                    after= line.substr(0, pos);
                    before = line.substr(pos + _s1.length());
                    outfile << after << _s2 << before << std::endl;
                    
                }
            }
        }