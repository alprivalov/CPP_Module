#include "Bureaucrate.hpp"

int main(){
    //init bureaucrate
    Bureaucrate bureaucrate("Kevin", 1);
    Bureaucrate bureaucrate2("Bob", 100);
    Bureaucrate bureaucrate3("Jean", 150);
    std::cout << std::endl;
    std::cout << "bureaucrate invalide :";
    try
    {
        Bureaucrate invalid_bureaucrate();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        Bureaucrate invalid_bureaucrate("Paul", 0);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    //test_one
    
    std::cout << std::endl;
    try
    {
        std::cout << "bureaucrate1 :"<< std::endl;
        std::cout << bureaucrate.getGrade() << " increment_grade :";
        bureaucrate.increment_grade();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() <<  '\n';
    }

    //test_two
    std::cout << std::endl;
    std::cout << "bureaucrate2 :"<< std::endl;
    try
    {
        std::cout  << bureaucrate2.getGrade() << " decrement_grade :";
        bureaucrate2.decrement_grade();
        std::cout << "good" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    //test_three
    std::cout << std::endl;
    std::cout << "bureaucrate3 :"<< std::endl;
    try
    {
        std::cout << bureaucrate3.getGrade() << " increment_grade :";
        bureaucrate3.increment_grade();
        std::cout << "good"<< std::endl;
        std::cout << bureaucrate3.getGrade() << " decrement_grade :";
        bureaucrate3.decrement_grade();
        std::cout << "good" << std::endl;
        std::cout << bureaucrate3.getGrade() << " decrement_grade :";
        bureaucrate3.decrement_grade();
        std::cout << "good" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl;
}