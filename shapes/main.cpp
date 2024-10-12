#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <memory>
#include <map>
#include <tuple>
#include <functional>

#include "Shape.hpp"
#include "Rectangle.hpp"
#include "Square.hpp"
#include "Circle.hpp"
#include "Visitor.hpp"

using namespace std;

using Collection = vector<shared_ptr<Shape>>;

auto sortByArea = [](shared_ptr<Shape> first, shared_ptr<Shape> second)
{
    if (first == nullptr || second == nullptr)
        return false;
    return (first->getArea() < second->getArea());
};

auto perimeterBiggerThan20 = [](shared_ptr<Shape> s)
{
    if (s)
        return (s->getPerimeter() > 20);
    return false;
};

auto areaLessThan10 = [](shared_ptr<Shape> s)
{
    if (s)
        return (s->getArea() < 10);
    return false;
};

auto areaLessThanX = [x = 10](shared_ptr<Shape> s)
{
    if (s)
        return (s->getArea() < x);
    return false;
};

void printCollectionElements(const Collection &collection)
{
    for (const auto &el : collection)
        if (el)
            el->print();
}

void printAreas(const Collection &collection)
{
    for (const auto &el : collection)
        if (el)
            el->getArea();
}

void findFirstShapeMatchingPredicate(const Collection &collection,
                                     std::function<bool(shared_ptr<Shape> s)> predicate,
                                     std::string info)
{
    auto iter = std::find_if(collection.begin(), collection.end(), predicate);
    if (*iter != nullptr)
    {
        cout << "First shape matching predicate: " << info << endl;
        (*iter)->print();
    }
    else
    {
        cout << "There is no shape matching predicate " << info << endl;
    }
}

template <class DerivedType, class... Arguments>
std::shared_ptr<Shape> make_shape(Arguments &&...args)
{
    return std::make_shared<DerivedType>(std::forward<Arguments>(args)...);
}

void visitAll(Collection &collection, ShapeVisitorBase &visitor)
{
    for (const auto &el : collection)
    {
        if(el)
            el->accept(visitor);
    }
}

int main()
{
    Collection shapes = {make_shared<Circle>(2.0),
                         make_shared<Circle>(3.0),
                         nullptr,
                         make_shared<Circle>(4.0),
                         make_shared<Rectangle>(10.0, 5.0),
                         make_shared<Square>(3.0),
                         make_shared<Circle>(4.0)};

    printCollectionElements(shapes);

    cout << "Areas before sort: " << std::endl;
    printAreas(shapes);

    std::sort(shapes.begin(), shapes.end(), sortByArea);

    cout << "Areas after sort: " << std::endl;
    printAreas(shapes);

    auto square = make_shared<Square>(4.0);
    shapes.push_back(square);

    findFirstShapeMatchingPredicate(shapes, perimeterBiggerThan20, "perimeter bigger than 20");
    findFirstShapeMatchingPredicate(shapes, areaLessThanX, "area less than 10");

    Collection collectionWithColors = {make_shared<Circle>(Color::GREEN), make_shared<Circle>(Color::BLUE), make_shared<Circle>(Color::RED), make_shared<Circle>(Color::GREEN)};
    printCollectionElements(collectionWithColors);

    std::cout << alignof(Circle) << std::endl;

    std::map<std::shared_ptr<Shape>, double> perimeters;
    constexpr uint8_t the_way_to_do_that = 2;
    switch (the_way_to_do_that)
    {
    case 1:
        for (const auto &shape : shapes)
        {
            if (shape)
            {
                perimeters.emplace(shape, shape->getPerimeter());
            }
        }
        break;

    case 2:
        std::transform(shapes.begin(), shapes.end(), inserter(perimeters, perimeters.begin()), [](auto &shape)
                       {
                                                                                                auto perimeter = 0.;
                                                                                                    if(shape) 
                                                                                                        perimeter = shape->getPerimeter();
                                                                                                    return std::make_pair(shape, perimeter); });
        break;

    default:
        break;
    }

    for (const auto &[shape, perimeter] : perimeters)
    {
        if (shape)
        {
            shape->print();
            std::cout << "\nPerimeter: " << perimeter << "\n\n";
        }
    }

    auto circle = make_shape<Circle>(4);
    auto rectangle = make_shape<Rectangle>(2, 1);
    auto square2 = make_shape<Square>(8);

    PrintingVisitor printigVisitor;
    visitAll(shapes, printigVisitor);

    return 0;
}
