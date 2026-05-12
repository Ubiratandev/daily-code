#include<string>
#include<iostream>

class Weapon{
    private:
        std::string _typeOfWeapon;

    public:
        Weapon(std::string getTypeOfWeapon);
        void setTypeOfWeapon(std::string& value);
        std::string& getTypeOfWeapon(void);
        ~Weapon();
};