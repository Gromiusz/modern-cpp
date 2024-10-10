#include "Shape.hpp"
#include <iostream>

std::ostream &operator<<(std::ostream &os, Color c)
{
    switch (c)
    {
    case Color::RED:
        os << "Red" << std::endl;
        break;
    case Color::GREEN:
        os << "Green" << std::endl;
        break;
    case Color::BLUE:
        os << "Blue" << std::endl;
        break;

    default:
        break;
    }

    return os;
}

Shape::Shape(Color c)
{
    color = c;
}

void Shape::print() const
{
    std::cout << "Unknown Shape" << std::endl;
}

Color Shape::getColor() const
{
    return color;
}
