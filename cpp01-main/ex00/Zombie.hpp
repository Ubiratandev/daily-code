#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include<iostream>
#include<string>
class Zombie{
    private:
        std::string name;
    public:
        Zombie(){};
        Zombie(const std::string& n) : name(n){};
        void announce(void);
        void setName(std::string& value);
       
};
    Zombie* newZombie(const std::string& name);
    void randomChump( std::string name );
#endif