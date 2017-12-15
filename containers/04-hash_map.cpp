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
template <typename HashType, typename V>
struct Hash {
   // using Int = HashType;

    Hash(V&& v){
        _value = std::hash<V>{}(v);
    };

   private:
    HashType _value;
};

template <typename Data>
using MyMap = std::map<Hash<std::int64_t, Data>, Data>;

template <typename Data>
struct HashMap {

    Data& at(const MyMap<Data> h){
        return _map.at(h);
    }

    //void put(Data&&);
    bool insert (Data&& d){
        Hash<std::int64_t, Data> h(d);
        auto p = std::pair<Hash<std::int64_t,Data>, Data>(h, d);
        auto r _map.insert(p);
        return r.second;
    }

    bool empty() { return _map.empty(); }

    MyMap<Data> _map;
};

TEST(MyMap, simple) {
    MyMap<int> asd;
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
