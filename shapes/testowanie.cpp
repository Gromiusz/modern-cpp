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

class C {
    int a;
public:
    C(int _a) : a{_a} {}
    virtual ~C() = default;
};

class D : public C {
    int b;
    int* ptr;
public:
    D(int _a, int _b) : C(_a), b(_b) 
    {
        ptr = new int{80};
    }
    D(int _a, int _b, int& _c) : C(_a), b(_b) 
    {
        ptr = &_c;
    }
    ~D()
    {
        delete ptr;
    }
};

int main()
{
    B b(2);
    B bb(1, 3);

    
    std::cout << b.a << std::endl;
    assert(b.a == 2);
    assert(bb.a == 1);
    assert(bb.b == 3);

    C c{2};
    D d{3, 4};

    int aaa{5};

    C* cc = new C{2};
    C* dd = new D{2,1};

    delete cc;
    delete dd;
}