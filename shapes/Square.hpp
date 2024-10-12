#pragma once

#include "Rectangle.hpp"

class Square : public Rectangle
{
public:
    using Rectangle::Rectangle;
    Square() = delete;
    Square(double x, Color c);
    Square(double x);
    Square(const Square & other) = default;

    double getArea() const noexcept override;
    double getY() = delete;
    double getPerimeter() const noexcept override;
    void print() const override;
};
