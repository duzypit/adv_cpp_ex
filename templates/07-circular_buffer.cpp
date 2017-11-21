#include <iostream>
#include <gtest/gtest.h>
#include <initializer_list>
#include <algorithm>
#include <string>
//http://slides.com/uczelnia_bt_kw/advanced-c#/9
//excercise
//Implement a circular buffer:
//Can store only up to N-elements
//has template<U> push() method (back)
//remove oldest element on insertion
//has a size() method
//is random readable but not writable
//has operator<<()

template<typename T, std::size_t N>
class CircularBuffer{
public:
    CircularBuffer(){
        this->_currentIndex = 0;
        this->_fill = 0;
    }

    CircularBuffer(const std::initializer_list<T>& list) {
        if(N < list.size()) throw std::out_of_range("To many args!");

        std::copy(list.begin(), list.end(), this->_data.begin());
        this->_currentIndex = list.size() -1;
        this->_fill = list.size();
    }

    const T& operator[](std::size_t index) const {
        return this -> _data[index];
    }

    void push(const T& t) {
        if (this->_currentIndex == this->_data.size()){
            this->_currentIndex = 0;
        }
        this->_data[_currentIndex] = t;
        this->_currentIndex++;
        this->updateFill();
    }

    std::size_t size(){
        return this->_fill;
    }
friend std::ostream& operator<<(std::ostream& os, const CircularBuffer<T, N>& buffer) {
    for(const auto& v : buffer._data) {
        os << v;
   }
   return os;
}

private:
    void updateFill(){
        if(this->_fill < this->_data.size()){
            this->_fill++;
        }
    }

    std::size_t _fill;
    std::array<T, N> _data;
    std::size_t _currentIndex;
};

/*
template <typename T, std::size_t N>
friend std::ostream& operator<<(std::ostream& os, const CircularBuffer<T, N>& buffer) {
   return os;
}
*/
TEST(CircularBuffer, empty_buffer_is_zerod) {
    CircularBuffer<std::string, 10> buffer;
    EXPECT_EQ(buffer[0].size(), 0);
}


TEST(CircularBuffer, initialized_by_list) {
    CircularBuffer<std::string, 10> buffer{{"one", "two", "three"}};
    EXPECT_EQ(buffer[0], "one");
}


TEST(CircularBuffer, stream_operator) {
    //using namespace std::string_literals;
    CircularBuffer<std::string, 2> buffer{{std::string{"one"}}};
    std::stringstream ss;
    ss << buffer;
    EXPECT_EQ(ss.str(), "one");
}

TEST(CircularBuffer, initialized_too_big) {
    auto fn = []() {
        CircularBuffer<std::string, 2> buffer{{"one", "two", "three"}};
    };
    EXPECT_ANY_THROW(fn());
}

TEST(CircularBuffer, small_buffer) {
    CircularBuffer<std::string, 2> buffer;
    buffer.push("asd");
    buffer.push("asd");
    buffer.push("dd");
    buffer.push("bb");
    EXPECT_EQ(buffer[0], "dd");
    EXPECT_EQ(buffer[1], "bb");
}

TEST(CircularBuffer, size_after_double_push){
    CircularBuffer<std::string,3> buffer;
    buffer.push("aa");
    buffer.push("bb");
    EXPECT_EQ(buffer.size(),2);
    buffer.push("cc");
    buffer.push("dd");
    EXPECT_EQ(buffer[0],"dd");
    EXPECT_EQ(buffer.size(), 3);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
