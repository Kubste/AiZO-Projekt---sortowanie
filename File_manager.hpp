#ifndef FILE_MANAGER_HPP
#define FILE_MANAGER_HPP
#include "Array_manager.hpp"
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#include <fstream>
using namespace std;

class File_manager {

    private:
        string file_path;

    public:
        void upload_from_file(Array_manager<int> &int_array_manager, Array_manager<float> &float_array_manager, int &data_type);

};

#endif