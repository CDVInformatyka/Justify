#include "Justify.h"
#include <windows.h>

/*
 * @AUTHOR      Paweł Otlewski
 * @CDV         Informatyka, 1 rok, zaocznie
 * @COMPILATOR  GNU GCC Compiler
 * @IDE         Code::Blocks 13.12
 * @LICENSE     MIT (X11)
 * @VCS         GitHub
 */

int main()
{
    setlocale(LC_ALL, "");
    SetConsoleTitleA("Justowanie tekstu");
    string plainText="", text="";
    text=chooseMode();
    if(text=="Błąd z plikiem!"){
        cout<<"Prawdopodobnie plik nie istnieje lub aplikacja nie ma do niego dostępu";
        pause();
        return 0;
    }
    cout<<text<<endl;
    //justify(text);
    return 0;
}
