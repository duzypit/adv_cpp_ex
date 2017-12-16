#include <iostream>
#include <array>
#include <vector>
#include <algorithm>

//https://slides.com/uczlenia_bt_kw/advanced-c#/7/2
//excercise
//modify Array:
//add a fucntion template getArray() that can bu used to deduce template parameter
//add default value heap = false and N = 10


template<typename T, std::size_t N = 10, bool use_heap = false>
class Array{
public:
    //default ctor
    Array(){
        this -> _size = N;
        if(use_heap){
            this -> _heap.reserve(N);
            this -> _heap.begin();
            this -> _onHeap = true;
            std::fill(this -> _heap.begin(), this -> _heap.begin() + N, 0);
        } else {
            std::fill(this -> _stack.begin(), this -> _stack.end(), -1);
        }
    }

    Array& container(){
        if(this -> _onHeap){
            std:: cout << "Heap" << std::endl;
        } else {
            std::cout << "Stack" << std::endl;
        }
        return *this;
    }

    Array& size(){
        std::cout << "Size: " << this -> _size << std::endl;
        return *this;
    }
    /*impl ommited */

private:
    bool _onHeap = false;
    std::size_t _size;
    std::array<T, N> _stack;
    std::vector<T> _heap;

};
//-std=c++11
/*template<typename T, std::size_t N = 10, bool use_heap = false>
auto getArr() -> Array<T, N, use_heap> {
    return Array<T, N, use_heap>{};
}
*/
//-std=c++14
//the auto return type 'without trailing return type' is a c++14 feature
template<typename T, std::size_t N, bool use_heap>
auto getArr() {
    return Array<T, N, use_heap>();
}



int main() {
    auto st = getArr<int,5,true>;
    //problem: base of member reference is a function; perhaps you ment to call it with no arguments?
    st.container();


    return 0;
}

