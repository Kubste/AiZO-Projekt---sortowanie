#include "Main.hpp"
#include <iostream>
#include <chrono>
using namespace std;

void Main::generate_array_option(int &data_type) {

        cout << "1. int" << endl << "2. float" << endl;
        cout << "Wybierz typ danych: ";
        cin >> data_type;
        cout << "Podaj wielkosc talicy: ";
        cin >> array_size;
        cout << "Podaj zakres generowania liczb pseudolosowych: ";
        cin >> range;
        cout << endl;

        switch(data_type) {
            case 1: int_array_manager.generate_array(array_size, (int)range, true);
            break;

            case 2: float_array_manager.generate_array(array_size, range, true);
            break;
        }
    }

void Main::display_array_option(int data_type) {
        if(data_type == 1) int_array_manager.display_array();
        else if(data_type == 2) float_array_manager.display_array();
        else cout << "Tablica jest pusta!" << endl;
    }

void Main::sort_option(int data_type) {
        int choice;

        cout << "1. Sortowanie przez wstawienie zwykle" << endl;
        cout << "2. Sortowanie przez wstawienie binarne" << endl;
        cout << "3. Sortowanie przez kopcowanie" << endl;
        cout << "4. Szybkie sortowanie" << endl;
        cout << "Wybierz algorytm sortowania: ";
        cin >> choice;

        switch(choice) {
            case 1: if(data_type == 1) int_array_manager.sort_insert_sort();
            else if(data_type == 2) float_array_manager.sort_insert_sort();
            break;

            case 2: if(data_type == 1) int_array_manager.sort_insert_sort_binary();
            else if(data_type == 2) float_array_manager.sort_insert_sort_binary();
            break;

            case 3: if(data_type == 1) int_array_manager.sort_heap_sort();
            else if(data_type == 2) float_array_manager.sort_heap_sort();
            break;

            case 4: if(data_type == 1) int_array_manager.sort_quick_sort();
            else if(data_type == 2) float_array_manager.sort_quick_sort();
            break;
        }
    }

void Main::display_sorted_array_option(int data_type) {
        if(data_type == 1) int_array_manager.display_sorted_array();
        else if(data_type == 2) float_array_manager.display_sorted_array();
        else cout << "Tablica jest pusta!" << endl;
    }

void Main::check_if_array_is_sorted_option(int data_type) {
        if(data_type == 1) {
            if(int_array_manager.check_if_array_is_sorted() == true) cout << "Tablica jest posortowana" << endl;
            else cout << "Tablica nie jest posortowana" << endl;
        } else if(data_type == 2) {
            if(float_array_manager.check_if_array_is_sorted() == true) cout << "Tablica jest posortowana" << endl;
            else cout << "Tablica nie jest posortowana" << endl;
        } else cout << "Tablica jest pusta!" << endl;
    }

void Main::undo_sort_option(int data_type) {
        if(data_type == 1) int_array_manager.undo_sort();
        else if(data_type == 2) float_array_manager.undo_sort();
        else cout << "Tablica jest pusta!" << endl;
    }

void Main::special_cases_option(int data_type) {
        int user_choice;

        cout << "1. Tablica posortowana rosnaco" << endl;
        cout << "2. Tablica posortowana malejaco" << endl;
        cout << "3. Tablica posortowana w 33%" << endl;
        cout << "4. Tablica posortowana w 66%" << endl;
        cout << "Wybierz opcje: ";
        cin >> user_choice;
        cout << endl << "Tablica zostala dostosowana" << endl;

        special_cases_switch(user_choice, data_type);
    }

void Main::special_cases_switch(int user_choice, int data_type) {

        switch(user_choice) {
            case 1: if(data_type == 1) int_array_manager.sort_special(1);
            else if(data_type == 2) float_array_manager.sort_special(1);
            break;

            case 2: if(data_type == 1) int_array_manager.sort_special(2);
            else if(data_type == 2) float_array_manager.sort_special(2);
            break;

            case 3: if(data_type == 1) int_array_manager.sort_special(3);
            else if(data_type == 2) float_array_manager.sort_special(3);
            break;

            case 4: if(data_type == 1) int_array_manager.sort_special(4);
            else if(data_type == 2) float_array_manager.sort_special(4);
            break;

            default:
            break;
        }
    }

