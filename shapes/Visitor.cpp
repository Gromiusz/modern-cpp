#include "Visitor.hpp"
#include "Shape.hpp"
#include "Square.hpp"
#include "Circle.hpp"
#include "Rectangle.hpp"

void PrintingVisitor::visit(Circle& circle)
{
    circle.print();
}

void PrintingVisitor::visit(Rectangle& rec)
{
    rec.print();
}

void PrintingVisitor::visit(Square& sq)
{
    sq.print();
}