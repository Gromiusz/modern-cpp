#pragma once
#include <iostream>
#include <memory>
#include "Visitor.hpp"

enum class Color : unsigned char
{
    RED,
    GREEN,
    BLUE,
    Default = RED
};

class Shape
{
protected:
    Color color = Color::Default;
    
public:
    virtual ~Shape() {}
    Shape() = default;
    Shape(Color c);
    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual void print() const;
    virtual Color getColor() const;
    virtual void accept(ShapeVisitorBase&) = 0;
};

std::ostream& operator<<(std::ostream& os, Color c);

