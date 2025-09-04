#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern {
    private:

    public:
        Intern(void);
        Intern(const Intern& other);
        Intern& operator=(const Intern& other);
        ~Intern(void);

        AForm*  makeForm(const std::string formName, const std::string formTarget);
};

#endif