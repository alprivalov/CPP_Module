#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
private:
    std::string ideas[100];
protected:
public:
    //format canonique
    Brain(void);
    Brain(Brain const & src);
    Brain & operator=(Brain const & rhs);
    ~Brain();
    
    //getter
    void    getter_ideas();
};

#endif