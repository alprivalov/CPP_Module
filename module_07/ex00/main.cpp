#include <iostream>

template< typename a >

void swap(a & x,a & y){
    a tmp;

    tmp = x;
    x = y; 
    y = tmp;
}

template< typename b >

b min(b const & x,b const & y){
    if(x >= y)
        return (y);
    else
        return (x);
}

template< typename c >

c max(c const & x,c const & y){
    if(x <= y)
        return (y);
    else
        return (x);
}

int foo(int x){
    std::cout << "long computing time " << std::endl;
    return x;
}

int main( void ) {
    int a = 2;
    int b = 3;
    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    return 0;
}