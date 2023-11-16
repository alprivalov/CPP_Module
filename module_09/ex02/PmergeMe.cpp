#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{
    // std::cout << "PmergeMe Default constructor called" << std::endl;
    return ;
}

PmergeMe::PmergeMe(PmergeMe const & src)
{
    // std::cout << "PmergeMe Copy constructor called" << std::endl;
    *this = src;
    return ;
}

PmergeMe::~PmergeMe()
{
    // std::cout << "PmergeMe Destructor called" << std::endl;
    return ;
}

PmergeMe & PmergeMe::operator=(PmergeMe const & rhs){
    // std::cout << " Copy assignment operator called PmergeMe" << std::endl;
    (void)rhs;
    return *this;
}

std::ostream & operator<< (std::ostream & o, PmergeMe const & rhs){
    (void)rhs;
    return o;
}

template< typename T >
void print_table(T & container){
    std::cout << container << " ";
}

template<typename T>
void iter(T begin, T end, void (*func)(typename T::value_type&))
{
    for (T it = begin; it != end; ++it) {
        func(*it);
    }
}

template<typename T>
void PmergeMe::insertion_sort(T & container,int left, int right)
{
    for (int i = left; i <= right; i++)
    {
        int tmp = container[i];
        int j = i;
        while ((j > left) && (container[j - 1] > tmp))
        {
            container[j] = container[j - 1];
            j--;
        }
        container[j] = tmp;
    }
}

const char* PmergeMe::WrongInputException::what() const throw(){
    return("Error :wrong input");
}

template<typename T>
void PmergeMe::merge(T & container ,int left, int middle, int right)
{
    int i = left;
    int j = middle + 1;
    int k = left;
    while ((i <= middle) && (j <= right))
    {
        if (container[i] < container[j])
        {
            temp[k] = container[i];
            i++;
        }
        else
        {
            temp[k] = container[j];
            j++;
        }
        k++;
    }
        for (; j <= right; j++, k++)
            temp[k] = container[j];
        for (; i <= middle; i++, k++)
            temp[k] = container[i];
        for (i = left; i <= right; i++)
            container[i] = temp[i];
}

template<typename T>
void PmergeMe::mergesort(T & container ,int left, int right)
{
    if (left < right)
    {
        if ((right - left) <= 15)
            insertion_sort(container, left, right);
        else
        {
            int middle = (left + right) / 2;
            mergesort(container,left, middle);
            mergesort(container,middle + 1, right);
            merge(container,left, middle, right);
        }
    }
}

template<typename T>
void PmergeMe::parsing(T & container, std::string str){
    char *ptr;
    long int number = strtol(str.c_str(),&ptr,10);
    if(*ptr || errno == ERANGE || number < 0 || number > INT_MAX)
        throw WrongInputException();
    container.push_back(number);
}

template<typename T>
void    PmergeMe::PmergeMe_start(T & container){
    std::cout << "Before:\t";
    iter(container.begin(),container.end(),&print_table);
    mergesort(container,0, container.size() - 1);
    std::cout << std::endl << "After:\t" ;
    iter(container.begin(),container.end(),&print_table);
}

void PmergeMe::init_vector(int ac, char **av){
    std::vector<int> vector;
    std::deque<int> deque;

    std::string av_to_string;
    struct timeval stop, start;
    float interval;
    for(int i = 1; i < ac ;i++)
    {
        av_to_string.append(av[i]);
        parsing(vector,av_to_string);
        parsing(deque,av_to_string);
        av_to_string.clear();
    }
    temp = new int[vector.size()];
    std::cout.setf(std::ios::fixed, std::ios::floatfield); // Activer la notation décimale
    
    //vector
    gettimeofday(&start, NULL);
    PmergeMe_start(vector);
    gettimeofday(&stop, NULL);
    interval = ((stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec);
    std::cout  << std::endl << "Time to process a range of " << vector.size() << " elements with std::vector :" << std::setprecision(6) << interval / 1000000 << " us" << std::endl; 

    //deque
    gettimeofday(&start, NULL);
    PmergeMe_start(deque);
    gettimeofday(&stop, NULL);
    interval = ((stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec);
    std::cout  << std::endl << "Time to process a range of " << vector.size() << " elements with std::deque :" << std::setprecision(6) << interval / 1000000 << " us" << std::endl; 
    delete[] temp;
}
