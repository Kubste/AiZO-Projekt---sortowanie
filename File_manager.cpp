#include "File_manager.hpp"
using namespace std;



void File_manager::upload_from_file(Array_manager<int> &int_array_manager, Array_manager<float> &float_array_manager, int &data_type) {
        string line;
        ifstream file;
        int number_of_rows = 0;
        int i = 0;

        cout << "1. int" << endl << "2. float" << endl;
        cout << "Wybierz typ danych: ";
        cin >> data_type;
        cout << "Podaj sciezke do pliku: ";
        cin >> file_path;

        file.open(file_path);

        if(file.is_open()) {
            if(getline(file, line)) {
                number_of_rows = stoi(line);
            }
            if(data_type == 1) {
                int_array_manager.generate_array(number_of_rows, 0, false);
                while(getline(file, line)) {
                    int_array_manager.save_from_file(i++, stoi(line));
                }
                i = 0;
            }
            else if(data_type == 2) { 
                float_array_manager.generate_array(number_of_rows, 0, false);
                while(getline(file, line)) {
                    float_array_manager.save_from_file(i++, stof(line));
                }
                i = 0;
            }
        }
        file.close();
    }