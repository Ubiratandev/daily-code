#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat; // 👈 forward declaration

class Form {
private:
    const std::string name;
    bool isSigned;
    const int gradeReqToSig;
    const int gradeReqToEx;

public:
    Form(const std::string name, int gradeReqToSig, int gradeReqToEx);
    ~Form();

    std::string getName() const;
    bool getIsSigned() const;
    int getSignGrade() const;
    int getExecGrade() const;

    void beSigned(const Bureaucrat& newBu);

    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw() {
            return "grade is too high";
        }
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw() {
            return "grade is too low";
        }
    };
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif