#include<string>
#include<iostream>

class Weppon{
    private:
        std::string typeOfWeppon;

    public:
        void setTypeOfWeppon(std::string& value);
        std::string& getTypeOfWeppon(void);
        Weppon();
        ~Weppon();
};