#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std;

/* Przydatne funkcje */
void cls(){
    system("CLS");
}

void pause(){
    system("PAUSE");
}

string getText(string description){
    string text;
    cout<<description;
    cin>>text;
    return text;
}

/* Dodawanie tekstu! */
string modeFile(){
    cls();
    cout<<"Upewnij się, że plik znajduje się w tym samym folderze, co plik exe!"<<endl;
    cout<<"Podaj nazwę pliku (z rozszerzeniem): ";
    string filename,text="",text1;
    cin>>filename;
    ifstream file;
    file.open(filename.c_str());
    if(file.good())
    {
        int i=0;
        while(getline(file, text1)){
            if(i!=0){text+=" ";}
            text+=text1;
            i=1;
        }
    } else {
        return "Błąd z plikiem!";
    }
    return text;
}

string modeNoFile(){
    return getText("Podaj tekst do wyrównania: ");
}

string chooseMode(){
    bool correct=0;
    string plainText;
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
