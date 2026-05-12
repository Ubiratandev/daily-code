#include "AForm.hpp"

AForm::AForm(std::string name, int sig, int ex)
: name(name), isSigned(false), gradeReqToSig(sig), gradeReqToEx(ex)
{
    if (sig < 1 || ex < 1)
        throw std::exception();

    if (sig > 150 || ex > 150)
        throw std::exception();
}

AForm::~AForm() {}

std::string AForm::getName() const { return name; }
bool AForm::getIsSigned() const { return isSigned; }
int AForm::getSignGrade() const { return gradeReqToSig; }
int AForm::getExecGrade() const { return gradeReqToEx; }