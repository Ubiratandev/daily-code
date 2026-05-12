#include<iostream>
#include<string>

class Harl
{
    private:
        std::string *args;
        void(Harl::*funcs[])();
    public:
        void Debug();
        void Info();
        void Waring();
        void Error();
        Harl();
        ~Harl();

        
};