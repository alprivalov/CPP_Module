#include "Span.hpp"
int main()
{
    std::cout<< "--------" << "Span size : 10001 , Vector 10000 copy"<< "--------" << std::endl;
    {
        std::vector<int> v1(10000,3);
        Span sp = Span(10001);
        try
        {
            sp.rangeofiterators(v1);
            std::cout <<"shortestSpan =>\t ";
            sp.shortestSpan();
            std::cout << std::endl;
            std::cout <<"longestSpan =>\t ";
            sp.longestSpan();
            std::cout << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr<< e.what() << '\n';
        }
        std::cout <<"print template: " << std::endl;
        sp.print();
    }

    std::cout<< "--------" << "Span size : 3, Vector size : 10000, cannot copy"<< "--------" << std::endl;
    {
        std::vector<int> v1(10000,3);
        Span sp = Span(3);
        try
        {
            sp.rangeofiterators(v1);
            std::cout <<"shortestSpan =>\t ";
            sp.shortestSpan();
            std::cout << std::endl;
            std::cout <<"longestSpan =>\t ";
            sp.longestSpan();
            std::cout << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr<< e.what() << '\n';
        }
    }

    std::cout << "--------"<< "Span size : 3, addNumber x 4, cannot copy" << "--------" << std::endl;
    {
        Span sp = Span(3);
        try
        {
            sp.addNumber(-1);
            sp.addNumber(0);
            sp.addNumber(10);
            sp.addNumber(20);
            std::cout <<"shortestSpan =>\t ";
            sp.shortestSpan();
            std::cout << std::endl;
            std::cout <<"longestSpan =>\t ";
            sp.longestSpan();
            std::cout << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr<< e.what() << '\n';
        }
        std::cout <<"print template: " << std::endl;
        sp.print();
    }

    std::cout<< "--------" << "Span size :3, addNumber x 3, copy"<< "--------" << std::endl;
    {
        Span sp = Span(3);
        try
        {
            sp.addNumber(-1);
            sp.addNumber(0);
            sp.addNumber(10);
            std::cout <<"shortestSpan =>\t ";
            sp.shortestSpan();
            std::cout << std::endl;
            std::cout <<"longestSpan =>\t ";
            sp.longestSpan();
            std::cout << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr<< e.what() << '\n';
        }
        std::cout <<"print template: " << std::endl;
        sp.print();
    }
    std::cout<< "--------" << "Span size:1 , too short"<< "--------" << std::endl;
    {
        Span sp = Span(1);
        try
        {
            sp.addNumber(-1);
            std::cout <<"shortestSpan =>\t ";
            sp.shortestSpan();
            std::cout << std::endl;
            std::cout <<"longestSpan =>\t ";
            sp.longestSpan();
            std::cout << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr<< e.what() << '\n';
        }
        std::cout <<"print template: " << std::endl;
        sp.print();
    }
}