#ifdef ZOMBIE_HPP
#define ZOMBIE_HPP
class Zombie{
    std::string name = "";
    Zombie (void);
    ~Zombie(void);
    void announce(std::string name);
}

#endif