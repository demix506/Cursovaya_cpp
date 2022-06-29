#include "bib.h"

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int a;
    do{
        cout << "\nВи в головному меню!\n1) Data Input\n2) Data Output\n3) File input\n4) File out\n0) Exit\n\n";
        cout << ">> "; cin >> a;
        switch (a) {
        case 1: inData(); break;
        case 2: outData(); break;
        case 3: inFile(); break;
        case 4: outFile(); break;
        case 0: cout << "Програма завершилась без помилок.\n"; break;
        default: cout << "Неправільна відповідь.\n";
        }
    } while (a != 0);
    return 0;
}