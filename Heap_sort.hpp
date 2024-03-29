#ifndef HEAP_SORT_HPP
#define HEAP_SORT_HPP
using namespace std;


template<typename T>
class Heap_sort {

    private:
        void swap_elements(T* &sorted_array, int x, int y);

        void heapify(T* &sorted_array, int array_size, int i);
    
    public:
        void sort(T* &sorted_array, int array_size);

};

#endif