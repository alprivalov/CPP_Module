#include "easyfind.hpp"

int main(){
    std::cout <<"------" << "test 1 :list :Found " <<"------" << std::endl;
    {
        std::list<int>  lst1;
        lst1.push_back(10);
        lst1.push_back(42);
        lst1.push_back(12);
        lst1.push_back(0);
        std::cout << "lst1 :" << easyfind(lst1,10) << std::endl;
    }
    std::cout <<"------" << "test 2 :list : Not found " <<"------" << std::endl;
    {
        std::list<int>  lst2;
        lst2.push_back(42);
        lst2.push_back(12);
        lst2.push_back(0);
        std::cout << "lst2 :" << easyfind(lst2,10) <<std::endl;
    }
    std::cout <<"------" << "test 3 :vector : Not found " <<"------" << std::endl;
    {
        std::vector<int>    v1(3,3);
        std::cout << "vector 1 :" << easyfind(v1,10) << std::endl;
    }
    std::cout <<"------" << "test 4 :vector : Found " <<"------" << std::endl;
    {
        std::vector<int>    v2(10,10);
        std::cout << "vector 2 :" << easyfind(v2,10) << std::endl;
    }
}