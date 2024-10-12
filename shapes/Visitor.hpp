#pragma once

class Circle;
class Rectangle;
class Square;

class ShapeVisitorBase
{
public:
    virtual ~ShapeVisitorBase() = default;
    virtual void visit(Circle&) = 0;
    virtual void visit(Rectangle&) = 0;
    virtual void visit(Square&) = 0;
};

class PrintingVisitor : public ShapeVisitorBase
{
public:
    void visit(Circle&);
    void visit(Rectangle&);
    void visit(Square&);
};