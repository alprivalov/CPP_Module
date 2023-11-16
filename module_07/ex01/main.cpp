#include <iostream>

template< typename tmp >

void iter(tmp *t,tmp size,void (*f)(tmp & )){
    for(int i = 0; i < size ;i++)
        f(t[i]);
}

template< typename a >

void print_table(a & x){
    std::cout << x << std::endl;
}

int main( void ) {
    int size = 10;
    int tab[size];

    for(int i = 0;i < 10;i++)
        tab[i] = i;
    iter(tab,10,&print_table);
    // iter<int>(tab,10,& print_table);
}