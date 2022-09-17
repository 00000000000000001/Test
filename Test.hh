#ifndef TEST_HH
#define TEST_HH

#include <iostream>
#include <sstream>
#include <string>

#define GRN "\e[0;32m"
#define RED "\e[0;31m"
#define BLUE "\e[0;36m"
#define WHT "\e[0;0m"

class Test
{
private:
    bool pass_{true};
    std::string last_{};
public:
    ~Test()
    {
        if (this->pass_)
        {
            std::cout << WHT ">> " << GRN "Test passed" << WHT << std::endl;
        }
        else
        {
            std::cout << WHT ">> " << RED "Test failed" << WHT << std::endl;
        }
    }

    template<class T>
    void print(bool pass, T const& exp, T const& act, std::string const& name)
    {
        std::cout << BLUE << "checking: ";
        if (pass)
        {
            std::cout << GRN << name << WHT << std::endl;
        }
        else
        {
            std::cout << RED << name << ": " << "expected: " << exp << " but was: " << act << WHT << std::endl;
        }
        
    }

    template<class T>
    /*
    * 'const char* name' standartisiert mit Built-in Function, die den Namen
    * aufrufenden Funktion enthält.
    */
    void equals(T const& exp, T const& act, std::string const& name = __builtin_FUNCTION())
    {
        if ( exp != act )
        {
            print(false, exp, act, name);
            this->pass_ = false;
        }
        else
        {
            print(true, exp, act, name);
        }
    }

    template<class T>
    std::string prints(std::string exp, T& t, std::string const& name = __builtin_FUNCTION()) 
    { 
        std::stringstream act{};
        act << t;
        equals( exp, act.str(), name );
        return act.str();
    }

    void fail(const char* name = __builtin_FUNCTION())
    {
        std::cout << BLUE << "checking: ";
        std::cout << RED << name << ": not implemented yet" << WHT << std::endl;
        this->pass_ = false;
    }
};

#endif