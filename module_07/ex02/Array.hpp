#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>

template < typename T>
class Array{
public:
    Array(void){
        tab = new T();
        _size = 0;
    }
    Array(unsigned int n){
        tab = new T[n];
        _size = n;
        for(size_t i = 0; i < _size; i++)
            tab[i] = i;
    }
    Array(Array const & content){
        std::cout << "Array Copy constructor called" << std::endl;
        tab = NULL;
        *this = content;
        return ;
    }
    Array & operator=(Array const & rhs){
        std::cout << " Copy assignment operator called tets" << std::endl;
        if(this != &rhs)
        {
            if (tab)
                delete[] tab;
            tab = new T[rhs._size];
            for(size_t i = 0; i < rhs._size;i++)
                tab[i] = rhs.tab[i];
            _size = rhs._size;
        }
        return *this;
    }
    T & operator[](size_t i){
        std::cout << "Copy assignment operator called tets" << std::endl;
        if(i >= _size)
            throw IndexIsOutOfBoundsException();
        return tab[i];
    }
    ~Array(void){
        if (tab)
            delete[] tab;
        std::cout << "Array Destructor called" << std::endl;
    }

    size_t size()const{
        return(_size);
    }
private:
    class IndexIsOutOfBoundsException : public std::exception
    {
        public :
            virtual const char* what() const throw(){
                return("index is out of bounds");
            }
    };
    T *tab;
    size_t _size;
};

#endif
