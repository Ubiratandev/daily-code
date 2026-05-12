#include "Bureaucrat.hpp"

Bureaucrat::~Bureaucrat()
{
    std::cout<<"Bureaucrat destructed with success"<<std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade)
    : name(name)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();

    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();

    this->grade = grade;

    std::cout << "Constructor called with success" << std::endl;
}
void Bureaucrat::setGrade(int newGrade)
{
    this->grade = newGrade;
}
void Bureaucrat::incrementGrade(int grade)
{
    if(grade + 1 > 150)
    {
        throw Bureaucrat::GradeTooLowException();
        
    }
    else   
        this->setGrade(grade + 1);
}
void Bureaucrat::decrementGrade(int grade)
{
    if(grade - 1 < 1)
    {
        throw Bureaucrat::GradeTooHighException();
    }
      else   
        this->setGrade(grade - 1);
}
int Bureaucrat::getGrade()
{
    return (this->grade);
}

std::ostream& operator<<(std::ostream& out, Bureaucrat& newBu)
{
   out << "Name: " << newBu.getName() << std::endl;
    out << "Grade: " << newBu.getGrade(); 
    return(out);
}

