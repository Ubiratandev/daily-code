#include<iostream>
#include<string>

class Harl
{
    private:
        void Debug();
        void Info();
        void Waring();
        void Error();
    public:
        
        void Complain(std::string);       
        Harl();
        ~Harl(void);

};