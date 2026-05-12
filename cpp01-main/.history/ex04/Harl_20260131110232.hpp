#include<iostream>
#include<string>

class Harl
{
    private:
        void debug();
        void info();
        void warning();
        void error();
    public:
        
        void Complain(std::string);       
        Harl();
        ~Harl(void);

};