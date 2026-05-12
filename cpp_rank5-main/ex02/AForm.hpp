#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class AForm {
private:
    const std::string name;
    bool isSigned;
    const int gradeReqToSig;
    const int gradeReqToEx;

public:
    AForm(std::string name, int sig, int ex);
    virtual ~AForm();

    std::string getName() const;
    bool getIsSigned() const;
    int getSignGrade() const;
    int getExecGrade() const;

    void beSigned(const Bureaucrat &b);
    void execute(Bureaucrat const & executor) const;

    virtual void executeAction() const = 0;
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif