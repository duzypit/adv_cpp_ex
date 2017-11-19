#include <iostream>
#include <vector>

//http://slides.com/uczelnia_bt_kw/advanced-c#/5/16
//Excercise

//Provide a operator<< that can work on any std::vector


template<typename T>
std::ostream& operator<< (
        std::ostream& os,
        const std::vector<T>& str) {
    os << "[ ";
    for(const auto& v : str){
        os << v << " ";
    }
    os << "]";
    return os;
}


int main(){
    std::vector<char> charz {'a','b','c'};
    std::cout << charz << std::endl;
}
