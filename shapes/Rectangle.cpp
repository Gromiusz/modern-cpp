#include "Rectangle.hpp"
#include <iostream>

Rectangle::Rectangle(double x, double y, Color c)
    : Shape(c),
      x_(x),
      y_(y)

{
}

Rectangle::Rectangle(double x, double y)
    : Rectangle(x, y, Color::Default)
{
}

double Rectangle::getArea() const noexcept
{
    return x_ * y_;
}

double Rectangle::getPerimeter() const noexcept
{
    return 2 * (x_ + y_);
}

double Rectangle::getX() const
{
    return x_;
}

double Rectangle::getY() const
{
    return y_;
}

void Rectangle::print() const
{
    std::cout << "Rectangle:   x: " << getX() << std::endl
              << "             y: " << getY() << std::endl
              << "          area: " << getArea() << std::endl
              << "     perimeter: " << getPerimeter() << std::endl
              << "         color: " << getColor() << std::endl;
}

void Rectangle::accept(ShapeVisitorBase& visitor)
{
    visitor.visit(*this);
}
