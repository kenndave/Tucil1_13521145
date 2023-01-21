#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void BruteForce(char x)
int main(){
    // KAMUS
    char mode;
    bool pick = false;
    // ALGORITMA UTAMA
    cout << "Selamat datang di permainan kartu 24!" << endl;
    while (!pick){
        cout << "Pilihlah (urutan angka) mode permainan yang ingin dimainkan." << endl;
        cout << "1. Input pilihan pengguna" << endl;
        cout << "2. Pilihan angka secara acak." << endl;
        cin >> mode;
        if (mode == '1'){
            pick =  true;
        }
        else if (mode == '2'){
            pick = true;
        }
    }


}