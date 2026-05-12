#include<iostream>
#include<string>

class Harl
{
    private:
       
    public:
        void Debug();
        void Info();
        void Waring();
        void Error();
        void Complain(std::string);
        Harl(std::string *args);
        ~Harl(void);

        
};