#ifndef INSERT_SORT_HPP
#define INSERT_SORT_HPP
using namespace std;


template<typename T>
class Insert_sort {

    public:
        void sort_normal(T* &sorted_array, int array_size);

        void sort_binary(T* &sorted_array, int array_size);

};

#endif