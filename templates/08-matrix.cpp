#include <iostream>
<<<<<<< HEAD
#include <type_traits>
=======
#include <array>
>>>>>>> d86ec1d5606ee1b7d0ddef2de76e4f4e50073eef
#include <vector>
/*
Excercise
implement Matrix<N, M, T> (order is random here!)
N - number of rows
M - number of columns
has templated copy ctor ( const Matrix<N1, M1, T1>& )
 - N1 < N
 - M1 < M
 - T1 convertible to T
has operators:
 - operator<<
 - operator[]
 - template operator+ (const Matrix<N1, M1, T1>)
is specialized for N = 0 && M = 0 (cannot be created)
is specialized for bools!! (std::vector<bool> is pure evil!)
*/

template<std::size_t N, std::size_t M, typename T>
class Matrix{
public:
	//default ctor
	Matrix() : _data(N*M) {
        std::cout << "base class w/o spec" << std::endl;
    }

	//copy ctor
/*  template<int N1, int M1, typename T1>
	Matrix(const Matrix<N1,M1,T1>&) {}b
*/


    T operator[](int index) const{
        return this->_data[index];
    }

	T& operator[](int index){
        return this->_data[index];
    }

    T operator() (std::size_t row, std::size_t col) const{
        if(row <= this->_rows && col <= this->_cols){
            return this->_data[this->_cols *row + col];
        } else {
            throw std::runtime_error("wrong boundariew");
        }
    }

    T& operator() (const std::size_t row, const std::size_t col){
       if(row <= this->_rows && col <= this->_cols){
            return this->_data[this->_cols *row + col];
        } else {
            throw std::runtime_error("wrong boundaries");
        }
    }

	friend std::ostream& operator<<(std::ostream& os, const Matrix<N,M,T>& mat){
            std::size_t currentCol = 0;
            //tutaj wyłącznie for(;;) nie range loop
            for(auto v : mat._data){
                currentCol++;
                if(currentCol > mat._cols){
                    currentCol = 0;
                    os << std::endl;
                }
                os << "  " << v <<  "  ";
            }

        return os;
	}

/*
    Matrix& operator=(const Matrix& m);
*/
/*
	Matrix& operator+(const Matrix<N,M,T>& rhs){

	}
*/

    //for testing only
    void fill(T val){
        std::fill(this->_data.begin(), this->_data.begin()+(N*M), val);
    }

    //for testing only
    void printData(){
        for(auto v : this->_data){
            std::cout << v << " ";
        }
        std::cout << std::endl;
    }
private:
    std::size_t _rows = N;
    std::size_t _cols = M;
<<<<<<< HEAD
    std::vector<T> _data;
=======
    std::array<T, (N*M)> _data;
    //std::vector<T> _data;
>>>>>>> d86ec1d5606ee1b7d0ddef2de76e4f4e50073eef
};

template<std::size_t N, std:: size_t M>
class Matrix<N, M, bool>{
public:
	Matrix() {
		static_assert(true, "Bool type is not supported!");
        std::cout << "Bool type is not supported!" << std::endl;

	}
};

template<typename T>
class Matrix<0,0, T>{
public:
	Matrix(){
		static_assert(true, "Matrix for N = 0 && M = 0 cannot be created!");
        std::cout << "Matrix for N = 0 && M =0 cannot be created!" << std::endl;
	}
};

int main(){
    //spec for 0,0
    Matrix <0,0,int> intz;
<<<<<<< HEAD
    //spec for bool - error, spec don't work
    Matrix<1, 1, bool> boolz;

    Matrix<2,2, int> proper;
    //indirect use of operator[]
    proper(0,0) = 0;
    proper(0,1) = 1;
    proper(1,0) = 2;
    proper(1,1) = 3;

    //operator<<
    std::cout << proper << std::endl;





=======
    Matrix<2,2, int> proper;
    //proper.fill(10);
    //
    proper[0] = 0;
    std::cout << " Elem 0 proper: " << proper[0] << std::endl;
    //proper(0,0) = 0;
    //proper(0,1) = 1;
    //proper(1,0) = 2;
    //proper(1,1) = 3;
    //std::cout << proper << std::endl;
    //proper.printData();
/*
    std::vector<int> test;
    test.reserve(2);
    test[1] = 5;
    test[0] = 0;
    //std::fill(test.begin(), test.end(), 2);
    //std::cout << test[1] << std::endl;
    for(auto &v : test){
        std::cout << v << " " << std::endl;
    }
    std::cout << "test" << std::endl;
*/
>>>>>>> d86ec1d5606ee1b7d0ddef2de76e4f4e50073eef
    return 0;
}
