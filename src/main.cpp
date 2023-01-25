#include <bits/stdc++.h>
#include <ctime>
#include <cmath>
using namespace std;
using namespace std::chrono;

int strToInt(string x){
    // ALGORITMA
    if (x == "A"){return 1;}
    else if (x == "2"){
        return 2;
    }
    else if (x == "3"){
        return 3;
    }
    else if (x == "4"){
        return 4;
    }
    else if (x == "5"){
        return 5;
    }
    else if (x == "6"){
        return 6;
    }
    else if (x == "7"){
        return 7;
    }
    else if (x == "8"){
        return 8;
    }
    else if (x == "9"){
        return 9;
    }
    else if (x == "10"){
        return 10;
    }
    else if (x == "J"){
        return 11;
    }
    else if (x == "Q"){
        return 12;
    }
    else if (x == "K"){
        return 13;
    }
    else{
        return 0;
    }
}
string intToStr(int x){
    // ALGORITMA
    if (x == 1){
        return "1";
    }
    else if (x == 2){
        return "2";
    }
    else if (x == 3){
        return "3";
    }
    else if (x == 4){
        return "4";
    }
    else if (x == 5){
        return "5";
    }
    else if (x == 6){
        return "6";
    }
    else if (x == 7){
        return "7";
    }
    else if (x == 8){
        return "8";
    }
    else if (x == 9){
        return "9";
    }
    else if (x == 10){
        return "10";
    }
    else if (x == 11){
        return "11";
    }
    else if (x == 12){
        return "12";
    }
    else if (x == 13){
        return "13";
    }
    else{
        return " ";
    }
}
double operasi(double a, double b, string c){
    // ALGORITMA
    if (c == " + "){
        return (a + b);
    }
    else if (c == " - "){
        return (a - b);
    }
    else if (c == " / "){
        if (b != 0){
            return (a / b);
        }
    }
    else if (c == " * ") {
        return (a * b);
    }
}

double hitung(double a, double b, double c, double d, string op1, string op2, string op3, int var){
    // KAMUS LOKAL
    double hasil, sub;
    // ALGORITMA
    if (var == 1){
        if ((b == 0 && op1 == " / ") || (c == 0 && op2 == " / ") || (d == 0 && op3 == " / ")){
            return 0;
        }
        else{
            hasil = operasi(a, b, op1);
            hasil = operasi(hasil, c, op2);
            hasil = operasi(hasil, d, op3);
            return hasil;
        }
    }
    else if (var == 2){
        if (c == 0 && op2 == " / "){
            return 0;
        }
        else{
            hasil= operasi(b, c, op2);
            if ((hasil == 0 && op1 == " / ") || (d == 0 && op3 == " / ")){
                return 0;
            }
            else{
                hasil = operasi(a, hasil, op1);
                hasil = operasi(hasil, d, op3);
                return hasil;
            }
        }
    }
    else if (var == 3){
        // (a op b) op (c op d) --> a ama b, c ama d, hasil ab sama hasil cd
        if ((b == 0 && op1 == " / ") || d == 0 && op3 == " / "){
            return 0;
        }
        else {
            hasil = operasi(a, b, op1);
            sub = operasi(c, d, op3);
            if (sub == 0 && op2 == " / "){
                return 0;
            }
            else{
                hasil = operasi(hasil, sub, op2);
                return hasil;
            }
        }
    }
    else if (var == 4){
        // a op ((b op c) op d) --> b ama c, hasil ama d, a sama hasil.
        if ((c == 0 && op2 == " / ") || (d == 0 && op3 == " / ")){
            return 0;
        }
        else {
            hasil = operasi(b, c, op2);
            hasil = operasi(hasil, d, op3);
            if (hasil == 0 && op1 == " / "){
                return 0;
            }
            else {
                hasil = operasi(a, hasil, op1);
                return hasil;
            }
        }
    }
    else if (var == 5){
        // a op (b op (c op d)) -- > c ama d, b ama hasil, a ama hasil.
        hasil = operasi(c, d, op3);
        hasil = operasi(b, hasil, op2);
        hasil = operasi(a, hasil, op1);

        if (d == 0 && op3 == " / "){
            return 0;
        }
        else{
            hasil = operasi(c, d, op3);
            if (hasil == 0 && op3 == " / "){
                return 0;
            }
            else{
                hasil = operasi(b, hasil, op2);
                if (hasil == 0 && op1 == " / "){
                    return 0;
                }
                else{
                    hasil = operasi(a, hasil, op1);
                    return hasil;
                }
            }
        }
    }
    else{
        return 0;
    }
}

