#ifdef ZOMBIE_CPP
#DEFINE ZOMBIE_CPP
class Zombies{
    Zombies ( int N, std::string nam);
    ~Zombies(void)
    {
        std::cout<<"the object is destroied";
    }

}

#endif