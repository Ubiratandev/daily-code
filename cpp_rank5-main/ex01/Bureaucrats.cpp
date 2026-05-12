#include "Bureaucrats.hpp"

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

std::string Bureaucrat::getName() const
{
    return(this->name);
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
int Bureaucrat::getGrade()const
{
    return (this->grade);
}


// void    Bureaucrat::signForm(Form& newForm)
// {
//     try
//     {
//         newForm.beSigned(*this);
//     }
//     catch(std::exception& e)
//     {
//         std::cout << e.what()<< std::endl;
//     }
    
// }

void Bureaucrat::signForm(Form& form)
{
    try
    {
        form.beSigned(*this);
        std::cout << this->getName() << " signed " << form.getName() << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << this->getName() << " couldn’t sign "
                  << form.getName() << " because " << e.what() << std::endl;
    }
}


std::ostream& operator<<(std::ostream& out, const Bureaucrat& newBu)
{
   out << "Name: " << newBu.getName() << std::endl;
    out << "Grade: " << newBu.getGrade(); 
    return(out);
}
