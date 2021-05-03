#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    string str;
    int step;
    vector<int> new_code;
    vector<char> new_str, symbols;
    cin >> step;
    if (step > 26) {
        int r = step / 26;
        step = step - (r * 26);
    }
    system("cls");
    string path = "input.txt";
    string path1 = "output.txt";
    fstream textin;
    fstream textout; 
    textin.open(path, fstream::in | fstream::out | fstream::app);
    textout.open(path1, fstream::in | fstream::out);
    if (!textin.is_open()) {
        cout << "Ошибка при открытии файла" << endl;
   }
    else {

        while (getline(textin, str)) {
            for (int i = 0; i < str.size(); i++) {
                symbols[i] = str[i];
                int cod = int(symbols[i]);
                 if (cod >= 32 && cod <= 63) {
                     new_code.push_back(cod);
                 }
                 else if (cod >= 123 && cod <= 126) {
                     new_code.push_back(cod);
                 }
                 else if (cod >= 91 && cod <= 96) {
                     new_code.push_back(cod);
                 }
                 else if (cod >= 65 && cod <= 90) {
                     int code = (int)symbols[i] + step;
                     if (code > 90) {
                         code -= 26;
                     }
                     new_code.push_back(code);
                 }
                 else if (cod >= 97 && cod <= 122) {
                     int code = (int)symbols[i] + step;
                     if (code > 122) {
                         code -= 26;
                     }
                     new_code.push_back(code);
                new_code.push_back(cod);
            }
        }

        cout << "\n";
         for (int i = 0; i < str.size(); i++) {
             char n_sym = (char)new_code[i];
             new_str.push_back(n_sym);
         }

                 for (int i = 0; i < new_str.size(); i++) {
                     textout << new_str[i];
                 }

         }
        textin.close();
        textout.close();
    }
}
