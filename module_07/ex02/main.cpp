#include "Array.hpp"

int main(){

    Array<int>a = Array<int>(10);
    try
    {
        std::cout << a[9] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Cannot access array because " << e.what() << '\n';
    }
    a.size();
    return 0;
}