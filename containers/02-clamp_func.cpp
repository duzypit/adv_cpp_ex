#include <iostream>
#include <vector>
#include <algorithm>
/*
http://slides.com/uczelnia_bt_kw/containers#/5/19

excercise
implement a clamp function that:
has two std::vector<>(input, output), hi, lo and enum arguments
checks if elements are less than T and if true inserts them to second container
enum arg is:
Replace // do a in place insertion
Clear // clear before adding
Append // just add

*/
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


std::size_t findIndex(std::vector<int> vec, int val){
	return distance(vec.begin(), std::find(vec.begin(), vec.end(), val));

}

enum class Op{
    Replace, Clear, Append
};

template<typename T>
std::vector<T> clamp(std::vector<T> input, std::vector<T> output, T hi, T lo, Op operation){
    switch(operation){
        case Op::Append :
            for(auto &v : input){
                if (v <= hi && v >= lo){
                    output.push_back(v);
                }
            }
            break;
        case Op::Clear :
            output.clear();
            for(auto &v : input){
                if (v <= hi && v >= lo){
                    output.push_back(v);
                }
            }

            break;

        case Op::Replace :
            for(auto &v : input){
                if (v <= hi && v >= lo){
                    output[findIndex(input, v)] = v;
                }
            }
            break;
    }
    return output;
}


int main(){

    std::vector<int> input = {1,2,3,4,5};
    std::vector<int> output = {6,7,5,9};
    std::cout << "1:" << std::endl;
    std::cout << "Input: " << input << std::endl;
    std::cout << "Output: " << output << std::endl;

    std::vector<int> resultAppend = clamp(input, output, 4,2, Op::Append);
    std::cout << "Append: " << resultAppend << std::endl;
    std::cout << "2:" << std::endl;
    std::cout << "Input: " << input << std::endl;
    std::cout << "Output: " << output << std::endl;
    std::cout << "Clear: " << clamp(input, output, 4,2, Op::Clear) << std::endl;
    std::cout << "3:" << std::endl;
    std::cout << "Input: " << input << std::endl;
    std::cout << "Output: " << output << std::endl;
    std::cout << "Replace: " <<clamp(input, output, 4,3, Op::Replace) << std::endl;

    return 0;


}


