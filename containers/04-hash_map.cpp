#include <iostream>
#include <map>
#include <type_traits>

//http://slides.com/uczelnia_bt_kw/containers#/9/11

/*
excercise

implement hash_map/dictonary based on std::map:

uses std::map<> as a container
Key is a custom Hash  {} type;
Key is calculated from key
*/
struct Hash {
  template<typename V>
  Hash(V&& v) {
      auto h = std::hash<typename std::decay<V>::type>{};
      _value = h(std::forward<V>(v));

    }
  std::int64_t _value;
};

auto cmp = [](Hash,Hash) {};

template<typename Data>
using MyMap = std::map<Hash, Data, decltype(cmp)>;

template<typename Data>
struct HashMap {
  Data& at(std::string key);
  void put(std::string key, Data);
  bool check(Data) const noexcept;
private:
  MyMap<Data> _map;
};


