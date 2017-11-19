#include <iostream>
#include <vector>
#include <array>
//http://slides.com/uczelnia_bt_kw/advanced-c#/5/17
//Excercise

//Provide a operator<< that can work on any container
//alomst solution:
//https://stackoverflow.com/questions/1154212/how-could-i-print-the-contents-of-any-container-in-a-generic-way

template<typename T, template<typename ELEM, typename ALLOC=std::allocator<ELEM>> class Container>
std::ostream& operator<< (
        std::ostream& os,
        const Container<T>& container) {

    typename Container<T>::const_iterator beg = container.begin();

    os << "[ ";
    while(beg != container.end()) {
        os << " " << *beg++;
    }
    os << " ]";

    return os;
}


int main(){
    std::vector<char> charz {'a','b','c'};
    std::vector<int> intz {1,2,3};
    std::cout << charz << std::endl;
    std::cout << intz << std::endl;
    std::array<int, 10> aintz;
    std::fill(aintz.begin(), aintz.end(), 11);

    //problem
    std::cout << aintz << std::endl;
    return 0;
}
