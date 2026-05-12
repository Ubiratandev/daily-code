#include<iostream>
#include<string>

class Harl
{
    private:
        void Debug();
        void Info();
        void Waring();
        void Error();
        void Complain(std::string);       
    public:
      
        Harl();
        ~Harl(void);

};