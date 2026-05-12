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
        
    Harl();
    ~Harl(void);
    void Complain(std::string);       

};