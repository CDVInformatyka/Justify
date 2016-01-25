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

void pause(string opis=""){
    if (!(opis=="")){
        cout<<opis<<endl;
    }
    system("PAUSE");
}

/**
 * Obługa plików i tekstu
 */

string plainText(){
    ifstream file;
    string text="",text1="";
    pause("Upewnij się, że plik tekstowy text.txt znajduje sie w folderze z aplikacją!");
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
    }
    return text;
}

/**
 * Justowanie
 */

string przycinanieTekstu(string &text, int &poczatek, int &koniec ) {
    string bufor;
    if(koniec==text.length()){
        bufor.insert(0,text,poczatek,text.length()-poczatek+1);
        poczatek=text.length();
        return bufor;
    }
    while(koniec>poczatek){
        if(text[koniec--]!=' ')
             continue;
        break;
    }
    bufor.insert(0,text,poczatek,koniec-poczatek+1);
    poczatek=koniec+2;
    return bufor;
}

void wyrownanie(string &text , int szerokosc){
    int pozycja=0;
    while(text.length()<szerokosc){
        if(text[pozycja++]==' '){
            text.insert(pozycja," ",1);
            pozycja++;
        }
        if(pozycja>=text.length())
             pozycja=0;
    }
}

void justify(string text, int szerokosc){
    string  wynik="";
    fstream plikWynik;
    int     dlugoscTekstu=text.length(), poczatek=0, koniec;
    if ((poczatek+szerokosc)<dlugoscTekstu){
        koniec=poczatek+szerokosc;
    } else {
        koniec=dlugoscTekstu;
    }
    plikWynik.open("wynik.txt", ios::trunc | ios::out);
    while (poczatek < koniec){
        string liniaWynik = przycinanieTekstu(text,poczatek,koniec);
        wyrownanie(liniaWynik, szerokosc);
        if ((poczatek+szerokosc)<dlugoscTekstu){
            koniec=poczatek+szerokosc;
        } else {
            koniec=dlugoscTekstu;
        }
        cout<<liniaWynik<<endl;
        plikWynik<<liniaWynik<<endl;
    }
    plikWynik.close();
}
