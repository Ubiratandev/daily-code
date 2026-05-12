#include<istream>
#include<string>
#include"sed.hpp"

int main(int argc, char *argv[])
{
    if(argc < 4)
        return(-1);
    Sed::Sed(argv[1], argv[2], argv[3]);
}