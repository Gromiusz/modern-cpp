#include <iostream>
#include <vector>
#include <algorithm>

std::vector numbers = {18, 21, 36, 90 ,27, 14, 103};

auto moduloLambda = [](int el){ return el % 3 == 0; };

class ModuloFunctor
{
public:
    bool operator()(const int & el) {
        return el % 3 == 0;
    }
};

bool moduloFunction(const int& el)
{
    return el % 3 == 0;
}

std::ostream& operator<<(std::ostream& os, const std::vector<int>& vec)
{
    std::cout << std::endl;
    for(const int& el : vec)
    {
        std::cout << el << " ";
    }
    return os;
}

int main()
{
    bool numbersLambda = std::all_of(numbers.begin(), numbers.end(), moduloLambda);
    bool numbersFunctor = std::all_of(numbers.begin(), numbers.end(), ModuloFunctor{});
    bool numbersFunction = std::all_of(numbers.begin(), numbers.end(), moduloFunction);

    std::cout << numbers << std::endl;
    std::cout << numbersLambda << std::endl;
    std::cout << numbersFunctor << std::endl;
    std::cout << numbersFunction << std::endl;
}