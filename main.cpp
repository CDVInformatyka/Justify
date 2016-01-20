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
    setlocale(LC_ALL,"");
    SetConsoleTitleA("Justowanie tekstu");
    string text="";
    text=plainText();
    justify(text);
    return 0;
}
