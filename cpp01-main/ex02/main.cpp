#include <iostream>
#include <string>

int main()
{
    std::string var = "HI THIS IS BRAIN";
    
    std::string* pointer = &var;

    std::string& ref = var;

    
    std::cout<<"adress of var: "<<&var<<std::endl;
    std::cout<<"adress of pointer: "<<pointer<<std::endl;
    std::cout<<"adress of ref: "<<&ref<<std::endl;

    std::cout<<"value of var "<<var<<std::endl;
    std::cout<<"value of pointer "<<*pointer<<std::endl;
    std::cout<<"value of ref "<<ref<<std::endl;
}