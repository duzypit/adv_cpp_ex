
//http://slides.com/uczelnia_bt_kw/containers#/7/5
/*
excercise

compare std::list and std::vector performance:

    test1: add 1 000 000 elements via push_back (ints, float and some big structure)
    test2: find specified value
    test3: insert at random position
    use std::chrono's time capturing mechanisms
*/

#include <iostream>
#include <chrono>

int main(){
    auto start = std::chrono::system_clock::now();

/* do some work */

    auto end = std::chrono::system_clock::now();
    auto elapsed = end - start;
    std::cout << elapsed.count() << '\n';

    return 0;
}
