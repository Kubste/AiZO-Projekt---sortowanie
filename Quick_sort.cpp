#include "Quick_sort.hpp"
using namespace std;


template<typename T>
void Quick_sort<T>::swap_elements(T* &sorted_array, int x, int y) {            // funkcja zamieniajace miejscami elementy tablicy
        T temp = sorted_array[x];
        sorted_array[x] = sorted_array[y];
        sorted_array[y] = temp;
    }

template<typename T>
void Quick_sort<T>::sort(T* &sorted_array, int left_main_index, int right_main_index) {
        
        int left_index = left_main_index - 1;
        int right_index = right_main_index + 1;
        T pivot = sorted_array[(left_index + right_index) / 2];     // ustalenie wartosci pivot, jako srodkowa wartosc tablicy

        while(true) {

            while(pivot > sorted_array[++left_index]);              // zwiekszanie/zmiejszanie wartosci lewego i prawego wskaznika,
            while(pivot < sorted_array[--right_index]);             // do momentu gdy ich wartosc nie bedzie mniejsza/wieksza od pivot

            if(left_index <= right_index) swap_elements(sorted_array, left_index, right_index);
            else break;                                         // zamiana miejscami elementow wskazywanych przez prawy i lewy wskaznik

        }

        if(right_index > left_main_index) sort(sorted_array, left_main_index, right_index); // dalsze dzielenie tablicy i sortowanie 
        if(left_index < right_main_index) sort(sorted_array, left_index, right_main_index); 

    }