#include <iostream>
#include <gtest/gtest.h>
#include <random>

//http://slides.com/uczelnia_bt_kw/ptrs-dynamic-allocation#/8
/*
excercise

implement a program that:

    has a Shape interface with Rect, Circle and triangle implementations
    have a function that accepts Shape pointer
    calculates Shape area
    shape is created based command line input
    shape parameters are random (0, 100)
*/
namespace {
const int min = 0;
const int max = 100;
}  // namespace

int randomValue() {
    std::random_device rd;
    std::default_random_engine engine{rd()};
    std::uniform_int_distribution<int> dist{min, max};

    return dist(engine);
}

class Shape{
public:
    virtual ~Shape() = default;
    virtual double area() const noexcept = 0;
};

class Rect : public Shape{
public:
    Rect(int a, int b) : _a(a), _b(b){}
    double area() const noexcept override{
        return _a * _b;
    }

private:
    double _a;
    double _b;
};

class Triangle : public Shape{
public:
    Triangle(int h, int a) : _h(h), _a(a) {}
    double area() const noexcept override{
        return (_a*_h)/2;
    }
private:
    double _h;
    double _a;
};

class Circle : public Shape{
public:
    Circle(double radius) : _r(radius){}
    double area() const noexcept override{
        return M_PI * _r;
    }

private:
    double _r;
};

Shape* create(std::string id){
    if (id == "rect") return new Rect(randomValue(), randomValue());
    if (id == "circle") return new Circle(randomValue());
    if (id == "triangle") return new Triangle(randomValue(), randomValue());

    return nullptr;
}

double area(Shape *s) {return s->area();}

TEST(Shape, Rect) {
    auto sh = create(std::string("rect"));

    EXPECT_GE(area(sh), min * min);
    EXPECT_LE(area(sh), max * max);

    delete sh;
}
TEST(Shape, Circle) {
    auto sh = create(std::string("circle"));

    EXPECT_GE(area(sh), min * M_PI);
    EXPECT_LE(area(sh), max * M_PI);

    delete sh;
}

TEST(Shape, Triangle){
    auto sh = create(std::string("triangle"));

    EXPECT_GE(area(sh), min*min);
    EXPECT_LE(area(sh),max*max);

    delete sh;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
