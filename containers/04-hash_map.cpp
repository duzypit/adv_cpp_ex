#include <iostream>
#include <map>
#include <functional>
#include <gtest/gtest.h>

//http://slides.com/uczelnia_bt_kw/containers#/9/11

/*
excercise

implement hash_map/dictonary based on std::map:

uses std::map<> as a container
Key is a custom Hash  {} type;
Key is calculated from key
*/
template <typename HashType>
struct Hash {
    using Int = HashType;
    template <typename V>
    Hash(V&& v);

   private:
    Int _value;
};

template <typename Data>
using MyMap = std::map<Hash<std::int64_t>, Data>;

template <typename Data>
struct HashMap {
    Data& at();
    void put(Data&&);

    bool empty() { return true; }

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

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
