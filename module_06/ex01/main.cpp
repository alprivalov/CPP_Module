#include "Serializer.hpp"

int main()
{
    Data Serializer;
    Serializer.input = 9999;
    std::cout << Serializer::deserialize(Serializer::serialize(&Serializer))->input << std::endl;;
}