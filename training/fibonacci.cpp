#include <iostream>

constexpr unsigned Fibonnacci(unsigned n)
{
    if(n > 1)
    {
        return Fibonnacci(n-1) + Fibonnacci(n-2);
    }
    else if(n == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    constexpr unsigned w = Fibonnacci(45);
    std::cout << w << std::endl;

    return 0;
}