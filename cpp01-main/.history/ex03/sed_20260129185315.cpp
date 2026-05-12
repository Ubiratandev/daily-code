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

 void replaceWord(std::string fileName, std::string s1, std::string s2 )
        {
            std::string line;
            std::ifstream infile(fileName);
            size_t pos;
            std::string after;
            std::string before;
            std::string newline;
            std::ofstream outfile(fileName+".replace");
            if(s1.empty())
                return;
            while(std::getline(infile, line))
            {
                pos = line.find(s1);
                if(pos == std::string::npos)
                {
                    outfile <<line<<std::endl;
                }
                else
                {
                    after= line.substr(0, pos);
                    before = line.substr(pos + s1.length());
                    newline = after + s2 + before + "\n";
                    outfile << newline;
                }
            }
        }