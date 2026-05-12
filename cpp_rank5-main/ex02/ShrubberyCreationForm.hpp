#ifndef SHRUBBERYCREATIONFORM
#define SHRUBBERYCREATIONFORM
#include<iostream>
#include<string>
#include"AForm.hpp"
class ShrubberyCreationForm : public AForm
{
    private:
        std::string target;
    public:
          ShrubberyCreationForm(std::string target);
        void executeAction() const;
};
#endif