#include<iostream>
#include<string>

class HumanA{
    private:
        std::string weapon;
        std::string name;
    public:
        HumanA(std::string weappon, std::string name);
        std::string getMyWeapon();
        void setMyWeapon(std::string typeWeapon);
        void atack(void);
};