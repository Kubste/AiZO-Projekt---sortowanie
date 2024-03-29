#ifndef QUICK_SORT_HPP
#define QUICK_SORT_HPP
#include "Array_manager.hpp"
using namespace std;


template<typename T>
class Quick_sort {

    private:
        void swap_elements(T* &sorted_array, int x, int y);

    public:
        void sort(T* &sorted_array, int left_main_index, int right_main_index);

};

#endif