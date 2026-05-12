#ifndef Bureaucrat_hpp
#define Bureaucrat_hpp
#include<iostream>
#include<string>
#include<exception>
#include"Form.hpp"

class Bureaucrat{
    private:
        const   std::string name;
        int     grade;
    public:
        ~Bureaucrat();
        Bureaucrat(std::string name, int grade);
        std::string getName() const;
        int getGrade()const;
        void setGrade(int newGrade);
        void    incrementGrade(int grade);
        void    decrementGrade(int grade);
        void    signForm(Form& newForm);
        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw(){
                    return("the high grade possible is 1");
                }
        };
        class GradeTooLowException : public std::exception{
            public:
                const char* what() const throw() {
                    return("the less grade is 150");
                }
        };
   
};
std::ostream& operator<<(std::ostream& out, const Bureaucrat& newBu);
#endif