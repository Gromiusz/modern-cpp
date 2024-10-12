#include "Circle.hpp"
#include <math.h>
#include <iostream>
#include <numbers>

namespace num = std::numbers;

static_assert(M_PI != 3.14, "M_PI is not precise");

double getPi()
{
    return M_PI;
}

Circle::Circle(double r, Color c)
    : Shape(c), r_(r)
{
}

Circle::Circle(double r)
    : Circle(r, Color::Default)
{
}

double Circle::getArea() const
{
    return num::pi * r_ * r_;
}

double Circle::getPerimeter() const
{
    return 2 * num::pi * r_;
}

double Circle::getRadius() const
{
    return r_;
}

void Circle::print() const
{
    std::cout << "Circle: radius: " << getRadius() << std::endl
              << "          area: " << getArea() << std::endl
              << "     perimeter: " << getPerimeter() << std::endl
              << "         color: " << getColor() << std::endl;
}
