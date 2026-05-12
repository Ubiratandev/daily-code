#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include<iostream>
#include<string>
class Zombie{
    private:
        std::string name;
    public:
        Zombie (void);
        ~Zombie(void);
        void announce(void);
        void setName(std::string& value);
        void zombieHorde(int n, std::string nome);
};

#endif