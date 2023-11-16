#include "Span.hpp"

Span::Span(void)
{
    std::cout << "Span Default constructor called" << std::endl;
    return ;
}
Span::Span(unsigned int N):_size(N)
{
    v1.reserve(N);
    std::cout << "Span Default constructor called" << std::endl;
    return ;
}

Span::Span(Span const & src)
{
    std::cout << "Span Copy constructor called" << std::endl;
    *this = src;
    return ;
}

Span::~Span()
{
    std::cout << "Span Destructor called" << std::endl;
    return ;
}

Span & Span::operator=(Span const & rhs){
    std::cout << " Copy assignment operator called Span" << std::endl;
    if (this != &rhs)
    (void)rhs;
    return *this;
}

const char* Span::OutofRangeException::what() const throw(){
    return("Error: OutofRangeException");
}

const char* Span::ShortRangeException::what() const throw(){
    return("Error: ShortRangeException");
}



std::ostream & operator<< (std::ostream & o, Span const & rhs){
    (void)rhs;
    return o;
}

void Span::addNumber(int nb){
    if (_size > v1.size())
        v1.push_back(nb);
    else
        std::cout << "Cannot add :" << nb << std::endl;
}

// template <typename T >
void Span::shortestSpan(){
    std::vector<int>::iterator it;
    std::vector<int>::iterator it_tmp;
    int size = 0;
    int output_value = 0;
    std::vector<int> tmp;
    if (v1.size() < 2)
        throw ShortRangeException();
    for(it = v1.begin(); it != v1.end(); ++it)
    {
        size++;
        tmp.push_back(*it);
        it_tmp = it;
    }
    std::sort(tmp.begin(),tmp.end());
    output_value = abs(tmp[size - 1] - tmp[0]);
    for(it = tmp.begin(); it != tmp.end(); ++it)
    {
        if(*it - *it_tmp < output_value)
            output_value = abs(*it - *it_tmp);
        *it_tmp = *it;
    }
    std::cout << abs(output_value);
}

void Span::longestSpan(){
    std::vector<int>::iterator it;
    std::vector<int> tmp;
    int output_value = 0;
    int size = 0;
    if (v1.size() < 2)
        throw ShortRangeException();

    for(it = v1.begin(); it != v1.end(); ++it)
    {
        tmp.push_back(*it);
        size++;
    }
    std::sort(tmp.begin(),tmp.end());
    output_value = tmp[size - 1];
    output_value -= *tmp.begin();
    std::cout << abs(output_value);
}

void Span::rangeofiterators(std::vector<int> v2){
    std::vector<int>::iterator it;

    if(v2.size() + v1.size() > _size)
        throw OutofRangeException();
    for(it = v2.begin(); it != v2.end(); ++it)
        addNumber(*it);
}

void Span::print(){
    std::vector<int>::iterator it;

    for(it = v1.begin(); it != v1.end(); ++it)
        std::cout << *it << std::endl;
}