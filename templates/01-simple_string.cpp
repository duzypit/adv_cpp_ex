#include <iostream>
#include <vector>
#include <algorithm>
#include <gtest/gtest.h>
#include <functional>
//http://slides.com/uczelnia_bt_kw/advanced-c#/2/6
//excercise

//Simple String template:

//    works! // can store values - letters
//    has operator+=
//    has operator==
//    can be constructed from const char* and std::string
//    has copy ctor
//template <typename T>
//String<T>& operator+(const String<T> lhs, const String<T>& rhs);

template<typename T>
class String{
public:
    //ctor
    String(){}

    //can be construced from const char*
    String(const char* str) {
        this -> size = 0;
        while (str[this->size] != '\0') this->size++;
        std::copy(str, str+this->size, std::back_inserter(this->_data));
        //std::copy(_data.begin(), str, str + this -> size);
    }

    //can be constructed from std::string
    String(std::string str){
        this -> size = str.size();
        std::copy(str.begin(), str.end(),std::back_inserter(this ->_data));
    }

    //has copy ctor
    String(const String& obj){
        this->size = obj.size;
        this->_data = obj._data;
    }

    //index operator
    T& operator[](int n) {
        return this -> _data[n];
    }
    //addition assignment op
    String& operator += (const T& c){
        this -> _data.push_back(c);
        this -> size++;
        return *this;
    }

    String& operator +=(const std::string& s){
        //for (T c : s){
        std::copy(s.begin(), s.end(), std::back_inserter(this ->_data));

        //}
        this -> size += s.size();
        return *this;
    }

    const char* c_str() const{
        return std::string(this->_data.begin(), this->_data.end()).c_str();
    }

    std::size_t dataHash() const{
        return std::hash<std::string>{} (std::string(this->_data.begin(), this->_data.end()));
    }

    friend String<T>& operator+(const String<T> lhs, const String<T>& rhs){
        String temp = lhs;
        //std::cout << "lhs cstr: " << lhs.c_str() << std::endl;
        temp += std::string(rhs.c_str());
        //std::cout << "tmp after += " << temp.c_str() << std::endl;
        return temp;
    }


private:
    size_t size;
    std::vector<T> _data;
};


template <typename T>
bool operator== (const String<T>& lhs, const String<T>& rhs){
    //std::cout << "test: "<< lhs.c_str() << " " << rhs.c_str() << std::endl;
    return (lhs.dataHash() == rhs.dataHash());
}

TEST (String, constructFromCString){
    const char* test = "test";
    String<char> t(test);
    EXPECT_STREQ("test", t.c_str()) << "Construct from cstr failed";
}

TEST(String, constructFromStdString){
    std::string test("test");
    String<char> t(test);
    EXPECT_STREQ("test", t.c_str()) << "Construct from std::string failed";
}

TEST(String, copyCtor){
    String<char> a(std::string("test"));
    String<char> b(a);
    EXPECT_STREQ(a.c_str(), b.c_str()) << "Copy ctor failed";
}

TEST(String, indexOp){
    String<char> a(std::string("test"));
    EXPECT_EQ('t', a[0]) << "Index operator failed";
}

TEST(String, additionAssignmentOp){
    char a = 'a';
    String<char> b;
    b += a;
    EXPECT_EQ('a', b[0]) << "Addition assignment operator failed";
}

TEST(String, eqOperator){
    String<char> a("test");
    String<char> b("test");
    EXPECT_EQ(true, a == b) << "Eq operator failed";
}

TEST(String, addOperator){
    String<char> a("te");
    String<char> b("st");
    String<char> c = a+b;
    EXPECT_EQ("test", c.c_str()) << "Add operator failed";
}

int main(int argc, char **argv) {

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

}

