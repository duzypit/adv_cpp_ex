#include <iostream>
#include <vector>
#include <cmath>

//http://slides.com/uczelnia_bt_kw/containers#/5/18
/*
excercise
implement a template function that:
accepts a vector of T1's
accept a number T2
returns a vector of elements that are std::pow'ed()
*/
template<typename T1, typename T2>
class Powed{
    //smtn
};

template<typename T1, typename T2>
class Powed<std::vector<T1>,T2> {
    public:
        Powed(std::vector<T1> d, T2 p) : _oldData(d), _data(d)  {
            this->vPow(p);
        }

        std::vector<T1> originalVec() {
            return this->_oldData;
        }
        std::vector<T1> powedVec(){
            return this->_data;
        }
    private:
    void vPow(T2 p){
        for(auto& v : this -> _data){
            v = std::pow(v, p);
        }
    }

    std::vector<T1> _oldData;
    std::vector<T1> _data;

};

template<typename T1>
std::ostream& operator<<(std::ostream& os, const std::vector<T1>& data){
    os << "[ ";
    for(auto& v : data){
        os << v << " ";
    }
    os << "]";
    return os;
}

int main(){
    std::vector<int> data {1,2,3,4,5};
    Powed<std::vector<int>, int> p(data, 2);
    std::cout << "Original: " << p.originalVec() << std::endl;
    std::cout << "Powed: " << p.powedVec() << std::endl;
}
