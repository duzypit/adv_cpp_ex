#include <array>
#include <vector>
#include <algorithm>

//https://slides.com/uczlenia_bt_kw/advanced-c#/5/15
//excercise
//For Array<N, T, bool> implement a template getArray() function that can deduce T


template<std::size_t N, typename T,  bool use_heap>
class Array{
public:
    //default ctor
    Array(){
        if(use_heap){
            this -> _heap.reserve(N);
            this -> _heap.begin();
            this -> _onHeap = true;
            std::fill(this -> _heap.begin(), this -> _heap.begin() + N, 0);
        } else {
            std::fill(this -> _stack.begin(), this -> _stack.end(), -1);
        }
    }

    /*impl ommited */

private:
    bool _onHeap = false;
    std::array<T, N> _stack;
    std::vector<T> _heap;

};
//-std=c++11
template<std::size_t N, typename T, bool use_heap>
auto getArr() -> Array<N, T, use_heap> {
    return Array<N, T, use_heap>();
}

//-std=c++14
//the auto return type 'without trailing return type' is a c++14 feature
//template<std::size_t N, typename T, bool use_heap>
//auto getArr() {
//    return Array<N, T, use_heap>();
//}



int main() {
    auto stack = getArr<10, int, false>;
    return 0;
}

