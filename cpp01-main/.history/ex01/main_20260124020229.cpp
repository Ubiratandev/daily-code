#include <iostream>
#include <string>

int main()
{
    std::string var = "HI THIS IS BRAIN";
    
    std::string* pointer = &var;

    std::string& ref = var;

    std::cout<<&var;
    std::cout<<pointer;
    std::cout<<&ref;

    std::cout<<var;
    std::cout<<*pointer;
    std::cout<<ref;
}