void Main::generate_results(int &data_type) {
        int number_of_sorts;
        int array_size;
        float range;
        int sorting_alg;
        int special_case;
        chrono::duration<double, milli> total_time;

        cout << "1. int" << endl;
        cout << "2. float" << endl;
        cout << "Podaj typ danych: ";
        cin >> data_type;
        cout << endl << "1. Tablica posortowana rosnaco" << endl;
        cout << "2. Tablica posortowana malejaco" << endl;
        cout << "3. Tablica posortowana w 33%" << endl;
        cout << "4. Tablica posortowana w 66%" << endl;
        cout << "5. Tablica losowa" << endl;
        cout << "Wybierz opcje: ";
        cin >> special_case;
        cout << endl <<"Z ilu sortowan chcesz pobrac dane: ";
        cin >> number_of_sorts;
        cout << "Podaj rozmiar tablicy: ";
        cin >> array_size;
        cout << "Podaj zakres generowania liczb pseudolosowych: ";
        cin >> range;
        cout << endl << "1. Sortowanie przez wstawienie zwykle" << endl;
        cout << "2. Sortowanie przez wstawienie binarne" << endl;
        cout << "3. Sortowanie przez kopcowanie" << endl;
        cout << "4. Szybkie sortowanie" << endl;
        cout << "Wybierz algorytm sortowania: ";
        cin >> sorting_alg;
        cout << endl;


        for(int i = 1; i <= number_of_sorts; i++) {

            if(data_type == 1) {
                int_array_manager.generate_array(array_size, (int)range, true);
                special_cases_switch(special_case, data_type);

                switch(sorting_alg) {
                    case 1: total_time = total_time + int_array_manager.sort_insert_sort();
                    break;

                    case 2: total_time = total_time + int_array_manager.sort_insert_sort_binary();
                    break;

                    case 3: total_time = total_time + int_array_manager.sort_heap_sort();
                    break;

                    case 4: total_time = total_time + int_array_manager.sort_quick_sort();
                    break;
                }
            }
            else if(data_type == 2) {
                float_array_manager.generate_array(array_size, range, true);
                special_cases_switch(special_case, data_type);

                switch(sorting_alg) {
                    case 1: total_time = total_time + float_array_manager.sort_insert_sort();
                    break;

                    case 2: total_time = total_time + float_array_manager.sort_insert_sort_binary();
                    break;

                    case 3: total_time = total_time + float_array_manager.sort_heap_sort();
                    break;

                    case 4: total_time = total_time + float_array_manager.sort_quick_sort();
                    break;
                }
            }
            if(data_type == 1) {
                if(int_array_manager.check_if_array_is_sorted() == true) cout << "Tablica jest posortowana" << endl;
                else {
                    cout << endl << endl << "WYSTAPIL BLAD W CZASIE SORTOWANIA!!! " << i << 
                    " TABLICA NIE ZOSTALA POSORTOWANA!!!" << endl << endl; 
                }
            }
            else if(data_type == 2) {
                if(float_array_manager.check_if_array_is_sorted() == true) cout << "Tablica jest posortowana" << endl;
                else {
                    cout << endl << endl << "WYSTAPIL BLAD W CZASIE SORTOWANIA!!! " << i << 
                    " TABLICA NIE ZOSTALA POSORTOWANA!!!" << endl << endl; 
                }
            }
            cout << "Wykonano: " << i << " sortowanie" << endl << endl;
        }
        cout << "Seria sortowan ukonczona, wykonano: " << number_of_sorts << " sortowan" << endl;
        cout << "Laczny czas wykonanych sortowan: " << total_time.count() << " milisekund" << endl;
    }

void Main::run() {
        int menu_user_choice;
        int data_type = -1;
        srand(time(NULL));                                              // Inicjalizacja generatora liczb pseudolosowych

        while(true) {

            cout << endl << "Dostepne opcje:" << endl;
            cout << "1. Wczytaj tablice z pliku" << endl;
            cout << "2. Wygeneruj tablice zawierajaca losowe wartosci" << endl;
            cout << "3. Wyswietl tablice na ekranie" << endl;
            cout << "4. Uruchom wybrany algorytm sortowania" << endl;
            cout << "5. Wyswietl posortowana talbice" << endl;
            cout << "6. Sprawdz czy tablica jest posortowana" << endl;
            cout << "7. Cofnij sortowanie" << endl;
            cout << "8. Przypadki szczegolne" << endl;
            cout << "9. Generuj wynik" << endl;
            cout << "10. Zakoncz" << endl;
            cout << "Wybierz opcje: ";
            cin >> menu_user_choice;
            cout << endl;

            switch(menu_user_choice) {
                case 1: file_manager.upload_from_file(int_array_manager, float_array_manager, data_type);
                break;

                case 2: generate_array_option(data_type);
                break;

                case 3: display_array_option(data_type);
                break;

                case 4: sort_option(data_type);
                break;

                case 5: display_sorted_array_option(data_type);
                break;

                case 6: check_if_array_is_sorted_option(data_type);
                break;

                case 7: undo_sort_option(data_type);
                break;

                case 8: special_cases_option(data_type);
                break;

                case 9: generate_results(data_type);
                break;

                case 10: exit(0);
            }
        }
    }

int main() {

    Main main_obj;
    main_obj.run();

    return 0;
}