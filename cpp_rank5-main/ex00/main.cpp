#include "Bureaucrat.hpp"
int main()
{
    try
    {
        Bureaucrat newBou("Bira", 150);
        // newBou.decrementGrade(newBou.getGrade());
        newBou.incrementGrade(newBou.getGrade());
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}