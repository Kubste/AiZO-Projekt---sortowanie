#include "Array_manager.hpp"
#include <iostream>
#include <time.h>
#include <chrono>
#include <cstdlib>
using namespace std;


template<typename T>
    chrono::duration<double, milli> Array_manager<T>::measure_time(chrono::high_resolution_clock::time_point t0, 
    chrono::high_resolution_clock::time_point t1) {
        chrono::duration<double, milli> time = t1 - t0;
        return time;
    }

template<typename T>
void Array_manager<T>::reverse_sort() {
        quick_sort.sort(sorted_array, 0, array_size - 1);

        for(int i = 0; i < array_size; i++) {
            main_array[i] = sorted_array[array_size - i - 1];
        }
    }

template<typename T>
Array_manager<T>::~Array_manager() {
        free(main_array);
        free(sorted_array);
    }

template<typename T>
void Array_manager<T>::generate_array(int array_size, T range, bool fill) {

        T number;
        this-> array_size = array_size;

        if(!is_array_created) {
            main_array = (T*)malloc(array_size * sizeof(T));
            sorted_array = (T*)malloc(array_size * sizeof(T));
            is_array_created = true;
        } else {
            main_array = (T*)realloc(main_array, array_size * sizeof(T));
            sorted_array = (T*)realloc(sorted_array, array_size * sizeof(T));
        }

        if(fill == true) {
            for(int i = 0; i < array_size; i++) {
                number = (T)((rand() / static_cast<float>(RAND_MAX)) * range);
                main_array[i] = number;
                sorted_array[i] = number;
            }
        }
        cout << "Tablica zostala wygenerowana" << endl;
    }

template<typename T>
void Array_manager<T>::display_array() {
        cout << "Zawartosc tablicy: " << endl;
        for(int i = 0; i < array_size; i++) {
            cout << main_array[i] << endl;
        }
    }

template<typename T>
void Array_manager<T>::display_sorted_array() {
        cout << "Zawartosc tablicy: " << endl;
        for(int i = 0; i < array_size; i++) {
            cout << sorted_array[i] << endl;
        }
    }

template<typename T>
void Array_manager<T>::save_from_file(int i, T number) {
        main_array[i] = number;
        sorted_array[i] = number;
    }

template<typename T>
bool Array_manager<T>::check_if_array_is_sorted() {
        T number;
        for(int i = 0; i < array_size - 1; i++) {
            if(sorted_array[i] > sorted_array[i + 1]) return false;
        } 
        return true;
    }

template<typename T>
    chrono::duration<double, milli> Array_manager<T>::sort_insert_sort() {            // funkcja wywolujaca funkcje sortujaca, oraz obliczajaca
        auto t0 = chrono::high_resolution_clock::now();             // czas jaki zajelo sortowanie
        insert_sort.sort_normal(sorted_array, array_size);
        auto t1 = chrono::high_resolution_clock::now();
        chrono::duration<double, milli> time = measure_time(t0, t1);
        cout << "Sortowanie zakonczone" << endl;
        cout << "Sortowanie zajelo: " << time.count() << " milisekund" << endl;
        return time;
    }

template<typename T>
    chrono::duration<double, milli> Array_manager<T>::sort_insert_sort_binary() {
        auto t0 = chrono::high_resolution_clock::now();
        insert_sort.sort_binary(sorted_array, array_size);
        auto t1 = chrono::high_resolution_clock::now();
        chrono::duration<double, milli> time = measure_time(t0, t1);
        cout << "Sortowanie zakonczone" << endl;
        cout << "Sortowanie zajelo: " << time.count() << " milisekund" << endl;
        return time;
    }

template<typename T>
    chrono::duration<double, milli> Array_manager<T>::sort_heap_sort() {
        auto t0 = chrono::high_resolution_clock::now();
        heap_sort.sort(sorted_array, array_size);
        auto t1 = chrono::high_resolution_clock::now();
        chrono::duration<double, milli> time = measure_time(t0, t1);
        cout << "Sortowanie zakonczone" << endl;
        cout << "Sortowanie zajelo: " << time.count() << " milisekund" << endl;
        return time;
    }

template<typename T>
    chrono::duration<double, milli> Array_manager<T>::sort_quick_sort() {
        auto t0 = chrono::high_resolution_clock::now();
        quick_sort.sort(sorted_array, 0, array_size - 1);
        auto t1 = chrono::high_resolution_clock::now();
        chrono::duration<double, milli> time = measure_time(t0, t1);
        cout << "Sortowanie zakonczone" << endl;
        cout << "Sortowanie zajelo: " << time.count() << " milisekund" << endl;
        return time;
    }

template<typename T>
void Array_manager<T>::undo_sort() {
        for(int i = 0; i < array_size; i++) {
            sorted_array[i] = main_array[i];
        }
        cout << "Zawartosc glownej tablicy zostala przywrocona" << endl;
    }

template<typename T>
void Array_manager<T>::sort_special(int irange) {             // funkcja sortujaca glowna tablice w calosci / w 33% / 66% lub w kolejnosci malejacej
        int range;
        if(irange == 2) {
            reverse_sort();
            undo_sort();
            return;
        } else if(irange == 1) range = array_size;
        else if(irange == 3) range = array_size / 3;
        else if(irange == 4) range = (array_size / 3) * 2;
        quick_sort.sort(main_array, 0, array_size - 1);
        int swap_index;

        if(irange == 3 || irange == 4) {
            for(int i = range; i < array_size; i++) {
                swap_index = (int)((rand() / static_cast<float>(RAND_MAX)) * (range - i)) + i;
                T temp = main_array[i];
                main_array[i] = main_array[swap_index];
                main_array[swap_index] = temp;
            }
        }

        undo_sort();
    }