long BruteForce(string x, vector<string>& solutions, int& sol){
    // KAMUS LOKAL
    string inpt, solution, op[4] = {" + ", " - ", " / ", " * "};
    int input[4];
    bool already, valid = false, save = false;
    double hasil;
    char ans;
    int a, b, c, d, e, lngth = 7, space_count;
    // ALGORITMA 
    if (x == "1"){
        while (!valid){
            string sinput[4];
            bool enough_space = false;
            space_count = 0;
            cout << "Nilai-nilai kartu: A, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K" << endl;
            cout << "Masukkan 4 nilai kartu (setiap nilai dipisahkan dengan spasi):" << endl;
            getline(cin >> ws, inpt);
            for(char space : inpt){
                if (space == ' '){
                    space_count++;
                }
            }
            if (space_count == 3){
                enough_space = true;
                int i = 0, j = 0;
                while ((i < inpt.length()) && (j <= 3)){
                    if (inpt[i] != ' '){
                        sinput[j] += inpt[i];
                        i++;
                    }
                    else{
                        i++;
                        j++;
                    }
                }
            }
            if (enough_space){
                for (int x = 0; x < 4; x++){
                    valid = true;
                    e = strToInt(sinput[x]);
                    if (e > 0 && e < 14){
                        input[x] = e;
                    }
                    else{
                        valid = false;
                        break;
                    }
                }
            }
        }
    }
    if (x == "2"){
        valid = true;
        string sinput[4];
        srand(time(nullptr));
        for (int i = 0; i < 4; i++){
            input[i] = (rand() % 13) + 1;
            sinput[i] = intToStr(input[i]);
        }
        cout << "Kartu yang didapatkan: ";
        for (int i = 0; i < 4; i++){
            cout << intToStr(input[i]) << " ";
        }
        cout << endl;
    }
    //cout << "The four numbers are: " << input[0] << ", " << input[1] << ", " << input[2] << ", " << input[3] << "." << endl;
    // Algoritma
    // Case 1
    int mulai = clock();
    if (valid){
        for (string i : op){
            for (string j : op){
                for (string k : op){
                    // looping operasi
                    for (int idx1 = 0; idx1 < 4; idx1++){
                        a = input[idx1];
                        for (int idx2 = 0; idx2 < 4; idx2++){
                            b = input[idx2];
                            for (int idx3 = 0; idx3 < 4; idx3++){
                                c = input[idx3];
                                for (int idx4 = 0; idx4 < 4; idx4++){
                                    d = input[idx4];
                                    // looping (permutasi) input
                                    if (idx1 != idx2 && idx1 != idx3 && idx1 != idx4 && idx2 != idx3 && idx2 != idx4 && idx3 != idx4){
                                        // varian 1
                                        hasil = hitung(a, b, c, d, i, j, k, 1);
                                        if (hasil == 24){
                                            solution = "((" + intToStr(a) + i + intToStr(b) + ")" + j + intToStr(c) + ")" + k + intToStr(d);
                                            already = false;
                                            for (string check : solutions){
                                                if (solution == check){
                                                    already = true;
                                                    break;
                                                }
                                            }
                                            if (!already){
                                                solutions.push_back(solution);
                                                sol++;
                                            } 
                                        }
                                        // varian 2
                                        hasil = hitung(a, b, c, d, i, j, k, 2);
                                        if (hasil == 24){
                                            solution = "(" + intToStr(a) + i + "(" + intToStr(b) + j + intToStr(c) + "))" + k + intToStr(d);
                                            already = false;
                                            for (string check : solutions){
                                                if (solution == check){
                                                    already = true;
                                                    break;
                                                }
                                            }
                                            if (!already){
                                                solutions.push_back(solution);
                                                sol++;
                                            }
                                        }
                                        hasil = hitung(a, b, c, d, i, j, k, 3);
                                        if (hasil == 24){
                                            solution = "(" + intToStr(a) + i + intToStr(b) + ")" + j + "(" + intToStr(c) + k + intToStr(d) + ")";
                                            already = false;
                                            for (string check : solutions){
                                                if (solution == check){
                                                    already = true;
                                                    break;
                                                }
                                            }
                                            if (!already){
                                                solutions.push_back(solution);
                                                sol++;
                                            }
                                        }
                                        hasil = hitung(a, b, c, d, i, j, k, 4);
                                        if (hasil == 24){
                                            solution = intToStr(a) + i + "((" + intToStr(b) + j + intToStr(c) + ")" + k + intToStr(d) + ")";
                                            already = false;
                                            for (string check : solutions){
                                                if (solution == check){
                                                    already = true;
                                                    break;
                                                }
                                            }
                                            if (!already){
                                                solutions.push_back(solution);
                                                sol++;
                                            }
                                        }
                                        // a op (b op (c op d)) -- > c ama d, b ama hasil, a ama hasil.
                                        hasil = hitung(a, b, c, d, i, j, k, 5);
                                        if (hasil == 24){
                                            solution = intToStr(a) + i + "(" + intToStr(b) + j + "(" + intToStr(c) + k + intToStr(d) + "))";
                                            already = false;
                                            for (string check : solutions){
                                                if (solution == check){
                                                    already = true;
                                                    break;
                                                }
                                            }
                                            if (!already){
                                                solutions.push_back(solution);
                                                sol++;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    int berhenti = clock();
    return (berhenti-mulai);
}

void saveFile(vector<string> answers){
    string ans, filename;
    bool save;
    while (!save){
        if ((ans != "Y") || (ans != "y") || (ans != "N") || (ans != "n")){
            cout << "Apakah anda ingin menyimpan luaran solusi tersebut? (Y/N)" << endl;
            getline(cin, ans);
            save = true;
        }
    }
    if (ans == "Y" || ans == "y"){
        cout << "Nama file yang diinginkan: (tanpa format)" << endl;
        getline(cin, filename);
        //string full = "../bin/" + filename + ".txt";
        string file = "bin/" + filename + ".txt";
        int all = 1;
        ofstream MyFile(file);
        for (string soll: answers){
            if (all % 4 == 0){
                MyFile << soll << endl;
            }
            else{
                MyFile << soll << "    ";
            }
            all++;
        }
        //MyFile.open(full);
        cout << "File tersimpan." << endl;
        MyFile.close();
    }
    else{
        cout << "File tidak tersimpan." << endl;
    }
}
int main(){
    // KAMUS
    vector<string> answers;
    string filename = " ";
    int ex, sol = 0;
    bool pick = false, save = false; 
    string mode, ans;
    // ALGORITMA UTAMA
    cout << "Selamat datang di permainan kartu 24!" << endl;
                    cout << " __   __  ___  _   _______   ___ _____   ____    _     _" << endl;  
                    cout << "|  \\ /  |/ _ \\| | / /  ___) (   |_   _) (___ \\ /  |   | |" << endl;  
                    cout << "|   v   | |_| | |/ /| |_     | |  | |     __) ) o |_  | |" << endl;  
                    cout << "| |\\_/| |  _  |   < |  _)    | |  | |    / __/__   _) | |" << endl;  
                    cout << "| |   | | | | | |\\ \\| |___   | |  | |   | |___  | |   |_|" << endl;  
                    cout << "|_|   |_|_| |_|_| \\_\\_____) (___) |_|   |_____) |_|    O" << "\n" << endl;
    while (!pick){
        cout << "Pilihlah (urutan angka) mode permainan yang ingin dimainkan." << endl;
        cout << "1. Input pilihan pengguna" << endl;
        cout << "2. Pilihan angka secara acak." << endl;
        getline(cin, mode);
        if (mode == "1"){
            ex = BruteForce(mode, answers, sol);
            pick =  true;
        }
        else if (mode == "2"){
            ex = BruteForce(mode, answers, sol);
            pick = true;
        }
    }
    // Output
    int pause = 1;
    for (string soll: answers){
        cout << soll << endl;
    }
    cout << "Jumlah solusi  : " << sol << "." << endl;
    cout << "Waktu Eksekusi : " << ex << " milisekon." << endl;
    saveFile(answers);
}