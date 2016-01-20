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
    }
    return text;
}

/**
 * Justowanie
 */

string przycinanieTekstu(string &text, int &poczatek, int &koniec ) {
    string buffor;
    if(koniec==text.length()){
        buffor.insert(0,text,poczatek,text.length()-poczatek+1);
        poczatek=text.length();
        return buffor;
    }
    while(koniec>poczatek){
        if(text[koniec--]!=' ')
             continue;
        break;
    }
    buffor.insert(0,text,poczatek,koniec-poczatek+1);
    poczatek=koniec+2;
    return buffor;
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
        string liniaWynik = przycinanieTekstu(text,poczatek,koniec);
        wyrownanie(liniaWynik, szerokosc);
        if ((poczatek+szerokosc) < dlugoscTekstu){
            koniec=poczatek+szerokosc;
        } else {
            koniec=dlugoscTekstu;
        }
        cout << liniaWynik << endl;
    }
}
