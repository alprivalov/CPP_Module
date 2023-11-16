#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{
    // std::cout << "BitcoinExchange Default constructor called" << std::endl;
    return ;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & src)
{
    // std::cout << "BitcoinExchange Copy constructor called" << std::endl;
    *this = src;
    return ;
}

BitcoinExchange::~BitcoinExchange()
{
    // std::cout << "BitcoinExchange Destructor called" << std::endl;
    return ;
}

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const & rhs){
    // std::cout << " Copy assignment operator called BitcoinExchange" << std::endl;
    if(this != &rhs)
    {
        map_data = rhs.map_data;
    }
    return *this;
}


std::ostream & operator<<(std::ostream & o, BitcoinExchange const & rhs){
    (void)rhs;
    return o;
}

const char* BitcoinExchange::CannotOpenFdException::what() const throw(){
    return("Error: cannot open fd");
}
const char* BitcoinExchange::WrongDateException::what() const throw(){
    return("Error: bad input => ");
}
const char* BitcoinExchange::WrongDateFormatException::what() const throw(){
    return("Error: wrong date format ");
}
const char* BitcoinExchange::WrongValueException::what() const throw(){
    return("Error: wrong value input => ");
}
const char* BitcoinExchange::TooTargeANumberException::what() const throw(){
    return("Error: too large a number => ");
}
const char* BitcoinExchange::NotAPositiveNumberException::what() const throw(){
    return("Error: not a positive number => ");
}
const char* BitcoinExchange::NotYetCreatedException::what() const throw(){
    return("Error: Doesn't exist at this day => ");
}

static int check_date_int(int year, int month, int day){
    if(year>=1900 && year<=9999)
    {
        //check month
        if(month>=1 && month<=12)
        {
            //check days
            if((day>=1 && day<=31) && (month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12))
                return(0);
            else if((day>=1 && day<=30) && (month==4 || month==6 || month==9 || month==11))
                return(0);
            else if((day>=1 && day<=28) && (month==2))
                return(0);
            else if(day==29 && month==2 && (year%400==0 ||(year%4==0 && year%100!=0)))
                return(0);
            else
                return(1);
        }
        else
            return(1);
    }
    else
        return(1);
}

static int check_date_string(std::string str){
    for(size_t i = 0;i < str.size();i++)
        if( str[i]< '0' || str[i] > '9')
            return(1);
    return(0);
}

static int check_date_string_float(std::string str){
    int flag = 0;
    for(size_t i = 0;i < str.size();i++)
    {
        if(i == 0 && (str[i] == '-' || str[i] == '+'))
            continue;
        if( str[i]< '0' || str[i] > '9')
        {
            if(str[i] == '.' && flag == 0)
                flag++;
            else
                return(1);
        }
    }
    return(0);
}

int     BitcoinExchange::string_to_int(int type, std::string line){
    std::string string_date;

    switch (type)
    {
    case YEAR:
        string_date = line.substr(0,4);
        if(check_date_string(string_date))
            throw WrongDateException();
        return(atoi(string_date.c_str()));
    case MONTH:
        string_date = line.substr(5,2);
        if(check_date_string(string_date))
            throw WrongDateException();
        return(atoi(string_date.c_str()));
    case DAY:
        string_date = line.substr(8,2);
        if(check_date_string(string_date))
            throw WrongDateException();
        return(atoi(string_date.c_str()));
    }
    return(0);
}


float     BitcoinExchange::string_to_float(int type,std::string line){
    std::string string_date;
    if(type == DATA)
        string_date = line.substr(11,line.size() - 11);
    else
        string_date = line.substr(13,line.size() - 13);
    if(check_date_string_float(string_date))
        throw WrongValueException();
    return(atof(string_date.c_str()));
}

void BitcoinExchange::parsing_input(int type,std::string line){
    int         date;
    int         year;
    int         month;
    int         day;
    float         value = 0;
    float output_value;
    //year
    year = string_to_int(YEAR,line);
    month = string_to_int(MONTH,line);
    day = string_to_int(DAY,line);
    value = string_to_float(type, line);
    date = (year * 10000) + (month * 100) + day;
    //date
    if(type == DATA)
    {
        if(date < 20090103)
            throw NotYetCreatedException();
        if(check_date_int(year,month,day))
            throw WrongDateException();
        map_data.insert(std::pair<int,float>(date,value));
    }
    else
    {
        if(date < 20090103)
            throw NotYetCreatedException();
        if(value > 1000)
            throw TooTargeANumberException();
        output_value = map_data.lower_bound(date)->second * value;
        if(output_value < 0)
            throw NotAPositiveNumberException();
        std::cout << line.substr(0,11) << "=> " << value << " = ";
        std::cout << output_value << std::endl;
    }
}

void BitcoinExchange::exceptionchecker(std::string line, int type){
    std::string type_str;
    if(type == DATA)
        type_str = "Data: ";
    else
        type_str = "Input: ";
    try
    {
        if(type == DATA)
        {
            if (line.size() < 12 || line[10] != ','|| line[4] != '-'|| line[7] != '-')
            throw WrongDateException();
            parsing_input(DATA,line);
        }
        if(type == INPUT)
        {
            if (line.size() < 14  || line.compare(10, 3," | ")|| line[4] != '-'|| line[7] != '-')
                throw WrongDateException();
            parsing_input(INPUT,line);
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << type_str << e.what() << line << std::endl;
    }
}

void   BitcoinExchange::init_database(char **av,int type){
    std::ifstream   fd_input_database;
    std::string line;

    if(type == DATA)
        fd_input_database.open("data.csv");
    else if(type == INPUT)
        fd_input_database.open(av[1]);
    if(!fd_input_database)
        throw CannotOpenFdException();
    getline(fd_input_database,line);
    if(line.compare("date | value") && line.compare("date,exchange_rate"))
        throw WrongDateFormatException();
    while(getline(fd_input_database,line))
    {
        if(type == DATA)
            exceptionchecker(line,DATA);
        else
            exceptionchecker(line,INPUT);
    }
}

void    BitcoinExchange::print_database(){

    for (std::map<int,float>::iterator it=map_data.begin(); it!=map_data.end(); ++it)
        std::cout << "map_data : " << it->first << " => " << it->second << std::endl;
}
