#include <iostream>

//http://slides.com/uczelnia_bt_kw/pointerz#/3/3
//excercise

//implement a find min function that:

//    is a template function ! :)
//    accepts arguments as an array (pointer, array)
//    returns smallest element

template <typename T>
T findMini(T _arr[], int size){
    T min = _arr[0];
    for(int i = 0; i < size; i++){
        if (_arr[i] < min) {
            min = _arr[i];
        }
    }

    return min;

}

int main(){
    int arr[5]= {3,6,8,2,3};
    int *aptr = arr;

    std::cout << " min in array: " << findMini(arr,5) << std::endl;
    std::cout << " min in ptr: " << findMini(aptr, 5) << std::endl;


}
