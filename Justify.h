#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std;

/**
 * Podstawowe funkcje
 */

void cls(){
    system("CLS");
}

void pause(){
    system("PAUSE");
}

string getText(string description){
    string text;
    cout<<description<<endl;
    getline(cin,text);
    cout<<text<<endl;
    return text;
}

/**
 * Obługa plików i tekstu
 */
string modeFile(){
    cls();
    cout<<"Upewnij się, że plik znajduje się w tym samym folderze, co plik exe!"<<endl;
    cout<<"Podaj nazwę pliku (z rozszerzeniem): ";
    string filename,text="",text1;
    cin>>filename;
    ifstream file;
    file.open(filename.c_str());
    if(file.is_open())
    {
        while(getline(file, text1)){
            text+=text1+" ";
        }
    } else {
        text="Błąd z plikiem!";
    }
    return text;
}

string modeNoFile(){
    string text;
    getline(cin,text);
    cout<<text<<endl;
    return text;
    //return getText("Podaj tekst do wyrównania: ");
}

string pobieranieTekstuOMG(){
    bool correct=0;
    string plainText;
    do {
        string text="";
        cout<<"Pobierać dane z pliku? (T/N): ";
        cin>>text;
        if(text=="T" || text=="N" || text=="t" || text=="n"){
            correct=1;
            if(text=="T" || text=="t"){
                plainText=modeFile();
            } else {
                getline(cin,plainText);
            }
        }
    } while (correct!=1);
    return plainText;
}

string chooseMode(){
    bool correct=0;
    string plainText;
    do {
        string text="";
        cout<<"Pobierać dane z pliku? (T/N): ";
        cin>>text;
        if(text=="T" || text=="N" || text=="t" || text=="n"){
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

/**
 * Justowanie
 */

//string przycinanieTekstu(){
//    return 0;
//};
//
//void justify(string text){
//    const int szerokosc = 80;
//    string wynik="";
//    int dlugoscTekstu = text.length();
//    int poczatek=0;
//    int koniec;
//    if ((poczatek+szerokosc) < dlugoscTekstu){
//        koniec=poczatek+szerokosc;
//    } else {
//        koniec=dlugoscTekstu;
//    }
//    while (poczatek < koniec){
//        string liniaWynik = przycinanieTekstu();
//    }
//}
