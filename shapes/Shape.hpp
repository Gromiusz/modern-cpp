#pragma once
#include <iostream>

enum class Color : unsigned char
{
    RED,
    GREEN,
    BLUE
};

class Shape
{
protected:
    Color color = Color::RED;
    
public:
    virtual ~Shape() {}
    Shape() = default;
    Shape(Color c) {}
    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual void print() const;
    virtual Color getColor() const;
};

std::ostream& operator<<(std::ostream& os, Color c);