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

/**
 * Obługa plików i tekstu
 */

string plainText(){
    ifstream file;
    string text="",text1="";
    file.open("text.txt");
    if(file.is_open() && file.good())
    {
        while(getline(file, text1)){
            text+=text1+" ";
        }
        file.close();
    } else {
        cout<<"Brak pliku text.txt!\nPodaj tekst do justowania:"<<endl;
        getline(cin,text);
        cout<<text<<endl;
        pause();
    }
    return text;
}

/**
 * Justowanie
 */

string przycinanieTekstu(){
    return 0;
};

void justify(string text){
    const int szerokosc = 80;
    string wynik="";
    int dlugoscTekstu = text.length();
    int poczatek=0;
    int koniec;
    if ((poczatek+szerokosc) < dlugoscTekstu){
        koniec=poczatek+szerokosc;
    } else {
        koniec=dlugoscTekstu;
    }
    while (poczatek < koniec){
        string liniaWynik = przycinanieTekstu();
    }
}
