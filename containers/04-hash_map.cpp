#include <iostream>
#include <map>
#include <functional>
#include <utility>
#include <gtest/gtest.h>

//http://slides.com/uczelnia_bt_kw/containers#/9/11

/*
excercise

implement hash_map/dictonary based on std::map:

uses std::map<> as a container
Key is a custom Hash  {} type;
Key is calculated from key
*/
template <typename V>
struct Hash {
   // using Int = HashType;

    Hash(V& v){
        _value = std::hash<V>{}(v);
    };

  // private:
    std::int64_t _value;
};

template <typename T>
struct cmp{
    bool operator() (const Hash<T> lhs, const Hash<T> rhs) const {
        return lhs._value < rhs._value;
    }
};

template <typename Data>
struct HashMap {

    Data& at(const std::map<Hash<Data>, Data> h){
        return _map.at(h);
    }

    //void put(Data&&);
    bool insert (Data d){
        Hash<Data> h(d);
        auto result =  _map.insert(std::pair<Hash<Data>, Data>(h, d));
        //_map.insert(p);
        return result.second;

    }

    bool empty() { return _map.empty(); }


    std::map<Hash<Data>, Data, cmp<Data>> _map;

};

TEST(MyMap, simple) {
    HashMap<int> asd;
    EXPECT_TRUE(asd.empty());
}
TEST(HashMap, simple) {
    HashMap<std::string> hm;
    EXPECT_TRUE(hm.empty());
}

TEST(HashMap, insert){

    HashMap<std::string> hm;
    hm.insert("Test");
    EXPECT_FALSE(hm.empty());


}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
