#ifndef Span_HPP
#define Span_HPP

#include <iostream>
#include <vector>
#include <algorithm> 
#include <list>

class Span
{
private:
    std::vector<int> v1;
    unsigned int _size;
    class OutofRangeException : public std::exception
    {
        public :
            virtual const char* what() const throw();
    };
    class ShortRangeException : public std::exception
    {
        public :
            virtual const char* what() const throw();
    };
protected:
public:
    //format canonique
    Span(void);
    Span(Span const & src);
    Span(unsigned int N);
    Span & operator=(Span const & rhs);
    ~Span();

    //additional constructor
   
    //getter

    //functions
    void addNumber(int nb);
    void shortestSpan();
    void longestSpan();
    void rangeofiterators(std::vector<int> v2);
    void print();

};
std::ostream & operator<<(std::ostream & o, Span const & rhs);

#endif