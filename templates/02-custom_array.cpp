#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <gtest/gtest.h>

//http://slides.com/uczelnia_bt_kw/advanced-c#/4/2
//excercise

//custom Array<10,T, false>

//    uses std::array or std::vector based on 2nd template parameter
//    provides a typical interface (operator[], begin(), end())
//    has a max()/min() method
//    template_array.cpp

//odpowiedź dlaczego tak to zaimplementowałem:
//https://github.com/Super-Teachers/advcpp/blob/master/templates/template_array.cpp

template<std::size_t size, typename T,  bool use_heap>
class Array{
public:
    //default ctor
    Array(){
        if(use_heap){
            this -> _heap.reserve(size);
            this -> _heap.begin();
            this -> _onHeap = true;
            std::fill(this -> _heap.begin(), this -> _heap.begin() + size, 0);
        } else {
            std::fill(this -> _stack.begin(), this -> _stack.end(), -1);
        }
    }

    //jaki typ ma byc zwracany?
    /*
    T* begin() {
        if(this->_onHeap) {
            return this->_heap.begin();
        } else {
            return this->_stack.begin();
        }
    }

    //end() - to samo jak wyżej
    T* end() {
        if(this->_onHeap) {
            return this->_heap.end();
        } else {
            return this->_stack.end();
        }
    }
*/

    T& operator[](std::size_t index){
        if(this -> _onHeap){
            return this -> _heap[index];
        } else {
            return this -> _stack[index];
        }
    }

    T max() const {
        if(this -> _onHeap) {
            return std::max_element(this -> _heap.begin(), this -> _heap.end());
        } else {
            return std::max_element(this -> _stack.begin(), this -> _stack.end());
        }
    }


    T min() const {
        if(this -> _onHeap) {
            return std::min_element(this -> _heap.begin(), this -> _heap.end());
        } else {
            return std::min_element(this -> _stack.begin(), this -> _stack.end());
        }
    }


private:
    bool _onHeap = false;
    std::array<T, size> _stack;
    std::vector<T> _heap;

};

TEST(Array, stack_simple) {
    Array<10, int, false> stack;
    //musiałem dodac fill -1 w konstruktorze, bo kompilator wstawiał mi 0
    // uninitialized
    EXPECT_NE(stack[0], 0);

    stack[5] = 10;
    EXPECT_EQ(stack[5], 10);
}

TEST(Array, heap_simple) {
    Array<10, int, true> heap;

    // uninitialized
    EXPECT_EQ(heap[0], 0);

    heap[5] = 10;
    EXPECT_EQ(heap[5], 10);
}

TEST(Array, heap_begin){
    Array<10, int, true> heap;

    heap[0] = 1;
    EXPECT_EQ(heap.begin(), 5);
}

int main(int argc, char **argv) {

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

}

