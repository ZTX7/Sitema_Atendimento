#include <stdio.h>
#include <locale.h>
#include <wchar.h>

// teste de caracteres especiais

int main() {
    setlocale(LC_ALL, "");
    wprintf(L"áãâç\n");
    return 0;
}