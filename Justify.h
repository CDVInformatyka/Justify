#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <sys/stat.h>

using namespace std;

/* Przydatne funkcje */
void cls(){
    system("CLS");
}

bool fileExists (string& fileName) {
    ifstream file(fileName.c_str());
    if (file.good()) {
        file.close();
        return true;
    } else {
        file.close();
        return false;
    }
}

/* Dodawanie tekstu! */
string modeFile(){
    cout<<"Upewnij się, że plik znajduje się w tym samym folderze, co plik exe!"<<endl;
    cout<<"Podaj nazwę pliku (z rozszerzeniem): ";
    string filename;
    cin>>filename;
    ofstream file;
    if(fileExists(filename)){
        return "Pliku nie znaleziono!";
    }
    file.open(filename.c_str());
}
string modeNoFile(){
    return "kupa";
}

string chooseMode(){
    bool correct=0;
    string plainText="";
    do {
        cls();
        string text="";
        cout<<"Pobierać dane z pliku? (T/N): ";
        cin>>text;
        if(text=="T" || text=="N" || text=="t" || text=="n"){
            cls();
            correct=1;
            if(text=="T" || text=="t"){
                plainText=modeFile();
            } else {
                plainText=modeNoFile();
            }
        }
    } while (correct!=1);
    return plainText;
}
