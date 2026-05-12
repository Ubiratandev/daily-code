#include<iostream>
#include<string>

class sed
{
    private:
        std::string _fileName;
        std::string _s1;
        std::string _s2;
    public:
        std::string getFileName();
        std::string getS1();
        std::string getS2();
};