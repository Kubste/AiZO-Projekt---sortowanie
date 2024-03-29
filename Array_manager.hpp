#ifndef ARRAY_MANAGER_HPP
#define ARRAY_MANAGER_HPP
#include "Insert_sort.hpp"
#include "Heap_sort.hpp"
#include "Quick_sort.hpp"
#include "Insert_sort.cpp"
#include "Heap_sort.cpp"
#include "Quick_sort.cpp"
#include <chrono>
using namespace std;

template<typename T>
class Array_manager {

    private:
        T *main_array;
        T *sorted_array;
        Insert_sort<T> insert_sort;
        Heap_sort<T> heap_sort;
        Quick_sort<T> quick_sort;
        int array_size;
        bool is_array_created = false;

        chrono::duration<double, milli> measure_time(chrono::high_resolution_clock::time_point t0, 
        chrono::high_resolution_clock::time_point t1);

        void reverse_sort();

    public:
        ~Array_manager();

        void generate_array(int array_size, T range, bool fill);

        void display_array();

        void display_sorted_array();

        void save_from_file(int i, T number);

        bool check_if_array_is_sorted();

        chrono::duration<double, milli> sort_insert_sort();

        chrono::duration<double, milli> sort_insert_sort_binary();

        chrono::duration<double, milli> sort_heap_sort();

        chrono::duration<double, milli> sort_quick_sort();

        void undo_sort();

        void sort_special(int irange);

};

#endif