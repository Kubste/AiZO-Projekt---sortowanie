#ifndef MAIN_HPP
#define MAIN_HPP
#include "Array_manager.hpp"
#include "File_manager.hpp"
#include "Array_manager.cpp"
#include "File_manager.cpp"
using namespace std;


class Main {

    private:
        Array_manager<int> int_array_manager;
        Array_manager<float> float_array_manager;
        File_manager file_manager;
        int array_size;
        float range;

        void generate_array_option(int &data_type);

        void display_array_option(int data_type);

        void sort_option(int data_type);

        void display_sorted_array_option(int data_type);

        void check_if_array_is_sorted_option(int data_type);

        void undo_sort_option(int data_type);

        void special_cases_option(int data_type);

        void special_cases_switch(int user_choice, int data_type);

        void generate_results(int &data_type);

    public:
        void run();

};

#endif