#include<iostream>
#include<string>
#include <fstream>

class Sed
{
    private:
        std::string _fileName;
        std::string _s1;
        std::string _s2;
    public:
        std::string getFileName();
        std::string getS1();
        std::string getS2();
        void setFileName();
        Sed(std::string fileName,std::string s1, std::string s2);
        ~Sed(void);
        void replaceWord(std::string fileName, std::string s1, std::string s2 )
        {
            std::string line;
            std::ifstream infile(fileName);
            while(std::getline(infile, line))
            {
                std::cout<<line<<std::endl;
            }
        }
};