#include<istream>
#include<string>
#include"sed.hpp"

int main(int argc, char *argv[])
{
    if(argc != 4)
    {
        std::cout<<"the numbers of args must be 4"<<std::endl;
        return(1);
    }
    std::string newFileName = argv[1];
    std::string newS1 = argv[2];
    std::string newS2 = argv[3];

    if(newS1.empty())
    {
        std::cout<<"the s1 must be a value"<<std::endl;
        return(1);
    }
        Sed newSed(newFileName, newS1, newS2);

}