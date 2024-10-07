#include <cassert>
#include <iostream>

struct A {
    explicit A(int _a) : a(_a) {};
    int a;
};

struct B : A {
    using A::A;
    B(int _a, int _b) : A(_a), b(_b) {};
    int b;
};

int main()
{
    B b(2);
    B bb(1, 3);

    
    std::cout << b.a << std::endl;
    assert(b.a == 2);
    assert(bb.a == 1);
    assert(bb.b == 3);
}