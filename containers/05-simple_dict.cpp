#include <gtest/gtest.h>
#include <string>
#include <algorithm>
//compile with flags -pthread -lgtest

//http://slides.com/uczelnia_bt_kw/containers#/13
/*
excercise

Implement a simple dictionary:

    has a set of predefined words
    case insensitive

struct Dictionary {
  void addWord(string); //noexcept
  void removeWord(string);
  bool check(string) const noexcept;
};
*/

struct Dictionary {
    using word = std::string;
    void addWord(const word& w) {
        _data.insert(toLower(w));
    }
    void removeWord(const word& w) {
        _data.erase(toLower(w));
    }

    bool spell(const word& w) const noexcept {

        if (_data.find(toLower(w)) == _data.end()) {
            return false;
        }
        return true;
    }

private:
    std::string toLower(const word& w) const{
        std::string tmp (w);
        std::transform(tmp.begin(), tmp.end(), tmp.begin(), [](unsigned char c) {return std::tolower(c);});
        return tmp;

    }
    std::set<std::string> _data;
};

TEST(Dictionary, add_word) {
    Dictionary d;
    d.addWord("bartek");
    EXPECT_TRUE(d.spell("Bartek"));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
