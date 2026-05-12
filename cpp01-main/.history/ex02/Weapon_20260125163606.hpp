#include<string>
#include<iostream>

class Weapon{
    private:
        std::string typeOfWeapon;

    public:
        void setTypeOfWeapon(std::string value);
        std::string& getTypeOfWeapon(void);
        Weapon();
        ~Weapon();
};