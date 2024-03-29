#include "Heap_sort.hpp"
#include <iostream>
using namespace std;

template<typename T>
void Heap_sort<T>::swap_elements(T* &sorted_array, int x, int y) {    // funkcja zamieniajaca miejscami elementy tablicy
        T temp = sorted_array[x];
        sorted_array[x] = sorted_array[y];
        sorted_array[y] = temp;
    }

template<typename T>
void Heap_sort<T>::heapify(T* &sorted_array, int array_size, int i) {
        int largest = i;                                        // aktualnie najwiekszy element - rodzic
        int left = 2 * i + 1;                                   // potomkowie 
        int right = 2 * i + 2;

        if(left < array_size && sorted_array[left] > sorted_array[largest]) largest = left;     // zmiana indeksu rodzica i potomka, 
        if(right < array_size && sorted_array[right] > sorted_array[largest]) largest = right;  // jesli ma wieksza wartosc

        if(largest != i) {                                      // zamiana miejscami w tablicy rodzica i potomka w tablicy,
            swap_elements(sorted_array, i, largest);            // jesli wartosc potomka byla wieksza niz rodzica
            heapify(sorted_array, array_size, largest);         // kontynuowanie budowania kopca, do momentu kiedy element 
        }                                                       // trafi na wlasciwe miejsce
    }

template<typename T>
void Heap_sort<T>::sort(T* &sorted_array, int array_size) {
        int j;

        for(int i = 1; i < array_size; i++) {
            j = i;
            while(sorted_array[j] > sorted_array[(j-1)/ 2]) {       // budowanie kopca
                swap_elements(sorted_array, j, (j - 1) / 2);        // zamiana miejscami elementu rodzica i potomka, jesli wartosc
                j = (j-1)/2;                                        // potomka jest większa
            }
        }
        for(int i = array_size - 1; i >= 0; i--) {
            swap_elements(sorted_array, 0, i);                      // zamiana pierwszego i ostatniego elementu, aby usunąc największy
            heapify(sorted_array, i, 0);                            // element z kopca ; tworzenie kopca z pozostalych elementow tablicy
    }
    }