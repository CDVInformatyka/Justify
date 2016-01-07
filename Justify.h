#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

void cls(){
    system("CLS");
}

int walidacjaInt(){
	int x;
	while(!(cin>>x)){cin.clear();cin.sync();}
	cls();return x;
}

string modeFile(){
    return "kupa";
}
string modeNoFile(){
    return "kupa";
}

string chooseMode(){
    bool correct=0;
    do {
        cls();
        string text="";
        cout<<"Pobierać dane z pliku? (T/N): ";
        cin>>text;
        if(text=="T" || text=="N" || text=="t" || text=="n"){
            cls();
            correct=1;
            string plainText="";
            if(text=="T" || text=="t"){
                plainText=modeFile();
            } else {
                plainText=modeNoFile();
            }
        }
    } while (correct!=1);
    return plainText;
}
