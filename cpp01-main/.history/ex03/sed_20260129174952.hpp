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
            int pos;
            std::string after;
            std::string before;
            std::string newline;
            while(std::getline(infile, line))
            {
                pos = line.find(s1);
                after= line.substr(0, pos);
                before = line.substr(pos + s1.length());
                newline = after + s2 + before + "\n";
                std::cout<<line<<std::endl;
            }
        }
};