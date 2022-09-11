#ifndef TEST_HH
#define TEST_HH

#include <iostream>
#include <sstream>

#define GRN "\e[0;32m"
#define RED "\e[0;31m"
#define BLUE "\e[0;36m"
#define WHT "\e[0;0m"

class Test
{
private:
    bool pass_{false};
public:
    ~Test()
    {
        if (this->pass_)
        {
            std::cout << WHT ">> " << GRN "Test erfolgreich" << WHT << std::endl;
        }
        else
        {
            std::cout << WHT ">> " << RED "Test fehlgeschlagen" << WHT << std::endl;
        }
    }
    void print_checking()
    {
        std::cout << BLUE << "checking: ";
        
    }

    template<class T>
    /*
    * 'const char* name' standartisiert mit Built-in Function, die den Namen
    * aufrufenden Funktion enthält.
    */
    void equals(T const& expected, T const& actual, const char* name = __builtin_FUNCTION())
    {
        print_checking();
        if ( expected != actual )
        {
            std::cout << RED << name << ": " << "expected: " << expected << " but was: " << actual << WHT << std::endl;
            this->pass_ = false;
        }
        else
        {
            std::cout << GRN << name << WHT << std::endl;
            this->pass_ = true;
        }
    }

    void fail(const char* name = __builtin_FUNCTION())
    {
        print_checking();
        std::cout << RED << name << ": not implemented yet" << WHT << std::endl;
        this->pass_ = false;
    }

    template<class T>
    void prints(std::string exp, T& t, const char* name = __builtin_FUNCTION()) 
    { 
        std::stringstream act;
        act << t;
        equals( exp, act.str(), name );
    }
};

#endif