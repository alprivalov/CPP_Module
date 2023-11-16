#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

template < typename T>
std::string easyfind(T & a,int b){

    if(std::find(a.begin(),a.end(),b) != a.end())
        return("found");
    else
        return("Not found");
}