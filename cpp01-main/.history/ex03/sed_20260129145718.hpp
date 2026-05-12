#include<iostream>
#include<string>

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
        void setS1();
        void setS2();
        Sed(std::string fileName,std::string s1, std::string s2);
};