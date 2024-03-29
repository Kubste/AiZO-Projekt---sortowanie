#include "Insert_sort.hpp"
using namespace std;


template<typename T>
void Insert_sort<T>::sort_normal(T* &sorted_array, int array_size) {

        for(int i = 1; i < array_size; i++) {            // glowna petla, przechodzaca przez kazdy element tablicy, oprocz pierwszego
            T  element = sorted_array[i];                // aktualnie ustawiana liczba
            int j = i - 1;                                      

            while(j >= 0 && sorted_array[j] > element) { // petla ustawiajaca rozpatrywany element tablicy na odpowiadajace mu miejsce
                sorted_array[j + 1] = sorted_array[j];   // stopniowe przesuwanie posortowanej czesci tablicy, do momentu, gdy 
                j--;                                     // petla napotka na liczbe, ktora jest nie wieksza od rozpatrywanego elementu
            }
            sorted_array[j + 1] = element;               // wpisanie ustawianej liczby na odpowiadajace jej miejsce
        }
    }

template<typename T>
void Insert_sort<T>::sort_binary(T* &sorted_array, int array_size) {
        int start_index, end_index, middle;              // zmienne wykorzystywane przy wyszukiwaniu binarnym
        T sorted_number;                                 // aktualnie ustawiana liczba

        for(int i = 1; i < array_size; i++) {            // glowna petla, przechodzaca przez kazdy element tablicy, oprocz pierwszego
            sorted_number = sorted_array[i];
            start_index = -1;                            // ustawinie poczatkowych granic przeszukiwanego obszaru
            end_index = i;

            while(end_index - start_index > 1) {        // petla wyszukujaca odpowiednie miejce dla aktualnie ustawianej liczby
                middle = (start_index + end_index) / 2; // srodek przeszukiwanego obszaru
                if(sorted_number <= sorted_array[middle]) end_index = middle;   // modyfikowanie granic przeszukiwanego prezdzialu
                else start_index = middle;
            }

            for(int j = i; j > end_index; j--) sorted_array[j] = sorted_array[j - 1];   // przesuawnie tablicy

            sorted_array[end_index] = sorted_number;    // umieszczenie ustawianej liczby na odpowiedniej pozycji
        }
    }