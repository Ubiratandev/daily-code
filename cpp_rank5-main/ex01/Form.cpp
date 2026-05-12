#include "Form.hpp"
#include "Bureaucrats.hpp"
Form::Form(const std::string name, int gradeReqToSig, int gradeReqToEx)
    : name(name), isSigned(false), gradeReqToSig(gradeReqToSig), gradeReqToEx(gradeReqToEx)
{
    if (gradeReqToSig < 1 || gradeReqToEx < 1)
        throw GradeTooHighException();

    if (gradeReqToSig > 150 || gradeReqToEx > 150)
        throw GradeTooLowException();
    std::cout << "Form constructor called"<< std::endl;
}

std::string Form::getName() const { return name; }
bool Form::getIsSigned() const { return isSigned; }
int Form::getSignGrade() const { return gradeReqToSig; }
int Form::getExecGrade() const { return gradeReqToEx; }

void Form::beSigned(const Bureaucrat &newBu)
{
    if (newBu.getGrade() > gradeReqToSig)
        throw GradeTooLowException();

    isSigned = true;
}

 Form::~Form()
{
    std::cout << "destructor called" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Form& form)
{
    out << "Form name: " << form.getName() << std::endl;
    out << "Signed: " << (form.getIsSigned() ? "yes" : "no") << std::endl;
    out << "Grade to sign: " << form.getSignGrade() << std::endl;
    out << "Grade to execute: " << form.getExecGrade();

    return out;
}