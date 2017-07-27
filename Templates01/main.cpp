// Example program
#include <iostream>
#include <string>

template<typename T>
T Min(T valueA, T valueB)
{
    return valueA < valueB ? valueA : valueB;
}

template<typename T>
T Max(T valueA, T valueB)
{
    return valueA > valueB ? valueA : valueB;
}

int main()
{
    std::cout << "Min(8, 10): " << Min(10, 8) << std::endl;
    std::cout << "Min(8.0, 10.0): " << Min(10.0, 8.0) << std::endl;
    std::cout << "Min(8.0f, 10.0f): " << Min(10.0f, 8.0f) << std::endl;
    std::cout << "Min('A', 'a'): " << Min('A', 'a') << std::endl;
}