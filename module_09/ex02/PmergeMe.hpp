#ifndef PmergeMe_HPP
#define PmergeMe_HPP

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <time.h>
#include <stdlib.h>
#include <cerrno>
#include <sys/time.h>
#include <iomanip>
#include <limits.h>

class PmergeMe
{
private:
    int *temp;

    template<typename T>
    void parsing(T & container,std::string str);  

    template<typename T>
    void mergesort(T & container ,int left, int right);

    template<typename T>
    void merge(T & container, int left, int middle, int right);

    template<typename T>
    void insertion_sort(T & container,int left, int right);

    template<typename T>
    void print_vector(T & container);
    class WrongInputException : public std::exception
    {
        public:
            virtual const char * what() const throw();
    };
    template<typename T>
    void    PmergeMe_start(T & container);
protected:
public:
    //format canonique
    PmergeMe(void);
    PmergeMe(PmergeMe const & src);
    PmergeMe & operator=(PmergeMe const & rhs);
    ~PmergeMe();

    //additional constructor
   
    //getter

    //functions
    void init_vector(int ac, char **av);
};
std::ostream & operator<<(std::ostream & o, PmergeMe const & rhs);

#endif