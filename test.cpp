#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int strToInt(string x){
    if (x == "A"){return 1;}
    else if (x == "2"){return 2;}
    else if (x == "3"){return 3;}
    else if (x == "4"){return 4;}
    else if (x == "5"){return 5;}
    else if (x == "6"){return 6;}
    else if (x == "7"){return 7;}
    else if (x == "8"){return 8;}
    else if (x == "9"){return 9;}
    else if (x == "10"){return 10;}
    else if (x == "J"){return 11;}
    else if (x == "Q"){return 12;}
    else if (x == "K"){return 13;}
}
string intToStr(int x){
    if (x == 1){return "A";}
    else if (x == 2){return "2";}
    else if (x == 3){return "3";}
    else if (x == 4){return "4";}
    else if (x == 5){return "5";}
    else if (x == 6){return "6";}
    else if (x == 7){return "7";}
    else if (x == 8){return "8";}
    else if (x == 9){return "9";}
    else if (x == 10){return "10";}
    else if (x == 11){return "J";}
    else if (x == 12){return "Q";}
    else if (x == 13){return "K";}
}
double operasi(double a, double b, string c){
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
    double hasil, sub;
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
    else if (var == 6){
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
int main(){
    // Containers
    vector<string> solutions;
    string solution, sinput[4], op[4] = {" + ", " - ", " / ", " * "};
    int input[4];
    bool valid = false, already, save; 
    int a, b, c, d, sol = 0;
    double sub, hasil;
    // Jenis kurung
    // ((a op b) op c) op d --> a ama b, hasil ama c, hasil ama d
    // (a op (b op c)) op d --> b ama c, a sama hasil, hasil sama d
    // (a op b) op (c op d) --> a ama b, c ama d, hasil ab sama hasil cd
    // a op ((b op c) op d) --> b ama c, hasil ama d, a sama hasil.
    // a op (b op (c op d)) -- > c ama d, b ama hasil, a ama hasil.

    // Input
    while (!valid){
        cout << "Enter 4 numbers:" << endl;
        cin >> sinput[0] >> sinput[1] >> sinput[2] >> sinput[3];
        for (int x = 0; x < 4; x++){
            valid = true;
            if (sinput[x] == "A"){input[x] = 1;}
            else if (sinput[x] == "2"){input[x] = 2;}
            else if (sinput[x] == "3"){input[x] = 3;}
            else if (sinput[x] == "4"){input[x] = 4;}
            else if (sinput[x] == "5"){input[x] = 5;}
            else if (sinput[x] == "6"){input[x] = 6;}
            else if (sinput[x] == "7"){input[x] = 7;}
            else if (sinput[x] == "8"){input[x] = 8;}
            else if (sinput[x] == "9"){input[x] = 9;}
            else if (sinput[x] == "10"){input[x] = 10;}
            else if (sinput[x] == "J"){input[x] = 11;}
            else if (sinput[x] == "Q"){input[x] = 12;}
            else if (sinput[x] == "K"){input[x] = 13;}
            else{
                valid = false;
                break;
            }
        }
    }
    //cout << "The four numbers are: " << input[0] << ", " << input[1] << ", " << input[2] << ", " << input[3] << "." << endl;
    // Algoritma
    // Case 1
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
    // Output
    
    // File
    ofstream MyFile("filename.txt");
    int pause = 1;
    for (string soll: solutions){
        if (pause % 4 == 0){
            MyFile << soll << endl;
            cout << soll << endl;
        }
        else{
            MyFile << soll << "    ";
            cout << soll << "    ";
        }
        pause++;
    }
    if ((pause-1) % 4 != 0){
        cout << "\n" << "Jumlah solusi: " << sol << "." << endl;;
    }
    else{
        cout << "Jumlah solusi: " << sol << "." << endl;
    }

    char ans;
    save = false;
    while (!save){
        if ((ans != 'Y') || (ans != 'y') || (ans != 'N') || (ans != 'n')){
            cout << "Save answer? (Y/N)" << endl;
            cin >> ans;
            save = true;
        }
    }
    if (ans == 'Y' || ans == 'y'){
        cout << "File saved." << endl;
        MyFile.close();
    }
    else{
        cout << "File not saved." << endl;
    }
}









// Output
    
    // File
    ofstream MyFile("filename.txt");
    int pause = 1;
    for (string soll: solutions){
        if (pause % 4 == 0){
            MyFile << soll << endl;
            cout << soll << endl;
        }
        else{
            MyFile << soll << "    ";
            cout << soll << "    ";
        }
        pause++;
    }
    if ((pause-1) % 4 != 0){
        cout << "\n" << "Jumlah solusi: " << sol << "." << endl;;
    }
    else{
        cout << "Jumlah solusi: " << sol << "." << endl;
    }

    char ans;
    save = false;
    while (!save){
        if ((ans != 'Y') || (ans != 'y') || (ans != 'N') || (ans != 'n')){
            cout << "Save answer? (Y/N)" << endl;
            cin >> ans;
            save = true;
        }
    }
    if (ans == 'Y' || ans == 'y'){
        cout << "File saved." << endl;
        MyFile.close();
    }
    else{
        cout << "File not saved." << endl;
    }