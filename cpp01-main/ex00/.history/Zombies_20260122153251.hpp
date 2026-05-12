#ifdef ZOMBIE_HPP
#define ZOMBIE_HPP
class Zombies{
    std::string name = "";
    Zombies (void);
    ~Zombies(void);
    void announce(std::string name);
}

#endif