#pragma once

#include "Shape.hpp"

class Rectangle : public Shape
{
public:
    using Shape::Shape;
    Rectangle() = delete;
    Rectangle(double x, double y, Color c);
    Rectangle(double x, double y);
    Rectangle(const Rectangle &other) = default;

    double getArea() const noexcept override;
    double getPerimeter() const noexcept override;
    virtual double getX() const final;
    double getY() const;
    void print() const override;
    void accept(ShapeVisitorBase&) override;

private:
    double x_ = 1.0;
    double y_ = 1.0;
};
